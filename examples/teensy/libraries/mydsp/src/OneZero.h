#ifndef ONEZERO_H_INCLUDED
#define ONEZERO_H_INCLUDED

class OneZero{
public:
  OneZero();
  
  void setB1(float b);
  float tick(float input);
private:
  float del, b1;
};

#endif  // ONEZERO_H_INCLUDED