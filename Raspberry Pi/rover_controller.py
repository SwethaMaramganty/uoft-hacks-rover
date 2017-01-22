"""
Script that gets input from a PS3 controller and sends it to the rover
"""

import pygame, serial, time, os
import serial.tools.list_ports as list_ports

class RoverController:
    """
    Controller for the rover
    """
    UP = 4
    RIGHT = 5
    DOWN = 6
    LEFT = 7
    SELECT = 0
    CIRCLE = 13
    SQUARE = 15

    def __init__(self):
        """
        Constructor
        """
        # Sets up pygame
        pygame.init()
        self._controller = pygame.joystick.Joystick(0)
        self._controller.init()

        # Serial port
        self._serial = serial.Serial(list_ports.comports()[0].device, 9600)

        self._claw_current = False
        self._claw_previous = False

    def controller_listener(self):
        """
        Gets the input from the controller and sends it to the Arduino Uno
        """
        for event in pygame.event.get():
            pass
        if self._controller.get_button(self.UP):
            # Move forward
            self._serial.write([1])
            print(1)
        elif self._controller.get_button(self.DOWN):
            # Move backward
            self._serial.write([2])
            print(2)
        elif self._controller.get_button(self.LEFT):
            # Turn left
            self._serial.write([3])
            print(3)
        elif self._controller.get_button(self.RIGHT):
            # Turn right
            self._serial.write([4])
            print(4)
        elif self._controller.get_button(self.SELECT):
            # Shut down system
            print("SEL")
            os.system("sudo shutdown now -h")
        else:
            # Stop
            self._serial.write([0])
            print(0)

        if self._controller.get_button(self.CIRCLE):
            # Buzzer
            self._serial.write([6])

        # Controls the claw. Claw only opens/closes when the circle button
        # switches to high state to prevent it from opening/closing repeatedly.
        self._claw_current = self._controller.get_button(self.SQUARE)
        if self._claw_current != self._claw_previous:
            if self._claw_current:
                self._serial.write([5])
        self._claw_previous = self._claw_current


if __name__ == "__main__":
    controller = RoverController()
    
    while True:
        # Loop that listens for input
        controller.controller_listener()
            
