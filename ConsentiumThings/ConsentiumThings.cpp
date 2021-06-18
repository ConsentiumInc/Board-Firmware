#include <ConsentiumThings.h>

#define EspBaud 115200

ConsentiumThings::ConsentiumThings(){}

bool sendAT(String command,char response[]){
  Serial.println(command);
  delay(5000);
  if(Serial.find(response)){
    return true;
    }
  else
    return false;  
}

void ConsentiumThings::connect(){
    Serial.begin(EspBaud);
}

float ConsentiumThings::InternalTemp(){
  unsigned int wADC;
  ADMUX = (_BV(REFS1) | _BV(REFS0) | _BV(MUX3));
  ADCSRA |= _BV(ADEN);             
  ADCSRA |= _BV(ADSC);  
  while (bit_is_set(ADCSRA,ADSC));
  wADC = ADCW;
  
  float val = (wADC - 324.31 ) / 1.22;
  return val;   // return internal MCU temp. in degree C
}

void ConsentiumThings::initWiFi(const char* ssid, const char* password){
  sendAT("AT", (char*) "OK");
  sendAT("AT+CWMODE=3", (char*) "OK");
  
  String cmd="AT+CWJAP=\""+(String)ssid+"\",\""+(String)password+"\"";//join access point
  sendAT(cmd, (char*) "OK");
}

void ConsentiumThings::sendREST(const char* ip, const char* port, const char* key, String info[], int sensor_num, float data[]){
  float sensor_0 = data[0];
  float sensor_1 = data[1];

  String sensor_0_type = info[0];
  String sensor_1_type = info[1];
  
  sendAT("AT+CIPMUX=0", (char*) "OK");

  String tcp_str = "AT+CIPSTART=\"TCP\",\""+(String)ip + "\","+(String)port;

  bool tcp_resp = sendAT(tcp_str, (char*) "OK");

  if(tcp_resp=true){
    delay(2000);
    String serverName = "GET /update?send_key=" + (String)key + "&sensor1=";
    String serverPath = serverName + (String)sensor_0 + "&info1=" + sensor_0_type + "&sensor2=" + (String)sensor_1 + "&info2=" + sensor_1_type;

    bool rstatus = sendAT("AT+CIPSEND="+String(serverPath.length()), (char*) ">");
    if(rstatus=true){
      delay(5000);
      if(sendAT(serverPath, (char*) "OK")){
        sendAT("AT+CIPCLOSE", (char*) "OK");
      }
      else{
        Serial.println("No response");
      } 
    }
    else{
    Serial.println("AT+CIPSEND error!");
    }
  }
  else{
    Serial.println("TCP error!");
  }
}

