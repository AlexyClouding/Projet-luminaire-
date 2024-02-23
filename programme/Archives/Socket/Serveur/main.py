import socket
import paho.mqtt.client as mqtt
import serial
import time

#------------------------------------------------
#---------------PARAMETRAGES --------------------
#------------------------------------------------
#Connexion série---
ser = serial.Serial('COM4')  # open serial port

#MQTT --
client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)

#Username broker (intégration TTN) -> MDP broker (intégration TTN)
client.username_pw_set("projet-btsfourcade@ttn","NNSXS.TEHNECHZQ3MJQXCVB3RKOSGMPMNUTWRO2GZFRUI.AWERZSCJJVG2RIQMNTWCHXAQ4B7RNLCJWMFPK5ABCAOV2OQ43HPA")

connected = False
#FONCTION DE CONNEXION MQTT
def connexionMQTT():
    global connected
    while not connected:
        try:
            # Connexion au broker TTN
            client.connect("eu1.cloud.thethings.network", 1883, 60)
            connected = True
            print("Connexion établie MQTT")
        except Exception as erreur:
            print("Échec de la connexion MQTT:", str(erreur))
            print("Nouvelle tentative de connexion dans 10 secondes...")
            time.sleep(10)

def on_disconnect(client, userdata, rc):
    print("Déconnexion du broker MQTT.")
    client.connected = False
    connexionMQTT()

#FONCTION D ENVOI MQTT
def Envoi(reception):
    trame = reception

    # Convertir chaque élément de la trame en une chaîne hexadécimale
    conversion = ''.join(format(x, '02x') for x in trame)

    # Créer la commande AT+MSG avec la trame
    message = f"AT+MSG={conversion}"
    ser.write(message.encode())
    print(message)


client.on_disconnect = on_disconnect

#Pas d'ouverture de socket sans la connexion mqtt
#Socket
socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socket.bind(('', 15555))

#BOUCLE D ECOUTE SOCKET
while True:
        socket.listen(5)
        client, address = socket.accept()
        print ("Une connexion c'est faite")

        reception = client.recv(255)
        if reception != "":
            print (reception)
            Envoi(reception)


print ("Close")
client.close()
stock.close()
