#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex05/ft_strlcat.c"
#include "../../../utils/constants.h"

int test1(void)
{
	char src[] = "Born to code";
    	char dest [] = "1337 42";

	ft_strlcat(dest, src, 20);
	
	if (strcmp(dest, "1337 42Born to code") != 0)
	{
		printf("    " RED "[1] Expected \"1337 42Born to code\" output %s\n" DEFAULT, dest);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strlcat(dest, src, 20) output \"%s\"\n" DEFAULT, dest);
	return (0);
}

int main(void)
{
	if (test1() != 0)
		return (-1);
	return (0);
}
