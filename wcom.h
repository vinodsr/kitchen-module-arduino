#ifndef wcom_h
#define wcom_h
#include "RF24.h"






struct wireless_msg_payload
{
  uint8_t number;
  uint8_t destination;
  char message[100];
};

class WCOM
{
private:

  wireless_msg_payload incoming;
public:
    int sendMessage(wireless_msg_payload payload);
    boolean readMessage();
    wireless_msg_payload getMessage();
    boolean isAvailable();
    void init();
    WCOM ();


    
};
#endif

