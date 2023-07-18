# Smart-Car-Parking-System
The proposed smart parking lot system consists of ultrasonic sensors, IR sensors, servo motors and
Arduino Uno and esp8266 Wi-Fi module using which the data will be sent to the blynk IoT Platform so
that any car owner can check if there is an empty slot in a parking lot using their phone or on computer.
## System Working:
The IR sensor at the entrance will detect incoming car and triggers the servo motor to the gate if there is
any empty slot in the parking lot. If there are no empty slots, then the gate will not open.
The parking lot is equipped with ultrasonic sensors for each slot for detecting the presence of any vehicle
parked in those slots. We are using Ultrasonic sensors instead of IR sensors because in open areas the
sunlight may interfere with the IR sensor and may give wrong detection of the vehicles, whereas
ultrasonic sensor uses ultrasonic sound waves to detect the objects.
The number of occupied and unoccupied slots in the parking lot can be monitored using Blynk by using
Esp8266 Wi-Fi module which sends the parking lot data to the blynk cloud server where people can see
the real time data through their mobile phones.
An Lcd display is also used to display number of vacant and occupied slots at parking slots near the
entrance.
