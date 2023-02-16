echo -e "\033[0;36m"
echo "+================================+"
echo "|   __ __ ___   __            __ |" 
echo "|  / // /<  /  / /____  _____/ /_|"
echo "| / // /_/ /  / __/ _ \/ ___/ __/|"
echo "|/__  __/ /  / /_/  __(__  ) /_  |"
echo "|  /_/ /_/   \__/\___/____/\__/  |"
echo "|                        41 TESTS|"
echo "+================================+"
echo -e "\033[0m"

GREEN='\033[32m'
RED='\033[31m'
DEFAULT='\033[0m'
CHECKS=0
PASSED=0
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

if [ "${1}" = "" ]; then
  echo "Please select an assignment. e.g. './test.sh C01'"
  exit 1
else
  echo "Generating test for ${1}..."
fi
echo "Collected files:"
ls ../* | grep -v "../41test:*" | grep -v "../41test" | column
#find .. -not -path "../41test/*" -not -path "../.*" -type f | sed 's/^..\///' | column | sort -t'/' -k1,1 -k2,2
echo -e ""
if [ "${1}" = "C02" ]; then
CHECKS=$((CHECKS+1))
if [ -f "${SCRIPT_DIR}/../ex00/ft_strcpy.c" ]; then
    echo -e "${GREEN}ft_strcpy.c exists.${DEFAULT}"
    if cc ${SCRIPT_DIR}/C02/ex00.c 2> /dev/null; then
    if ./a.out = 0; then
    	echo -e "\033[42m PASSED \033[0m""\033[38;5;8m ex00/\033[0mft_strcpy.c"
      echo -e "${GREEN}  \xE2\x9C\x93 \033[38;5;8m[1] ./ft_strcpy can be compiled. ${DEFAULT}"
	    echo -e "${GREEN}  \xE2\x9C\x93 \033[38;5;8m[2] Output should be squariyoh ${DEFAULT}"
    else
        echo "failed"
    fi
    rm a.out
    else
    	echo "cannot compile"
    fi
else
    echo -e "${RED}ft_strcpy.c does not exist.${DEFAULT}"
fi
echo -e ""
CHECKS=$((CHECKS+1))
if [ -f "${SCRIPT_DIR}/../ex01/ft_strncpy.c" ]; then
    echo -e "${GREEN}ft_strncpy.c exists.${DEFAULT}"
    if cc ${SCRIPT_DIR}/C02/ex01.c 2> /dev/null; then
    if ./a.out = 0; then
    	echo -e "\033[42m PASSED \033[0m""\033[38;5;8m ex00/\033[0mft_strncpy.c"
      echo -e "${GREEN}  \xE2\x9C\x93 \033[38;5;8m[1] ./ft_strncpy can be compiled. ${DEFAULT}"
	    echo -e "${GREEN}  \xE2\x9C\x93 \033[38;5;8m[2] Output should be squariyoh ${DEFAULT}"
    else
        echo "failed"
    fi
    rm a.out
    else
    	echo "cannot compile"
    fi
else
    echo -e "${RED}ft_strncpy.c does not exist.${DEFAULT}"
fi
echo -e ""
CHECKS=$((CHECKS+1))
if [ -f "${SCRIPT_DIR}/../ex02/ft_str_is_alpha.c" ]; then
    echo -e "${GREEN}ft_str_is_alpha.c exists.${DEFAULT}"
    if cc ${SCRIPT_DIR}/C02/ex02.c 2> /dev/null; then
    if ./a.out = 0; then
    	echo -e "\033[42m PASSED \033[0m""\033[38;5;8m ex00/\033[0mft_str_is_alpha.c"
	echo -e "${GREEN}  \xE2\x9C\x93 \033[38;5;8m[1] Output should be squariyoh ${DEFAULT}"
    else
        echo "failed"
    fi
    rm a.out
    else
    	echo "cannot compile"
    fi
else
    echo -e "${RED}ft_str_is_alpha.c does not exist.${DEFAULT}"
fi
echo -e ""
PASSED=$((PASSED+1))
PERCENT=$((100 * PASSED / CHECKS))

echo -e "\033[38;5;8mTotal checks:  ${DEFAULT}""${GREEN}${PASSED} passed  ${DEFAULT} ""${CHECKS} total"
if [ $PERCENT -ge 50 ]; then
echo -e "\033[38;5;8mFinal score:   ${DEFAULT}""${GREEN}$(echo $PERCENT | bc)/100${DEFAULT}"
echo -e "\033[38;5;8mStatus:        ${DEFAULT}""${GREEN}PASSED${DEFAULT}"
else
echo -e "\033[38;5;8mFinal score:   ${DEFAULT}""${RED}$(echo $PERCENT | bc)/100${DEFAULT}"
echo -e "\033[38;5;8mStatus:        ${DEFAULT}""${RED}FAILED${DEFAULT}"
fi
#echo "Functions used in ft_strcpy.c:"
#grep -o -E '([a-zA-Z_][a-zA-Z_0-9]*)\(' ../ex00/ft_strcpy.c | sed 's/(/\n/g' | sed 's/.* //g' | sed '/^$/d' | sort -u | tr '\n' ', ' | sed 's/,/, /' | sed 's/, $/\n/'
fi
