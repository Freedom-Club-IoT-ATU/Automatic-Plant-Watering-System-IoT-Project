#include <Stepper.h>
#include <Grove.h>


#define STEPPER_PIN1 8
#define STEPPER_PIN2 9
#define STEPPER_PIN3 10
#define STEPPER_PIN4 11
#define MOISTURE_SENSOR A0

// Define constants
#define STEPS_PER_REVOLUTION 200
#define MAX_FLOW_RATE 100 // Maximum flow rate in mL/min


Stepper stepper(STEPS_PER_REVOLUTION, STEPPER_PIN1, STEPPER_PIN2, STEPPER_PIN3, STEPPER_PIN4);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

void setup() {

  lcd.begin(16, 2);
  lcd.print("Automatic Plant");
  lcd.setCursor(0, 1);
  lcd.print("Watering System");
  delay(2000); 
  

  stepper.setSpeed(100);
}


int readMoistureLevel() {
  return Grove.moistureRead(MOISTURE_SENSOR);
}


void controlValve(int desiredFlowRate) {

  int steps = map(desiredFlowRate, 0, MAX_FLOW_RATE, 0, STEPS_PER_REVOLUTION);

  stepper.step(steps);
}


void displayFlowRate(int flowRate) {
  lcd.clear();
  lcd.print("Flow Rate: ");
  lcd.print(flowRate);
  lcd.print(" mL/min");
}

void loop() {

  int moistureLevel = readMoistureLevel();
  

  int desiredFlowRate = map(moistureLevel, 0, 1023, 0, MAX_FLOW_RATE);
  

  controlValve(desiredFlowRate);
  

  displayFlowRate(desiredFlowRate);
  
  delay(1000);
}

