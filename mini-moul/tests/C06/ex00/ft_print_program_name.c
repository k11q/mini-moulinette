#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "../../../utils/constants.h"

int test1(void);
char* modify_string(const char *str);

int main(void)
{
  if (test1() != 0)
    return (-1);
  return (0);
}

int test1()
{
  char buf[1024];
  char *program_name = "./program_name"; // Change this to your program name
  char *copy_program = "cp ../ex00/ft_print_program_name.c program_name.c";
  char *compile_command = "cc -Wall -Werror -Wextra program_name.c -o program_name"; // Change this to the compile command for your program
  FILE *fp;
  int result;

  // Compile the program
  system(copy_program);
  system(compile_command);

  // Run the program and capture its output
  fp = popen(program_name, "r");
  if (fp == NULL)
  {
    fprintf(stderr, "Failed to run command '%s': %s\n", program_name, strerror(errno));
    exit(EXIT_FAILURE);
  }

  while (fgets(buf, sizeof(buf), fp) != NULL)
  {
    if (strcmp(buf, "./program_name\n") != 0)
    {
      printf("    " RED "[1] %s Expected \"%s$\", got \"%s\"\n" DEFAULT, program_name, program_name, modify_string(buf));
      result = -1;
    }
    else
    {
      printf("  " GREEN CHECKMARK GREY " [1] %s Expected \"%s$\", got \"%s\"\n" DEFAULT, program_name, program_name, modify_string(buf));
      result = 0;
    }
  }

  if (pclose(fp) == -1)
  {
    fprintf(stderr, "Failed to close command stream: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Remove the program executable
  if (remove(program_name) != 0)
  {
    fprintf(stderr, "Failed to remove program '%s': %s\n", program_name, strerror(errno));
    exit(EXIT_FAILURE);
  }

  if (remove("program_name.c") != 0)
  {
    fprintf(stderr, "Failed to remove program '%s': %s\n", "program_name.c", strerror(errno));
    exit(EXIT_FAILURE);
  }

  return (result);
}

char* modify_string(const char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        char *new_str = (char*)malloc(len);
        strncpy(new_str, str, len - 1);
        new_str[len - 1] = '$';
        return new_str;
    } else {
        return strdup(str);
    }
}