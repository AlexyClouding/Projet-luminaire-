import paho.mqtt.client as mqtt
import json as json
import base64


# -----------------------------------
# -- Définitions des identifiants  --
# -----------------------------------
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
    else:
        i = 0
        while rc != 0:  # Tant que le code de résultat de connexion n'est pas égal à zéro
            i += 1
            print("Connexion échouée")
            print("Tentative de connexion %d.." % i)  # Utilisez % pour formater la chaîne avec la valeur de i

def Send(client, request):
    formaterrequest=request.encode()
    message = client.publish("Communication",formaterrequest)
    if(message.rc == mqtt.MQTT_ERR_SUCCESS):
        print("Information envoyer :",formaterrequest)

def Receive(client, userdata, msg):
    resultat_complet = json.loads(msg.payload.decode())
    payload = resultat_complet['uplink_message']['frm_payload']

    print("Information reçu :", base64.b64decode(payload).decode())
    Send(client, "Reception")




#Mise en place des liaison fonction programme / fonction paho
client.on_connect = Connect
client.on_message = Receive

#Abonnement a TTN pour recevoir tout les messages de TTN
client.subscribe("#")


#Créer une boucle infini du script
client.loop_forever()