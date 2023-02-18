#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex02/ft_swap.c"
#include "../../../utils/constants.h"

int test1(void);
int test2(void);
int test3(void);

int main(void)
{
	if (test1()+test2()+test3() != 0)
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
		printf("    " RED "[1] ft_swap(x = 2, y = 3) Expected x = 3, got %d. Expected y = 2, got %d\n" DEFAULT, x, y);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_swap(x = 2, y = 3) output x = 3, y = 2\n" DEFAULT);
	return (0);
}

int test2(void)
{
	int	x;
	int	y;
	
	x = 9;
	y = -4;
	ft_swap(&x, &y);

	if (x != -4 || y != 9)
	{
		printf("    " RED "[2] ft_swap(x = 9, y = -4) Expected x = -4, got %d. Expected y = 9, got %d\n" DEFAULT, x, y);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [2] ft_swap(x = 9, y = -4) output x = -4, y = 9\n" DEFAULT);
	return (0);
}

int test3(void)
{
	int	x;
	int	y;
	
	x = -32;
	y = 54;
	ft_swap(&x, &y);

	if (x != 54 || y != -32)
	{
		printf("    " RED "[3] ft_swap(x = -32, y = 54) Expected x = 54, got %d. Expected y = -32, got %d\n" DEFAULT, x, y);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [3] ft_swap(x = -32, y = 54) output x = 54, y = -32\n" DEFAULT);
	return (0);
}