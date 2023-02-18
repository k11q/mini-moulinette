#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex01/ft_strncmp.c"
#include "../../../utils/constants.h"

int test1(void)
{
	int result;
	int expected_output;

	result = ft_strncmp("Hello", "HelloWorld", 8);
	expected_output = -1;
	if (result != expected_output)
	{
		printf("    " RED "[1] ft_strncmp(\"Hello\", \"HelloWorld\", 8) Expected %d, got %d\n"DEFAULT, expected_output, result);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strncmp(\"Hello\", \"HelloWorld\", 8) Expected %d, got %d\n"DEFAULT, expected_output, result);
	return (0);
}

int test2(void)
{
	int result;
	int expected_output;

	result = ft_strncmp("Hello", "HelloWorld", 4);
	expected_output = 0;
	if (result != expected_output)
	{
		printf("    " RED "[2] ft_strncmp(\"Hello\", \"HelloWorld\", 4) Expected %d, got %d\n"DEFAULT, expected_output, result);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [2] ft_strncmp(\"Hello\", \"HelloWorld\", 4) Expected %d, got %d\n"DEFAULT, expected_output, result);
	return (0);
}

int test3(void)
{
	int result;
	int expected_output;

	result = ft_strncmp("Hello", "HelloWorld", 6);
	expected_output = -1;
	if (result != expected_output)
	{
		printf("    " RED "[3] ft_strncmp(\"Hello\", \"HelloWorld\", 6) Expected %d, got %d\n"DEFAULT, expected_output, result);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [3] ft_strncmp(\"Hello\", \"HelloWorld\", 6) Expected %d, got %d\n"DEFAULT, expected_output, result);
	return (0);
}

int main(void)
{
	if (test1() + test2() + test3() != 0)
		return (-1);
	return (0);
}
