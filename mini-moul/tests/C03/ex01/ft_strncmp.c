#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex01/ft_strncmp.c"
#include "../../../utils/constants.h"

int test1(void)
{
	if (ft_strncmp("Hello", "HelloWorld", 8) >= 0)
	{
		printf("    " RED "[1] ft_strcpy(\"ABCDEFGH\") doesn\'t output 1\n");
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strncmp(\"Hello\", \"HelloWorld\", 8) output %d\n" DEFAULT, ft_strncmp("Hello", "Hello1", 8));
	return (0);
}

int test2(void)
{
	if (ft_strncmp("Hello", "HelloWorld", 4) != 0)
	{
		printf("    " RED "[1] ft_strcpy(\"ABCDEFGH\") doesn\'t output 1\n");
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strncmp(\"Hello\", \"HelloWorld\", 4) output %d\n" DEFAULT, ft_strncmp("Hello", "Hello1", 4));
	return (0);
}

int test3(void)
{
	if (ft_strncmp("Hello", "HelloWorld", 6) >= 0)
	{
		printf("    " RED "[1] ft_strcpy(\"ABCDEFGH\") doesn\'t output 1\n");
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strncmp(\"Hello\", \"HelloWorld\", 6) output %d\n" DEFAULT, ft_strncmp("Hello", "Hello1", 6));
	return (0);
}

int main(void)
{
	if (test1() + test2() + test3() != 0)
		return (-1);
	return (0);
}
