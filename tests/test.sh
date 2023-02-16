echo -e "\033[0;36m"
echo "+================================+"
echo "|   __ __ ___   __            __ |" 
echo "|  / // /<  /  / /____  _____/ /_|"
echo "| / // /_/ /  / __/ _ \/ ___/ __/|"
echo "|/__  __/ /  / /_/  __(__  ) /_  |"
echo "|  /_/ /_/   \__/\___/____/\__/  |"
echo "|                                |"
echo "|                        41 TESTS|"
echo "+================================+"
echo -e "\033[0m"

GREEN='\033[32m'
RED='\033[31m'
DEFAULT='\033[0m'
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

if [ "${1}" = "" ]; then
  echo "Please select an assignment. e.g. './test.sh C01'"
  exit 1
else
  echo "Generating test for ${1}..."
fi

if [ -f "${SCRIPT_DIR}/../ex00/ft_strcpy.c" ]; then
    echo -e "${GREEN}ft_strcpy.c exists.${DEFAULT}"
    cc ${SCRIPT_DIR}/C02/ex00-test.c
    if ./a.out = 0; then
    	echo -e "\033[42m OK :D  \033[0m" "\033[38;5;8m C02/ex00/ft_strcpy.c \033[0m"
    else
        echo "failed"
    fi
    rm a.out
else
    echo -e "${RED}ft_strcpy.c does not exist.${DEFAULT}"
fi

#if gcc -Wall -Werror -Wextra -pedantic -c hello.c; then
#   echo "File myfunc.c can be compiled."
#else
#    echo "File myfunc.c cannot be compiled."
#    exit 1
#fi

echo "Functions used in ft_strcpy.c:"
grep -o -E '([a-zA-Z_][a-zA-Z_0-9]*)\(' ../ex00/ft_strcpy.c | sed 's/(/\n/g' | sed 's/.* //g' | sed '/^$/d' | sort -u | tr '\n' ', ' | sed 's/,/, /' | sed 's/, $/\n/'
