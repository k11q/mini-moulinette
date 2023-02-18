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
	int result;
	int expected_output;

	result = ft_strlen(c);
	expected_output = 5;
	if (result != expected_output)
	{
		printf("    " RED "[1] ft_strlen(\"Hello\") Expected %d, got %d\n" DEFAULT, expected_output, result);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strlen(\"Hello\") Expected %d, got %d\n" DEFAULT, expected_output, result);
	return (0);
}