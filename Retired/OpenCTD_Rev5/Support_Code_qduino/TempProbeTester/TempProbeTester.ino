#include <OneWire.h> //Temperature
#include <DallasTemperature.h> //Temperature

float tempA; //Temperature
float tempB; //Temperature
float tempC; //Temperature
float tempD; //Temperature
float tempE; //Temperature
float tempF; //Temperature
float tempG; //Temperature
float tempH; //Temperature
float tempI; //Temperature
float tempJ; //Temperature
float tempK; //Temperature
float tempL; //Temperature
float tempM; //Temperature
float tempN; //Temperature
float tempO; //Temperature
float tempP; //Temperature
float tempQ; //Temperature
float tempR; //Temperature
float tempS; //Temperature
float tempT; //Temperature
float tempU; //Temperature
float tempV; //Temperature
float tempW; //Temperature
float tempX; //Temperature
float tempY; //Temperature
float tempZ; //Temperature


#define ONE_WIRE_BUS 3 //Temperature
OneWire oneWire(ONE_WIRE_BUS); //Temperature
DallasTemperature sensors(&oneWire); //Temperature

void setup(void)
{
  Serial.begin(9600);

  sensors.begin(); //Temperature
}

void loop(void)
{ 

  sensors.requestTemperatures();  //Temperature
  
  tempA = sensors.getTempCByIndex(0); //Temperature
  tempB = sensors.getTempCByIndex(1); //Temperature
  tempC = sensors.getTempCByIndex(2); //Temperature
  tempD = sensors.getTempCByIndex(3); //Temperature
  tempE = sensors.getTempCByIndex(4); //Temperature
  tempF = sensors.getTempCByIndex(5); //Temperature
  tempG = sensors.getTempCByIndex(6); //Temperature
  tempH = sensors.getTempCByIndex(7); //Temperature
  tempI = sensors.getTempCByIndex(8); //Temperature
  tempJ = sensors.getTempCByIndex(9); //Temperature
  tempK = sensors.getTempCByIndex(10); //Temperature
  tempL = sensors.getTempCByIndex(11); //Temperature
  tempM = sensors.getTempCByIndex(12); //Temperature
  tempN = sensors.getTempCByIndex(13); //Temperature
  tempO = sensors.getTempCByIndex(14); //Temperature
  tempP = sensors.getTempCByIndex(15); //Temperature
  tempQ = sensors.getTempCByIndex(16); //Temperature
  tempR = sensors.getTempCByIndex(17); //Temperature
  tempS = sensors.getTempCByIndex(18); //Temperature
  tempT = sensors.getTempCByIndex(19); //Temperature
  tempU = sensors.getTempCByIndex(20); //Temperature
  tempV = sensors.getTempCByIndex(21); //Temperature
  tempW = sensors.getTempCByIndex(22); //Temperature
  tempX = sensors.getTempCByIndex(23); //Temperature
  tempY = sensors.getTempCByIndex(24); //Temperature
  tempZ = sensors.getTempCByIndex(25); //Temperature
  
  Serial.print(tempA); //Temperature
  Serial.print("  "); //Temperature
  Serial.print(tempB);  //Temperature
  Serial.print("  "); //Temperature
  Serial.print(tempC); //Temperature
  Serial.print("  "); //Temperature
  Serial.println(tempD); //Temperature
  Serial.print(tempE); //Temperature
  Serial.print("  "); //Temperature
  Serial.print(tempF);  //Temperature
  Serial.print("  "); //Temperature
  Serial.print(tempG); //Temperature
  Serial.print("  "); //Temperature
  Serial.println(tempH); //Temperature
  Serial.print(tempI); //Temperature
  Serial.print("  "); //Temperature
  Serial.print(tempJ);  //Temperature
  Serial.print("  "); //Temperature
  Serial.print(tempK); //Temperature
  Serial.print("  "); //Temperature
  Serial.println(tempL); //Temperature
  Serial.print(tempM); //Temperature
  Serial.print("  "); //Temperature
  Serial.print(tempN);  //Temperature
  Serial.print("  "); //Temperature
  Serial.print(tempO); //Temperature
  Serial.print("  "); //Temperature
  Serial.println(tempP); //Temperature
  Serial.print(tempQ); //Temperature
  Serial.print("  "); //Temperature
  Serial.print(tempR);  //Temperature
  Serial.print("  "); //Temperature
  Serial.print(tempS); //Temperature
  Serial.print("  "); //Temperature
  Serial.println(tempT); //Temperature
  Serial.print(tempU); //Temperature
  Serial.print("  "); //Temperature
  Serial.print(tempV);  //Temperature
  Serial.print("  "); //Temperature
  Serial.print(tempW); //Temperature
  Serial.print("  "); //Temperature
  Serial.println(tempX); //Temperature
  Serial.print(tempY); //Temperature
  Serial.print("  "); //Temperature
  Serial.println(tempZ); //Temperature
  Serial.println("End of readings");

  delay(1000);
}
