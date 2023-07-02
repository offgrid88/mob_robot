
// Motor_driver 1
// Motor 1
int motor1Pin1 = 2; 
int motor1Pin2 = 4; 
int enable1Pin = 15; 

// standby18
// Motor 2
int motor2Pin1=18;
int motor2Pin2=19;//18
int enable2Pin=23;

// Motor_Driver 2
// Motor 3
int motor3Pin1 = 33; 
int motor3Pin2 = 32; 
int enable3Pin = 14; 

// standby18
// Motor 4
int motor4Pin1=26;
int motor4Pin2=25;//18
int enable4Pin=27;

// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 200;

void setup() {
  // sets the pins as outputs:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  pinMode(motor3Pin1, OUTPUT);
  pinMode(motor3Pin2, OUTPUT);
  pinMode(enable3Pin, OUTPUT);

  pinMode(motor4Pin1, OUTPUT);
  pinMode(motor4Pin2, OUTPUT);
  pinMode(enable4Pin, OUTPUT);
  
  // configure LED PWM functionalitites
  ledcSetup(pwmChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, pwmChannel);
  ledcAttachPin(enable2Pin, pwmChannel);
  ledcAttachPin(enable3Pin, pwmChannel);
  ledcAttachPin(enable4Pin, pwmChannel);

  Serial.begin(115200);

  // testing
  Serial.print("Testing DC Motor...");
}

void loop() {
  // Move the DC motor forward at maximum speed
  Serial.println("Moving Forward");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH); 

  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH); 

  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, HIGH); 

  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, HIGH); 
 
 delay(2000);
  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);

  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, LOW);

  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, LOW);

  delay(1000);

  // Move DC motor backwards at maximum speed
  Serial.println("Moving Backwards");
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW); 

  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW); 

  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, LOW); 

  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, LOW); 

  delay(2000);

  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);

  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);

  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, LOW);

  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, LOW);

  delay(1000);

  // Move DC motor forward with increasing speed
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);

  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  
  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, LOW);

  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, LOW);

  while (dutyCycle <= 255){
    ledcWrite(pwmChannel, dutyCycle);   
    Serial.print("Forward with duty cycle: ");
    Serial.println(dutyCycle);
    dutyCycle = dutyCycle + 5;
    delay(500);
  }
  dutyCycle = 200;
}
