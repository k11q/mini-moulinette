GREEN='\033[32m'
RED='\033[31m'
DEFAULT='\033[0m'

echo "name: $1"
echo "age: $2"

if [ -f "../ex00/ft_strcpy.c" ]; then
    echo -e "${GREEN}ft_strcpy.c exists.${DEFAULT}"
    cc C02/ex00-test.c
    ./a.out
    rm a.out
else
    echo -e "${RED}ft_strcpy.c does not exist.${DEFAULT}"
fi

if gcc -Wall -Werror -Wextra -pedantic -c hello.c; then
    echo "File myfunc.c can be compiled."
else
    echo "File myfunc.c cannot be compiled."
    exit 1
fi

echo "Functions used in ft_strcpy.c:"
grep -o -E '([a-zA-Z_][a-zA-Z_0-9]*)\(' ../ex00/ft_strcpy.c | sed 's/(/\n/g' | sed 's/.* //g' | sed '/^$/d' | sort -u | tr '\n' ', ' | sed 's/,/, /' | sed 's/, $/\n/'
