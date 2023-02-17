#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex12/ft_print_memory.c"

#define GREEN "\033[38;5;84m"
#define RED "\033[31m"
#define GREY "\033[38;5;8m"
#define DEFAULT "\033[0m"
#define CHECKMARK "\xE2\x9C\x93"

int test1(void)
{
	printf("    " RED "[1] Sorry. Test not yet implemented\n");
	return (-1);
}

int main(void)
{
	if (test1() != 0)
		return (-1);
	return (0);
}