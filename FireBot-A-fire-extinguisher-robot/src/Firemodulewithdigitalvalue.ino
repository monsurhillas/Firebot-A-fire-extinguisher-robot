
//Defining section 

#define leftMotF 7
#define leftMotB 6
#define leftMotRPM 3
#define rightMotF 4
#define rightMotB 2
#define rightMotRPM 5
#define fiveV 8
#define Gnd 9
#define wpumpF 12
#define wpumpB 11
#define wpumpRPM 10 



int flame_sensorOne = A5;
int flame_sensorTwo = A4;
int flame_sensorThree = A3;
int flame_sensorFour= A2;
int flame_sensorFive = A1;
int defaultSpeed = 80;
int baseSpeed = 60;
int turnSpeed = 80;
int pumpSpeed = 255;

float one,two,three,four,five ;
bool straight=false;

void setup() {
  Serial.begin(9600);
  pinMode(flame_sensorOne, INPUT);
  pinMode(flame_sensorTwo, INPUT);
  pinMode(flame_sensorThree,INPUT);
  pinMode(flame_sensorFour,INPUT);
  pinMode(flame_sensorFive,INPUT);
  pinMode(leftMotF,OUTPUT);
  pinMode(leftMotB,OUTPUT);
  pinMode(leftMotRPM,OUTPUT);
  pinMode(rightMotF,OUTPUT);
  pinMode(rightMotB,OUTPUT);
  pinMode(rightMotRPM,OUTPUT);
  pinMode(fiveV,OUTPUT);
  pinMode(Gnd,OUTPUT);
  pinMode(wpumpF,OUTPUT);
  pinMode(wpumpB,OUTPUT);
  pinMode(wpumpRPM,OUTPUT);

  digitalWrite(fiveV,HIGH);
  digitalWrite(Gnd,LOW);
  digitalWrite(wpump,HIGH);
  
  
  Stop();

}



void front()
{
  digitalWrite(leftMotF,HIGH);
  digitalWrite(leftMotB,LOW);
  analogWrite(leftMotRPM,defaultSpeed);
  digitalWrite(rightMotF,HIGH);
  digitalWrite(rightMotB,LOW);
  analogWrite(rightMotRPM,defaultSpeed);
}

void back()
{
  digitalWrite(leftMotF,LOW);
  digitalWrite(leftMotB,HIGH);
  analogWrite(leftMotRPM,defaultSpeed);
  digitalWrite(rightMotF,LOW);
  digitalWrite(rightMotB,HIGH);
  analogWrite(rightMotRPM,defaultSpeed);
}

void leftTurn()
{
  digitalWrite(leftMotF,HIGH);
  digitalWrite(leftMotB,LOW);
  digitalWrite(rightMotF,LOW);
  digitalWrite(rightMotB,HIGH);
  digitalWrite(rightMotRPM,turnSpeed);
  digitalWrite(leftMotRPM,turnSpeed);
}

void rightTurn()
{
  digitalWrite(leftMotF,LOW);
  digitalWrite(leftMotB,HIGH);
  digitalWrite(rightMotF,HIGH);
  digitalWrite(rightMotB,LOW);
  digitalWrite(rightMotRPM,turnSpeed);
  digitalWrite(leftMotRPM,turnSpeed);
}
void Stop()
{
  digitalWrite(leftMotF,LOW);
  digitalWrite(leftMotB,LOW);
  digitalWrite(rightMotF,LOW);
  digitalWrite(rightMotB,LOW);
  digitalWrite(rightMotRPM,defaultSpeed);
  digitalWrite(leftMotRPM,defaultSpeed);
}


 
 

void loop() {
  // put your main code here, to run repeatedly:
  

   one = analogRead(flame_sensorOne) ;
  two = analogRead(flame_sensorTwo);
  three = analogRead(flame_sensorThree);
  four = analogRead(flame_sensorFour);
  five = analogRead(flame_sensorFive);


  Serial.print("One : ");
  Serial.print(one);
  Serial.print(" || Two : ");
  Serial.print(two);
  Serial.print(" || Three : ");
  Serial.print(three);
  Serial.print(" || Four : ");
  Serial.print(four);
  Serial.print(" || Five : ");
  Serial.println(five); 

  
 

/* ( if (one == 1||two ==1 || three==1 ||four==1 || five ==1)
  {
    Serial.println("Flame Detected");
    back();
  }
  else 
  {
    Serial.println("No flame detected");
  }*/

if(one<=200 && two <=200 && three <=200 && four <=200 && five<=200)
  {
    digitalWrite(wpumpF,LOW);
    digitalWrite(wpumpB,HIGH);
    digitalWrite(wpumpRPM,pumpSpeed);
    Stop();
    Serial.println(" ON STOP");
  }
  else if(one>200 && two>200 && three>200 && four>200 && five>200)
  {
    digitalWrite(wpumpF,HIGH);
    digitalWrite(wpumpB,LOW);
    digitalWrite(wpumpRPM,pumpSpeed);
    Stop();
    
    
    Serial.println(" ON STOP");
  }
 else 
 {
    digitalWrite(wpumpF,LOW);
    digitalWrite(wpumpB,HIGH);
    digitalWrite(wpumpRPM,pumpSpeed);
  
    if(two>200 || three>200)
    {
    front();
    Serial.println(" ON FRONT ");
    }
    if (five>200 || four>200) leftTurn();
    if(one>200 ||two>200) rightTurn();
    
      if(one>200 && five<=200 && four<=200 && three>200 && two >200)
      {
        rightTurn();
        Serial.println(" ON RIGHT ");
      }
      else if(one>200 && five<=200&& four<=200 && three <=200 && two >200)
      {
        rightTurn();
        Serial.println(" ON RIGHT ");
      }
      
      
      else if(five>200 && one<=200 && four>200 && three >200 && two <=200)
      {
        leftTurn();
        Serial.println(" ON LEFT ");
      }
       else if(five>200 && one<=200 && four >200 && three <=200 && two<=200)
      {
        leftTurn();
        Serial.println(" ON LEFT ");
      }
      else Stop();
  }

} 
