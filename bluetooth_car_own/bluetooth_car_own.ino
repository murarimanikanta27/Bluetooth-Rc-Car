#include "BluetoothSerial.h"
int mr1 = 12; //connecting front rightmotor1 to 12th gpio pin
int mr2 = 14; //connecting front rightmotor2 to 14th gpio pin
int ml1 = 26;//connecting front leftmotor1 to 26th gpio pin
int ml2 = 27;//connecting front leftmotor2 to 27th gpio pin
int lf=15;//connectinh front light to 15th gpio pin
int lb=25;//connectinh front light to 25th gpio pin
char sentchar;
int i=0;
int j=0;
const int freq = 5000; // setting frequency for dc motors
//setting channels for each dc motor
const int Channel1 = 0;
const int Channel2 = 1;
const int Channel3 = 2;
const int Channel4 = 3;
const int resolution = 8;// settiong resolution dor dc motors
BluetoothSerial BT;// taking bluetooth serial as BT
 
void setup(){
  // configure LED PWM functionalitites
  ledcSetup(Channel1, freq, resolution);
  ledcSetup(Channel2, freq, resolution);
  ledcSetup(Channel3, freq, resolution);
  ledcSetup(Channel4, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(mr1,Channel1);
  ledcAttachPin(mr2,Channel2);
  ledcAttachPin(ml1,Channel3);
  ledcAttachPin(ml2,Channel4);
  Serial.begin(9600);
  BT.begin("BLUETOOTH CAR");
  pinMode(lf,OUTPUT);
  pinMode(lb,OUTPUT);
   digitalWrite(lf,LOW);
    digitalWrite(lb,LOW); 
}
void Forward(){  //Function to move forward
      ledcWrite(Channel1,180);
      ledcWrite(Channel2,0);
      ledcWrite(Channel3,255);
      ledcWrite(Channel4,0);
}
void Backward(){ // Function to move backward
      ledcWrite(Channel1,0);
      ledcWrite(Channel2,180);
      ledcWrite(Channel3,0);
      ledcWrite(Channel4,255);
}
void Left(){ //Function To move Left
      ledcWrite(Channel1,0);
      ledcWrite(Channel2,255);
      ledcWrite(Channel3,255);
      ledcWrite(Channel4,0);
}
void Right(){//Function To move right
      ledcWrite(Channel1,255);
      ledcWrite(Channel2,0);
      ledcWrite(Channel3,0);
      ledcWrite(Channel4,255);
}
void Stop(){ //Function To stop
      ledcWrite(Channel1,0);
      ledcWrite(Channel2,0);
      ledcWrite(Channel3,0);
      ledcWrite(Channel4,0);
      
}
void FrontRight()//Function To move frontright
{
      ledcWrite(Channel1,120);
      ledcWrite(Channel2,0);
      ledcWrite(Channel3,0);
      ledcWrite(Channel4,120);
      //delay(300);
      //Forward();
}
void FrontLeft()//Function To move frontLeft
{
      ledcWrite(Channel1,0);
      ledcWrite(Channel2,120);
      ledcWrite(Channel3,120);
      ledcWrite(Channel4,0);
      //delay(300);
      //Forward();
}
void BackRight()//Function To move backright
{
      ledcWrite(Channel1,0);
      ledcWrite(Channel2,120);
      ledcWrite(Channel3,120);
      ledcWrite(Channel4,0);
      //delay(300);
      //Backward();
}
void BackLeft()//Function To move backLeft
{
      ledcWrite(Channel1,120);
      ledcWrite(Channel2,0);
      ledcWrite(Channel3,0);
      ledcWrite(Channel4,120);
      //delay(300);
      //Backward();
}
void LightFrontON()//Function To on frontlight
{
  digitalWrite(lf,HIGH); 
}
void LightFrontOFF()//Function To off front light
{
  digitalWrite(lf,LOW); 
}
void LightBackON()//Function To on back light
{
   digitalWrite(lb,HIGH); 
}
void LightBackOFF()//Function To off back light
{
   digitalWrite(lb,LOW); 
}

void loop() {
   sentchar=(char)BT.read();

   if (Serial.available()) {
    BT.write(Serial.read());
  
  }
  if (BT.available()) {
     
    Serial.print ("Received:");//print on serial monitor
    Serial.println(sentchar);//print on serial monitor   
    
    if(sentchar == 'F')
    {
      

     Forward();
       
    }
    if(sentchar == 'G')
    {
 
      Backward(); 
    }         
     if(sentchar == 'L')
    {

      Left();
    }        
    if(sentchar == 'R')
    {

      Right(); 
    }
    if(sentchar == 'S')
    {
      Stop();
    }
    if(sentchar=='Q')
    {
       FrontLeft();
    }
    if(sentchar=='E')
    {
      FrontRight();
    }
    if(sentchar=='C')
    {
       BackRight();
    }
    if(sentchar=='Z')
    {
      BackLeft();
    }
    if(sentchar=='M')
    {
       
       if(i==0)
       {
         //Serial.println("on");
         LightFrontON();
         i=1;
       }
       else
       {
         //Serial.println("off");
          LightFrontOFF();
          i=0;
       }
       

    }
    if(sentchar=='N')
    {
       if(j==0)
       {
         j=1;
         LightBackON();
       }
       else
       {
         j=0;
         LightBackOFF();
       }
    }
   
  }
   delay(20);
  
}
