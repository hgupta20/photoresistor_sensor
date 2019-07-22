
// Get your photoresistor wired correctly and have the "value" read from the photoresistor output to the
// serial monitor of the arduino software.

#include <LiquidCrystal.h>

// use the LiquidCrystal and initialize all the pins according to your circuit
// pin 12: RS
// pin 11: Enable
// pin 5: D4
// pin 4: D5
// pin 3: D6
// pin 2: D7
LiquidCrystal lcd (12,11,5,4,3,2);


// Initialize all the variables like scroll Cursor, to read the photocellvalue and photoCell pin 
int scrollCursor = 16; // since it is the screen width
int pCellReading;
int pCelldata = 0; // the data pin through which the audrino would read the data


// to display the value of the photocell
String value;

void setup() {
  Serial.begin(9600); // to communicate with the computer and display data to the serial monitor
  lcd.begin(16,2); // start the lcd 
  
}

void loop() {


  pCellReading = analogRead (pCelldata); // read the data and set the reading
  Serial.println(pCellReading); // print the reading on the serial monitor
  
  // compare the reading and brightness according to the range provided
  if (pCellReading < 40) {
    value = "Dark";
  }
  // other wise partially dark
  else if (pCellReading < 200) {
    value = "Parially Dark";
  }
  // other wise Medium
  else if (pCellReading < 500) {
    value = "Medium";
  }
  // other wise partially light
  else if (pCellReading < 800) {
    value = "partially light";
  }
  // other wise fully lit
  else if (pCellReading > 800) {
    value = "fully lit";
  }
  else {
    value = "Undefined"; // I dont think this would ever be the case
  }
  
  // To display the first row of LCD display
  lcd.setCursor(0,0);
  lcd.print("Brightness: ");
  lcd.print(pCellReading);
  
  // display the second row of LCD display
  lcd.setCursor(0, 1);
  lcd.print(value); 
  delay(100);  

  //clear screen
  lcd.clear();  
  
}
