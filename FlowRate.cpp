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