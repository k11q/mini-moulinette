#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex04/ft_is_negative.c"
#include "../../../utils/constants.h"
#define putchar custom_putchar

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
        char buffer[1024];
        fgets(buffer, sizeof(buffer), fp);
        fclose(fp);

        // Check that the output matches the expected value
        const char *expected_output = "P";
        if (strcmp(buffer, expected_output) != 0)
        {
                printf("    " RED "[1] Expected \"%s\", got \"%s\"\n", expected_output, buffer);
                remove("output.txt");
                return (-1);
        }
        else
                printf("  " GREEN CHECKMARK GREY " [1] ft_is_negative('8') output \"%s\"\n" DEFAULT, buffer);
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
        ft_is_negative(8);

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