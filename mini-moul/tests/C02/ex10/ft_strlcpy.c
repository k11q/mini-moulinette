#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex10/ft_strlcpy.c"
#include "../../../utils/constants.h"

int test1(void)
{
	char src[] = "World!";
	char dest[] = "Hello ";

	ft_strlcpy(dest, src, 10);
	if (strcmp(dest, "World!") != 0)
	{
		printf("    " RED "[1] Expected dest != \"World!\"\n");
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] Expected dest == \"World!\"\n" DEFAULT);
	return (0);
}

int test2(void)
{
	char src[] = "World!";
	char dest[] = "Hello ";

	if (ft_strlcpy(dest, src, 10) != 6)
	{
		printf("    " RED "[2] ft_strlcpy(dest, src, 10) != 6\"\n");
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [2] ft_strlcpy(dest, src, 10) == 6\n" DEFAULT);
	return (0);
}

int main(void)
{
	if (test1()+test2() != 0)
		return (-1);
	return (0);
}