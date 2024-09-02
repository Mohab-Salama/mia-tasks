#include <Wire.h>

// MPU6050 I2C address
#define MPU6050_ADDR 0x68 

// MPU6050 registers
#define  PWR_MGMT_1 0x6B
#define GYRO_XOUT_H 0x43
#define GYRO_YOUT_H 0x45
#define GYRO_ZOUT_H 0x47
#define gyroSensitivity  131.0
int16_t gyroX, gyroY, gyroZ;
float yaw = 0.0;


// Timer variables for integrating yaw
float Time;
float dt;

void setup() {
  Wire.begin();           // Initialize I2C communication
  Serial.begin(9600);     // Initialize serial communication
  
  // Wake up the MPU6050 from sleep mode
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(PWR_MGMT_1);
  Wire.write(0); // Set to zero to wake up the sensor
  Wire.endTransmission(true);
  
  Time = millis();
}

void loop() {
  // Read gyroscope data
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(GYRO_ZOUT_H);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 6, true);

  gyroX = Wire.read() << 8 | Wire.read(); 
  gyroY = Wire.read() << 8 | Wire.read();
  gyroZ = Wire.read() << 8 | Wire.read();

  // Calculate delta time
  float currentTime = millis();
  dt = (currentTime -Time) / 1000.0; // Convert ms to seconds
  Time = currentTime;

  // Convert gyroscope data to yaw angle in degrees
  float gyroZrate = gyroZ / gyroSensitivity; // Convert to deg/s
  yaw += gyroZrate * dt; // Integrate to get yaw angle

  // Print the yaw angle
  Serial.print("Yaw: ");
  Serial.println(yaw);

  delay(100); // Small delay to avoid too much data output
}
