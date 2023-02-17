#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex05/ft_sqrt.c"
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

	number = ft_sqrt(16);
	if (number != 4)
	{
		printf("    " RED "[1] Expected %d, got %d\n" DEFAULT, 4, number);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_sqrt(16) output %d\n" DEFAULT, number);
	return (0);
}