# Mini-moulinette

Mini-moulinette is a test runner for 42 assignments, providing automated tests for whole assignment with one command. The goal is to make thorough checking before submitting the assignments, with ease.

## Introduction

This is now day 11 of piscine. I have wasted so many hours getting evaluated, doing evaluation, waiting for evaluation, only to come back redoing it again because I kept making silly mistakes. I wish I can check my code thoroughly before submitting, but that too, will take a lot of my time. This is why I build this so I can stop wasting my time and many others, and shut moulinette up with just a single submission.

## Disclaimer

Mini-moulinette doesn't check if there's extra files or norm, you need to do it manually. Pair it with `norminette` and `ls */*` , you are good to go!

## Get Started

1. Clone the repo
2. Put the `mini-moul` directory and `mini-moul.sh` in your assignment directory, where you store your ex00, ex01... directories.
3. Run `./mini-moul.sh` with assignment number as argument. e.g: C02.

```bash
./mini-moul.sh {assignment number}
```

E.g.:

```bash
./mini-moul.sh C02
```

## Status

| Assignment            | Coverage                   | Accuracy         |
| :-------------------- | :------------------------: | :--------------: |
| C00                   | 100%                       | 99%              |
| C01                   | 100%                       | 99%              |
| C02                   | 90%                        | 99%              |
| C03                   | 90%                        | 99%              |
| C04                   | 60%                        | 99%              |
| C05                   | 0%                         | Not yet rated    |
| C06                   | 0%                         | Not yet rated    |
| C07                   | 0%                         | Not yet rated    |
| C08                   | 0%                         | Not yet rated    |
| C09                   | 0%                         | Not yet rated    |
| C10                   | 0%                         | Not yet rated    |
| C11                   | 0%                         | Not yet rated    |
| C12                   | 0%                         | Not yet rated    |
| C13                   | 0%                         | Not yet rated    |

## Alias

To enhance your experience, create an alias:

```bash
alias moul='./mini-moul.sh'
```

Now you can run with just:

```bash
moul {assignment number}
```

For example:

```bash
moul C02
```

## Contributing

1. Write an issue on why and what.
2. When approved, you can create a pull request.
3. If all checks are passed we'll merge.

## Authors

[Khairul Haaziq](@khairulhaaziq)

## License

MIT. Copyright Khairul Haaziq 2023.
