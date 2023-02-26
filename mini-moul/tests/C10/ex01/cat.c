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
        char *program_name = "./ft_cat"; // Change this to your program name
        char command[1024] = {0};
        strcat(command, program_name);
        strcat(command, " ");
        strcat(command, filename);
        FILE *output = popen(command, "r");
        if (output == NULL)
        {
            fprintf(stderr, "Failed to run command '%s': %s\n", command, strerror(errno));
            return -1;
        }

        // Check if output matches expected result
        fgets(buf, sizeof(buf), output);
if (strcmp(buf, tests[i].expected) != 0)
{
printf("Test '%s' failed. Expected output: '%s', Actual output: '%s'\n", tests[i].desc, tests[i].expected, buf);
error = -1;
}    // Clean up the created file
    if (remove(filename) != 0)
    {
        fprintf(stderr, "Failed to remove file '%s': %s\n", filename, strerror(errno));
        return -1;
    }

    pclose(output);
}

if (error == 0)
{
    printf("All tests passed successfully!\n");
}

return error;
}

