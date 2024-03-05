#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(10, 9); // CE, CSN

const byte address[6] = "12345";

void setup() {
  Serial.begin(9600);
  
  while(!radio.begin()){
    Serial.print("Not Connected! ...\n");
    delay(1000);
  }

  Serial.print("Connected! ...\n");
  delay(500);

  pinMode(2, OUTPUT);
  
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  bool tx;
  if (radio.available()) {
    radio.read(&tx, sizeof(tx));
    Serial.println(tx);

    if(tx)
      digitalWrite(2, HIGH);
    else
      digitalWrite(2, LOW);
  }
}
