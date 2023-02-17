#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex00/ft_strcmp.c"

#define GREEN "\033[38;5;84m"
#define RED "\033[31m"
#define GREY "\033[38;5;8m"
#define DEFAULT "\033[0m"
#define CHECKMARK "\xE2\x9C\x93"

int test1(void)
{
	if (ft_strcmp("Hello", "Hello1") >= 0)
	{
		printf("    " RED "[1] ft_strcpy(\"ABCDEFGH\") doesn\'t output 1\n");
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strcmp(\"Hello\", \"Hello1\") output %d\n" DEFAULT, ft_strcmp("Hello", "Hello1"));
	return (0);
}

int test2(void)
{
	if (ft_strcmp("Hello", "He") <= 0)
	{
		printf("    " RED "[2] ft_strcpy(\"ABCDEFGHaI\") doesn\'t output 0\n" DEFAULT);
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
		printf("    " RED "[3] ft_strcpy(\"-_134556ABCDEFGaH67\") doesn\'t output 0\n" DEFAULT);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [3] ft_strcmp(\"Hello\", \"Hello\") output %d\n" DEFAULT, ft_strcmp("Hello", "Hello"));
	return (0);
}

int main(void)
{
	if (test1() + test2() + test3() != 0)
		return (-1);
	return (0);
}
