#include "ft_printf.h"
#include <limits.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
	int		c;

	MB_CUR_MAX = 3;
	FD = open("/dev/ttys000", O_WRONLY);
	ft_printf("{%30S}", L"我是一只猫。");
	printf("\n%05.S", L"Jambon");
	return 0;
}
