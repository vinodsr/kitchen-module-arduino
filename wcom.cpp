
#include  "wcom.h"
#include "Logger.h"
#include "RF24.h"


#define XRF_CE 7
#define XRF_CSN 8

RF24 WCOM_radio (XRF_CE,XRF_CSN);

byte pipes[][7] = {"master", "slave", "idle"};

boolean WCOM :: isAvailable () {
 WCOM_radio.available();
}

int WCOM :: sendMessage(wireless_msg_payload payload) {
  Logger :: debug("Sending message" + String(payload.message));
  WCOM_radio.stopListening();
  WCOM_radio.openWritingPipe(pipes[1]);
  
  delay(10);
  WCOM_radio.write(&payload, sizeof(wireless_msg_payload) + 1);
  delay(10);
  WCOM_radio.startListening();
  return 0;
}

wireless_msg_payload WCOM::getMessage() {
  return this->incoming;
}
WCOM :: WCOM () {

}
boolean WCOM::readMessage() {
  if (WCOM_radio.available())
  {
    WCOM_radio.read(&incoming, sizeof(wireless_msg_payload));
    return true;
  }
  return false;
}
void WCOM :: init() {

  
  WCOM_radio.begin();
  WCOM_radio.setAutoAck(1); // Ensure autoACK is enabled
  WCOM_radio.setRetries(1, 3);
  WCOM_radio.enableDynamicPayloads();
  WCOM_radio.openWritingPipe(0xF0F0F0F0E1);
  WCOM_radio.openReadingPipe(1, pipes[0]);
  WCOM_radio.startListening();
  WCOM_radio.printDetails();
}


