#include "ft_printf.h"
#include <limits.h>
#include <fcntl.h>
#include <locale.h>
#include <wchar.h>
#include <float.h>

int main(int argc, const char *argv[])
{
	long double		bite;

//	bite = 4.94065645841246544176568792868E-324;
	bite = 3.14;
	ft_printf("%Lf\n", bite);
//	printf("\n");
	printf("%Lf\n", bite);
	//%      i 42 == | 42|
	//	% i -42 == |-42|
	//	% 4i 42 == |  42|
	return 0;
}
