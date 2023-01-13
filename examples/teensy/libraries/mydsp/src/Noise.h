#ifndef NOISE_H_INCLUDED
#define NOISE_H_INCLUDED

class Noise{
public:
  Noise();

  float tick();
private:
  float randDiv;
};

#endif  // NOISE_H_INCLUDED