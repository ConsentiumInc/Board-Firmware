#ifndef ConsentiumThings_h
#define ConsentiumThings_h

#include <Arduino.h>          

bool sendAT(String, char[]);

class ConsentiumThings{
    public:
        ConsentiumThings();
        void connect();
        double InternalTemp();
        void initWiFi(const char*, const char*);
        void sendREST(const char*, const char*, const char*, String[], int, float[]);
};

#endif