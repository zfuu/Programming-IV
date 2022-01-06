/*
 * extraf.c
 *
 *  Created on: 2021/02/04
 *      Author: s1918021
 */
#include <math.h>
float operation_absdiff(float v1, float v2) {
  if (v1 > v2)
    return v1 - v2;
  return v2 - v1;
}

float operation_power(float v1, float v2){
     int i;
     int power=0;
     for(i=0;i<v2;i++)
     {
    	 power=power+v1;
     }
     return power;
}



float operation_log(float v1,float v2){
	 float result;
	if(v2>0)
	{
		result= log(v1)/log(v2);
		return result;
	}
	else
	{
	 printf(" The argument cannot be less or equal to zero");
	 return 0;
	}
}
