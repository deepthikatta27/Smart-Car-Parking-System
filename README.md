# 🚗🅿️ Smart Car Parking System 🚗🅿️

## 📝 Description
The Smart Car Parking System is a project that aims to provide a convenient and efficient parking solution by using various sensors, Arduino Uno, and an ESP8266 Wi-Fi module to connect to the Blynk IoT Platform. This system allows car owners to check the availability of parking slots in real time through their mobile phones or computers.

## 🛠️ Components Used
- Arduino Uno
- ESP8266 Wi-Fi module
- Ultrasonic sensors
- IR sensors
- Servo motors
- LCD display
- Blynk IoT Platform

## 🔧 System Working
1. The IR sensor at the entrance detects incoming cars and triggers the servo motor to open the gate if there is an empty parking slot.
2. If all slots are occupied, the gate will remain closed, indicating there are no available parking spots.
3. Ultrasonic sensors in each parking slot detect the presence of vehicles parked in those slots.
4. The data from all sensors is collected and sent to the Blynk cloud server via the ESP8266 Wi-Fi module, which facilitates real-time monitoring.
5. Users can access the Blynk mobile app or use a computer to check the number of occupied and unoccupied parking slots.

## ⚙️ Setup and Execution
Follow these steps to set up and execute the Smart Car Parking System:

1. **Hardware Setup**
   - Connect the Arduino Uno, IR sensor, and servo motor to form the gate control mechanism.
   - Install ultrasonic sensors in each parking slot to detect vehicle presence.
   - Connect the LCD display to show the number of vacant and occupied slots.

2. **Software Setup**
   - Install the Arduino IDE on your computer if you haven't already.
   - Upload the necessary firmware and code onto the Arduino Uno.
   - Ensure the ESP8266 Wi-Fi module is correctly connected to the Arduino and the required libraries are installed.

3. **Blynk IoT Platform Setup**
   - Download the Blynk mobile app from the app store or use the Blynk web application on your computer.
   - Create a new Blynk account or log in if you already have one.
   - Set up a new project in the Blynk app and obtain the authentication token.

4. **Integration with Blynk**
   - Modify the Arduino code to include the Blynk library and integrate it with the ESP8266 Wi-Fi module.
   - Use the obtained authentication token to connect the Arduino to the Blynk cloud server.

5. **Deploy the System**
   - Install the entire setup at the parking lot entrance.
   - Ensure all connections are secure and the sensors are placed correctly.
   - Power on the Arduino and connect the ESP8266 to the Wi-Fi network.

6. **Monitor the Parking Lot**
   - Launch the Blynk mobile app or web application.
   - Access the Smart Car Parking System project you created earlier.
   - Monitor the real-time data, which will show the number of available and occupied parking slots.

7. **Testing**
   - Test the system by driving cars in and out of the parking lot.
   - Verify that the gate opens when there are vacant slots and remains closed when all slots are occupied.
   - Check if the sensor data is correctly updated on the Blynk platform.

8. **Troubleshooting**
   - If you encounter any issues, double-check the hardware connections and code for errors.
   - Ensure the Wi-Fi connection is stable and the ESP8266 is properly configured.

9. **Deployment**
    - Once you are satisfied with the system's performance and stability, deploy it in the actual parking lot.

## Safety Precautions
- Provide clear instructions and guidelines for users and personnel who interact with the system.
- Ensure proper insulation and protection of electrical components to prevent accidents.

