#include "ft_printf.h"
#include <limits.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
//	int		c;

//	MB_CUR_MAX = 3;
//	FD = open("/dev/ttys000", O_WRONLY);
	ft_printf("t %#7.5X\n", 0xab);
	printf("\n");
	printf("t %#7.5X", 0xab);
//%      i 42 == | 42|
//	% i -42 == |-42|
//	% 4i 42 == |  42|
	return 0;
}
