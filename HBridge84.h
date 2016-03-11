
#ifndef HBRIDGE_84
#define HBRIDGE_84
#include "Arduino.h"

// #define portOutputRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_output_PGM + (P))) )
#define portOutputReference(P) (((P) < 8) ? PORTA : PORTB)

class HBridge84 {
  byte en_pin;
  uint8_t en_timer;
  uint8_t en_bit;
  volatile uint8_t &en_port;
  
  byte a_pin;
  uint8_t a_bit;
  volatile uint8_t &a_port;
  
  byte b_pin;
  uint8_t b_bit;
  volatile uint8_t &b_port;

  void set_en();
  void clear_en();
  void write_en(uint8_t val);
  
  void set_a();
  void clear_a();
  void write_a(uint8_t val);
  
  void set_b();
  void clear_b();
  void write_b(uint8_t val);

public:
  HBridge84(byte a, byte b, byte en): 
    en_pin(en),
    en_timer(digitalPinToTimer(en)),
    en_bit(digitalPinToBitMask(en)),
    en_port(portOutputReference(en)),
    a_pin(a),
    a_bit(digitalPinToBitMask(a)),
    a_port(portOutputReference(a)),
    b_pin(b),
    b_bit(digitalPinToBitMask(b)),
    b_port(portOutputReference(b))
  { 
    setMode(OUTPUT); 
  }
  void setMode(byte);
  void coast();
  void forward();
  void forward(byte);
  void reverse();
  void reverse(byte);
  void brake();
  void brake(byte);
  void drive(int);
};

#endif

