import pyautogui
from time import sleep

n = int(input())

sleep(3)
for i in range(1, n+1):
    for j in range(1, i+1):
        pyautogui.write('#', interval=0.5)
    pyautogui.press('enter') # new line

