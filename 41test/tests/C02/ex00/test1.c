#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../../../../ex00/ft_strcpy.c"

int	main(void)
{
	char	dest[12];
	char	ex[12] = "FGccjqWCcYr";

	if (strcmp(ft_strcpy(dest, ex), "FGccjqWCcYr") != 0)
		return (-1);
	return (0);
}
