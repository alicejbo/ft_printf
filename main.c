#include "ft_printf.h"
#include <limits.h>
#include <fcntl.h>
#include <locale.h>
#include <wchar.h>
#include <float.h>
#include <math.h>
//#include <fenv.h>
//#include <tgmath.h>
//#include <stdbool.h>
//#include <assert.h>

int main(int argc, const char *argv[])
{
	float	bite;

//	bite = 4.94065645841246544176568792868E-324;
	bite = 33;
	ft_printf("%50f\n",bite);
	while (1)
		;
//	printf("\n");
//	printf("%50f\n", bite);
	//%      i 42 == | 42|
	//	% i -42 == |-42|
	//	% 4i 42 == |  42|
	return 0;
}
