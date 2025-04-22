#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)
const int centerPOS_stand = 350;
//200 min 10 degrees
//600 max 170 degrees
char incomingValue = 'n';
char testValue = 'z';
// our servo # counter
uint8_t servonum = 0;
uint8_t servonum_max = 12;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  delay(50);
  robo_stand();
  delay(1000);
}

void loop() {
incomingValue = Serial.read();
  
  if (incomingValue > 0) {
    testValue = incomingValue;
  }
  Serial.println(testValue);
  if (testValue == 'g') {
    robo_greet();
  }
  if (testValue == 'h') {
    robo_hug();
  }
  if (testValue == 's') {
    robo_sprinkler();
  }
  if (testValue == '0') {
    robo_emergency_stop();
  }
  if (testValue == 'u') {
    robo_stand();
  }
  if (testValue == 'w') {
    robo_wave();
  }
  }

/*
  VOIDS
*/
void robo_wave (){
  //variables
    //left shoulders
      const int left_shoulder_straight = 500;
      const int left_shoulder_up = 600;
      const int left_shoulder_stand = 280;
      const int left_shoulder_down = 420;


    //right shoulders
      const int right_shoulder_straight  = 200;
      const int right_shoulder_up = 350;
      const int right_shoulder_down = 350;

    //head
      const int head_left = 590;
      const int head_right = 120;
    //left hand go up
      const int left_hand_up = 440;
      const int left_hand_nuetral = 370;
      const int left_hand_down = 510;
    //right hand
      const int right_hand_down = 420;
      const int right_hand_up = 200;
    
  //head look left
    pwm.setPWM(12, 0, head_left);
    delay(1000);
  //arms straight
   pwm.setPWM(10, 0, left_shoulder_straight);
   delay(300);
  //left hand goes up
    pwm.setPWM(11, 0, left_hand_up);
    delay(250);
  //left shoulder goes up more
    pwm.setPWM(10, 0, left_shoulder_up);
  //left hand goes down
    pwm.setPWM(11, 0, left_hand_down);
  //left shoulder goes down
    pwm.setPWM(10, 0, left_shoulder_stand);
    pwm.setPWM(11, 0, left_hand_nuetral);
  //head turns right
    pwm.setPWM(12, 0, head_right);
  //right shoulder goes straight
    pwm.setPWM(7, 0, right_shoulder_down);
    delay(200);
  //right shoulder straight
    pwm.setPWM(7, 0, right_shoulder_straight);
    
  //right hand down
    pwm.setPWM(8, 0, right_hand_down);
    delay(300);
  //right hand up
    pwm.setPWM(8, 0, right_hand_up);
  //restart
  robo_stand();
  //again
  //head look left
    pwm.setPWM(12, 0, head_left);
    delay(500);
  //arms straight
   pwm.setPWM(10, 0, left_shoulder_straight);
   delay(300);
  //left hand goes up
    pwm.setPWM(11, 0, left_hand_up);
    delay(250);
  //left shoulder goes up more
    pwm.setPWM(10, 0, left_shoulder_up);
  //left hand goes down
    pwm.setPWM(11, 0, left_hand_down);
  //left shoulder goes down
    pwm.setPWM(10, 0, left_shoulder_stand);
    pwm.setPWM(11, 0, left_hand_nuetral);
  //head turns right
    pwm.setPWM(12, 0, head_right);
  //right shoulder goes straight
    pwm.setPWM(7, 0, right_shoulder_down);
    delay(200);
  //right shoulder straight
    pwm.setPWM(7, 0, right_shoulder_straight);
    
  //right hand down
    pwm.setPWM(8, 0, right_hand_down);
    delay(300);
  //right hand up
    pwm.setPWM(8, 0, right_hand_up);
  //restart
  robo_stand();
  //again
  //head look left
    pwm.setPWM(12, 0, head_left);
    delay(500);
  //arms straight
   pwm.setPWM(10, 0, left_shoulder_straight);
   delay(300);
  //left hand goes up
    pwm.setPWM(11, 0, left_hand_up);
    delay(250);
  //left shoulder goes up more
    pwm.setPWM(10, 0, left_shoulder_up);
  //left hand goes down
    pwm.setPWM(11, 0, left_hand_down);
  //left shoulder goes down
    pwm.setPWM(10, 0, left_shoulder_stand);
    pwm.setPWM(11, 0, left_hand_nuetral);
  //head turns right
    pwm.setPWM(12, 0, head_right);
  //right shoulder goes straight
    pwm.setPWM(7, 0, right_shoulder_down);
    delay(200);
  //right shoulder straight
    pwm.setPWM(7, 0, right_shoulder_straight);
    
  //right hand down
    pwm.setPWM(8, 0, right_hand_down);
    delay(300);
  //right hand up
    pwm.setPWM(8, 0, right_hand_up);
  //stand
    robo_stand();




    

}
void robo_stand (){
  //variables
    const int left_foot_stand = 380;
    const int left_knee_stand = 400;
    const int left_leg_stand = 380;
    const int right_foot_stand = 430;
    const int right_knee_stand =380; 
    const int right_leg_stand = 400;
    const int left_torso_stand = 400;
    const int right_torso_stand = 350;
    const int left_shoulder_stand = 280;
    const int left_hand_stand = 370;
    const int right_shoulder_stand = 420;
    const int right_hand_stand = 360;
    const int head_stand = 370;
  //Legs
    pwm.setPWM(0, 0, left_foot_stand);

    pwm.setPWM(1, 0, left_knee_stand);

    pwm.setPWM(2, 0, left_leg_stand);

    pwm.setPWM(3, 0, right_foot_stand);

    pwm.setPWM(4, 0, right_knee_stand);

    pwm.setPWM(5, 0, right_leg_stand);

  //Torso
    pwm.setPWM(6, 0, right_torso_stand);

    pwm.setPWM(9, 0, left_torso_stand);

  //Left Arm
    pwm.setPWM(7, 0, right_shoulder_stand);

    pwm.setPWM(8, 0, right_hand_stand);

  //Right Arm
    pwm.setPWM(10, 0, left_shoulder_stand);

    pwm.setPWM(11, 0, left_hand_stand);

  //head
    pwm.setPWM(12, 0, head_stand);
    }


