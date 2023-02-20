#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex01/ft_strncmp.c"
#include "../../../utils/constants.h"

typedef struct s_test
{
    char *desc;
    char *s1;
    char *s2;
    size_t n;
    int expected;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {
            .desc = "Comparing equal strings",
            .s1 = "Hello",
            .s2 = "Hello",
            .n = 5,
            .expected = 0,
        },
        {
            .desc = "Comparing strings with same prefix",
            .s1 = "Hello",
            .s2 = "HelloWorld",
            .n = 8,
            .expected = -1,
        },
        {
            .desc = "Comparing different strings",
            .s1 = "Hello",
            .s2 = "World",
            .n = 5,
            .expected = -1,
        },
        {
            .desc = "Comparing same string with different n values",
            .s1 = "Hello",
            .s2 = "Hello",
            .n = 6,
            .expected = 0,
        },
        {
            .desc = "Comparing empty strings",
            .s1 = "",
            .s2 = "",
            .n = 5,
            .expected = 0,
        }};
    int count = sizeof(tests) / sizeof(tests[0]);

    return run_tests(tests, count);
}

int run_tests(t_test *tests, int count)
{
    int i;
    int error = 0;

    for (i = 0; i < count; i++)
    {
        int result = ft_strncmp(tests[i].s1, tests[i].s2, tests[i].n);

        if ((result < 0 && tests[i].expected >= 0) || (result > 0 && tests[i].expected <= 0) || (result == 0 && tests[i].expected != 0))
        {
            printf(RED " [%d] %s: expected %s, got %d\n" DEFAULT, i + 1, tests[i].desc, (tests[i].expected < 0 ? "negative value" : (tests[i].expected > 0 ? "positive value" : "0")), result);
            error -= 1;
        }
        else
        {
            printf("  " GREEN CHECKMARK GREY " [%d] %s: expected %s, got %d\n" DEFAULT, i + 1, tests[i].desc, (tests[i].expected < 0 ? "negative value" : (tests[i].expected > 0 ? "positive value" : "0")), result);
        }
    }

    return error;
}