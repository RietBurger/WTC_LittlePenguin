// SPDX-License-Identifier: GPL-2.0
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/seq_file.h>
#include <linux/mount.h>
#include <linux/proc_fs.h>
#include <linux/fs_struct.h>
#include <linux/fs.h>
#include <linux/namei.h>
#include <linux/kallsyms.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("rburger");
MODULE_DESCRIPTION("find mount points");

static struct proc_dir_entry *proc_entry;

typedef int (*idef)(int(*)(struct vfsmount*, void*), void*,
				   struct vfsmount *);
typedef struct vfsmount *(*cdef)(const struct path *);

char *buff;

static int create_seq(struct vfsmount *root, void *data)
{
	struct super_block *root_sb;
	struct seq_file *s;
	struct path path;

	root_sb = root->mnt_sb;
	path.mnt = root;
	path.dentry = root->mnt_root;
	s = (struct seq_file *)data;
	seq_printf(s, "%-10s\t%s\n", root_sb->s_id,
		   d_path(&path, buff, PAGE_SIZE));
	return 0;
}

static void mounts(char *dir, struct seq_file *s)
{
	struct path path;
	struct vfsmount *root;
	cdef collectm;
	idef iteratem;

	iteratem = (void *)kallsyms_lookup_name("iterate_mounts");
	collectm = (void *)kallsyms_lookup_name("collect_mounts");
	kern_path(dir, 0, &path);
	root = collectm(&path);
	iteratem(create_seq, (void *)s, root);
}

static int seq_mounts(struct seq_file *s, void *v)
{
	mounts("/", s);
	return 0;
}

static int proc_open(struct inode *i, struct file *f)
{
	return single_open(f, &seq_mounts, NULL);
}

const static struct file_operations seqfops = {
	.owner = THIS_MODULE,
	.open = proc_open,
	.read = seq_read,
};

static int __init mymod_init(void)
{
	pr_info("RED: myMod started");
	proc_entry = proc_create("mymounts", 0644, NULL, &seqfops);
	buff = kmalloc(sizeof(char) * PAGE_SIZE, GFP_KERNEL);
	return 0;
}

static void __exit mymod_cleanup(void)
{
	kfree(buff);
	remove_proc_entry("mymounts", NULL);
	pr_info("RED: Cleaning up module.\n");
}
module_init(mymod_init);
module_exit(mymod_cleanup);
