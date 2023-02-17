#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex11/ft_putstr_non_printable.c"
#include "../../../utils/constants.h"

int test1(void)
{
	// Redirect the output to a file
	int saved_stdout = dup(STDOUT_FILENO);
	int output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);

	// Call the function to be tested
	ft_putstr_non_printable("Coucou\ntu vas bien");

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
	const char *expected_output = "Coucou\\0atu vas bien";
	if (strcmp(buffer, expected_output) != 0)
	{
		printf("    " RED "[1] Expected \"Coucou\\0atu vas bien\", got \"%s\"\n", buffer);
		remove("output.txt");
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_putstr_non_printable(\"Coucou\\ntu vas bien\") output \"Coucou\\0atu vas bien\"\n" DEFAULT);
	remove("output.txt");
	return (0);
}

/*
int test2(void)
{
	// Redirect the output to a file
	int saved_stdout = dup(STDOUT_FILENO);
	int output_fd = open("output2.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);

	// Call the function to be tested
	ft_putstr_non_printable("Coucou tu vas bie\t\v\0n");

	// Restore the original output
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);

	// Open the output file and check its contents
	FILE *fp = fopen("output2.txt", "r");
	char buffer[1024];
	fgets(buffer, sizeof(buffer), fp);
	fclose(fp);

	// Check that the output matches the expected value
	const char *expected_output = "Coucou tu vas bie\\09\\0b";
	if (strcmp(buffer, expected_output) != 0)
	{
		printf("    " RED "[2] Expected \"%s\", got \"%s\"\n" DEFAULT, expected_output, buffer);
		remove("output2.txt");
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [2] ft_putstr_non_printable(\"Coucou tu vas bie\\t\\v\\0n\") output \"Coucou tu vas bie\\09\\0b\" \n" DEFAULT);
	remove("output2.txt");
	return (0);
}
*/

int main()
{
	if (test1() != 0)
		return (-1);
	return 0;
}