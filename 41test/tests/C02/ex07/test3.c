#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../../../../ex01/ft_strncpy.c"

int	main(void)
{
	char src[] = "Hello";
	char dest[] = "World1";

	if (strcmp(ft_strncpy(dest, src, 7), "Hello") != 0)
		return (-1);
	return (0);
}