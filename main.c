#include "ft_printf.h"

int main(int argc, const char *argv[])
{
	int		a;

	a = ft_printf("%lld", 9223372036854775800);
	printf("a=%d\n", a);
	return 0;
}
