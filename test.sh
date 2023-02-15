echo "name: $1"
echo "age: $2"

if [ -f "ex00/ft_putstr.c" ]; then
    echo "ft_putstr.c exists."
else
    echo "ft_putstr.c does not exist."
    cc hello.c
    ./a.out
    rm a.out
    exit 1
fi

if gcc -Wall -Werror -Wextra -pedantic -c myfunc.c; then
    echo "File myfunc.c can be compiled."
else
    echo "File myfunc.c cannot be compiled."
    exit 1
fi

echo "Functions used in myfunc.c:"
grep -o -E '([a-zA-Z_][a-zA-Z_0-9]*)\(' myfunc.c | sed 's/(/\n/g' | sed 's/.* //g' | sed '/^$/d' | sort -u
