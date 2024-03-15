#include <Stepper.h>
#include <LiquidCrystal_RGB.h>
#include <Wire.h>
#include <Grove.h>

// Define pin numbers for components (assuming Grove shield)
#define STEPPER_PIN1 8
#define STEPPER_PIN2 9
#define STEPPER_PIN3 10
#define STEPPER_PIN4 11
#define MOISTURE_SENSOR A0

// Define constants
#define STEPS_PER_REVOLUTION 200
#define MAX_FLOW_RATE 100 // Maximum flow rate in mL/min

// Initialize the stepper motor with the number of steps and pins
Stepper stepper(STEPS_PER_REVOLUTION, STEPPER_PIN1, STEPPER_PIN2, STEPPER_PIN3, STEPPER_PIN4);
LiquidCrystal_RGB lcd(12, 11, 5, 4, 3, 2); // LCD pins for Grove shield

void setup() {
  // Set up the LCD display
  lcd.begin(16, 2);
  lcd.setRGB(255, 255, 255); // Set backlight color to white
  lcd.print("Automatic Plant");
  lcd.setCursor(0, 1);
  lcd.print("Watering System");
  delay(2000); // Delay for 2 seconds
  
  // Set up the stepper motor
  stepper.setSpeed(100); // Set initial speed
}

// Read moisture level function (using Grove Moisture Sensor)
int readMoistureLevel() {
  return Grove.moistureRead(MOISTURE_SENSOR);
}

// Control valve function
void controlValve(int desiredFlowRate) {
  // Calculate the number of steps for the stepper motor based on desired flow rate
  int steps = map(desiredFlowRate, 0, MAX_FLOW_RATE, 0, STEPS_PER_REVOLUTION);
  // Rotate the stepper motor to adjust the valve
  stepper.step(steps);
}

// Display flow rate function
void displayFlowRate(int flowRate) {
  lcd.clear();
  lcd.print("Flow Rate: ");
  lcd.print(flowRate);
  lcd.print(" mL/min");
}

void loop() {
  // Read moisture level from the soil
  int moistureLevel = readMoistureLevel();
  
  // Calculate desired flow rate based on moisture level (example logic)
  int desiredFlowRate = map(moistureLevel, 0, 1023, 0, MAX_FLOW_RATE);
  
  // Control the valve to adjust the flow rate
  controlValve(desiredFlowRate);
  
  // Display the current flow rate on the LCD display
  displayFlowRate(desiredFlowRate);
  
  delay(1000); // Delay for 1 second (adjust as needed)
}

