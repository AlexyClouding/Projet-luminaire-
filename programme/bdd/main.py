import paho.mqtt.client as mqtt
import json as json
import base64
import mysql.connector
import time
from random import randint

#Création du client MQTT
client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
#Username broker (intégration TTN) -> MDP broker (intégration TTN)
client.username_pw_set("projet-btsfourcade@ttn","NNSXS.TEHNECHZQ3MJQXCVB3RKOSGMPMNUTWRO2GZFRUI.AWERZSCJJVG2RIQMNTWCHXAQ4B7RNLCJWMFPK5ABCAOV2OQ43HPA")

connected = False
while not connected:
    try:
        # Connexion au broker TTN
        client.connect("eu1.cloud.thethings.network", 1883, 60)
        connected = True
        print("Connexion TTN établie")
    except Exception as e:
        print("Échec de la connexion")
        print("Nouvelle tentative de connexion dans 10 secondes...")
        time.sleep(10)  # Pause de 10 secondes avant la prochaine tentative


def connexionDB():
    while True:
        try:
            DataBase = mysql.connector.connect(host="10.10.10.16", user="technicien", password="luminaire123", database="Luminaire")
            db_Info = DataBase.get_server_info()
            print("Connected to MySQL Server version", db_Info)
            return DataBase  # Retourne la connexion à la base de données
        except mysql.connector.Error as err:
            print("Erreur de DB:", err)
            time.sleep(3)

DataBase = connexionDB()
Query = DataBase.cursor()

def RecupData(a,b,c,d,e,f):
    data = (a, b, c, d, e,f)
    ecriture(data)

def ecriture(data):
    print("-----------------")
    try:
        Query.execute("INSERT INTO Mesure (EtatBatterie, EtatLed, Temperature,Niveaubatterie,CourantLed,LuminositeExterieur) VALUES(%s, %s, %s, %s, %s,%s)",data)
        print("Valeurs (%s, %s, %s, %s, %s)",data)
        DataBase.commit()  # N'oubliez pas de valider la transaction
    except mysql.connector.Error as erreur:
        print("Erreur de requete : ", erreur)

def Receive(client, userdata, msg):
    resultat_complet = json.loads(msg.payload.decode())
    payload = resultat_complet['uplink_message']['frm_payload']
    print("Information reçu :", base64.b64decode(payload).decode())
    data=base64.b64decode(payload).decode()

    #---Temperature
    I1 = randint(2,7)
    Temp=I1*5

    #---Etat Batterie
    I2=randint(1,2)
    if I2==1:
        EtatB="ok"
    else:
        EtatB="Defaut"

    #---Niveau Batterie
    I3=randint(1,5)
    NivB=I3*20

    #---Courant Led
    #I4=random.uniform(0, 3.4)
    CourantL=1.2

    #---Etat Led
    I5=randint(1,2)
    if I5==1:
        EtatL="ok"
    else:
        EtatL="Defaut"

    #---Luminosité Extérieur
    LuminoExt=5
    time.sleep(1)
    RecupData(EtatB,EtatL,Temp,NivB,CourantL,LuminoExt)

#Query.execute("SELECT * FROM Mesure")
#rows = Query.fetchall()
#for row in rows:
#    print('{0} : {1} - {2} - {3} - {4} - {5}'.format(row[0], row[1], row[2], row[3], row[4], row[5]))

client.on_message = Receive
client.subscribe("#")
client.loop_forever()

#DataBase.close()
