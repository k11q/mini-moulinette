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

#utils
index=0
index2=0

#variables
CHECKS=0
PASSED=0
RESULT=""
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
dirname_found=0

main()
{
    print_header
    echo "Generating test for ${1}..."
    space
    #print_collected_files
    for dir in ./tests/* ; do
        dirname="$(basename "$dir")"
        if [ -d "$dir" ] && [ "$dirname" == "$1" ]; then
            dirname_found=1
            index=0
            for assignment in $dir/*; do
                assignmentname="$(basename "$assignment")"
                if [ -d "$assignment" ]; then
                    echo -e "${GREEN}  ${CHECKMARK}${DEFAULT}""${GREY} [1] ./$assignment exists.${DEFAULT}"
                    index2=0
                    for test in $assignment/*.c; do
                        ((index2++))
                        CHECKS=$((CHECKS+1))
                        if cc -o ${test%.c} $test 2> /dev/null; then
                            if ./${test%.c} = 0; then
                                echo -e "${GREEN}  ${CHECKMARK}${DEFAULT}""${GREY} [$(($index2+1))] ./ft_strcpy can be compiled.${DEFAULT}"
                                PASSED=$((PASSED+1))
                            else
                                echo "failed"
                            fi
                            rm ${test%.c}
                        else
                            echo -e "   ""${GREY} [$(($index2+1))] ./ft_strcpy does not compile. ${RED}FAILED${DEFAULT}"
                        fi
                    done
                    if [ $index -gt 0 ]; then
                        RESULT+=", "
                    fi
                    ((index++))
                    RESULT+="$assignmentname: OK"
                    echo -e "${BG_GREEN}${BLACK}${BOLD} PASS ${DEFAULT}${GREY} ex00/${DEFAULT}ft_strcpy.c"
                    space
                fi
            done
        fi
    done
    echo -e "${PURPLE}-----------------------------------${DEFAULT}"
    space
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

space()
{
    echo -e ""
}

if [ "${1}" = "" ]; then
    echo "Please select an assignment. e.g. './test.sh C01'"
    exit 1
fi
if [ "${1}" = "C00" -o "${1}" = "C01" -o "${1}" = "C02" -o "${1}" = "C03" -o "${1}" = "C04" -o "${1}" = "C05" -o "${1}" = "C06" -o "${1}" = "C07" -o "${1}" = "C08" -o "${1}" = "C09" -o "${1}" = "C10" -o "${1}" = "C11" -o "${1}" = "C12" -o "${1}" = "C13" ]; then
    main "$@"; exit
else
    echo -e "${RED}Invalid argument. Please select between C00 to C13${DEFAULT}"
fi
