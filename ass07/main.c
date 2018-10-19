#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_LEN 4096
static char receive[BUFFER_LEN];

int main(int ac, char **av)
{
	if (ac >= 1) {
		int ret, fd;
		char F;

		if (fd < 0) {
			perror("failed to open device");
			return errno;
		}

		printf("give intput\n");
		F = getchar();

		ret = write(fd, F, 2);
		if (ret < 0) {
			perror("failed to write message to device");
			return errno;
		}

		close(fd);
		fd = open("/sys/kernel/debug/fortytwo/foo", O_RDWR);
		ret = read(fd, receive, BUFFER_LEN);
		if (ret < 0) {
			perror("failed to read message from device");
			return errno;
		}
		printf("this is receive: %s", receive);
	} else {
		printf("Please add input\n");
		return (0);
	}
	return (0);
}
