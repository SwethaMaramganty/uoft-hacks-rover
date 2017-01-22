# UofT-Hacks-Rover

Rover made out tiny computers, electrical components, and duct tape for U of T hacks.

###[Demo Video 1](https://vimeo.com/200539136)

###[Demo Video 2](https://vimeo.com/200539681)

### Components
- Arduino Uno
- Raspberry Pi 3
- Raspberry Pi Camera
- Battery Pack (for Raspberry Pi 3)
- Rover Base
- DC Motors x2
- Wheels x2
- Caster Wheel
- L293D Motor Driver
- Mini Servo Claw
- 100uF Capacitor 
- Buzzer
- AA Battery Holder (for DC Motors)
- AA Batteries x4
- PS3 Controller
- Duct Tape

### Hardware Instructions
1. Attach the DC motors to the rover base
2. Attach wheels to the motors
3. Attach the caster wheel to the front of the rover base
4. Attach the AA battery holder to the rover base
5. Create the motor circuit using the DC motors, AA battery holder, and L293D motor driver
6. Mount the mini servo claw to the front of the rover base
7. Create the claw circuit using the mini servo claw and 100uF capacitor
8. Create the buzzer circuit
9. Mount the battery pack, Raspberry Pi, and Arduino Uno on the rover
10. Connect the Raspberry Pi to the battery pack, then connect the Arduino Uno to the Raspberry Pi
11. Connect the motor, claw, and buzzer circuits to the Arduino Uno. Follow the pinout in the code or change the code accordingly.
12. Connect the Raspberry Pi camera to the Raspberry Pi
12. Power up the Raspberry Pi and run the code

### Code Instructions
1. Upload rover_controller.ino to the Arduino Uno in the /Arduino/rover_controller directory
2. Run the rover_controller.py script on the Raspberry Pi in the /RaspberryPi directory

### Images
<img src=https://github.com/cmjten/UofT-Hacks-Rover/blob/master/images/20170122_060522.jpg width=600/>
