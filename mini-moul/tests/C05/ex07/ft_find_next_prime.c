#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex07/ft_find_next_prime.c"
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

	number = ft_find_next_prime(407013);
	if (number != 407023)
	{
		printf("    " RED "[1] Expected %d, got %d\n" DEFAULT, 407023, number);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_find_next_prime(407013) output %d\n" DEFAULT, number);
	return (0);
}