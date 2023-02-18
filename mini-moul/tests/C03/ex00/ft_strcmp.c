#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex00/ft_strcmp.c"
#include "../../../utils/constants.h"

int test1(void)
{
	if (ft_strcmp("Hello", "Hello1") >= 0)
	{
		printf("    " RED "[1] ft_strcmp(\"Hello\", \"Hello1\") Expected -49, got %d\n"DEFAULT, ft_strcmp("Hello", "Hello1"));
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strcmp(\"Hello\", \"Hello1\") Expected -49, got %d\n"DEFAULT, ft_strcmp("Hello", "Hello1"));
	return (0);
}

int test2(void)
{
	if (ft_strcmp("Hello", "He") <= 0)
	{
		printf("    " RED "[2] ft_strcmp(\"Hello\", \"He\") Expected 108, got %d\n" DEFAULT, ft_strcmp("Hello", "He"));
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [2] ft_strcmp(\"Hello\", \"He\") output %d\n" DEFAULT, ft_strcmp("Hello", "He"));
	return (0);
}

int test3(void)
{
	if (ft_strcmp("Hello", "Hello") != 0)
	{
		printf("    " RED "[3] ft_strcmp(\"Hello\", \"Hello\") Expected 0, got %d\n"DEFAULT, ft_strcmp("Hello", "Hello"));
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [3] ft_strcmp(\"Hello\", \"Hello\") Expected 0, got %d\n"DEFAULT, ft_strcmp("Hello", "Hello"));
	return (0);
}

int main(void)
{
	if (test1() + test2() + test3() != 0)
		return (-1);
	return (0);
}
