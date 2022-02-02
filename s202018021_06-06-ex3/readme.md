# s202018021_06-06-ex3
Fu, Ziyu

## 1. Instruction to compile the code

After using the `cd` (change directory) command to navigate to the correct working directory, use these following commands to compile the code:

```bash
% gcc -o 06-06-LogoOpenGL -framework GLUT -framework OpenGL 06-06-LogoOpenGL.c
% ./06-06-LogoOpenGL
```

## 2. Brief review of the code

In order the modify the original code and make it output a different logo, we only need to change the logic inside `void ic2_OpenGLLogo (float s)` function. 

The `(0,0)` point is located at the center of the frame. Using this logic, it's easy to transform a simple line drawing into code commands. 

Oh also I didn't like how it blinks at the end so I turned it off. 

## 3. Result of execution 
```
% ./06-06-LogoOpenGL
```

## 4. Explanation for extra files
`06-06-LogoOpenGL_OUTPUT` - A screenshot of the output frame. 