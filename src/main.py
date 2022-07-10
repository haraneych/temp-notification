import requests
import serial
import time
import datetime

from repuests import sendRequest
ser = serial.Serial('COM3', 9600)
while (1):
    s=str(ser.readline())
    dt_now = datetime.datetime.now()
    # print("現在時刻:"+str(dt_now)+"結果："+s)
    s1=s.replace("b'", '')
    s2=s1.replace("n", '')
    s3=s2.replace("\\", '')
    s4=s3.replace("'", '')
    message = s4[:-1]
    print(message)
    sendRequest(message)
    time.sleep(60)