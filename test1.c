#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	char a;

	a = '1';
	if (ac > 1)
		printf("%-13hhc\n", a);
	else
		printf("\n");
	return (0);
}
