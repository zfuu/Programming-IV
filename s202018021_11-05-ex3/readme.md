# s202018021_11-05-ex3
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
% gcc -o Go -framework GLUT -framework OpenGL 07-03-EmbededObjects.o 08-01-GLTools.o 09-02-Projection.o 09-03-Callback.o 11-02-ReadModel.o 11-04-FileObjects.o 11-04-MainFunction.o 11-05-Initialization.o 11-05-Rendering.o 
% ./Go
```

## 2. Brief review of the code
This exercise asks us to add a 2D object to be rendered together with the 3D CG object. This is pretty easy to do, when we copy the old custom logo code into `07-03-EmbededObjects.c`. And in order to actually add the 2D object into the frame, we need to call `ic2_OpenGLLogo(logoscale)` in `11-05-Rendering.c`. 

Changing the rotation, translation, as well as the scaling factor is also done in `11-05-Rendering.c`. I changed mine so that it flips alound the x axis. 


## 3. Result of execution 
```
% ./Go
```

## 4. Explanation for extra files
`OUTPUT1.png` - A screenshot of the objects at an arbitrary angle.

`OUTPUT2.png` - A screenshot of the objects at another arbitrary angle.

`OUTPUT3.png` - A screenshot of the objects at yet another arbitrary angle.