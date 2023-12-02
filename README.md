# compilers
Made by: Raphael Damasceno Rocha de moraes
## 1. Introduction

This is a compiler for a simple programming language called "C Minus" (C-). The compiler is written in C. The compiler is built using a handmade lexical analyzer, table oriented and the Bison parser generator. The compiler is built in 3 phases: Lexical Analysis, Syntax Analysis, and Semantic Analysis. The compiler is able to detect and report lexical, syntax, and semantic errors.

## 2. How to run
    make

#### running the compiler in the bin directory

    ./gcm <filename> <-l or -p or -s>
#### running at project directory
    bin/gcm <filename> <-l or -p or -s>

#### -l: lexical analysis
#### -p: syntax analysis
#### -s: semantic analysis

### 2.1. Requirements

- C compiler (gcc)
- Make

