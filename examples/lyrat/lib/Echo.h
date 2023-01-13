#ifndef ECHO_H_INCLUDED
#define ECHO_H_INCLUDED

class Echo{
public:
  Echo(int SR, int maxDel);
  ~Echo();
  
  void setFeedback(float f);
  void setDel(int d);
  float tick(float input);
private:
  float* delBuffer;
  float feedback, samplingRate;
  int readIndex, writeIndex, del;
};

#endif  // ECHO_H_INCLUDED