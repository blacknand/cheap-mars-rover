# Testing serial input using Python


from pynput import keyboard
import serial
import time


ser = serial.Serial('/dev/cu.usbmodem00001', 9600)                    # Wired port
time.sleep(2)                                                         # Wait for the serial connection to initialize

def on_press(key):
    try:
        if key.char == 'w':
            ser.write(b'w')
        elif key.char == 's':
            ser.write(b's')
        elif key.char == 'a':
            ser.write(b'a')
        elif key.char == 'd':
            ser.write(b'd')
    except AttributeError:
        pass

def on_release(key):
    if key == keyboard.Key.esc:
        # Stop listener
        return False
    else:
        ser.write(b'x')                                               # Stop the car when any key is released

# Collect events until released
with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    listener.join()

ser.close()
