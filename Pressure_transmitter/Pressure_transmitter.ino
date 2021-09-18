#include <SoftwareSerial.h>
SoftwareSerial mybluetooth(7,8);

typedef union {
  float number;
  uint8_t bytes[4];
}FLOATUNION_t;

FLOATUNION_t myValue1;

void setup() {
  mybluetooth.begin(9600);
}

void loop(){
  int sensorVal=analogRead(A0);
  float voltage = (sensorVal*5.0)/1020.0;
  float pressure_pascal = (3.0*((float)voltage-0.94))*1000000.0;//calibrate here
  float pressure_bar = pressure_pascal/10e5;
  myValue1.number = pressure_bar;

  
  for (int i = 0; i < 4; i++) {
    mybluetooth.write(myValue1.bytes[i]);
  }
  mybluetooth.write('\n');
  delay(100);
}
