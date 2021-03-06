#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_LEN 4096
static char receive[BUFFER_LEN];

int main()
{
	char stringToSend[BUFFER_LEN];
	int ret, fd;

	fd = open("/sys/kernel/debug/fortytwo/foo", O_RDWR);

	if (fd < 0) {
		perror("failed to open device");
		return errno;
	}
	printf("type a string \n");
	scanf("%[^\n]%*c", stringToSend);
	printf("writing message [%s] \n", stringToSend);

	ret = write(fd, stringToSend, strlen(stringToSend));
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
	printf("Message received: %s\n", receive);
	return (0);
}
