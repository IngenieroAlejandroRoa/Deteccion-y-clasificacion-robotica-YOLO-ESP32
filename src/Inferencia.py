import serial
import time

ser = serial.Serial('COM4', 115200, timeout=1)
time.sleep(2)

print("Enviando al ESP32...")
ser.write(b'Hola desde PC\n')  # Muy importante el \n
time.sleep(1)

while ser.in_waiting:
    print("ESP32 dijo:", ser.readline().decode('utf-8', errors='ignore').strip())

ser.close()
