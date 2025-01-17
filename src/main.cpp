/******************************************************************************
* + Project: IncaFarms                                                        *
* + Version: 0.4.1a                                                           *
* + Description: This is a smart irrigation system                            *
* + Board: ESP32 Feather V1                                                   *
* + Sensor: N/A                                                               *
* + Module: N/A                                                               *
* + Author: K0d3x 8its                                                        *
* + Date: October 5th, 2024                                                   *
* + License: MIT                                                              *
*******************************************************************************
  + Inspired by: Duckman | https://busyducks.com/ascii-art-arduino-pinouts/
  + Designed by: K0d3x   | https://github.com/k0d3x8its
*******************************************************************************
*                           ----[      ]-----             * VUSB = VIN | 5VDC *
*                      [ ]-|RST          ____|            *********************
*   MAX output 400mA = [ ]-|3V3         | __ |                                *
*                      [ ]-|NC          | __ |-[ ] = 3.7V Battery             *
*                      [ ]-|GND         |____|                                *
*                      [ ]-|A0            BAT|-[ ] = LiPo                     *
*                      [ ]-|A1             EN|-[ ]                            *
*         Input Only = [ ]-|A2           VUSB|-[ ] = VBUS                     *
*         Input Only = [ ]-|A3            D13|-[ ]                            * 
*         Input Only = [ ]-|A4            D12|-[ ]                            * 
*                      [ ]-|A5            D27|-[ ]                            * 
*                SCK = [ ]-|D5            D33|-[ ]                            *
*               MOSI = [ ]-|D18 Feather   D15|-[ ]                            * 
*               MISO = [ ]-|D19 Huzzah32  D32|-[ ]                            *
*                RX--> [ ]-|D16           D14|-[ ]                            * 
*                TX <--[ ]-|D17           D22|-[ ] = SCL                      * 
*                      [ ]-|D21           D23|-[ ] = SDA                      * 
*                           \_______________/                                 *                           
*                                                                             *                               
*******************************************************************************
    ******************     Feather Huzzah32 Overview      ******************  
*******************************************************************************
 **** https://learn.adafruit.com/adafruit-huzzah32-esp32-feather/overview ****
*******************************************************************************
*******************************************************************************
         ******************  Example Datasheet  ******************
*******************************************************************************
             *** https://www.website.com/path/to/datasheet ***
******************************************************************************/

#include <Arduino.h>

// define pins
const int valvePin = 0;                           // pin to control valve
const int buttonPin = 1;                          // physical push button
const int moistureSensorPin = A0;                 // pin for moisture sensor

// define threshold and timings
const int moistureThreshold = 300;                // threshold value
const unsigned long valveActiveDuration = 60000;  // valve active time in milliseconds
const unsigned long initDelay = 5000;             // intialization delay in milliseconds

// define states
enum State {
  INIT,
  IDLE,
  VALVE_ACTIVE,
  VALVE_REST,
  SHUTDOWN
};

// initial state
State currentState = INIT;

// time variable
unsigned long stateStartTime = 0;

void setup() {
  pinMode(valvePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(moistureSensorPin, INPUT);

  // Start with valve closed
  digitalWrite(valvePin, LOW);

  // Begin serial communication for debugging
  Serial.begin(115200);
}

void loop() {
  // Check if the button is pressed for shutdown
  if (digitalRead(buttonPin) == LOW) {
    currentState = SHUTDOWN;
  } 
}