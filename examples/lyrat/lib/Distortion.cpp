#include <cmath>

#include "Distortion.h"

Distortion::Distortion() : 
drive(0.0),
offset(0.0),
gain(1.0){}

void Distortion::setDrive(float d){
  drive = d;
}

void Distortion::setOffset(float o){
  offset = o;
}

void Distortion::setGain(float g){
  gain = g;
}

float Distortion::cubic(float x){
  return x - x*x*x/3;
}
    
float Distortion::tick(float input){
  float output = input*pow(10.0,2*drive) + offset;
  output = fmax(-1,fmin(1,output));
  output = cubic(output);
  return output*gain;
}
