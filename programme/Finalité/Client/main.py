import socket
import time
import paho.mqtt.client as mqtt
import serial


#------------------------------------------------
#---------------    MQTT     --------------------
#------------------------------------------------

#Création du client
client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
#Username broker (intégration TTN) -> MDP broker (intégration TTN)
client.username_pw_set("projet-btsfourcade@ttn","NNSXS.TEHNECHZQ3MJQXCVB3RKOSGMPMNUTWRO2GZFRUI.AWERZSCJJVG2RIQMNTWCHXAQ4B7RNLCJWMFPK5ABCAOV2OQ43HPA")

#------------------------------------------------------
#Connexion
#------------------------------------------------------
def connexionMQTT():
    global connected
    while not client.is_connected():
        try:

            # Connexion au broker TTN
            client.connect("eu1.cloud.thethings.network", 1883, 60)
            connected = True
            print("Connexion établie MQTT")
        except Exception as erreur:
            print("Échec de la connexion MQTT:", str(erreur))
            print("Nouvelle tentative de connexion dans 10 secondes...")
            time.sleep(10)

#------------------------------------------------------
#Déconnexion
#------------------------------------------------------
def on_disconnect(client, userdata, rc):
    print("Déconnexion du broker MQTT.")
    client.connected = False
    connexionMQTT()

#------------------------------------------------------
#Envoi de message
#------------------------------------------------------
def Envoi(reception):
    trame = reception

    # Convertir chaque élément de la trame en une chaîne hexadécimale
    conversion = ''.join(format(x, '02x') for x in trame)

    # Créer la commande AT+MSG avec la trame
    message = f"AT+MSG={conversion}"
    try:
        ser = serial.Serial('COM4')  # open serial port
        ser.write(message.encode())
        print("Serial_content_", message)
    except Exception as erreur:
        print("Serial_content_", message)
        print("Serial_error_",erreur)

client.on_disconnect = on_disconnect


#------------------------------------------------
#---------------   Socket    --------------------
#------------------------------------------------

#------------------------------------------------------
#Connexion Socket
#------------------------------------------------------
def connexionSocket(mysocket,hote,port):
    try:
        mysocket.connect((hote, port))
        print("Socket_connexion_true")
        return True
    except Exception as erreur:
        print("Socket_connexion_false_",erreur)
        return False


mysocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
connexionSocket(mysocket,"127.0.0.1",151)

# Envoi de messages toutes les 5 secondes tant que la connexion est active
while True:
    try:
        device_id = "A7s5D9b_"
        mysocket.sendall(device_id.encode())
        print("-----------------")
        print(f"Socket_DeVid_: {device_id}")
        reception = mysocket.recv(255)
        print("Socket_recv:", reception)
        Envoi(reception)
        print("-----------------")
        time.sleep(5)
    except Exception as erreur:
        mysocket.close()
        time.sleep(10)
        print("-----------------")
        print("Socket_error_", erreur)
        mysocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        connexionSocket(mysocket,"127.0.0.1",151)  # Relancer la connexion en cas d'erreur


# Fermeture de la connexion
mysocket.close()
print("Connexion fermée.")
