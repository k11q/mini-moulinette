#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include "../../../utils/constants.h"

typedef struct s_test
{
  char *desc;
  char *cmd;
  char *expected;
} t_test;

int run_test(t_test test, int test_num);
char *modify_string(const char *str);

int main(void)
{
  t_test tests[] = {
      {.desc = "Valid addition",
       .cmd = "./do-op 1 + 1",
       .expected = "2\n"},
      {.desc = "Valid subtraction",
       .cmd = "./do-op 10 - 5",
       .expected = "5\n"},
      {.desc = "Valid multiplication",
       .cmd = "./do-op 5 * 6",
       .expected = "30\n"},
      {.desc = "Valid division",
       .cmd = "./do-op 30 / 5",
       .expected = "6\n"},
      {.desc = "Valid modulo",
       .cmd = "./do-op 7 % 3",
       .expected = "1\n"},
      {.desc = "Division by 0",
       .cmd = "./do-op 7 / 0",
       .expected = "Stop : division by zero\n"},
      {.desc = "Modulo by 0",
       .cmd = "./do-op 7 % 0",
       .expected = "Stop : modulo by zero\n"},
      {.desc = "Invalid operator",
       .cmd = "./do-op 1 p 1",
       .expected = "0\n"},
      {.desc = "Invalid number of arguments",
       .cmd = "./do-op 1 +",
       .expected = ""},
      {.desc = "Invalid operator and number of arguments",
       .cmd = "./do-op 1",
       .expected = ""},
      {.desc = "Multiple valid operations",
       .cmd = "./do-op 1 + 1 * 2 - 3 / 3",
       .expected = "2\n"},
  };

  int num_tests = sizeof(tests) / sizeof(t_test);

  int overall_result = 0;

  for (int i = 0; i < num_tests; i++)
  {
    int result = run_test(tests[i], i + 1);

    if (result != 0)
    {
      overall_result = -1;
    }
  }

  return overall_result;
}

int run_test(t_test test, int test_num)
{
  fflush(stdout);
  char buf[1024];
  memset(buf, 0, sizeof(buf));
  char *copy_program = "cp ../ex05/do-op.c do-op.c";
  char *compile_command = "cc -Wall -Werror -Wextra do-op.c -o do-op";
  FILE *fp;
  int result;

  // Compile the program
  system(copy_program);
  system(compile_command);

  // Run the program and capture its output
  fp = popen(test.cmd, "r");
  if (fp == NULL)
  {
    fprintf(stderr, "Failed to run command '%s': %s\n", test.cmd, strerror(errno));
    exit(EXIT_FAILURE);
  }

  while (fgets(buf, sizeof(buf), fp) != NULL)
  {
    if (strcmp(buf, test.expected) != 0)
    {
      printf("    " RED "[%d] %s Expected \"%s\", got \"%s\"\n" DEFAULT, test_num, test.desc, test.expected, modify_string(buf));
      result = -1;
    }
    else {
printf(" " GREEN CHECKMARK GREY " [%d] %s output \"%s\" as expected\n" DEFAULT, test_num, test.desc, modify_string(buf));
result = 0;
}
}

if (pclose(fp) == -1)
{
fprintf(stderr, "Failed to close command stream: %s\n", strerror(errno));
exit(EXIT_FAILURE);
}

// Remove the program executable
if (remove("do-op") != 0)
{
fprintf(stderr, "Failed to remove program '%s': %s\n", "do-op", strerror(errno));
exit(EXIT_FAILURE);
}

if (remove("do-op.c") != 0)
{
fprintf(stderr, "Failed to remove program '%s': %s\n", "do-op.c", strerror(errno));
exit(EXIT_FAILURE);
}

return (result);
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
