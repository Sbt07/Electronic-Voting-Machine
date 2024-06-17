#include <LiquidCrystal.h> //library for including lcd display
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //adressing lcd via pins (in variable format)

#define sw1 15 // defining switch1 as pin 15 (A1) on arduino 
#define sw2 16 // defining switch1 as pin 15 (A2) on arduino 
#define sw3 17 // defining switch1 as pin 15 (A3) on arduino 
#define resultButton 14 // defining switch1 as pin 15 (A0) on arduino 

int vote1 = 0;
int vote2 = 0;
int vote3 = 0;

void setup()
{
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(resultButton, INPUT_PULLUP); // Using internal pull-up resistor for the result button

  lcd.begin(16, 2);
  lcd.print("Voting Machine");
  lcd.setCursor(0, 1);
  lcd.print("ESD Lab");
  delay(3000);

  digitalWrite(sw1, HIGH);
  digitalWrite(sw2, HIGH);
  digitalWrite(sw3, HIGH);
  digitalWrite(resultButton, HIGH);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BJP");
  lcd.setCursor(4, 0);
  lcd.print("INC");
  lcd.setCursor(8, 0);
  lcd.print("AAP");
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("BJP");
  lcd.setCursor(1, 1);
  lcd.print(vote1);
  lcd.setCursor(4, 0);
  lcd.print("INC");
  lcd.setCursor(5, 1);
  lcd.print(vote2);
  lcd.setCursor(8, 0);
  lcd.print("AAP");
  lcd.setCursor(9, 1);
  lcd.print(vote3);

  if (digitalRead(sw1) == 0)
  {
    vote1++;
    while (digitalRead(sw1) == 0)
      ;
  }

  if (digitalRead(sw2) == 0)
  {
    vote2++;
    while (digitalRead(sw2) == 0)
      ;
  }

  if (digitalRead(sw3) == 0)
  {
    vote3++;
    while (digitalRead(sw3) == 0)
      ;
  }

  if (digitalRead(resultButton) == LOW) // Check if result button is pressed
  {
    int totalVotes = vote1 + vote2 + vote3;

    if (totalVotes > 0)
    {
      if (vote1 > vote2 && vote1 > vote3)
      {
        lcd.clear();
        lcd.print("BJP Wins");
        delay(2000);
        lcd.clear();
      }
      else if (vote2 > vote1 && vote2 > vote3)
      {
        lcd.clear();
        lcd.print("INC Wins");
        delay(2000);
        lcd.clear();
      }
      else if (vote3 > vote1 && vote3 > vote2)
      {
        lcd.clear();
        lcd.print("AAP Wins");
        delay(2000);
        lcd.clear();
      }
      else
      {
        lcd.clear();
        lcd.print("Tie Up or No Result");
        delay(2000);
        lcd.clear();
      }
    }
    else
    {
      lcd.clear();
      lcd.print("No Voting Done");
      delay(2000);
      lcd.clear();
    }

    vote1 = 0;
    vote2 = 0;
    vote3 = 0;
    lcd.clear();
  }
}
