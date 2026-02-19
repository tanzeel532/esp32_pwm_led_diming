#include<Arduino.h>

const int pwm_freq = 1000;
const int pwm_channel = 0;  //total of 16 channels 0 to 15
const int pwm_res = 8;     //range from 0 to 16 bits

const int led_pin = 2;

int count = 0;

void setup(){ 
  ledcSetup(pwm_channel, pwm_freq, pwm_res);
  ledcAttachPin(led_pin, pwm_channel);
}
void loop(){
  delay(30);   //for smooth and visible diming

  ledcWrite(pwm_channel, count);

  //to automate diming
  if(count < 255)
  {
    count++;
  }
  else
  {
    count = 0;
  }
}