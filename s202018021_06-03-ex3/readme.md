# s202018021_06-03-ex3
Fu, Ziyu

## 1. Instruction to compile the code

After using the `cd` (change directory) command to navigate to the correct working directory, use these following commands to compile the code:

```bash
% gcc -o 06-03-SwapBuffersCheck -framework GLUT -framework OpenGL 06-03-SwapBuffersCheck.c
% ./06-03-SwapBuffersCheck
```

## 2. Brief review of the code

This objective of this exercise is to change the program so that the color cycle of the frames becomes (green → black → black → black → white → black → black → black). In order to achieve that, we only need to change the `loopcounter` logic on line 20. I changed the `loopmax` variable to 8, so that each loop can host 8 different color states. When `loopcounter` is at 4, the color needs to be white, and when `loopcounter` is at 8, it needs to display green and `loopcounter` needs to be reset. 

The frames updates at a rate that is significantly faster than what my human eye can catch, so in each state, I added a `printf` command that prints the current state number and the color it's showing. This print log allows me to confirm the operation of this code. 

## 3. Result of execution 
```
% ./06-03-SwapBuffersCheck                                                                
1 - black
2 - black
3 - black
4 - white
5 - black
6 - black
7 - black
8 - green
1 - black
2 - black
3 - black
```

## 4. Explanation for extra files
N/A