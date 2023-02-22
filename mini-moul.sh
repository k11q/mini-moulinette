source ~/mini-moulinette/mini-moul/config.sh

function handle_sigint {
  echo "${RED}Script aborted by user. Cleaning up..."
  rm -R ../mini-moul
  echo ""
  echo "${GREEN}Cleaning process done.${DEFAULT}"
  exit 1
}

if [[ "$#" -eq 1 ]]; then
	cp -R ~/mini-moulinette/mini-moul mini-moul
  run_norminette
  trap handle_sigint SIGINT
	cd mini-moul
  ./test.sh "$1"
  rm -R ../mini-moul
else
  printf "${RED}You need to choose an assignment. e.g: mini C02\n${DEFAULT}"

fi

exit 1

run_norminette()
{
    if command -v norminette &> /dev/null; then
        norminette
    else
        echo "norminette not found, skipping norminette checks"
    fi
}
