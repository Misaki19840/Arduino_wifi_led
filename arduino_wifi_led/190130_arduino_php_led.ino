#include "ESP8266.h"
#include <SoftwareSerial.h>

#define SSID "xxx"
#define PASSWORD "xxx"
#define HOST_NAME "xxx"
#define FILE_NAME "controller_get_status.php"

int n = 0;

SoftwareSerial mySerial(2, 3);  //RX, TX
ESP8266 wifi(mySerial);

/**
 * 初期設定
 */
void setup(void)
{
  Serial.begin(9600);

  if (wifi.setOprToStationSoftAP()) {
    Serial.println("to station ok");
  } else {
    Serial.println("to station error");
  }

  if (wifi.joinAP(SSID, PASSWORD)) {
    Serial.println("connect success");
  } else {
    Serial.println("connect error");
  }

  if (wifi.disableMUX()) {
    Serial.println("disable mux success");
  } else {
    Serial.println("disable mux error");
  }

  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop(void)
{
  uint8_t buffer[524] = {0};
  bool device_st[2] = {false};

  // TCPで接続
 wifi.createTCP(HOST_NAME, 80);
  
  // サーバーへ渡す情報
 char sendStr[128];
 sprintf(sendStr, "GET /%s?data=a HTTP/1.0\r\nHost: %s\r\nUser-Agent: arduino\r\n\r\n", FILE_NAME, HOST_NAME);
 wifi.send((const uint8_t*)sendStr, strlen(sendStr));

 uint32_t len = wifi.recv(buffer, sizeof(buffer), 10000);

 // DEBUG
 // show contents
 if (len > 0) {
 Serial.print("Received:[");
 for(uint32_t i = 0; i < len; i++) {
 Serial.print((char)buffer[i]);
 }
 Serial.print("]\r\n");
 }

 // set device status
 uint32_t device_idx = 0;
 bool is_inbody = false;
 for(uint32_t i = 0; i < len; i++) {
 if( (char)buffer[i] == '{' ) is_inbody = true;
 if( is_inbody ){
  if( buffer[i-1] == ':'){
    if( buffer[i] == '1' ) device_st[device_idx] = true;
    else device_st[device_idx] = false;
    device_idx++;
  }
 }
 }

 // DEBUG
 Serial.print("device1: ");
 Serial.print(device_st[0]);
 Serial.print(", device2: ");
 Serial.print(device_st[1]);

  // write status to pins
 if( device_st[0] ) digitalWrite(13, HIGH);
 else digitalWrite(13, LOW);
 if( device_st[1] ) digitalWrite(12, HIGH);
 else digitalWrite(12, LOW);

  delay(5000);
 }
