#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex08/ft_print_combn.c"
#include "../../../utils/constants.h"

void print_success(char *str, int num);
void print_error(char *str, int num);
void redirect_output(void);
int test1(void);

int main(void)
{
        if (test1() != 0)
                return (-1);
        return (0);
}

int test1(void)
{
        redirect_output();
        // Open the output file and check its contents
        FILE *fp = fopen("output.txt", "r");
        char buffer[1024000];
        fgets(buffer, sizeof(buffer), fp);
        fclose(fp);

        // Check that the output matches the expected value
        const char *expected_output = "01, 02, 03, 04, 05, 06, 07, 08, 09, 12, 13, 14, 15, 16, 17, 18, 19, 23, 24, 25, 26, 27, 28, 29, 34, 35, 36, 37, 38, 39, 45, 46, 47, 48, 49, 56, 57, 58, 59, 67, 68, 69, 78, 79, 89";
            if (strcmp(buffer, expected_output) != 0)
        {
                printf("    " RED "[1] Expected \"%s\", got \"%s\"\n", expected_output, buffer);
                remove("output.txt");
                return (-1);
        }
        else printf("  " GREEN CHECKMARK GREY " [1] ft_print_combn(2) output correctly\n" DEFAULT);
        remove("output.txt");
        return (0);
}

void redirect_output(void)
{
        // Redirect the output to a file
        int saved_stdout = dup(STDOUT_FILENO);
        int output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        dup2(output_fd, STDOUT_FILENO);
        close(output_fd);

        // Call the function to be tested
        ft_print_combn(2);

        // Restore the original output
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(saved_stdout);
}

void print_success(char *str, int num)
{
        printf("  " GREEN CHECKMARK GREY " [%d] %s\n" DEFAULT, num, str);
}

void print_error(char *str, int num)
{
        printf("    " RED "[%d] %s\n" DEFAULT, num, str);
}