#define BUTTON1 A1
#define BUZZER_DIO 3
#define LED1_DIO 10
#define LED2_DIO 11
#define LED3_DIO 12
#define LED4_DIO 13

#define ON LOW
#define OFF HIGH

void setup() {
  pinMode(BUTTON1, INPUT);
  pinMode(BUZZER_DIO, OUTPUT);
  pinMode(LED1_DIO, OUTPUT);
  pinMode(LED2_DIO, OUTPUT);
  pinMode(LED3_DIO, OUTPUT);
  pinMode(LED4_DIO, OUTPUT);

  digitalWrite(BUZZER_DIO, OFF);
  digitalWrite(LED1_DIO, OFF);
  digitalWrite(LED2_DIO, OFF);
  digitalWrite(LED3_DIO, OFF);
  digitalWrite(LED4_DIO, OFF);

  Serial.begin(9600);
}

void loop() {
  char data = 0;
  if (Serial.available() > 0) {
    char value = Serial.read();
    if (value == 2) {
      digitalWrite(BUZZER_DIO, OFF);
      digitalWrite(LED1_DIO, OFF);
      digitalWrite(LED2_DIO, OFF);
      digitalWrite(LED3_DIO, OFF);
      digitalWrite(LED4_DIO, OFF);
    }
  }
  while (digitalRead(BUTTON1) == 0) {
    data = 0b0001;
    digitalWrite(BUZZER_DIO, ON);
      digitalWrite(LED1_DIO, ON);
      digitalWrite(LED2_DIO, ON);
      digitalWrite(LED3_DIO, ON);
      digitalWrite(LED4_DIO, ON);
  }
  if (data > 0) {
    Serial.write(data);
    }
}
