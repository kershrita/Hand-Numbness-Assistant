#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <DFRobot_MLX90614.h>

// Threshold Temperature
#define TEMPERATURE_THRESHOLD 40.0

DFRobot_MLX90614_I2C sensor;   // instantiate an object to drive our sensor

RF24 radio(10, 9); // CE, CSN
const byte address[6] = "12345";
bool vib = false;

void setup() {
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  
  while(!radio.begin()){
    Serial.print("Not Connected! ...\n");
    delay(2000);
  }
  
  // initialize the sensor
  while( NO_ERR != sensor.begin() ){
    Serial.println("Communication with device failed, please check connection");
    delay(2000);
  }

  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  sensor.setEmissivityCorrectionCoefficient(0.98);

  sensor.enterSleepMode();
  delay(50);
  sensor.enterSleepMode(false);
  delay(200);
}

void loop() {

  // get ambient temperature, unit is Celsius
  float ambientTemp = sensor.getAmbientTempCelsius();

  // get temperature of object 1, unit is Celsius
  float objectTemp = sensor.getObjectTempCelsius();

  // print measured data in Celsius
  Serial.print("Ambient celsius : "); Serial.print(ambientTemp); Serial.println(" C");
  Serial.print("Object celsius : ");  Serial.print(objectTemp);  Serial.println(" C");

  // Update LEDs and Buzzer based on temperature
  if (objectTemp > TEMPERATURE_THRESHOLD) {
    digitalWrite(2, HIGH);   // Turn on Red LED and Buzzer
    vib = true;
    radio.write(&vib, sizeof(vib)); // send the message
    
  } else {
    digitalWrite(2, LOW);    // Turn off Red LED
    vib = false;
    radio.write(&vib, sizeof(vib)); // send the message
  }
  
  delay(1000);
}
