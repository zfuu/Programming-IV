# s202018021_05-07-04-ex3
Fu, Ziyu

## 1. Instruction to compile the code

After using the `cd` (change directory) command to navigate to the correct working directory, use these following commands to compile the code:

```bash
% gcc s202018021_05-07-04-ex3.c
% ./a.out 
```

## 2. Brief review of the code

In this program, I created custom `print` functions that automatically runs `fflush` after `printf`. Because the original program is using formatted strings (integer and string), I had to make separate functions for each kind of string formatting. 

To print a simple string, `print_with_flush(char p[])` is used. The string to print is passed directly to the `printf` function inside. 

To print a string with an `%d` (integer) format specifier, `print_with_flush_int(char p[], int num)` is used, and to print a string with a `%s` (string) format specifier, `print_with_flush_string(char p[], char s[])` is used. 

## 3. Result of execution 
```
% gcc s202018021_05-07-04-ex3.c

% ./a.out hello.txt
Number of Options : 2
Let's open "hello.txt"! 
Ready to read "hello.txt"
File hello.txt is now closed.
All set. Bye!
```

## 4. Explanation for extra files
N/A