
#include "HBridge84.h"
#include "Arduino.h"

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif

static void turnOffPWM(uint8_t timer)
{
  switch (timer)
  {
    #if defined(TCCR1A) && defined(COM1A1)
    case TIMER1A:   cbi(TCCR1A, COM1A1);    break;
    #endif
    #if defined(TCCR1A) && defined(COM1B1)
    case TIMER1B:   cbi(TCCR1A, COM1B1);    break;
    #endif
    
    #if defined(TCCR0A) && defined(COM0A1)
    case  TIMER0A:  cbi(TCCR0A, COM0A1);    break;
    #endif
    
    #if defined(TIMER0B) && defined(COM0B1)
    case  TIMER0B:  cbi(TCCR0A, COM0B1);    break;
    #endif
  }
}

void HBridge84::set_en(){
  turnOffPWM(en_timer);
  en_port |= en_bit; // set
}
void HBridge84::clear_en(){
  turnOffPWM(en_timer);
  en_port &= ~en_bit; // clear
}
void HBridge84::write_en(uint8_t val){
  turnOffPWM(en_timer);
  if (val == LOW) {
    en_port &= ~en_bit; // clear
  } else {
    en_port |= en_bit; // set
  }
}

void HBridge84::set_a(){
  a_port |= a_bit; // set
}
void HBridge84::clear_a(){
  a_port &= ~a_bit; // clear
}
void HBridge84::write_a(uint8_t val){
  if (val == LOW) {
    a_port &= ~a_bit; // clear
  } else {
    a_port |= a_bit; // set
  }
}

void HBridge84::set_b(){
  b_port |= b_bit; // set
}
void HBridge84::clear_b(){
  b_port &= ~b_bit; // clear
}
void HBridge84::write_b(uint8_t val){
  if (val == LOW) {
    b_port &= ~b_bit; // clear
  } else {
    b_port |= b_bit; // set
  }
}
  
void HBridge84::setMode(byte mode) { // set all pins to mode
  pinMode(a_pin, mode);
  pinMode(b_pin, mode);
  pinMode(en_pin, mode);
}

void HBridge84::coast() {
  clear_en(); // disable first
  clear_a();
  clear_b();
}

void HBridge84::forward() {
  set_a();
  clear_b();
  set_en();
}

void HBridge84::reverse() {
  clear_a();
  set_b();
  set_en();
}

void HBridge84::forward(byte a) {
  set_a();
  clear_b();
  analogWrite(en_pin, a); // pulse enable last
}

void HBridge84::reverse(byte a) {
  clear_a();
  set_b();
  analogWrite(en_pin, a); // pulse enable last
}

void HBridge84::brake() {
  clear_a();
  clear_b();
  digitalWrite(en_pin, HIGH); // enable last
}

void HBridge84::brake(byte a) {
  clear_a();
  clear_b();
  analogWrite(en_pin, a); // pulse enable last
}

void HBridge84::drive(int a) {
  a = a >> 1; // divide by two but faster
  if (a > 255) { // top half of range
    a = (a - 256);
    if (a > 10) forward(a); else coast();
  } else { // bottom half of range
    a = (255 - a);
    if (a > 10) reverse(a); else coast();
  }
}

