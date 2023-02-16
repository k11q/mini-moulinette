#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../../../../ex00/ft_strcpy.c"

int	main(void)
{
	char	dest[40];
	char	ex[40] = "gVepWWXynLOXqCHCscGrowUZSebdZIfy";

	if (strcmp(ft_strcpy(dest, ex), "gVepWWXynLOXqCHCscGrowUZSebdZIfy") != 0)
		return (-1);
	return (0);
}
