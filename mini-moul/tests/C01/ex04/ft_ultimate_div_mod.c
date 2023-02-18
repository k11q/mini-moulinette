#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex04/ft_ultimate_div_mod.c"
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
	int x;
	int	y;

	x = 15;
	y = 3;
	ft_ultimate_div_mod(&x, &y);

	if (x != 5 || y != 0)
	{
		printf("    " RED "[1] ft_ultimate_div_mod(x = 15, y = 3) Expected x = 3, got %d. Expected y = 2, got %d\n" DEFAULT, x, y);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_ultimate_div_mod(x = 15, y = 3) Expected x = 3, got %d. Expected y = 2, got %d\n" DEFAULT, x, y);
	return (0);
}