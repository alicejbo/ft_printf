#include "ft_printf.h"
#include <limits.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
	int		ret;

//	MB_CUR_MAX = 3;
//	FD = open("/dev/ttys000", O_WRONLY);
	ft_printf("t %5p\n", 0);
	printf("\n");
	printf("t %05.c", 0);
//%      i 42 == | 42|
//	% i -42 == |-42|
//	% 4i 42 == |  42|
	return 0;
}
