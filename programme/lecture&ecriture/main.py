import paho.mqtt.client as mqtt
import json as json
import base64
import serial
import time

# -----------------------------------
# ---------- Définitions  -----------
# -----------------------------------
#Connexion série
app = serial.Serial('COM4')  # open serial port

#Création du client
client = mqtt.Client()
#Username broker (intégration TTN) -> MDP broker (intégration TTN)
client.username_pw_set("projet-btsfourcade@ttn","NNSXS.TEHNECHZQ3MJQXCVB3RKOSGMPMNUTWRO2GZFRUI.AWERZSCJJVG2RIQMNTWCHXAQ4B7RNLCJWMFPK5ABCAOV2OQ43HPA")

#Connexion a TTN -> lien broker -> port broker
client.connect("eu1.cloud.thethings.network", 1883, 60)


#-----------------------------------
#---- DEFINITION DES FONCTIONS -----
#-----------------------------------
def Connect(client, userdata, flags, rc):
    if str(rc) == '0':  # Vérifie si le code de résultat de connexion est égal à zéro
        print("Connexion établie")

def Receive(client, userdata, msg):
    resultat_complet = json.loads(msg.payload.decode())
    payload = resultat_complet['uplink_message']['frm_payload']
    print("Information reçu :", base64.b64decode(payload).decode())
    time.sleep(15)
    app.write(b'AT+MSG="Napoleon etait un grand homme, VIVE L EMPEREUR"')  # write a string


#Mise en place des liaison fonction programme / fonction paho
client.on_connect = Connect
client.on_message = Receive

#Abonnement a TTN pour recevoir tout les messages de TTN
client.subscribe("#")

app.write(b'AT+MSG="Initialisions la boucle"')     # write a string

#Créer une boucle infini du script
client.loop_forever()