void robo_greet (){
  //variables
    //left shoulders
      const int left_shoulder_straight = 500;
    //right shoulders
      const int right_shoulder_straight  = 200;
      const int left_shoulder_down = 460;
    //head
      const int head_left = 590;
    //left hand go up
      const int left_hand_up = 440;
      const int left_hand_nuetral = 370;
      const int left_hand_down = 510;

    //
    const int left_foot;
    const int left_knee;
    const int left_leg;
    const int right_foot;
    const int right_knee; 
    const int right_leg;
    const int left_torso;
    const int right_torso;
    
    const int right_hand;
    

  //arms straight
pwm.setPWM(10, 0, left_shoulder_straight);
   delay(1000);
  //head look left
    pwm.setPWM(12, 0, head_left);
    delay(1000);
  //left hand goes up
  
    pwm.setPWM(11, 0, left_hand_up);
    delay(250);
    pwm.setPWM(11, 0, left_hand_nuetral);
    delay(50);
    
  //left shoulder goes up and down
    pwm.setPWM(10, 0, left_shoulder_down);
    delay(50);
    //left hand goes up
  
    pwm.setPWM(11, 0, left_hand_up);
    delay(250);
    pwm.setPWM(11, 0, left_hand_nuetral);
    delay(50);
    
  //left shoulder goes up and down
    pwm.setPWM(10, 0, left_shoulder_down);
    delay(50);
    //left hand goes up
  
    pwm.setPWM(11, 0, left_hand_up);
    delay(250);
    pwm.setPWM(11, 0, left_hand_nuetral);
    delay(50);
    
  //left shoulder goes up and down
    pwm.setPWM(10, 0, left_shoulder_down);
    delay(50);
    /*
  //head turns right
    pwm.serPWM(12, 0, head_right);
    delay(500);
  //left shoulder goes up and down
    pwm.setPWM(10, 0, right_shoulder_up);
    delay(50);
    */
}

void robo_hug() {
  //variables
    //left shoulders
      const int left_shoulder_straight = 500;
      const int left_shoulder_goes_in = 220;
    //right shoulders
      const int right_shoulder_straight  = 200;
      const int right_shoulder_in = 460;
    //right had goes in
      const int right_hand_in = 270;
    //left hand go up
      const int left_hand_in = 500;
    //left torso
      const int left_torso_goes_in = 150;
    //right torso
      const int right_torso_goes_in = 600;
  //code
    pwm.setPWM(10, 0, left_shoulder_straight);
    pwm.setPWM(7, 0, right_shoulder_straight);
    pwm.setPWM(6, 0, right_torso_goes_in);
    pwm.setPWM(9, 0, left_torso_goes_in);
    delay(1000);
    pwm.setPWM(7, 0, right_shoulder_in);
    pwm.setPWM(10, 0, left_shoulder_goes_in);
    delay(500);
    pwm.setPWM(11, 0, right_hand_in);
    pwm.setPWM(8, 0, left_hand_in);
    delay(2000);
}

