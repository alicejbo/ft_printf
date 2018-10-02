#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac > 1)
		printf("% #o\n", atoi(av[1]));
	else
		printf("\n");
	return (0);
}
