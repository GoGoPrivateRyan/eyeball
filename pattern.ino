#include "Arduino.h"

void pattern1()
{
  posP = 1000;
  posB = 1500;
  
  servoP.writeMicroseconds(posP);
  servoB.writeMicroseconds(posB);
  delay(15);

  //Serial.println("pattern1");

  // 眼皮: 
  //   - 閉 -> 半開, 慢慢張開
  while (posP <= 1500)
  {
    //Serial.print("P: C->M ");
    //Serial.println(posP);
    servoP.writeMicroseconds(posP);  
    posP += 50;
    delay(100);
  }

  // 眼球: 
  //   - 中 -> 右, 慢慢轉
  //   - 右 -> 左, 快轉
  //   - 左 -> 中, 慢慢轉
  while (posB <= 2000)
  {
    //Serial.print("B: M->R ");
    //Serial.println(posB);
    servoB.writeMicroseconds(posB);  
    posB += 50;
    delay(100);
  }  

  while (posB >= 1000)
  {
    //Serial.print("B: R->L ");
    //Serial.println(posB);
    servoB.writeMicroseconds(posB);  
    posB -= 150;
    delay(30);
  }  

  while (posB <= 1500)
  {
    //Serial.print("B: L->M ");
    //Serial.println(posB);
    servoB.writeMicroseconds(posB);  
    posB += 50;
    delay(100);
  } 

  // 眼皮: 
  //   - 半開 -> 全開, 慢慢張開
  //   - 全開 -> 閉, 快快閉
  //   - 閉 -> 全開, 快快開
  while (posP <= 2000)
  {
    //Serial.print("P: M->F ");
    //Serial.println(posP);
    servoP.writeMicroseconds(posP);  
    posP += 50;
    delay(100);
  }  

  while (posP >= 1000)
  {
    //Serial.print("P: F->C ");
    //Serial.println(posP);
    servoP.writeMicroseconds(posP);  
    posP -= 150;
    delay(30);
  } 

  while (posP <= 2000)
  {
    //Serial.print("P: C->F ");
    //Serial.println(posP);
    servoP.writeMicroseconds(posP);  
    posP += 150;
    delay(30);
  }   

  delay(1000);
}

void pattern2()
{
  // 眼皮: 
  //   - 閉 -> +半開, 慢慢張開
  //   - +半開 -> 閉, 瞬閉
  //   - 重覆 3 遍

  posP = 1000;

  for (int i=0; i<3; i++)
  {
    while (posP <= 1800)
    {
      servoP.writeMicroseconds(posP);  
      posP += 50;
      delay(100);
    }  
    servoP.writeMicroseconds(1000);
    delay(100);
  }

  delay(1000);
}

void pattern3()
{
  // 眼皮: 
  //   - 閉 -> 全開, 瞬開
  // 眼球
  //   - 中+ -> 左 -> 右, 瞬轉
  // 眼皮:
  //   - 全開 -> -半閉, 瞬閉
  //   - 重覆 2 遍

  servoP.writeMicroseconds(1000);  
  servoB.writeMicroseconds(1800);  
  delay(15);

  servoP.writeMicroseconds(2000);  
  servoB.writeMicroseconds(1000);  
  delay(15);
  servoB.writeMicroseconds(2000);  

  for (int i=0; i<2; i++)
  {
    servoP.writeMicroseconds(1200);
    delay(15);  
    servoP.writeMicroseconds(2000);
    delay(15);
  }
  
  delay(1000);  
}
