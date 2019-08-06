#include <SoftwareSerial.h>

SoftwareSerial hc12(11, 12);
#define hc12_set_pin 10

// set pin of the hc12 must be set to low to program the hc12, delays are result of trial and error for optimal pin waiting time
void command(String command) {
  pinMode(hc12_set_pin, OUTPUT);
  delay(20);
  digitalWrite(hc12_set_pin, LOW); // to enter the hc12 into command mode
  delay(20);
  hc12.print(command);
  delay(20);
  digitalWrite(hc12_set_pin, HIGH);
  delay(20);
  pinMode(hc12_set_pin, INPUT);
}

void setup() {
  Serial.begin(19200);
  hc12.begin(9600);
  command("AT+C010");
  // AT+Bxxxx: baud rate
  // AT+Cxxxx: comms channel
  // AT+FUx: transmission mode
  // AT+Px: transmission power
}

void loop() {
    while (hc12.available()) {
      Serial.println(hc12.read()); // reply: usually OK+xxxx
    }
}
