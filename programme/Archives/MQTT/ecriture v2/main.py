import paho.mqtt.client as mqtt
import serial
import time

#Connexion série
ser = serial.Serial('COM4')  # open serial port

#Création du client
client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
#Username broker (intégration TTN) -> MDP broker (intégration TTN)
client.username_pw_set("projet-btsfourcade@ttn","NNSXS.TEHNECHZQ3MJQXCVB3RKOSGMPMNUTWRO2GZFRUI.AWERZSCJJVG2RIQMNTWCHXAQ4B7RNLCJWMFPK5ABCAOV2OQ43HPA")

connected = False
while not connected:
    try:
        # Connexion au broker TTN
        client.connect("eu1.cloud.thethings.network", 1883, 60)
        connected = True
        print("Connexion établie")
    except Exception as e:
        print("Échec de la connexion:", str(e))
        print("Nouvelle tentative de connexion dans 10 secondes...")
        time.sleep(10)

def Envoi():
    trame = [0x01, 0x0D, 0xFF, 0x00, 0x03]

    # Convertir chaque élément de la trame en une chaîne hexadécimale
    conversion = ''.join(format(x, '02x') for x in trame)

    # Créer la commande AT+MSG avec la trame
    message = f"AT+MSG={conversion}"
    ser.write(message.encode())
    print(message)

duree=1
t = Intervallometre(duree)
t.setDaemon(True)
t.start()
