
#include "../iotpanda.h"



int main(int argc, const char *argv[])
{
	int fd;
	char buff[256];
	int len = 0;

	if (argc < 2)
		err_arg_quit("Usage: %s <fifo>\n", argv[0]);

	if ((fd = open(argv[1], O_RDWR)) == -1)
		sys_quit("[fifo] open error : ");

	while(1)
	{
	
		bzero(buff, sizeof(buff));

		if ((len = read(fd, buff, sizeof(buff))) == -1)
			sys_quit("read fifo error ");

		write(STDOUT_FILENO, buff, len);
	}
	return 0;
}
