#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex00/ft_strlen.c"

#define GREEN "\033[38;5;84m"
#define RED "\033[31m"
#define GREY "\033[38;5;8m"
#define DEFAULT "\033[0m"
#define CHECKMARK "\xE2\x9C\x93"

int test1(void)
{
	if (ft_strlen("854dsjfksdlk") != 12)
	{
		printf("    " RED "[1] ft_strlen(\"854dsjfksdlk\") doesn\'t output 12\n");
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strlen(\"854dsjfksdlk\") output %d\n" DEFAULT, ft_strlen("854dsjfksdlk"));
	return (0);
}

int main(void)
{
	if (test1() != 0)
		return (-1);
	return (0);
}
