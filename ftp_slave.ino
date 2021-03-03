#include <ESP8266WiFi.h>
#include <SD.h>
#include "ESP8266FtpServer.h"

const char* ssid = "YOUR SSID";
const char* password = "YOUR PASSWORD";

FtpServer ftpSrv;//set #define FTP_DEBUG in ESP8266FtpServer.h to see ftp verbose on serial

void setup(void){
  Serial.begin(115200);  
  WiFi.begin(ssid, password);
  //connection
  while (WiFi.status() != WL_CONNECTED) {//wait 10 seconds
    Serial.println("Not Connected");
    delay(500);
  }
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  //2 indicates the Chip select pin
  if (SD.begin(2)) {
      Serial.println("SD opened!");
      ftpSrv.begin("username","password");    
  } else {
    Serial.println("SD card Not Detected");
    Serial.println("Restarting in 0");
    Serial.print(1/0);
    
    }
}
void loop(void){
  ftpSrv.handleFTP();        
  }
