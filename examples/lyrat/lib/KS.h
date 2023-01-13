#ifndef KS_H_INCLUDED
#define KS_H_INCLUDED

class KS{
public:
  KS(int SR);
  ~KS();
  
  void setFeedback(float f);
  void setFreq(float f);
  void trigger();
  float oneZero(float x);
  float tick();
private:
  float* delBuffer;
  float feedback, samplingRate, zeroDel;
  int readIndex, writeIndex, del;
  bool trig;
};

#endif  // KS_H_INCLUDED