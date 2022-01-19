# s202018021_04-02-ex3
Fu, Ziyu

## 1. Instruction to compile the code

After using the `cd` (change directory) command to navigate to the correct working directory, use these following commands to compile the code:

```bash
% gcc -Wall -c 04-02-SC-BasicFunctions.c
% gcc -Wall -c 04-02-SC-ExtraFunctions.c
% gcc -Wall -c 04-02-SC-Main.c
% gcc -Wall -o 04-02-SC-Go 04-02-SC-Main.o 04-02-SC-BasicFunctions.o 04-02-SC-ExtraFunctions.o
% ./04-02-SC-Go
```

## 2. Brief review of the code
In order to extend the functionality of our simple calculator, we can add the logorithm and exponentiation logic to `04-02-SC-ExtraFunctions.c`, and link the corresponding functions to `04-02-SC-Main.c` through the header file `04-02-SC.h`.

## 3. Result of execution 
```
% gcc -Wall -c 04-02-SC-BasicFunctions.c
% gcc -Wall -c 04-02-SC-ExtraFunctions.c
% gcc -Wall -c 04-02-SC-Main.c
% gcc -Wall -o 04-02-SC-Go 04-02-SC-Main.o 04-02-SC-BasicFunctions.o 04-02-SC-ExtraFunctions.o

% ./04-02-SC-Go  
1 + 5
1 + 5 = 6
2 * 1.5
2 * 1.5 = 3
9 log 3
9 log 3 = 0.5
1 log 0
Invalid input! Logarithm result undefined.
1 log 0 = 0
2 exp 3
2 exp 3 = 8
2 exp 2.5
2 exp 2.5 = 5.65685
```

## 4. Explanation for extra files
N/A