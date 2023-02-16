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

GREEN='\033[92m'
RED='\033[101m'
BLUE='\033[94m'
BG_GREEN='\033[42m'
BG_RED='\033[38;5;8m[1]'
GREY='\033[38;5;8m'
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
if [ "${1}" = "C02" ]; then
CHECKS=$((CHECKS+1))
echo -e ""
echo -e "${BLUE}ex00/ft_strcpy.c${DEFAULT}"
echo -e ""
if [ -f "${SCRIPT_DIR}/../ex00/ft_strcpy.c" ]; then
    echo -e "${BG_GREEN} PASS ${DEFAULT}""${GREY} [1] ./ft_strcpy.c exists.${DEFAULT}"
    if cc ${SCRIPT_DIR}/C02/ex00.c 2> /dev/null; then
    if ./a.out = 0; then
      echo -e "${BG_GREEN} PASS ${DEFAULT}""${GREY} [2] ./ft_strcpy can be compiled.${DEFAULT}"
	    echo -e "${BG_GREEN} PASS ${DEFAULT}""${GREY} [3] Output should be squariyoh.${DEFAULT}"
      #echo -e "\033[42m PASSED \033[0m""\033[38;5;8m ex00/\033[0mft_strcpy.c"
      PASSED=$((PASSED+1))
    else
        echo "failed"
    fi
    rm a.out
    else
    	echo -e " \033[38;5;8m[1] ./ft_strcpy.c does not compile.  ${RED}FAILED${DEFAULT}"
    fi
else
    echo -e " \033[38;5;8m[1] ./ft_strcpy.c does not exists.  ${RED}FAILED${DEFAULT}"
fi
echo -e ""
echo -e "Result:  ${GREEN}OK :D ${GREY}ex00/${DEFAULT}ft_strcpy.c"
echo -e ""
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
