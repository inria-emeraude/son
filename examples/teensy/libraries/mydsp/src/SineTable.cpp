#include <cmath>

#include "SineTable.h"

#define PI 3.141592653589

SineTable::SineTable(int size) :
tableSize(size)
{
  table = new float[size];
  for(int i=0; i<size; i++){
    table[i] = std::sin(i*2.0*PI/size);
  }
}

SineTable::~SineTable()
{
  delete[] table;
}
    
float SineTable::tick(int index){
  return table[index%tableSize];
}
