void loop() {
  // Read moisture level from the soil
  int moistureLevel = readMoistureLevel();
  
  // Calculate desired flow rate based on moisture level
  int desiredFlowRate = map(moistureLevel, 0, 1023, 0, MAX_FLOW_RATE); //calculations to be adjusted based on tests to be completed
  
  // Control the valve to adjust the flow rate
  controlValve(desiredFlowRate);
  
  // Display the current flow rate on the LCD display
  displayFlowRate(desiredFlowRate);
  
  delay(1000); // Delay for 1 second 
}