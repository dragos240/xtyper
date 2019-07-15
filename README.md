# xtyper - a simple, low dependency auto-typer for use in scripts

## Dependencies

You will need XTest for this to work. Fortunately it's easy to get and may even be
already installed on your system. Search your software repository for "xtst". You may
find it under libxtst or similar.

## Compiling

To compile this progoram, you will want to install pkg-config to find the linker
flags. If you plan to bundle xtyper with a script, you will not need pkg-config since
it will already be compiled. Once you install this, the only thing to do is to build
it with `make`.

## Usage

The syntax of xtyper is very simple. There is one argument, which is what you want it
to type. Note that you can type multiple words by surrounding your input text in
quotes. Below are some examples.

```
$ ./xtyper Test
$ ./xtyper "A few words"
```
