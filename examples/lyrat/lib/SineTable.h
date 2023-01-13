#ifndef SINE_TABLE_H_INCLUDED
#define SINE_TABLE_H_INCLUDED

class SineTable{
public:
  SineTable(int size);
  ~SineTable();
  float tick(int index);
private:
  float *table;
  int tableSize;
};

#endif  // SINE_TABLE_H_INCLUDED