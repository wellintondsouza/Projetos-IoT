// C++ code
//
void setup()
{
  
  pinMode(7,INPUT);
  pinMode(13,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop()
{
  int movimento = digitalRead (7);
    
    if (movimento) {
 digitalWrite(13,HIGH);
   delay(2000);
 digitalWrite(8,HIGH);
   
    }
      else {
   digitalWrite(13,LOW);
   delay(2000);
 digitalWrite(8,LOW);
   } 
}
