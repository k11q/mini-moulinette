source mini-moul/config.sh

cd mini-moul

if [[ "$#" -eq 1 ]]; then
  ./test.sh "$1"
else
  printf "${RED}You need to choose an assignment. e.g: ./mini-moul.sh C02\n${DEFAULT}"
fi
