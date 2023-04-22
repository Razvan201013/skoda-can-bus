


#include <mcp_can.h>            //CAN Bus Shield Compatibility Library
#include <SPI.h>                //CAN Bus Shield SPI Pin Library

#include <Wire.h>               //Extension Library for measuring current


#include <Arduino.h>

MCP_CAN CAN0(9);     // Set CS to pin 9




#define SPEED_PIN 5
int Speed = 0;
int SpeedSendVal = 50;
int RPM;
int absWarning = 0; 
String blinkerleft;
String blinkerright; 
String check = "TRUE";
String batWarning = "FALSE";

int speed = 0;
byte speedL = 0;
byte speedH = 0;
int count;






	// Called when starting the arduino (setup method in main sketch)
	void setup() {





  START_INIT:
  
 
// Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK) Serial.println("MCP2515 Initialized Successfully!");
  else Serial.println("Error Initializing MCP2515...");

  CAN0.setMode(MCP_NORMAL);   


    
	}

	
	

//turn off abs and airbag. And make rpm work
unsigned char airbag[8] = {0x050, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00};
unsigned char ABS[8] = {0x1A0, 0x18, 0x00, 0xfe, 0xfe, 0x00, 0xff};
unsigned char rpm[8] = {0x280, 0x3D, 0x3D, 0x3D, 0x00, 0x1B, 0x0E};
unsigned char door[8] = {B1000, B1000};
unsigned char placeholder[8] = {0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char battery[8] = {B11111111};
unsigned char bl[8] = {B001};
unsigned char br[8] = {B010};
unsigned char lights[8] = {0xDA0, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,};
unsigned char lights2[8] = {0x5d7,0x5d7,0x5d7,0x5d7,0x5d7,0x5d7,0x5d7};





 
void loop() {

 
 CAN0.sendMsgBuf(0x1A0, 0, 8, ABS);
CAN0.sendMsgBuf(0x050, 0, 8, airbag);
CAN0.sendMsgBuf(0x280, 0, 8, rpm);
//CAN0.sendMsgBuf(0x470, 0, 8, door);
CAN0.sendMsgBuf(0x470, 0, 8, battery);
//CAN0.sendMsgBuf(0x5d7, 0, 8, lights);
CAN0.sendMsgBuf(0x5d7, 0, 8, lights2);
Serial.println("Message Sent Successfully!");

count++;
  if (count == 0x00)
  {
    count = 0xFF;
    count++;
  }















	}





 

 






   












	void idle() {

	}



