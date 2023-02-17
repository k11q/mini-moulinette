#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex02/ft_iterative_power.c"
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
	int	number;

	number = ft_iterative_power(4, 3);
	if (number != 64)
	{
		printf("    " RED "[1] Expected %d, got %d\n" DEFAULT, 64, number);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_iterative_power(4, 3) output %d\n" DEFAULT, number);
	return (0);
}