void robo_sprinkler () {
  //variables
    //left torso
      const int left_torso_in = 150;
    //left hand
      const int left_hand_right = 250;
      const int left_hand_left = 450;
      const int left_hand_stand = 370;
    //left shoulder
      const int left_shoulder_move_right = 220;
      const int left_shoulder_move_left = 320;
    //right shoulder
      const int right_shoulder_move_left = 450;
      const int right_shoulder_move_right = 350;
    //right torso
      const int right_torso_up = 600;
    //right hand
      const int right_hand_left = 450;
      const int right_hand_right = 240;
      const int right_hand_stand = 360;
    //head
      const int head_left = 590;
      const int head_right = 180;
      const int head_stand = 370;

 
    //left torso in and hand goes in
      pwm.setPWM(9, 0, left_torso_in);
      pwm.setPWM(6, 0, right_torso_up);
      delay(1000);
    //shoulders move sideways
      pwm.setPWM(10, 0, left_shoulder_move_right);
      pwm.setPWM(7, 0, right_shoulder_move_right);  
      pwm.setPWM(12, 0, head_right);
    //hands go right and left
      hands_shake();
    //move shoulders
      pwm.setPWM(10, 0, left_shoulder_move_left);
      pwm.setPWM(7, 0, right_shoulder_move_left);
      pwm.setPWM(12, 0, head_left);
      delay(500);
    //hands shake
      pwm.setPWM(11, 0, left_hand_right);
      pwm.setPWM(8, 0, right_hand_right);
      delay(100);
      pwm.setPWM(8, 0, right_hand_left);
      pwm.setPWM(11, 0, left_hand_left);
      delay(100);
      pwm.setPWM(11, 0, left_hand_stand);
      pwm.setPWM(8, 0, right_hand_stand);
    //again
      pwm.setPWM(10, 0, left_shoulder_move_right);
      pwm.setPWM(7, 0, right_shoulder_move_right);
      pwm.setPWM(12, 0, head_right);
  
    //hands go right and left
      hands_shake();
    //move shoulders
      pwm.setPWM(10, 0, left_shoulder_move_left);
      pwm.setPWM(7, 0, right_shoulder_move_left);
      pwm.setPWM(12, 0, head_left);
      delay(500);
    //hands shake
      pwm.setPWM(11, 0, left_hand_right);
      pwm.setPWM(8, 0, right_hand_right);
      delay(100);
      pwm.setPWM(8, 0, right_hand_left);
      pwm.setPWM(11, 0, left_hand_left);
      delay(100);
      pwm.setPWM(11, 0, left_hand_stand);
      pwm.setPWM(8, 0, right_hand_stand);
    //again
      pwm.setPWM(10, 0, left_shoulder_move_right);
      pwm.setPWM(7, 0, right_shoulder_move_right); 
      pwm.setPWM(12, 0, head_right);
    //hands go right and left
      hands_shake();
    //move shoulders
      pwm.setPWM(10, 0, left_shoulder_move_left);
      pwm.setPWM(7, 0, right_shoulder_move_left);
      pwm.set      delay(500);
PWM(12, 0, head_left);
    //hands shake
      pwm.setPWM(11, 0, left_hand_right);
      pwm.setPWM(8, 0, right_hand_right);
      delay(100);
      pwm.setPWM(8, 0, right_hand_left);
      pwm.setPWM(11, 0, left_hand_left);
      delay(100);
      pwm.setPWM(11, 0, left_hand_stand);
      pwm.setPWM(8, 0, right_hand_stand);
      pwm.setPWM(12, 0, head_stand);
}
void hands_shake() {
    //left hand
      const int left_hand_right = 230;
      const int left_hand_left = 450;
    //right hand
      const int right_hand_left = 450;
      const int right_hand_right = 150;
      pwm.setPWM(11, 0, left_hand_right);
      pwm.setPWM(8, 0, right_hand_right);
      delay(100);
      pwm.setPWM(8, 0, right_hand_left);
      pwm.setPWM(11, 0, left_hand_left);
      delay(100);
      pwm.setPWM(11, 0, left_hand_right);
      pwm.setPWM(8, 0, right_hand_right);
      delay(100);
      pwm.setPWM(8, 0, right_hand_left);
      pwm.setPWM(11, 0, left_hand_left);
      pwm.setPWM(11, 0, left_hand_right);
      pwm.setPWM(8, 0, right_hand_right);
      delay(100);
      pwm.setPWM(8, 0, right_hand_left);
      pwm.setPWM(11, 0, left_hand_left);
      delay(100);
      pwm.setPWM(11, 0, left_hand_right);
      pwm.setPWM(8, 0, right_hand_right);
      delay(100);
      pwm.setPWM(8, 0, right_hand_left);
      pwm.setPWM(11, 0, left_hand_left);
}
void robo_emergency_stop () {
  for (int i = 0; i <= servonum_max; i++) {
    pwm.setPWM(i, 0, 0);
  }
}