import serial

import time

import sys,tty,termios

# XBee setting

s = serial.Serial(sys.argv[1])

s.write("+++".encode())

char = s.read(2)

print("Enter AT mode.")

print(char.decode())


s.write("ATMY 0x234\r\n".encode())

char = s.read(3)

print("Set MY 0x234.")

print(char.decode())


s.write("ATDL 0x235\r\n".encode())

char = s.read(3)

print("Set DL 0x235.")

print(char.decode())


s.write("ATID 0x1\r\n".encode())

char = s.read(3)

print("Set PAN ID 0x1.")

print(char.decode())


s.write("ATWR\r\n".encode())

char = s.read(3)

print("Write config.")

print(char.decode())


s.write("ATMY\r\n".encode())

char = s.read(4)

print("MY :")

print(char.decode())


s.write("ATDL\r\n".encode())

char = s.read(4)

print("DL : ")

print(char.decode())


s.write("ATCN\r\n".encode())

char = s.read(3)

print("Exit AT mode.")

print(char.decode())


print("start sending RPC")

class _Getch:

    def __call__(self):

        fd = sys.stdin.fileno()

        old_settings = termios.tcgetattr(fd)

        try:

            tty.setraw(sys.stdin.fileno())

            ch = sys.stdin.read(1)

        finally:

            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)

        return ch

while True:

   # send RPC to remote
    s.write("/goStraight/run 100\r\".encode())
    time.sleep(1)

    s.write("/goStraight/run 100\r".encode())
    time.sleep(1)
    
    s.write("/turn/run 100 0.9\n".encode())
    time.sleep(1)



s.close()

