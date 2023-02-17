#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex06/ft_is_prime.c"
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

	number = ft_is_prime(258449);
	if (number != 1)
	{
		printf("    " RED "[1] Expected %d, got %d\n" DEFAULT, 24, number);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_is_prime(258449) output %d\n" DEFAULT, number);
	return (0);
}