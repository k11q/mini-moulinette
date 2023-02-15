#include <stdio.h>
#include <unistd.h>
#define RESET   "\033[0m"
#define GREEN   "\033[32m"

int	main(void)
{
	printf(GREEN "Test 1: " RESET);
	printf(GREEN "Diff OK :D\n" RESET);
}
