#include <Servo.h> 

#define PIN_P 2   // 眼皮
#define PIN_B 3   // 眼球

Servo servoP, servoB;
int posP, posB;
long randNumber;
              
// 眼皮: 
//   - 1000: 閉眼
//   - 1500: 半開
//   - 2000: 全開
// 眼球:
//   - 1000: 左
//   - 1500: 中
//   - 2000: 右

void setup() 
{ 
  Serial.begin(9600);

  randomSeed(analogRead(0));
  
  servoP.attach(PIN_P);
  servoB.attach(PIN_B);
  
  posP = posB = 1500;

  servoP.writeMicroseconds(posP);  
  servoB.writeMicroseconds(posB);
  delay(15);  
} 
 
void loop() 
{ 
  randNumber = random(0, 3);
  
  if (randNumber <= 1)
    pattern1();
  else if (randNumber > 1 && randNumber <= 2)
    pattern2();
  else
    pattern3();
} 

