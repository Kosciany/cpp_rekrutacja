// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 8
#define WIATRAK 6
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
char komenda;
/*
   The setup function. We only start the sensors here
*/
void setup(void)
{
  // start serial port
  Serial.begin(9600);
  // Start up the library
  sensors.begin();
  pinMode(WIATRAK,OUTPUT);
}

/*
   Main function, get and show the temperature
*/
void loop(void)
{
  if (Serial.available())
  {
    komenda = Serial.read();
    if (komenda == 't')
    { // call sensors.requestTemperatures() to issue a global temperature
      // request to all devices on the bu
      sensors.requestTemperatures(); // Send the command to get temperatures
      // After we got the temperatures, we can print them here.
      // We use the function ByIndex, and as an example get the temperature from the first sensor only.
      Serial.print('(');
      Serial.print(String(sensors.getTempCByIndex(0)));
      Serial.print(')');
    }
    else if (komenda == 'n')
    {
     digitalWrite(WIATRAK, HIGH);
     Serial.print('k');
    }
    else if (komenda == 'f')
    {
     digitalWrite(WIATRAK, LOW);
     Serial.print('k');
    }
    else Serial.print('!');
  }

}
