const int8_t incrementButton = D4;
const int8_t resetButton = D2;
const int8_t firstBit = D8;
const int8_t secondBit = D9;
const int8_t thirdBit = D10;
int8_t currentCount = 0;
bool bResetPrev = false;
bool bIncrementPrev = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, STM32!");
  pinMode(incrementButton, INPUT_PULLDOWN);
  pinMode(resetButton, INPUT_PULLDOWN);
  pinMode(firstBit, OUTPUT);
  pinMode(secondBit, OUTPUT);
  pinMode(thirdBit, OUTPUT);
  currentCount = 0;
  bResetPrev = false;
  bIncrementPrev = false;
}

void WriteBinary(const uint8_t toDisplay) 
{
  // Serial.print("To Display 3 bit status is as follows:");
  // Serial.println(toDisplay & (1 << 2));
  // Serial.println(toDisplay & (1 << 1));
  // Serial.println(toDisplay & (1 << 0));
  digitalWrite(firstBit, (toDisplay & (1 << 0)) != 0 ? HIGH : LOW);
  digitalWrite(secondBit, (toDisplay & (1 << 1)) != 0 ? HIGH : LOW);
  digitalWrite(thirdBit, (toDisplay & (1 << 2)) != 0 ? HIGH : LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation

  int incrementVal = digitalRead(incrementButton);
  int resetVal = digitalRead(resetButton);

  if (incrementVal != bIncrementPrev) 
  {
    bIncrementPrev = incrementVal;
    if (incrementVal == HIGH) 
    {
      currentCount += 1;
      if (currentCount > 7) 
      {
        currentCount = 0;
      }
      Serial.print("Incrementing Count, new count is ");
      Serial.print(currentCount);
      Serial.println(" after incrementing");
      WriteBinary(currentCount);
    }
  }

  if (resetVal != bResetPrev) 
  {
    bResetPrev = resetVal;
    if (resetVal == HIGH) 
    {
      currentCount = 0;
      Serial.print("Count has been reset to 0");
      WriteBinary(currentCount);
    }
  }
}
