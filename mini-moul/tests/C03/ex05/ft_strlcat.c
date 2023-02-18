#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex05/ft_strlcat.c"
#include "../../../utils/constants.h"

int test1(void)
{
	char src[] = "Born to code";
    	char dest [] = "1337 42";
	char *expected_output = "1337 42Born to code";

	ft_strlcat(dest, src, 20);
	
	if (strcmp(dest, expected_output) != 0)
	{
		printf("    " RED "[1] ft_strlcat(\"1337 42\", \"Born to code\", 20) Expected \"%s\" output %s\n" DEFAULT, expected_output, dest);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strlcat(\"1337 42\", \"Born to code\", 20) Expected \"%s\" output %s\n" DEFAULT, expected_output, dest);
	return (0);
}

int main(void)
{
	if (test1() != 0)
		return (-1);
	return (0);
}
