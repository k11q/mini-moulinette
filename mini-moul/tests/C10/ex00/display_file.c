#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "../../../utils/constants.h"

typedef struct s_test
{
    char *desc;
    char *filename;
    char *expected;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {
            .desc = "Display contents of file",
            .filename = "test.txt",
            .expected = "Hello, world!\n",
        },
        {
            .desc = "No argument provided",
            .filename = "",
            .expected = "File name missing.\n",
        },
        {
            .desc = "Too many arguments provided",
            .filename = "test.txt test2.txt",
            .expected = "Too many arguments.\n",
        },
        {
            .desc = "File cannot be read",
            .filename = "does_not_exist.txt",
            .expected = "Cannot read file.\n",
        },
    };
    int count = sizeof(tests) / sizeof(tests[0]);

    return run_tests(tests, count);
}

int run_tests(t_test *tests, int count)
{
    int i, j;
    int error = 0;

    for (i = 0; i < count; i++)
    {
        // Create the file with the test content
        char *filename = tests[i].filename;
        FILE *fp = fopen(filename, "w");
        fprintf(fp, "Hello, world!\n");
        fclose(fp);

        // Run the program and capture its output
        char buf[1024];
        memset(buf, 0, sizeof(buf));
        char *program_name = "./ft_display_file"; // Change this to your program name
        char command[1024] = {0};
        strcat(command, program_name);
	    strcat(command, " ");
    strcat(command, filename);

    int pipefd[2];
    pipe(pipefd);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);
    int status = system(command);

    char expected_output[1024];
    memset(expected_output, 0, sizeof(expected_output));
    strcat(expected_output, tests[i].expected);

    int len = read(pipefd[0], buf, sizeof(buf));
    buf[len] = '\0';
    close(pipefd[0]);

    if (strcmp(buf, expected_output) != 0)
    {
        printf("    " RED "[%d] %s Failed\n" DEFAULT, i + 1, tests[i].desc);
        printf("        Expected: \"%s\"\n", expected_output);
        printf("        Got:      \"%s\"\n", buf);
        error -= 1;
    }
    else
    {
        printf("  " GREEN CHECKMARK GREY " [%d] %s output \"%s\" as expected\n" DEFAULT, i + 1, tests[i].desc, modify_string(buf));
    }

    // Remove the file created for this test
    remove(filename);
}

return error;
}

char *modify_string(const char *str)
{
int len = strlen(str);
if (len > 0 && str[len - 1] == '\n')
{
char *new_str = (char *)malloc(len);
strncpy(new_str, str, len - 1);
new_str[len - 1] = '$';
return new_str;
}
else
{
return strdup(str);
}
}
       

