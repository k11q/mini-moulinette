#constants
GREEN='\033[38;5;84m'
RED='\033[31m'
BLUE='\033[38;5;45m'
PURPLE='\033[38;5;63m'
PINK='\033[38;5;207m'
BLACK='\033[38;5;0m'
BG_GREEN='\033[48;5;84m'
BG_RED='\033[48;5;197m'
GREY='\033[38;5;8m'
BOLD='\033[1m'
DEFAULT='\033[0m'
CHECKMARK='\xE2\x9C\x93'
DATA=$(cat data.json)

#utils
index=0
index2=0
assignment_data=NULL
test_data=NULL
test_error=NULL
test_name=NULL

#variables
checks=0
passed=0
marks=0
questions=0
break_score=0
score_false=0
result=""
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
dirname_found=0

main()
{
    #print_collected_files
    for dir in ./tests/* ; do
        dirname="$(basename "$dir")"
        if [ -d "$dir" ] && [ "$dirname" == "$1" ]; then
            print_header
            echo "Generating test for ${1}..."
            space
            dirname_found=1
            index=0
            for assignment in $dir/*; do
                questions=$((questions+1))
                score_false=0
                assignmentname="$(basename "$assignment")"
                file_name=$(echo "$DATA" | jq -r ".C02[] | select(.exercise == \"$assignmentname\").file")
                assignment_data=$(echo "$DATA" | jq -r ".C02[] | select(.exercise == \"$assignmentname\")")
                if cc -o test1 $assignment/test1.c 2> /dev/null; then
                    rm test1
                    checks=$((checks+1))
                    passed=$((passed+1))
                    if [ -d "$assignment" ]; then
                        index2=0
                        for test in $assignment/*.c; do
                            ((index2++))
                            checks=$((checks+1))
                            test_name=${test##*/}
                            test_name=${test_name%.c}
                            test_data=$(echo "$assignment_data" | jq '.tests[] | select(.name == "'"$test_name"'")')
                            test_error=$(echo "$test_data" | jq -r '.error')
                            if cc -o ${test%.c} $test 2> /dev/null; then
                                if ./${test%.c} = 0; then
                                    echo -e "${GREEN}  ${CHECKMARK}${DEFAULT}""${GREY} [$(($index2))] $test_error${DEFAULT}"
                                    passed=$((passed+1))
                                else
                                    break_score=1
                                    score_false=1
                                    echo "failed"
                                fi
                                rm ${test%.c}
                            else
                                echo -e "    ""${GREY}[$(($index2+1))] $test_error ${RED}FAILED${DEFAULT}"
                            fi
                        done
                        if [ $index -gt 0 ]; then
                            result+=", "
                        fi
                        if [ $score_false = 0 ]; then
                            result+="${GREEN}$assignmentname: OK${DEFAULT}"
                            echo -e "${BG_GREEN}${BLACK}${BOLD} PASS ${DEFAULT}${GREY} $assignmentname/${DEFAULT}$file_name"
                        else
                            result+="${RED}$assignmentname: KO${DEFAULT}"
                            echo -e "${BG_RED}${BOLD} FAIL ${DEFAULT}${GREY} $assignmentname/${DEFAULT}$file_name"
                        fi
                        if [ $break_score = 0 ]; then
                            marks=$((marks+1))
                        fi
                        ((index++))
                        space
                    else
                        echo -e "${RED}    $assignmentname does not exist.${DEFAULT}"
                    fi
                else
                    break_score=1
                    checks=$((checks+1))
                    echo -e "${RED}    $file_name cannot compile.${DEFAULT}"
                    echo -e "${BG_RED}${BOLD} FAIL ${DEFAULT}${GREY} $assignmentname/${DEFAULT}$file_name"
                    space
                    if [ $index -gt 0 ]; then
                            result+=", "
                        fi
                    result+="${RED}$assignmentname: KO${DEFAULT}"
                fi
            done
            break
        else
            echo -e "${RED}Sorry. Tests for $1 isn't available yet. Consider contributing at Github.${DEFAULT}"
            exit 1
        fi
    done
    echo -e "${PURPLE}-----------------------------------${DEFAULT}"
    space
    PERCENT=$((100 * marks / questions))
    #echo -e "Total checks:  ""${GREEN}${passed} passed  ${DEFAULT} ""${checks} total"
    echo -e "Result:        ${result}"
    if [ $PERCENT -ge 50 ]; then
        echo -e "Final score:   ""${GREEN}$(echo $PERCENT | bc)/100${DEFAULT}"
        echo -e "Status:        ""${GREEN}passed${DEFAULT}"
    else
        echo -e "Final score:   ""${RED}$(echo $PERCENT | bc)/100${DEFAULT}"
        echo -e "Status:        ""${RED}FAILED${DEFAULT}"
    fi
    echo -e "${GREY}Test completed."
    space
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

check_dependency()
{
    if ! command -v jq &> /dev/null; then
        echo "jq is not installed. To install:"
        echo "  Ubuntu/Debian:"
        echo "    sudo apt-get update"
        echo "    sudo apt-get install jq"
        echo "  macOS/Homebrew:"
        echo "    brew install jq"
    fi
}

check_dependency
if [ "${1}" = "" ]; then
    echo "Please select an assignment. e.g. './test.sh C01'"
    exit 1
fi
if [ "${1}" = "C00" -o "${1}" = "C01" -o "${1}" = "C02" -o "${1}" = "C03" -o "${1}" = "C04" -o "${1}" = "C05" -o "${1}" = "C06" -o "${1}" = "C07" -o "${1}" = "C08" -o "${1}" = "C09" -o "${1}" = "C10" -o "${1}" = "C11" -o "${1}" = "C12" -o "${1}" = "C13" ]; then
    main "$@"; exit
else
    echo -e "${RED}Invalid argument. Please select between C00 to C13${DEFAULT}"
fi
