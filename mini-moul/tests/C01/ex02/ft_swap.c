#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex02/ft_swap.c"
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
	int	x;
	int	y;
	
	x = 2;
	y = 3;
	ft_swap(&x, &y);

	if (x != 3 || y != 2)
	{
		printf("    " RED "[1] Expected x = 3, got %d. Expected y = 2, got %d\n" DEFAULT, x, y);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_swap(x = 2, y = 3) output x = 3, y = 2\n" DEFAULT);
	return (0);
}