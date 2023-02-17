source nm/config.sh

cd nm

if [[ "$#" -eq 1 ]]; then
  ./test.sh "$1"
else
  printf "${RED}You need to choose an assignment\n${DEFAULT}"
fi
