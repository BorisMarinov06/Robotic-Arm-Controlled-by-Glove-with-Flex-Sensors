#include <RH_ASK.h>
#include <SPI.h>

RH_ASK rf_driver;

int flex1 = A2;
int flex2 = A3;
int flex3 = A4;
int flex4 = A5;
int flex5 = A6;

void setup() {
    Serial.begin(9600);
    rf_driver.init();
}

void loop() {
    int flex1_pos = analogRead(flex1);
    int flex2_pos = analogRead(flex2);
    int flex3_pos = analogRead(flex3);
    int flex4_pos = analogRead(flex4);
    int flex5_pos = analogRead(flex5);
    
    char data[32];
    sprintf(data, "%d,%d,%d,%d,%d", flex1_pos, flex2_pos, flex3_pos, flex4_pos, flex5_pos);
    
    rf_driver.send((uint8_t *)data, strlen(data));
    rf_driver.waitPacketSent();
    
    Serial.println(data);
    delay(50);
}