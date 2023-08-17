#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int tempPin = A0;
int gasPin = A1;
int fan = 7;
float cel;
float hum;
float gas;

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(fan, OUTPUT);
  digitalWrite(fan, LOW);
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gas Sensor:");
  lcd.setCursor(0, 1);
  lcd.print("Fan Status:");
}

void loop()
{
  cel = analogRead(tempPin) * 0.48875; // Convert to Celsius
  hum = analogRead(A2) * 0.0977;      // Convert to percentage
  gas = analogRead(gasPin) / 100.0;   // Normalize gas value

  lcd.setCursor(12, 0);
  lcd.print(cel, 1);
  lcd.setCursor(10, 1);
  lcd.print(hum, 1);

  lcd.setCursor(11, 0);
  lcd.print(gas, 2);

  lcd.setCursor(11, 1);
  if (cel > 30.0)
  {
    digitalWrite(fan, HIGH);
    lcd.print("ON ");
  }
  else
  {
    digitalWrite(fan, LOW);
    lcd.print("OFF");
  }

  delay(2000);
}
