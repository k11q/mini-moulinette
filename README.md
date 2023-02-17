# Simula

Simula is a test suite for 42 assignments, providing automated tests for checking before submitting your assignments, simulating moulinette.

## Introduction

This is now day 11 of piscine. I have wasted so many hours getting evaluated, doing evaluation, waiting for evaluation, only to come back redoing it again because I kept making silly mistakes. I wish I can check my code thoroughly before submitting, but that too, will take a lot of my time. This is why I build this so I can stop wasting my time and many others, and shut moulinette up with just a single submission.

## Disclaimer

Simula doesn't check if there's extra files or norm, you need to do it manually. Pair it with `norminette` and `ls */*` , you are good to go!

## Get Started

1. Clone the repo
2. Put the `simula` directory `simula.sh` in your assignment directory, where you store your ex00, ex01... directories.
3. Run `./simula.sh` with assignment number as argument. e.g: C02.

```bash
./simula.sh {assignment number}
```

E.g.:

```bash
./simula.sh C02
```

## Alias

To enhance your experience, create an alias:

```bash
alias simula='./simula.sh'
```

Now you can run with just:

```bash
simula {assignment number}
```

## Contributing

1. Write an issue on why and what.
2. When approved, you can create a pull request.
3. If all checks are passed we'll merge.

## Authors

[Khairul Haaziq](@khairulhaaziq)
