#include "func.h"

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
 // Wire.onReceive(receiveEvent);

  setup_wifi();
  client.setServer(MQTT_SERVER, 1883);
  client.setCallback(callback);
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
  Serial.println(sizeof(cpd));
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if (millis() - lastSendToServer > cpd.sendDataToServerEvery) {
    lastSendToServer =  millis();
    client.publish("outTopic", createJSON().c_str());

    setCurrentDateTime();

    Serial.println("###################");
    Serial.print(cpd.dateYear);         Serial.print('/');
    Serial.print(cpd.dateMonth);        Serial.print('/');
    Serial.print(cpd.dateDay);          Serial.print(' ');
    Serial.print(cpd.dateHour);         Serial.print(':');
    Serial.print(cpd.dateMinute);       Serial.print(':');
    Serial.print(cpd.dateSecond);       Serial.println();
  }
  if (millis() - lastTransmit > TRANSMIT_EVERY) {
    lastTransmit =  millis();
    i2cTransmit();
  }
 
}
