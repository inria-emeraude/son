#ifndef DISTORTION_H_INCLUDED
#define DISTORTION_H_INCLUDED

class Distortion{
public:
  Distortion();
  
  void setDrive(float d);
  void setOffset(float o);
  void setGain(float g);
  float tick(float input);
private:
  float cubic(float x);
  float drive, offset, gain;
};

#endif  // DISTORTION_H_INCLUDED