import pywhatkit
import schedule
import time
from datetime import datetime

def send_whatsapp():
    phone_number = '+34695317030'
    message = 'Hola Amorrrr desde Python'

    pywhatkit.sendwhatmsg_instantly(phone_number, message)

send_whatsapp()