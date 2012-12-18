String serialDataIn;
String xString;
String yString;
int yVal;
int xVal;
int counter;

char inchar;
byte inbyte;

void setup(){
  Serial.begin(9600);
  counter = 0;
  serialDataIn = String("");
  pinMode(13,OUTPUT);
}

void loop()
{
 readSerialData();
 if (xVal > 895){
 digitalWrite(13,HIGH);
 }else{
 digitalWrite(13,LOW);
 }
   
}



String readSerialData()
{


serialDataIn="";
  if(Serial.available() >0){
    inbyte = Serial.read();
    inchar = char(inbyte);
    
    
    if (inchar == 'X'){
      while (inchar != '\n') {
        if(Serial.available() >0){
          inbyte=Serial.read();
          inchar = char(inbyte);
          serialDataIn += inchar;
        }
      }
      xString=serialDataIn;
      xVal=xString.toInt();
      Serial.println("x=" + serialDataIn);
      

    }
    else if (inchar == 'Y'){
      while (inchar != '\n') { 
        if(Serial.available() >0){
        inbyte=Serial.read();
        inchar = char(inbyte);
        serialDataIn += inchar;
        }
      }
      yString=String(serialDataIn);
        yVal=yString.toInt();
      Serial.println("y=" + yString);



    }
  }

}


