#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex01/ft_recursive_factorial.c"
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

	number = ft_recursive_factorial(4);
	if (number != 24)
	{
		printf("    " RED "[1] Expected %d, got %d\n" DEFAULT, 24, number);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_recursive_factorial(4) output %d\n" DEFAULT, number);
	return (0);
}