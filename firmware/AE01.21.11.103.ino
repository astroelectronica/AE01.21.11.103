//AE01.21.11.103
//MCP4531-103
//ARDUINO UNO R3
//astroelectronic@

//Schematic reference: AE01.21.11.101

#include <Wire.h>//I2C LIBRARY

int AE021L002_PC=0;//VALUE OF P0W

void setup() {
  Wire.begin(); //ENABLE I2C BUS
  Serial.begin(9600);//SERIAL BAUD RATE
}

void loop() {
  if (Serial.available()) {//SERIAL COMM ENABLE?
  AE021L002_PC = Serial.parseInt();//CONVERT CHAR TO INT
  Wire.beginTransmission(byte(0x2E));//MCP5431 ADDRESS
  Wire.write(byte(0x00));//WRITE INSTRUCTION
  Wire.write(AE021L002_PC);//SEND I2C WIPER0 VALUE
  Wire.endTransmission();//STOP I2C
  delay(2);//DELAY TIME
  }
}
