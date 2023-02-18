#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex04/ft_putnbr_base.c"
#include "../../../utils/constants.h"

void redirect_output(void);
int test1(void);
void redirect_output2(void);
int test2(void);
void redirect_output3(void);
int test3(void);
void redirect_output4(void);
int test4(void);

int main(void)
{
        if (test1()+test2()+test3()+test4() != 0)
                return (-1);
        return (0);
}

int test1(void)
{
        redirect_output();
        // Open the output file and check its contents
        FILE *fp = fopen("output.txt", "r");
        char buffer[80024];
        fgets(buffer, sizeof(buffer), fp);
        fclose(fp);

        // Check that the output matches the expected value
        const char *expected_output = "-1100";
            if (strcmp(buffer, expected_output) != 0)
        {
                printf("    " RED "[1] Expected \"%s\", got \"%s\"\n"DEFAULT, expected_output, buffer);
                remove("output.txt");
                return (-1);
        }
        else printf("  " GREEN CHECKMARK GREY " [1] Expected \"%s\", got \"%s\"\n"DEFAULT, expected_output, buffer);
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
        ft_putnbr_base(-12, "01");

        // Restore the original output
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(saved_stdout);
}

int test2(void)
{
        redirect_output2();
        // Open the output file and check its contents
        FILE *fp = fopen("output.txt", "r");
        char buffer[80024];
        fgets(buffer, sizeof(buffer), fp);
        fclose(fp);

        // Check that the output matches the expected value
        const char *expected_output = "vp\0";
            if (strncmp(buffer, expected_output, 2) != 0)
        {
                printf("    " RED "[2] Expected \"%s\", got \"%s\"\n", expected_output, buffer);
                remove("output.txt");
                return (-1);
        }
        else printf("  " GREEN CHECKMARK GREY " [2] Expected \"%s\", got \"%s\"\n"DEFAULT, expected_output, buffer);
        remove("output.txt");
        return (0);
}

void redirect_output2(void)
{
        // Redirect the output to a file
        int saved_stdout = dup(STDOUT_FILENO);
        int output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        dup2(output_fd, STDOUT_FILENO);
        close(output_fd);

        // Call the function to be tested
        ft_putnbr_base(40, "poneyvif");

        // Restore the original output
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(saved_stdout);
}

int test3(void)
{
        redirect_output3();
        // Open the output file and check its contents
        FILE *fp = fopen("output.txt", "r");
        char buffer[80024];
        fgets(buffer, sizeof(buffer), fp);
        fclose(fp);

        // Check that the output matches the expected value
        const char *expected_output = "894867";
            if (strncmp(buffer, expected_output, 6) != 0)
        {
                printf("    " RED "[3] Expected \"%s\", got \"%s\"\n", expected_output, buffer);
                remove("output.txt");
                return (-1);
        }
        else printf("  " GREEN CHECKMARK GREY " [3] Expected \"%s\", got \"%s\"\n"DEFAULT, expected_output, buffer);
        remove("output.txt");
        return (0);
}

void redirect_output3(void)
{
        // Redirect the output to a file
        int saved_stdout = dup(STDOUT_FILENO);
        int output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        dup2(output_fd, STDOUT_FILENO);
        close(output_fd);

        // Call the function to be tested
        ft_putnbr_base(894867, "0123456789");

        // Restore the original output
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(saved_stdout);
}

int test4(void)
{
        redirect_output4();
        // Open the output file and check its contents
        FILE *fp = fopen("output.txt", "r");
        char buffer[80024];
        fgets(buffer, sizeof(buffer), fp);
        fclose(fp);

        // Check that the output matches the expected value
        const char *expected_output = "35";
            if (strncmp(buffer, expected_output, 2) != 0)
        {
                printf("    " RED "[1] Expected \"%s\", got \"%s\"\n", expected_output, buffer);
                remove("output.txt");
                return (-1);
        }
        else printf("  " GREEN CHECKMARK GREY " [1] ft_putnbr(-2147483648) output \"%s\"\n" DEFAULT, buffer);
        remove("output.txt");
        return (0);
}

void redirect_output4(void)
{
        // Redirect the output to a file
        int saved_stdout = dup(STDOUT_FILENO);
        int output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        dup2(output_fd, STDOUT_FILENO);
        close(output_fd);

        // Call the function to be tested
        ft_putnbr_base(53, "0123456789abcdef");

        // Restore the original output
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(saved_stdout);
}