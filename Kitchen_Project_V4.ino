/**
 * 
 * Kitchen Utils - IHN 
 * 
 * Developed by Vinod Surendran
 */




#include "Logger.h"
#include "MotionDetector.h"
#include "GasDetector.h"
#include "dht11.h"
#include "Display.h"
#include "wcom.h"

#include <Thread.h>
#include <ThreadController.h>
#include <TimerOne.h>
#include <EEPROM.h>



#define ENABLE_LOG
#define APP_LOG_LEVEL LOG_LEVEL_DEBUG


/*
 *  Sensor declarations 
 */

MotionDetector mDetector(10, HIGH);
GasDetector gDetector(A0);
dht11 dd;
Display lcd(true);
WCOM wcom;

/**
 * Common functions 
 */

#define SALT "iCAT"

struct config_structure
{
  char salt[5];
  int version;
  char uuid[38];
 
};
config_structure config;

void display(String msg) {
  lcd.print(msg);
}


void display(String title,String msg) {
  lcd.print(msg);
}



/**
 *  Thread monitors 
 */

ThreadController controller = ThreadController();

Thread gasSensorThd = Thread();
Thread motionDtdThd = Thread();

void motionDtdMonitor() {
  if(mDetector.isDetected()) {
    //display ("Some one is there ");
    //tone(A4, 5000, 5000);
   // delay(3000);
   
  }
}

void gasSensorMonitor() {
   if (gDetector.getGasLevel() > 400 ) {
    lcd.print("GAS LEAK !","G Sensor : " + String(gDetector.getGasLevel()));
    
  } else {
  //  lcd.print("G Sensor : " + String(gDetector.getGasLevel()));
  }

  // Send the status
wireless_msg_payload payload;
String s = String("GAS : ") + gDetector.getGasLevel();
s.toCharArray(payload.message,100); 
  wcom.sendMessage(payload);
}



/**
 *  Setup 
 */
bool error = false;
const int buttonPin = A7; 
void setup() {
  
  #ifdef ENABLE_LOG
  Logger::init();
  Logger::setLevel(APP_LOG_LEVEL);
  #endif

  pinMode(buttonPin,INPUT);

  lcd.turnOn();
  display("Booting ...");
  delay(1000);
  EEPROM.get(0, config);
 
/**
 *  Booting steps 
 */


 if (strcmp (config.salt,SALT) != 0) {
    lcd.print("ERROR!","NO HEADER FOUND !");
    error = true;
    return;
    
 } else {
  // ok read values ... 
  lcd.print("salt",config.salt);
  delay(200);
  lcd.print("version",String(config.version));
  delay(200);
  lcd.print("uuid",config.uuid);
  delay(200);
  //lcd.print(" ... ");
  delay(100);
 }

  Logger::debug("Setting up WIFI");
  wcom.init();
 




// Setting up the threads 

  gasSensorThd.setInterval(1000);
  gasSensorThd.onRun(gasSensorMonitor);
  motionDtdThd.setInterval(100);
  motionDtdThd.onRun(motionDtdMonitor);
  controller.add(&gasSensorThd);
  controller.add(&motionDtdThd);

  Timer1.initialize(1000000);
 // Timer1.attachInterrupt(timerCallback);



  display("READY !");
}



/** 
 *  Timer callback
 */
void timerCallback() {
  Logger::debug("timer callback ");
  controller.run();
  
}

/**
 * Loop 
 */

void loop() {
    lcd.print("554");
  // Incase of error dont execute.
 int buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
   lcd.print("HIGH");
  } else {
    // turn LED off:
   lcd.print("LOW");

  }
  if(error) {
    return;
  }
  int val = dd.read(A1);
  //Serial.println(val);
 Serial.println(dd.temperature);

  //display("VERIFYING ..... ");
  //display("TEMP : " + String(dd.temperature));
//  if(wcom.readMessage() == true) {
//    wireless_msg_payload payload = wcom.getMessage();
//    Logger :: debug("Message GOT = ");
//    Logger :: debug(payload.message);
//  }

  // Send the status
wireless_msg_payload payload;
String s = String("TEMP : ") + dd.temperature;
s.toCharArray(payload.message,100); 
  wcom.sendMessage(payload);

  
  delay(2000);
}




