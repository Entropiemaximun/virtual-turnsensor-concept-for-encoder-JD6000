/*
 virtual TurnSensor  based on value modification  Bricbric 2024

 signal  to A1

 resultat sur D13  ou  led  du nano 

 modif  code  proposition  sebastien B pour prendre lafrequence
  */


#define seuil_tension 100  // seuil de saut qui  compare deux etats
#define seuil_pas 3      // seuil d'activation   nb d'erreur succesive qui le declenche

#define SENSOR_PIN A1  //
#define SIGNAL_PIN 13  //    on regarde la led  du nano  pour  voir le resultat  ca doit clignoter

//loop time variables in microseconds
const uint16_t LOOP_TIME = 100;  //10Hz
uint32_t lastTime = LOOP_TIME;
uint32_t currentTime = LOOP_TIME;



int sensor = 0;     //setpoint - actual
int sensorOld = 0;  //keep  old  sensor value  //  ajout bricbric  **************

uint8_t pulseCount = 1;  // Steering Wheel Encoder
byte signal_= LOW;

void setup() {

  Serial.begin(38400);
  Serial.println("Turn sensor BricBric  2024");

  pinMode(SIGNAL_PIN, INPUT);
  digitalWrite(SIGNAL_PIN, LOW);

signal_= LOW;
  
}

void loop() {
  // Loop triggers every 100 msec and sends back steer angle etc
  currentTime = millis();

  if (currentTime - lastTime >= LOOP_TIME) {
    lastTime = currentTime;
    sensor = pulseIn(SENSOR_PIN, HIGH,5000);


    if (abs(sensor - sensorOld) > seuil_tension) {
      if (pulseCount++ > seuil_pas) {
        signal_ = !signal_;
        digitalWrite(SIGNAL_PIN, signal_);
        Serial.print("reprise_volant 100 ,");
      } else {
        Serial.print("tremblment_volant  0 ,");
      }
      Serial.print(" >>+-  10");
    } else {
      if (pulseCount-- < seuil_pas){
      digitalWrite(SIGNAL_PIN, LOW);
      signal_= LOW;
      }

      Serial.print("signal 100 , >>+- 0");
    }

    if (pulseCount < 1) pulseCount = 1;
    if (pulseCount > seuil_pas) pulseCount = seuil_pas + 1;
    sensorOld = sensor;

    Serial.print(" , sensor ");
    Serial.print(sensor);
    Serial.print(" , pulse ");
    Serial.println(pulseCount );
  }
  yield();
}
