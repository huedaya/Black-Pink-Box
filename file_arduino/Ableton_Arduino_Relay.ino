// created by kim 
// ready to go, just upload to arduino
// arduino mega PWM pins we will use with leds
int led[10]={2,3,4,5,6,7,8,9,10,11};
//cc midi messages three bytes
byte statusByte;
byte Note;
byte Velocity;
//cc midi message channel 1  1011 0000
byte ccmidi = 177;

void setup(){
  
  //test the leds
  //for(int i=0;i<2;i++){
   // pinMode(led[i],OUTPUT);
   // for(int j=0;j<255;j++){
      //digitalWrite(led[i],j);
   //   delay(1);
   //   }
      //digitalWrite(led[i],0);
    //}
  //start the serial into the boud rate of 115200
  Serial.begin(115200);

  
 //digitalWrite(2,HIGH);
    //        delay(100);
   //         digitalWrite(2,LOW);
}
void loop(){
  //waite for a midi message
  while(Serial.available() <3);
  //run the function that will control the leds
  readmidi();
  
  }
void readmidi(){
  
  do{
    //sheck if there is any message
    if (Serial.available()){
      //store the data into the variables 
      statusByte = Serial.read();
      Serial.print(statusByte);
      Note = Serial.read();
      Velocity = Serial.read(); 
      //check if the message is a cc midi message 
      if (statusByte>0){

        //controll the leds acording to the data bytes
        for(int i=2;i<=11;i++){
          // Note 0 == C-2
          if(Note == i-2) 
          {
            //digitalWrite(led[i],ControllerValue*2);
             
            pinMode(i,OUTPUT);
            
            if(Velocity > 80){
              digitalWrite(i,LOW);
            }else{
              digitalWrite(i,HIGH);
            }
            
            //delay(100);
          }else{
            
            
          }
        } 
      }
    }
  }
  //repeat until there is no message
  while (Serial.available() > 2);
}
