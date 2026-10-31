#define DATA 6
#define LATCH 8
#define CLOCK 10

void sendMax(byte reg, byte data)
{
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, reg);
  shiftOut(DATA, CLOCK, MSBFIRST, data);
  digitalWrite(LATCH, HIGH);
}

void setup()
{
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);

  sendMax(0x0F, 0x00);
  sendMax(0x09, 0x00);
  sendMax(0x0A, 0x07);
  sendMax(0x0B, 0x07);
  sendMax(0x0C, 0x01);
}

void loop()
{
  for (byte i = 1; i <= 8; i++)
  {
    byte rowPattern = (i % 2 != 0) ? B10101010 : ~B10101010;
    sendMax(i, rowPattern);
  }
  do {} while (1);
}
