#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex00/ft_ft.c"
#include "../../../utils/constants.h"

int test1(void);

int main(void)
{
	if (test1() != 0)
		return (-1);
	return (0);
}

int test1(void)
{
	int	*nbr;
	int	number = 33;

	nbr = &number;
	ft_ft(nbr);

	if (number != 42)
	{
		printf("    " RED "[1] Expected %d, got %d\n" DEFAULT, 42, number);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_ft(nbr) output %d\n" DEFAULT, number);
	return (0);
}