# s202018021_07-05-ex1
Fu, Ziyu

## 1. Instruction to compile the code

After using the `cd` (change directory) command to navigate to the correct working directory, use these following commands to compile the code:

```bash
% gcc -Wall -c 07-03-EmbededObjects.c
% gcc -Wall -c 07-03-Projection.c
% gcc -Wall -c 07-04-Initialization.c
% gcc -Wall -c 07-05-Callback.c
% gcc -Wall -c 07-05-MainFunction.c
% gcc -Wall -c 07-05-Rendering.c
% gcc -o Go -framework GLUT -framework OpenGL 07-05-MainFunction.o 07-03-EmbededObjects.o  07-04-Initialization.o 07-03-Projection.o 07-05-Callback.o 07-05-Rendering.o
% ./Go
```

## 2. Brief review of the code
This exercise wants us to add two additional user triggered events to the original code: change logo color when the user presses `c`, and change it back when the user presses `C`.

It's easy to give the program the ability to respond to two new key inputs. The key inputs are handled by the `ic2_NormalKeyInput` function in `07-05-Callback.c`. We only need to add two more `case`s corresponding to `c` and `C`.

However, it is a little more complicated to change the color of the logo on the go. To achieve that, we need to pass the `(r, g, b)` values in as parameters. In order to do that, the definition of `ic2_OpenGLLogo()` in `07-03-EmbededObjects.c` needs to be changed. The parameters passed into this function should become `(float s, GLfloat r, GLfloat g, GLfloat b)`. This allows us to control the color of the logo using the `(r, g, b)` variables. 

All the corresponding occurrence of `void ic2_OpenGLLogo (float s, GLfloat r, GLfloat g, GLfloat b)` needs to be modified as well. Also, additional global variables need to be created in `07-05-MainFunction.c` in order to host the `(r, g, b)` variables. 

## 3. Result of execution 
```
% ./Go
```

## 4. Explanation for extra files
`OUTPUT1.png` - A screenshot of the output frame when the program first launches. The logo is `#FFFFFF` (white).

`OUTPUT2.png` - A screenshot of the output frame after pressing `c`. The logo becomes `#00FFFF` (cyan/aqua).