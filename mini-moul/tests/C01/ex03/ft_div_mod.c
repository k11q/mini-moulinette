#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex03/ft_div_mod.c"
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
	int a;
	int b;
	int x;
	int y;

	a = 10;
	b = 5;
	ft_div_mod(a, b, &x, &y);


	if (x != 2 || y != 0)
	{
		printf("    " RED "[1] Expected x = 3, got %d. Expected y = 2, got %d\n" DEFAULT, x, y);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_div_mod(10, 5, &x, &y) output x = 2, y = 0\n" DEFAULT);
	return (0);
}