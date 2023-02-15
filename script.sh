#!/bin/bash

# Set colors
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# Set a flag to track whether any test failed
FAILED=0

# Compile the program
gcc -o print_args print_args.c

# Test case 1: No arguments
if [ "$(./print_args)" != "" ]; then
  echo -e "${RED}Test case 1 failed: Expected output: '', actual output: '$(./print_args)'${NC}"
  FAILED=1
else
  echo -e "${GREEN}Test case 1 passed.${NC}"
fi

# Test case 2: One argument
if [ "$(./print_args QBWTtLu8RI9Kvfr)" != "QBWTtLu8RI9Kvfrs" ]; then
  echo -e "${RED}Test case 2 failed: Expected output: 'QBWTtLu8RI9Kvfrs', actual output: '$(./print_args QBWTtLu8RI9Kvfr)'${NC}"
  FAILED=1
else
  echo -e "${GREEN}Test case 2 passed.${NC}"
fi

# Test case 3: Multiple arguments
if [ "$(./print_args Hello World!)" != "Hello"$'\n'"World!" ]; then
  echo -e "${RED}Test case 3 failed: Expected output: 'Hello\nWorld!', actual output: '$(./print_args Hello World!)'${NC}"
  FAILED=1
else
  echo -e "${GREEN}Test case 3 passed.${NC}"
fi

# Add more test cases as needed

# Remove the executable
rm print_args

# Remove any output files (assuming they start with "print_args_output")
rm -f print_args_output*

# Print a message indicating whether any tests failed
if [ $FAILED -eq 0 ]; then
  echo -e "${GREEN}All tests passed successfully.${NC}"
else
  echo -e "${RED}Some tests failed.${NC}"
fi

