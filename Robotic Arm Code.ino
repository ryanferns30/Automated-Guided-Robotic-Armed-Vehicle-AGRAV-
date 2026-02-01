// Green WIRE RX  ON HC05 TO TX PIN NO-1 ON ARDUINO
// Yellow WIRE TX ON HC05 TO RX PIN NO-0 ON ARDUINO
// A4 is led 

// CAR START
#include <AFMotor.h>
#include <Servo.h>    //add Servo Motor library
#include <NewPing.h>  //add Ultrasonic sensor library

#define TRIG_PIN A0  // Pin A0 on the Motor Drive Shield soldered to the ultrasonic sensor
#define ECHO_PIN A1  // Pin A1 on the Motor Drive Shield soldered to the ultrasonic sensor


int leftir = A2;       //A2 PIN
int rightir = A3;      //A3 PIN
#define horn_Buzz 2    //WHITE WIRE
AF_DCMotor motor1(1);  // M1 on Motor Shield
AF_DCMotor motor2(2);  // M2
AF_DCMotor motor3(3);  // M3
AF_DCMotor motor4(4);  // M4
 

char bluetoothInput = 'S';  // Input from Bluetooth HC-05
int speedCar = 100;         // 50 - 255.
int speedCar1 = 255; // Speed for Line Follower only 
int speed_Coeff = 3;
boolean lightFront = false;
boolean lightBack = false;
boolean horn = false;
// CAR END

//ARM START
Servo motor_1;
Servo motor_2;
Servo motor_3;
Servo motor_4;


int servo1 = 90;
int servo2 = 90;
int servo3 = 90;
int servo4 = 90;



void setup() 
{
  Serial1.begin(9600);  // Connect to Bluetooth HC-05
  pinMode(leftir, INPUT);
  pinMode(rightir, INPUT);
  pinMode(horn_Buzz, OUTPUT);
  motor1.setSpeed(speedCar);  // Initialise Motor Speed
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
  pinMode(horn_Buzz, OUTPUT);
  digitalWrite(horn_Buzz, LOW);
  ;
 // stopCar();  // Initialise Car Position

  // ARM START
  motor_1.attach(44);
 motor_2.attach(45);
 motor_3.attach(46);
 motor_4.attach(47);

 
 motor_1.write(servo1); 
motor_2.write(servo2); 
motor_3.write(servo3); 
motor_4.write(servo4); 


delay(100);
 // ARM START
}


void loop() {
  //LineFollower();
  
  bluetoothInput = Serial1.read();  // Read Bluetooth HC-05
   switch (bluetoothInput) {
      
    case '0': speedCar = 100; break;
    case '1': speedCar = 115; break;
    case '2': speedCar = 130; break;
    case '3': speedCar = 145; break;
    case '4': speedCar = 160; break;
    case '5': speedCar = 175; break;
    case '6': speedCar = 190; break;
    case '7': speedCar = 205; break;
    case '8': speedCar = 220; break;
    case '9': speedCar = 235; break;
    case 'q': speedCar = 255; break;
    case 'F': goForward(); break;
    case 'B': goBackward(); break;
    case 'L': turnLeft(); break;
    case 'R': turnRight(); break;
    case 'S': stopCar(); break;
    case 'W': lightFront = true; break;
    case 'w': lightFront = false; break;
    case 'U': lightBack = true; break;
    case 'u': lightBack = false; break;
    case 'V': horn = true; break;
    case 'v': horn = false; break;

    case 'X': LineFollower(); break;
    case 'x': stopCar(); break;
   case 'A': WaistL (); break;
   case 'C': WaistR(); break;
   case 'E': ShoulderD (); break;
   case 'K': SholderU(); break;
   case 'M': WristR(); break;
   case 'N': WristL(); break;
   case 'O': Grippero(); break;
   case 'P': Gripperc (); break;
   case 'z': stoparm(); break;
  }  // end switch
    
//if(bt_data > 20){Speed = bt_data;}
}

void WaistL (){
if(servo1<180){servo1 = servo1+5;}
motor_1.write(servo1);  
}


void WaistR() {
if(servo1>0){servo1 = servo1-5;} 
motor_1.write(servo1);  
}

void ShoulderD (){
if(servo2>0){servo2 = servo2-5;}
motor_2.write(servo2);
}


void SholderU() {
if(servo2<180){servo2 = servo2+5;}
motor_2.write(servo2);  

}

void WristR(){
if(servo3>0){servo3 = servo3-5;}
motor_3.write(servo3);
}


void WristL() {
if(servo3<180){servo3 = servo3+5;}
motor_3.write(servo3);
}

void Grippero() {
if(servo4<180){servo4 = servo4+5;}
motor_4.write(servo4);
}

void Gripperc()
{
if(servo4>0){servo4 = servo4-5;}
motor_4.write(servo4);
}

void stoparm(){
  motor_1.write(90); 
   motor_2.write(90); 
    motor_3.write(90); 
     motor_4.write(90); 
   
}




void goForward() {
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void goBackward() {
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void turnRight() {
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void turnLeft() {
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void stopCar() {
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void LineFollower() {
    while (Serial1.read() !='x'){

  //BLACK COLOUR = HIGH - 1
  //WHITE COLOUR = LOW - 0
  int lefteye = analogRead(leftir);
  int righteye = analogRead(rightir);
  Serial1.print("leftValue:");  //print the values in the monitor
  Serial1.print(lefteye);
  Serial1.print("......rightValue:");
  Serial1.println(righteye);

  if ((righteye >= 50) && (lefteye >= 50)) {
    goForward1();
  } 
  else if ((righteye < 50) && (lefteye > 50)) {
    turnLeft1();
  }
  else if ((righteye > 50) && (lefteye < 50)) {
    turnRight1();
  } 
else if ((righteye < 50) && (lefteye < 50)) {
    turnRight1();
  } 

 
  //else {
    //stopCar1();
    ;  //if all else fails, stop the motors
    //delay(500);
  //}
  //digitalWrite(horn_Buzz, HIGH);
  delay(20);
  // digitalWrite(buzzer, LOW);
 
  }
}
void goForward1() {
  motor1.setSpeed(speedCar1);
  motor2.setSpeed(speedCar1);
  motor3.setSpeed(speedCar1);
  motor4.setSpeed(speedCar1);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(15);
  stopCar();
}
void goBackward1() {
  motor1.setSpeed(speedCar1);
  motor2.setSpeed(speedCar1);
  motor3.setSpeed(speedCar1);
  motor4.setSpeed(speedCar1);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void turnRight1() {
  motor1.setSpeed(speedCar1);
  motor2.setSpeed(speedCar1);
  motor3.setSpeed(speedCar1);
  motor4.setSpeed(speedCar1);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(30);
  stopCar();
}
void turnLeft1() {
  motor1.setSpeed(speedCar1);
  motor2.setSpeed(speedCar1);
  motor3.setSpeed(speedCar1);
  motor4.setSpeed(speedCar1);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(30);
  stopCar();
}
void stopCar1() {
  motor1.setSpeed(speedCar1);
  motor2.setSpeed(speedCar1);
  motor3.setSpeed(speedCar1);
  motor4.setSpeed(speedCar1);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}


 
 