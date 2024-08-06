#!/bin/bash

source ~/mini-moulinette/mini-moul/config.sh

function handle_sigint {
  echo "${RED}Script aborted by user. Cleaning up..."
  rm -R mini-moul
  echo ""
  echo "${GREEN}Cleaning process done.${DEFAULT}"
  exit 1
}

run_norminette() {
  if command -v norminette &> /dev/null; then
    echo "Running norminette on user files:"
    for file in *.c *.h; do
      if [ -f "$file" ]; then
        norminette "$file"
      fi
    done
  else
    echo "norminette not found, skipping norminette checks"
  fi
}

# Prompt user for assignment input
read -p "Enter the assignment number (00-13): " assignment_number

# Validate input
if [[ ! $assignment_number =~ ^(0[0-9]|1[0-3])$ ]]; then
  printf "${RED}Invalid input. Please enter a number between 00 and 13.${DEFAULT}\n"
  exit 1
fi

assignment="C${assignment_number}"

run_norminette

cp -R ~/mini-moulinette/mini-moul mini-moul
trap handle_sigint SIGINT
cd mini-moul
./test.sh "$assignment"
cd ..
rm -R mini-moul

exit 0
