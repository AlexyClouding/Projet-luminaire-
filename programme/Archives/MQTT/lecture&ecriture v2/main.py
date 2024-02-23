import paho.mqtt.client as mqtt
import json as json
import base64
import serial
import time

# -----------------------------------
# ---------- Définitions  -----------
# -----------------------------------
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
        print("Échec de la connexion")
        print("Nouvelle tentative de connexion dans 10 secondes...")
        time.sleep(10)  # Pause de 10 secondes avant la prochaine tentative

#-----------------------------------
#---- DEFINITION DES FONCTIONS -----
#-----------------------------------


def Receive(client, userdata, msg):
    resultat_complet = json.loads(msg.payload.decode())
    payload = resultat_complet['uplink_message']['frm_payload']
    print("Information reçu :", base64.b64decode(payload).decode())
    time.sleep(15)
    ser.write(b'AT+MSG="Napoleon etait un grand homme, VIVE L EMPEREUR"')  # write a string


#Connexion entre la reception de message Paho et la fonction receive script
client.on_message = Receive

#Abonnement a TTN pour recevoir tout les messages de TTN
client.subscribe("#")

ser.write(b'AT+MSG="Initialisions la boucle"')     # write a string

#Créer une boucle infini du script
client.loop_forever()




