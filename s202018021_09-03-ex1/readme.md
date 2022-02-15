# s202018021_09-03-ex1
Fu, Ziyu

## 1. Instruction to compile the code

After using the `cd` (change directory) command to navigate to the correct working directory, use these following commands to compile the code:

```bash
% gcc -Wall -c 07-03-EmbededObjects.c
% gcc -Wall -c 07-03-Projection.c
% gcc -Wall -c 07-04-Initialization.c
% gcc -Wall -c 07-05-Callback.c
% gcc -Wall -c 07-05-MainFunction.c
% gcc -Wall -c 08-01-GLTools.c
% gcc -Wall -c 08-04-Rendering.c
% gcc -o Go -framework GLUT -framework OpenGL 07-05-MainFunction.o 07-03-EmbededObjects.o  07-04-Initialization.o 07-03-Projection.o 07-05-Callback.o 08-01-GLTools.o 08-04-Rendering.o
% ./Go
```

## 2. Brief review of the code
This exercise asks us to rotate the OpenGL logo so that it's flipping along the x axis. This is a pretty easy modification on `08-04-Rendering.c`. The `glRotatef()` function needs to be modified. so that only the `x` vector is active. 
## 3. Result of execution 
```
% ./Go
```

## 4. Explanation for extra files
`OUTPUT1.png` - A screenshot of the output frame at an arbitrary angle.

`OUTPUT2.png` - A screenshot of the output frame at another arbitrary angle.