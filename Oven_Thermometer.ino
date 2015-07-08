//****************************************************************
//*  Name    : Bluetooth Oven Thermometer Demo                   *
//*  Author  : Robert Joseph Korn                                *
//*  Notice  : Copyright (c) 2015 Open Valley Consulting Corp    *
//*          : All Rights Reserved                               *
//*  Date    : 7/8/15                                            *
//*  Version : 1.0                                               *
//*  Notes   : Works with max6675 library from adafruit          *
//*          : Used with app inventor on Android                 *
//*          :                                                   *
//****************************************************************

#include "max6675.h"

int tcDO = 7;
int tcCS = 8;
int tcCLK = 9;

int T = 0;
int X = 0;
char buf[4] = "";

MAX6675 tc(tcCLK, tcCS, tcDO);
  
void setup() {
  Serial.begin(9600);
}

void loop() {
   T = tc.readFahrenheit();
   X = map(T, 0, 500, 345, 20);
   sprintf(buf, "%04d",X);
   Serial.println(buf);
   delay(400);
}
