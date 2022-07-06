import serial
import time
import datetime
ser = serial.Serial('COM3', 9600)
while (1):
    s=str(ser.readline())
    dt_now = datetime.datetime.now()
    # print("現在時刻:"+str(dt_now)+"結果："+s)
    print(s)
    time.sleep(0.1)