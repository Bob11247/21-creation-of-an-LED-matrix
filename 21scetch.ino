#define DATA 6
#define LATCH 8
#define CLOCK 10

void setup()
{
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
}

void loop()
{
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, ~B10101010);
  shiftOut(DATA, CLOCK, MSBFIRST, B10101010);
  digitalWrite(LATCH, HIGH);
  do {} while (1);
}
