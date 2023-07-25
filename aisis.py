from pynput.keyboard import Key, Controller

keyboard = Controller()

# Press and release space
keyboard.press('a')
keyboard.release('a')