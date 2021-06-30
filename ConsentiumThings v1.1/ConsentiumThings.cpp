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

double ConsentiumThings::InternalTemp(){
  unsigned int wADC;
  double t;
  ADMUX = (_BV(REFS1) | _BV(REFS0) | _BV(MUX3));
  ADCSRA |= _BV(ADEN);  // enable the ADC
  delay(20);            // wait for voltages to become stable.
  ADCSRA |= _BV(ADSC);  // Start the ADC
  while (bit_is_set(ADCSRA,ADSC));
  wADC = ADCW;
  t = (wADC - 324.31 ) / 1.22;
  return (t);
}

void ConsentiumThings::initWiFi(const char* ssid, const char* password){
  sendAT("AT", (char*) "OK");
  sendAT("AT+CWMODE=3", (char*) "OK");
  
  String cmd="AT+CWJAP=\""+(String)ssid+"\",\""+(String)password+"\"";//join access point
  if (sendAT(cmd, (char*) "OK")){
    Serial.println("WiFi connected");
  }
  else {
    Serial.println("WiFi not connected");
  }
}

void ConsentiumThings::sendREST(const char* ip, const char* port, const char* key, String info[], int sensor_num, float data[]){ 
  String serverURL;
  sendAT("AT+CIPMUX=0", (char*) "OK");

  String tcp_str = "AT+CIPSTART=\"TCP\",\""+(String)ip + "\","+(String)port;

  bool tcp_resp = sendAT(tcp_str, (char*) "OK");

  if(tcp_resp=true){
    delay(2000);
    if (sensor_num == 1){
      float sensor_0 = data[0];
      String sensor_0_type = info[0];

      serverURL = "GET /update?send_key=" + (String)key + "&sensor1=" + (String)sensor_0 + "&info1=" + sensor_0_type;
    }
    else if (sensor_num == 2){
      float sensor_0 = data[0];
      String sensor_0_type = info[0];
      float sensor_1 = data[1];
      String sensor_1_type = info[1];

      serverURL = "GET /update?send_key=" + (String)key + "&sensor1=" + (String)sensor_0 + "&info1=" + sensor_0_type + "&sensor2=" + (String)sensor_1 + "&info2=" + sensor_1_type;
    }
    else if (sensor_num == 3){
      float sensor_0 = data[0];
      String sensor_0_type = info[0];
      float sensor_1 = data[1];
      String sensor_1_type = info[1];
      float sensor_2 = data[2];
      String sensor_2_type = info[2];

      serverURL = "GET /update?send_key=" + (String)key + "&sensor1=" + (String)sensor_0 + "&info1=" + sensor_0_type + "&sensor2=" + (String)sensor_1 + "&info2=" + sensor_1_type + "&sensor3=" + (String)sensor_2 + "&info3=" + sensor_2_type;
    }
    else if (sensor_num == 4){
      float sensor_0 = data[0];
      String sensor_0_type = info[0];
      float sensor_1 = data[1];
      String sensor_1_type = info[1];
      float sensor_2 = data[2];
      String sensor_2_type = info[2];
      float sensor_3 = data[3];
      String sensor_3_type = info[3];

      serverURL = "GET /update?send_key=" + (String)key + "&sensor1=" + (String)sensor_0 + "&info1=" + sensor_0_type + "&sensor2=" + (String)sensor_1 + "&info2=" + sensor_1_type + "&sensor3=" + (String)sensor_2 + "&info3=" + sensor_2_type + "&sensor4=" + (String)sensor_3 + "&info4=" + sensor_3_type;
    }
    else if (sensor_num == 5){
      float sensor_0 = data[0];
      String sensor_0_type = info[0];
      float sensor_1 = data[1];
      String sensor_1_type = info[1];
      float sensor_2 = data[2];
      String sensor_2_type = info[2];
      float sensor_3 = data[3];
      String sensor_3_type = info[3];  
      float sensor_4 = data[4];
      String sensor_4_type = info[4]; 
      
      serverURL = "GET /update?send_key=" + (String)key + "&sensor1=" + (String)sensor_0 + "&info1=" + sensor_0_type + "&sensor2=" + (String)sensor_1 + "&info2=" + sensor_1_type + "&sensor3=" + (String)sensor_2 + "&info3=" + sensor_2_type + "&sensor4=" + (String)sensor_3 + "&info4=" + sensor_3_type + "&sensor5=" + (String)sensor_4 + "&info5=" + sensor_4_type;
    }
    else if (sensor_num == 6){
      float sensor_0 = data[0];
      String sensor_0_type = info[0];
      float sensor_1 = data[1];
      String sensor_1_type = info[1];
      float sensor_2 = data[2];
      String sensor_2_type = info[2];
      float sensor_3 = data[3];
      String sensor_3_type = info[3];  
      float sensor_4 = data[4];
      String sensor_4_type = info[4]; 
      float sensor_5 = data[5];
      String sensor_5_type = info[5]; 
      
      serverURL = "GET /update?send_key=" + (String)key + "&sensor1=" + (String)sensor_0 + "&info1=" + sensor_0_type + "&sensor2=" + (String)sensor_1 + "&info2=" + sensor_1_type + "&sensor3=" + (String)sensor_2 + "&info3=" + sensor_2_type + "&sensor4=" + (String)sensor_3 + "&info4=" + sensor_3_type + "&sensor5=" + (String)sensor_4 + "&info5=" + sensor_4_type + "&sensor6=" + (String)sensor_5 + "&info6=" + sensor_5_type;
    }
    else if (sensor_num == 7){
      float sensor_0 = data[0];
      String sensor_0_type = info[0];
      float sensor_1 = data[1];
      String sensor_1_type = info[1];
      float sensor_2 = data[2];
      String sensor_2_type = info[2];
      float sensor_3 = data[3];
      String sensor_3_type = info[3];  
      float sensor_4 = data[4];
      String sensor_4_type = info[4]; 
      float sensor_5 = data[5];
      String sensor_5_type = info[5]; 
      float sensor_6 = data[6];
      String sensor_6_type = info[6]; 
      
      serverURL = "GET /update?send_key=" + (String)key + "&sensor1=" + (String)sensor_0 + "&info1=" + sensor_0_type + "&sensor2=" + (String)sensor_1 + "&info2=" + sensor_1_type + "&sensor3=" + (String)sensor_2 + "&info3=" + sensor_2_type + "&sensor4=" + (String)sensor_3 + "&info4=" + sensor_3_type + "&sensor5=" + (String)sensor_4 + "&info5=" + sensor_4_type + "&sensor6=" + (String)sensor_5 + "&info6=" + sensor_5_type + "&sensor7=" + (String)sensor_6 + "&info7=" + sensor_6_type;
    }

    //String serverPath = serverName  + "&sensor2=" + (String)sensor_1 + "&info2=" + sensor_1_type;

    bool rstatus = sendAT("AT+CIPSEND="+String(serverURL.length()), (char*) ">");
    if(rstatus=true){
      delay(5000);
      if(sendAT(serverURL, (char*) "OK")){
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

