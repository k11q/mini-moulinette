#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex04/ft_fibonacci.c"
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

	number = ft_fibonacci(7);
	if (number != 13)
	{
		printf("    " RED "[1] Expected %d, got %d\n" DEFAULT, 13, number);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_fibonacci(4) output %d\n" DEFAULT, number);
	return (0);
}