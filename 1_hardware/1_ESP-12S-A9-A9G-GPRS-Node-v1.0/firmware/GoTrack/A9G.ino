// All the functions interacting with the A9G module
SoftwareSerial swSer(A9G_RXPIN, A9G_TXPIN);

ICACHE_RAM_ATTR void handleInterrupt() {
  Serial.println("An interrupt has occurred.");
}

// A9G functions
int A9GPOWERON()
{
  digitalWrite(A9G_PON, LOW);
  delay(3000);
  digitalWrite(A9G_PON, HIGH);
  delay(5000);
  String msg = String("");
  msg = sendData("AT", 1000, DEBUG);
  if ( msg.indexOf("OK") >= 0 ) {
    Serial.println("GET OK");
    return 1;
  }
  else {
    Serial.println("NOT GET OK");
    return 0;
  }
}

int A9GPOWEROFF()
{
  digitalWrite(A9G_POFF, HIGH);
  delay(3000);
  digitalWrite(A9G_POFF, LOW);
  delay(5000);
  String msg = String("");
  msg = sendData("AT", 1000, DEBUG);
  if ( msg.indexOf("OK") >= 0 ) {
    Serial.println("GET OK");
    return 1;
  }
  else {
    Serial.println("NOT GET OK");
    return 0;
  }
}

int A9GENTERLOWPOWER()
{
  String msg = String("");
  msg = sendData("AT+SLEEP=1", 1000, DEBUG);
  if ( msg.indexOf("OK") >= 0 ) {
    digitalWrite(A9G_LOWP, LOW);
    return 1;
  }
  else {
    return 0;
  }
}

String sendData(String command, const int timeout, boolean debug)
{
  String response = "";
  swSer.println(command);
  long int time = millis();
  while ( (time + timeout) > millis())
  {
    while (swSer.available())
    {
      char c = swSer.read();
      response += c;
    }
  }
  if (debug)
  {
    Serial.print(response);
  }
  return response;
}

void SendTextMessage(String message, String phonenum)
{
  // sendData("AT+CMGF=1",1000,DEBUG);            //Set the SMS in text mode

  String ATCMD = "AT+CMGS=";
  String cammand = ATCMD + "\"" + phonenum + "\"";
  // Serial.println(cammand);
  //  sendData(cammand,1000,DEBUG);
  // sendData(message,1000,DEBUG);                //the content of the message
  swSer.println("AT+CMGF=1");
  swSer.println(cammand);
  swSer.println(message);
  swSer.write(26);

}
