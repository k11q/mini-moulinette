# Not Moulinette

Not Moulinette is a test suite for 42 assignments, providing automated tests for checking before submitting your assignments.

## Introduction

This is now day 11 of piscine. I have wasted so many hours getting evaluated, doing evaluation, waiting for evaluation, only to come back redoing it again because I kept making silly mistakes. I wish I can check my code thoroughly before submitting, but that too, will take a lot of my time. This is why I build this so I can stop wasting my time and many others, and shut moulinette up with just a single submission.

## Disclaimer

Not Moulinette doesn't check if there's extra files or norm, you need to do it manually. Pair it with `norminette` and `ls */*` , you are good to go!

## Get Started

### Dependencies

To run, you are required to install these jq:

#### macOS/Homebrew:

```bash
brew install jq
```

#### 42 School VM:

1. Download the jq-osx-amd64 binary: https://github.com/stedolan/jq/releases.
2. Move the jq binary to a directory in your $PATH, such as $HOME/bin:

```bash
mkdir -p $HOME/bin
mv jq-osx-amd64/jq $HOME/bin/jq
```

3. Make the jq binary executable:

```bash
chmod +x $HOME/bin/jq
```
4. Add $HOME/bin to your $PATH:

```bash
export PATH=$HOME/bin:$PATH
```

5. Done! You can check the jq version by running:

```bash
jq --version
```

### Get Started

1. Clone the repo
2. Put the `nm` directory in your assignment directory, where you store your ex00, ex01... directories.
3. Change directory to inside the `nm` directory.

```bash
cd nm
```

3. Run the `test.sh` from inside.

```bash
./test.sh {Assignment number}
```

E.g.:

```bash
./test.sh C02
```

## Contributing

1. Write an issue on why and what.
2. When approved, you can create a pull request.
3. If all checks are passed we'll merge.

## Authors

[Khairul Haaziq](@khairulhaaziq)
