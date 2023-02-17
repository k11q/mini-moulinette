source simula/config.sh

echo "alias simula1='./simula.sh'" >> ~/.bash_profile

cd simula

if [[ "$#" -eq 1 ]]; then
  ./test.sh "$1"
else
  printf "${RED}You need to choose an assignment. e.g: ./simula.sh C02\n${DEFAULT}"
fi
