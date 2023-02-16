#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../../../../ex00/ft_strcpy.c"

int	main(void)
{
	char	dest[5];
	char	ex[5] = "TcXF";

	if (strcmp(ft_strcpy(dest, ex), "TcXF") != 0)
		return (-1);
	return (0);
}
