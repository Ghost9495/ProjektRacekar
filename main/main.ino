const int STEERING_DOUT = 9;
const int THROTTLE_DOUT = 10;

String incomingString;
String tempValue;
int steeringValue = 0;
int throttleValue = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    // read the incoming string:
    incomingString = Serial.readString();

    tempValue = getValue(incomingString, ';', 0);
    steeringValue = tempValue.toInt();

    tempValue = getValue(incomingString, ';', 1);
    throttleValue = tempValue.toInt();

    analogWrite(STEERING_DOUT, steeringValue);
    analogWrite(THROTTLE_DOUT, throttleValue);
  }
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++)
  {
    if (data.charAt(i) == separator || i == maxIndex)
    {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
