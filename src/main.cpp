#include <Arduino.h>

#define sw_L1 21
#define sw_L2 22
#define sw_R1 23
#define sw_R2 25

bool L1, L2, R1, R2;

class motor {
  public:
    int pinA, pinB;

    void setPin(int pin_a, int pin_b) {
      pinA = pin_a;
      pinB = pin_b;
      pinMode(pinA, OUTPUT);
      pinMode(pinB, OUTPUT);
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
    };

    void forword() {
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
    }

    void backward() {
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
    }

    void stop() {
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
    }
};

motor motorLeft;
motor motorRight;

void setup() {
  // put your setup code here, to run once:
  pinMode(sw_L1, INPUT_PULLUP);
  pinMode(sw_L2, INPUT_PULLUP);
  pinMode(sw_R1, INPUT_PULLUP);
  pinMode(sw_R2, INPUT_PULLUP);

  motorLeft.setPin(16, 17);
  motorRight.setPin(18, 19);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  L1 = digitalRead(sw_L1);
  L2 = digitalRead(sw_L2);
  R1 = digitalRead(sw_R1);
  R2 = digitalRead(sw_R2);

  if (L1 == true && L2 ==  true) {
    motorLeft.stop();
  } else if (L1 == true && L2 == false) {
    motorLeft.forword();
  } else if (L1 == false && L2 == true) {
    motorLeft.backward();
  } else {
    motorLeft.stop();
  }

  if (R1 == true && R2 ==  true) {
    motorRight.stop();
  } else if (R1 == true && R2 == false) {
    motorRight.forword();
  } else if (R1 == false && R2 == true) {
    motorRight.backward();
  } else {
    motorRight.stop();
  }

}
