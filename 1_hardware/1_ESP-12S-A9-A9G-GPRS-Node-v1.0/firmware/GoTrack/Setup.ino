void setup()
{
  Serial.begin(BAUD_RATE);
  Serial.println("System started");

  // Start the A9G module (GPS, GPRS)
  swSer.begin(A9_BAUD_RATE);
  for (char ch = ' '; ch <= 'z'; ch++) {
    swSer.write(ch);
  }
  swSer.println("");

  pinMode(A9G_PON, OUTPUT);//LOW LEVEL ACTIVE
  pinMode(A9G_POFF, OUTPUT);//HIGH LEVEL ACTIVE
  pinMode(A9G_LOWP, OUTPUT);//LOW LEVEL ACTIVE

  digitalWrite(A9G_PON, HIGH);
  digitalWrite(A9G_POFF, LOW);
  digitalWrite(A9G_LOWP, HIGH);

  Serial.println("After 2s A9G will POWER ON.");
  delay(2000);

  if (A9GPOWERON() == 1)
    Serial.println("A9G POWER ON.");

  Serial.println("Enable the GPS");
  sendData("AT+GPS=1", 1000, DEBUG);
  pinMode(A9G_WAKE, INPUT);//interruptPin
  attachInterrupt(digitalPinToInterrupt(A9G_WAKE), handleInterrupt, RISING);

  // Everything else
  Scheduler.start(&gps_task);
  Scheduler.start(&sensors_task);
  Scheduler.start(&sms_task);
  Scheduler.start(&gprs_task);
  Scheduler.begin();
}
