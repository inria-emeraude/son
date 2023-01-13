#ifndef BUTTON_HANDLER_H_INCLUDED
#define BUTTON_HANDLER_H_INCLUDED

class ButtonHandler{
public:
  ButtonHandler(int nParams, int precision);
  
  int getParamNumber();
  int getValue();
  void tick();
private:
  int n, p, param, value;
  bool paramChange, valueChange, holdMode;
};

#endif  // BUTTON_HANDLER_H_INCLUDED