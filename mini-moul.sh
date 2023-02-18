source ~/mini-moulinette/mini-moul/config.sh

if [[ "$#" -eq 1 ]]; then
	cp -R ~/mini-moulinette/mini-moul mini-moul
	cd mini-moul
  ./test.sh "$1"
  rm -R ../mini-moul
else
  printf "${RED}You need to choose an assignment. e.g: ./mini-moul.sh C02\n${DEFAULT}"

fi

exit 1
