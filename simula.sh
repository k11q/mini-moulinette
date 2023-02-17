source simula/config.sh

cd simula

if [[ "$#" -eq 1 ]]; then
  ./test.sh "$1"
else
  printf "${RED}You need to choose an assignment. e.g: ./simula.sh C02\n${DEFAULT}"
fi
