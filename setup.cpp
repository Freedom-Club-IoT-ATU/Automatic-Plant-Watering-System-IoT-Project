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