# s202018021_06-07-ex1
Fu, Ziyu

## 1. Instruction to compile the code

After using the `cd` (change directory) command to navigate to the correct working directory, use these following commands to compile the code:

```bash
% gcc -o 06-07-Periodic -framework GLUT -framework OpenGL 06-07-Periodic.c
% ./06-07-Periodic
```

## 2. Brief review of the code

The exercise asks us to make the animation smoother by changing the `loopcounter` logic and the `glutTimerFunc` logic. I made `loopmax` to be 100 so that the increments are smaller. 

I also made the refresh rate fater by changing the arguments that are passed into `void glutTimerFunc(unsigned int millis, void (*func)(int value), int value)` in `void ic2_timerhandler(int keynumber)` on line 145. This made the animation significantly smoother than how it was. 

## 3. Result of execution 
```
% ./06-07-Periodic
```

## 4. Explanation for extra files
`OUTPUT.png` - A screenshot of the output frame.

`OUTPUT.mov` - A quick screen recording of the output. 