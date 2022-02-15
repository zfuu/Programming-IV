# s202018021_08-04-ex8
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
This exercise asks us to rotate the OpenGL logo so that it looks like it's on the tip of a clockhand. The key is to rotate the logo and then translate it a set distance to the side. 

That's pretty easy to do. We just need to recycle the `loopcounter` logic from the earlier exercises, and pass that value into the `glRotatef()` command. I set `loopmax` so be `360` so that the logo would rotate a full 360 degree. Works like a charm. 

## 3. Result of execution 
```
% ./Go
```

## 4. Explanation for extra files
`OUTPUT1.png` - A screenshot of the output frame at an arbitrary angle.

`OUTPUT2.png` - A screenshot of the output frame at another arbitrary angle.