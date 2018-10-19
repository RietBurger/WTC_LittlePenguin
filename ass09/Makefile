ifneq ($(KERNELRELEASE),)
	obj-m := my_mod.o

else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD	:=$(shell pwd)

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	insmod my_mod.ko

endif

clean:
	rm -rf *.o *~core.depend .*.cmd *.ko *.mod.c\
		.tmp_versions module* Module*  \
