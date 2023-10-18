// Define the ultrasonic sensor pins
const int trigPin = 2;
const int echoPin = 3;

// Variables to store the duration and distance values
long duration;
float distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Define the trigPin as an output and the echoPin as an input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send a 10 microsecond pulse to the trigPin to start the measurement
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the duration from the echoPin
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance based on the duration and the speed of sound (343 meters per second at sea level and 20 degrees Celsius)
  distance = (duration * 0.0343) / 2;
  
  // Print the distance in centimeters and inches
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm / ");
  Serial.print(distance * 0.3937);
  Serial.println(" inches");
  
  // Wait for a brief moment before taking the next measurement
  delay(1000);
}
