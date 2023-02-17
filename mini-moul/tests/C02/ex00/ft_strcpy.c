#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex00/ft_strcpy.c"

#define GREEN "\033[38;5;84m"
#define RED "\033[31m"
#define GREY "\033[38;5;8m"
#define DEFAULT "\033[0m"
#define CHECKMARK "\xE2\x9C\x93"

int test1(void)
{
	char dest[12];
	char ex[12] = "FGccjqWCcYr";

	if (strcmp(ft_strcpy(dest, ex), "FGccjqWCcYr") != 0)
	{
		printf("    " RED "[1] ft_strcpy(\"ABCDEFGH\") doesn\'t output 1\n");
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strcpy(\"ABCDEFGH\") output 1\n" DEFAULT);
	return (0);
}

int test2(void)
{
	char dest2[40];
	char ex2[40] = "gVepWWXynLOXqCHCscGrowUZSebdZIfy";

	if (strcmp(ft_strcpy(dest2, ex2), "gVepWWXynLOXqCHCscGrowUZSebdZIfy") != 0)
	{
		printf("    " RED "[2] ft_strcpy(\"ABCDEFGHaI\") doesn\'t output 0\n" DEFAULT);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [2] ft_strcpy(\"ABCDEFGHaI\") output 0\n" DEFAULT);
	return (0);
}

int test3(void)
{
	char dest3[5];
	char ex3[5] = "TcXF";

	if (strcmp(ft_strcpy(dest3, ex3), "TcXF") != 0)
	{
		printf("    " RED "[3] ft_strcpy(\"-_134556ABCDEFGaH67\") doesn\'t output 0\n" DEFAULT);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [3] ft_strcpy(\"-_134556ABCDEFGaH67\") output 0\n" DEFAULT);
	return (0);
}

int main(void)
{
	if (test1() + test2() + test3() != 0)
		return (-1);
	return (0);
}
