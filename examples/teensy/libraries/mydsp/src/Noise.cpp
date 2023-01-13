#include <cstdlib>

#include "Noise.h"

Noise::Noise() :
randDiv(1.0/RAND_MAX){}
    
float Noise::tick(){
  return rand()*randDiv*2 - 1;
}
