// motor one
int enA = 3; //right
int in1 = 6;
int in2 = 4;
// motor two
int enB = 5; //left
int in3 = 1;
int in4 = 2;

int D1 = 7;
int D2 = 8;
int D3 = 9;
int D4 = 10;
int D5 = 11;
int D6 = 12;
float kp=1.4;
float kd=0.32;
int lerror=0;
int error=0;
int RS,LS;
void setup()                    // run once, when the sketch starts
{
 Serial.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor
 pinMode(enA, OUTPUT);
 pinMode(enB, OUTPUT);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);

 pinMode(D1, INPUT);
 pinMode(D2, INPUT);
 pinMode(D3, INPUT);
 pinMode(D4, INPUT);
 pinMode(D5, INPUT);
 pinMode(D6, INPUT);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW); 
 delay(1000);
}



void loop() 
{
  int detect1 = digitalRead(D1);
  int detect2 = digitalRead(D2);
  int detect3 = digitalRead(D3);
  int detect4 = digitalRead(D4);
  int detect5 = digitalRead(D5);
  int detect6 = digitalRead(D6);
  //int detect7 = digitalRead(D7);
 
  int pos=0;
  detect1=1-detect1;
  detect2=1-detect2;
  detect3=1-detect3;
  detect4=1-detect4;
  detect5=1-detect5;
  detect6=1-detect6;
  if(!(detect1 == 0 && detect2 == 0 && detect3 == 0 && detect4 == 0 && detect5 == 0 && detect6 == 0))
  {
    Serial.print("If");
    pos=(0*detect1+100*detect2+200*detect3+300*detect4+400*detect5+500*detect6)/(detect1+detect2+detect3+detect4+detect5+detect6);
  error=pos-250;
  float change= kp* error - kd*(error-lerror);
  lerror=error;
   RS=255 + (int)change;
   LS=255 - (int)change;
 Serial.println(error);
  if(RS>255) RS=255;
  if(LS>255) LS=255;
  if(RS<0) RS=0;
  if(LS<0) LS=0;
   LS*=0.4;
   RS*=0.4;
   
   RS*=0.6;
  analogWrite(enA, RS);
  analogWrite(enB, LS);
  }
  else 
  {
    float change;
  if(lerror>0)
    {
     change=255;
      }
  else
    {
    change=-255;
      }
    RS=255 + (int)change;
   LS=255 - (int)change;
 Serial.println(error);
  if(RS>255) RS=255;
  if(LS>255) LS=255;
  if(RS<0) RS=0;
  if(LS<0) LS=0;
   LS*=0.4;
   RS*=0.4;
   
   RS*=0.6;
  analogWrite(enA, RS);
  analogWrite(enB, LS);
  }
}
