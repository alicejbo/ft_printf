#include "ft_printf.h"
#include <limits.h>
#include <fcntl.h>
#include <locale.h>
#include <wchar.h>
#include <float.h>

int main(int argc, const char *argv[])
{
	double		bite;

//	bite = 4.94065645841246544176568792868E-324;
	bite = -.2229;
	ft_printf("%.3f\n",bite);
//	printf("\n");
	printf("%.3f\n", bite);
	//%      i 42 == | 42|
	//	% i -42 == |-42|
	//	% 4i 42 == |  42|
	return 0;
}
