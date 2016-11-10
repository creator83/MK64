#include "MK02F12810.h"                 // Device header

#ifndef GPIO_H
#define GPIO_H



class Gpio
{
//variables
public:
  enum class Port :uint8_t {A , B , C , D , E};
  enum class mux :uint8_t {Analog, GPIO , Alt2 , Alt3 , Alt4 , Alt5 , Alt6 , Alt7};
  enum class mode: uint8_t {Input, Output};
  enum class out : uint8_t{PushPull , OpenDrain};
  enum class PP : uint8_t{PullDown, PullUp};
  enum class state : uint8_t {Off, On};

private:
  static PORT_MemMapPtr PortBase [5];
  static GPIO_MemMapPtr GpioBase [5];
//static unsigned int pAdr [3];	
  uint8_t prt;
//functions
public:
  Gpio ();
  Gpio(Port p );
  Gpio(uint8_t p );
  void settingPinPort (Port p);
  void settingPinPort (uint8_t p);

  //function for pins

  void settingPin (uint8_t pin , mux mx = mux::GPIO, mode m = mode::Output);
  void settingPinDirection (uint8_t pin , mode m);
  void PuPdPin (uint8_t pin, state s, PP p);
  void setPin (uint8_t pin );
  void clearPin (uint8_t pin);
  void toglePin (uint8_t pin);
  void setPinState (uint8_t pin , state s);
  bool pinState (uint8_t pin);

  //function for port
  void settingPort (uint32_t val, mux mx = mux::GPIO, mode m = mode::Output);
  void settingPortDirection (uint32_t val, mode m);
  void setValPort (uint32_t value);
  void clearValPort (uint32_t value);

public:
  class Pin
  {
  public:
	  Pin ();
	  void sPin (unsigned int pin );
  };

};

#endif



