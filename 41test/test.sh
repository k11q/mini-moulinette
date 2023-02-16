#constants
GREEN='\033[38;5;84m'
RED='\033[31m'
BLUE='\033[38;5;45m'
PURPLE='\033[38;5;63m'
PINK='\033[38;5;207m'
BLACK='\033[38;5;0m'
BG_GREEN='\033[48;5;84m'
BG_RED='\033[38;5;8m[1]'
GREY='\033[38;5;8m'
BOLD='\033[1m'
DEFAULT='\033[0m'
CHECKMARK='\xE2\x9C\x93'

#variables
CHECKS=0
PASSED=0
RESULT=""
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

main()
{
    #check if arg exist
    if [ "${1}" = "" ]; then
        echo "Please select an assignment. e.g. './test.sh C01'"
        exit 1
        elif [ "${1}" = "C00" -o "${1}" = "C01" -o "${1}" = "C02" -o "${1}" = "C03" -o "${1}" = "C04" -o "${1}" = "C05" -o "${1}" = "C06" -o "${1}" = "C07" -o "${1}" = "C08" -o "${1}" = "C09" -o "${1}" = "C10" -o "${1}" = "C11" -o "${1}" = "C12" -o "${1}" = "C13" ]; then
        
        #assignment C01
        if [ "${1}" != "C02" ]; then
            echo -e "${RED}Tests for ${1} not yet implemented.${DEFAULT}"
            exit 1
        fi
        
        print_header
        echo "Generating test for ${1}..."
        #print all collected files
        print_collected_files
        
        #assignment C02
        if [ "${1}" = "C02" ]; then
            CHECKS=$((CHECKS+1))
            echo -e ""
            echo -e "${PINK}ex00/ft_strcpy.c ${PURPLE}------------------${DEFAULT}"
            echo -e ""
            if [ -f "${SCRIPT_DIR}/../ex00/ft_strcpy.c" ]; then
                echo -e "${GREEN}  ${CHECKMARK}${DEFAULT}""${GREY} [1] ./ft_strcpy.c exists.${DEFAULT}"
                if cc ${SCRIPT_DIR}/C02/ex00.c 2> /dev/null; then
                    if ./a.out = 0; then
                        echo -e "${GREEN}  ${CHECKMARK}${DEFAULT}""${GREY} [2] ./ft_strcpy can be compiled.${DEFAULT}"
                        echo -e "${GREEN}  ${CHECKMARK}${DEFAULT}""${GREY} [3] Output should be squariyoh.${DEFAULT}"
                        PASSED=$((PASSED+1))
                    else
                        echo "failed"
                    fi
                    rm a.out
                else
                    echo -e " ${GREY} ./ft_strcpy.c does not compile.  ${RED}FAILED${DEFAULT}"
                fi
            else
                echo -e " ${GREY} ./ft_strcpy.c does not exists.  ${RED}FAILED${DEFAULT}"
            fi
            echo -e ""
            RESULT+="ex00: OK"
            echo -e "${BG_GREEN}${BLACK}${BOLD} PASS ${DEFAULT}${GREY} ex00/${DEFAULT}ft_strcpy.c"
            echo -e ""
            echo -e "${PURPLE}-----------------------------------${DEFAULT}"
            echo -e ""
            PERCENT=$((100 * PASSED / CHECKS))
            echo -e "${GREY}Total checks:  ${DEFAULT}""${GREEN}${PASSED} passed  ${DEFAULT} ""${CHECKS} total"
            echo -e "${GREY}Result:        ${DEFAULT}${RESULT}"
            if [ $PERCENT -ge 50 ]; then
                echo -e "${GREY}Final score:   ${DEFAULT}""${GREEN}$(echo $PERCENT | bc)/100${DEFAULT}"
                echo -e "${GREY}Status:        ${DEFAULT}""${GREEN}PASSED${DEFAULT}"
            else
                echo -e "${GREY}Final score:   ${DEFAULT}""${RED}$(echo $PERCENT | bc)/100${DEFAULT}"
                echo -e "${GREY}Status:        ${DEFAULT}""${RED}FAILED${DEFAULT}"
            fi
            #echo "Functions used in ft_strcpy.c:"
            #grep -o -E '([a-zA-Z_][a-zA-Z_0-9]*)\(' ../ex00/ft_strcpy.c | sed 's/(/\n/g' | sed 's/.* //g' | sed '/^$/d' | sort -u | tr '\n' ', ' | sed 's/,/, /' | sed 's/, $/\n/'
        fi
    else
        echo -e "${RED}Invalid argument. Please select between C00 to C13${DEFAULT}"
    fi
}

print_header()
{
    echo -e "${BLUE}"
    echo "+================================+"
    echo "|   __ __ ___   __            __ |"
    echo "|  / // //  / _/ /____  _____/ /_|"
    echo "| / // /_/ //_  __/ _ \/ ___/ __/|"
    echo "|/__  __/ /  / /_/  __(__  ) /_  |"
    echo "|  /_/ /_/   \__/\___/____/\__/  |"
    echo "|                        41 TESTS|"
    echo "+================================+"
    echo -e "${DEFAULT}"
}

print_collected_files()
{
    echo "Collected files:"
    ls ../* | grep -v "../41test:*" | grep -v "../41test" | column
}

main "$@"; exit
