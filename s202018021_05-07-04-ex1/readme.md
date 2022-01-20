# s202018021_05-07-04-ex1
Fu, Ziyu

## 1. Instruction to compile the code

After using the `cd` (change directory) command to navigate to the correct working directory, use these following commands to compile the code:

```bash
% gcc s202018021_05-07-04-ex1.c
% ./a.out 
```

## 2. Brief review of the code

`fflush(stdout)` flushes the current buffer content in `stdout`. This would effectively "prioritize" the `printf()` command if `stdout` has a long buffer to deal with. However, in modern computers, because of the excess of computing power, doing this normally does not have a noticeable effect to the outcome of the execution. 

## 3. Result of execution 
```
% gcc s202018021_05-07-04-ex1.c

% ./a.out hello.txt
Number of Options : 2
Let's open "hello.txt"! 
Ready to read "hello.txt"
File hello.txt is now closed.
All set. Bye!
```

## 4. Explanation for extra files
N/A