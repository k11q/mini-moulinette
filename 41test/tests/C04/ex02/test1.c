#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex02/ft_putnbr.c"

#define GREEN "\033[38;5;84m"
#define RED "\033[31m"
#define GREY "\033[38;5;8m"
#define DEFAULT "\033[0m"
#define CHECKMARK "\xE2\x9C\x93"

int test1(void)
{
	// Redirect the output to a file
	int saved_stdout = dup(STDOUT_FILENO);
	int output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);

	// Call the function to be tested
	ft_putnbr(289343);

	// Restore the original output
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);

	// Open the output file and check its contents
	FILE *fp = fopen("output.txt", "r");
	char buffer[1024];
	fgets(buffer, sizeof(buffer), fp);
	fclose(fp);

	// Check that the output matches the expected value
	const char *expected_output = "289343";
	if (strcmp(buffer, expected_output) != 0)
	{
		printf("    " RED "[1] Expected \"289343\", got \"%s\"\n", buffer);
		remove("output.txt");
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_putnbr(289343) output \"289343\"\n" DEFAULT);
	remove("output.txt");
	return (0);
}
/*
int test2(void)
{
	// Redirect the output to a file
	int saved_stdout = dup(STDOUT_FILENO);
	int output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);

	// Call the function to be tested
	ft_putnbr(-53454);

	// Restore the original output
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);

	// Open the output file and check its contents
	FILE *fp = fopen("output.txt", "r");
	char buffer[1024];
	fgets(buffer, sizeof(buffer), fp);
	fclose(fp);

	// Check that the output matches the expected value
	const char *expected_output = "-53454";
	if (strcmp(buffer, expected_output) != 0)
	{
		printf("    " RED "[1] Expected \"-53454\", got \"%s\"\n", buffer);
		remove("output.txt");
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_putnbr(-53454) output \"-53454\"\n" DEFAULT);
	remove("output.txt");
	return (0);
}
*/
int main()
{
	if (test1() != 0)
		return (-1);
	return 0;
}