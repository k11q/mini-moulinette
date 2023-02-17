#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex06/ft_strlen.c"
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
	char *c = "Hello";

	if (ft_strlen(c) != 5)
	{
		printf("    " RED "[1] Expected %d, got %d\n" DEFAULT, 5, ft_strlen(c));
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strlen(\"Hello\") output %d\n" DEFAULT, ft_strlen(c));
	return (0);
}