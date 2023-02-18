# Mini-moulinette

Mini-moulinette is a test runner for 42 assignments, providing automated tests for whole assignment with one command. The goal is to make thorough checking before submitting the assignments, with ease.


## Introduction

This is now day 11 of piscine. I have wasted so many hours getting evaluated, doing evaluation, waiting for evaluation, only to come back redoing it again because I kept making silly mistakes. I wish I can check my code thoroughly before submitting, but that too, will take a lot of my time. This is why I build this so I can stop wasting my time and many others, and shut moulinette up with just a single submission.


## Disclaimer

Mini-moulinette doesn't check if there's extra files or norm, you need to do it manually. Pair it with `norminette` and `ls */*` , you are good to go!


## Get Started

1. Go to your root `~` directory.

```bash
cd ~
```


2. Clone the git there.

```bash
git clone https://github.com/khairulhaaziq/mini-moulinette.git
```


3. Now create an alias for it.

```bash
alias moul='~/mini-moulinette/mini-moul.sh'
```

> **Note**
> For now, the alias only works on the current terminal session, I'm figuring out how to make it permanent. Since then you need to add the alias for every terminal/session.


3. Run `./mini-moul.sh` with assignment number as argument. e.g: C02.

```bash
moul C02
```

e.g.: C03

```bash
moul C03
```


## Status

| Assignment            | Coverage                   | Accuracy         |
| :-------------------- | :------------------------: | :--------------: |
| C00                   | 9/9                        | Not yet rated    |
| C01                   | 9/9                        | 99%              |
| C02                   | 12/13                      | 99%              |
| C03                   | 6/6                        | 99%              |
| C04                   | 6/6                        | 99%              |
| C05                   | 8/9                        | 99%              |
| C06                   | 0/4                        | Not yet rated    |
| C07                   | 0/6                        | Not yet rated    |
| C08                   | 0/6                        | Not yet rated    |
| C09                   | 0/3                        | Not yet rated    |
| C10                   | 0/4                        | Not yet rated    |
| C11                   | 0/8                        | Not yet rated    |
| C12                   | 0/18                       | Not yet rated    |
| C13                   | 0/8                        | Not yet rated    |


## Contributing

1. Write an issue on why and what.
2. When approved, you can create a pull request.
3. If all checks are passed we'll merge.


## Authors

[Khairul Haaziq](@khairulhaaziq)
[chatgpt](ai.com)


## License

MIT. Copyright Khairul Haaziq 2023.
