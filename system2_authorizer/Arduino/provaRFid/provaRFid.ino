#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>

#define RST_PIN 9
#define SS_PIN  10

MFRC522 mfrc522(SS_PIN, RST_PIN);
String MasterTag = "AB C5 11 1C"; // Enter you tag UID which we get it from first code. 

String UIDCard = "";

char data[12];

#define BlueLED  2
#define GreenLED 3
#define RedLED 4

#define Buzzer 5


SoftwareSerial mySerial(8,7); //RX,TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);

  SPI.begin();
  mfrc522.PCD_Init();



  pinMode(GreenLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
  pinMode(RedLED, OUTPUT);

  pinMode(Buzzer, OUTPUT);

  digitalWrite(BlueLED, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(BlueLED, HIGH);
  digitalWrite(RedLED, LOW);
  digitalWrite(GreenLED, LOW);
  noTone(Buzzer);

  //Wait until new tag is available
  while (getUID())
  {
    //Serial.print("UID: ");
    //Serial.println(UIDCard);
    

    if (UIDCard == MasterTag)
    {
      digitalWrite(GreenLED, HIGH);
      digitalWrite(BlueLED, LOW);
      digitalWrite(RedLED, LOW);

      UIDCard.toCharArray(data,12);
      for(int i=0;i<12;i++){
        mySerial.write(data[i]);
        Serial.write(data[i]);
        //delay(1000);
      }
      //mySerial.write(data);
      //Serial.write(data);


      delay(50);
      for (int i = 0; i < 2; i++) {
        tone(Buzzer, 2000);
        delay(250);
        noTone(Buzzer);
        delay(250);
      }
      delay(500);
    }
    else
    {
      digitalWrite(BlueLED, LOW);
      digitalWrite(GreenLED, LOW);
      tone(Buzzer, 2000);

      for(int i = 0; i < 10;i++){
        digitalWrite(RedLED, HIGH);
        delay(250);
        digitalWrite(RedLED, LOW);
        delay(250);
      }
      noTone(Buzzer);
    }

    delay(2000);

  }
}
boolean getUID()
{
  if (! mfrc522.PICC_IsNewCardPresent()) {
    //Serial.println("card Not found");
    return false;
  }

  if (! mfrc522.PICC_ReadCardSerial()) {
    //Serial.println("Not able to read the card");
    return false;
  }
  UIDCard = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    UIDCard.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    UIDCard.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  UIDCard.toUpperCase();
  UIDCard = UIDCard.substring(1);

  mfrc522.PICC_HaltA();
  return true;
}