#ifndef SMOOTH_H_INCLUDED
#define SMOOTH_H_INCLUDED

class Smooth{
public:
  Smooth();
  
  void setPole(float p);
  float tick(float input);
private:
  float del, s;
};

#endif  // SMOOTH_H_INCLUDED