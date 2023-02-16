# Adversary

Lightweight self-learning rock-paper-scissors engine in C++ that is designed to learn the
moves of it's adversary over time with a simple self-made AI. Development of this project
is on _Linux_, so it should work on just about any _Unix_ machine, but it won't work for
you _Windows_ people.

## Setup

For compilation, I developed this with _GCC_, but I assume that _Clang_ will work as
well. Additionally, in the `test` directory, there is a _Python_ script that runs a
simple (yet hideous) GUI. To run it, paste the following code in the `test` directory:

```bash
source compile_dll
# "adversary.so" now in the directory
./window.py &
```
