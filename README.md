# TP2_Reseau_Serialization
Sur ce repository est sotcké le TP réalisé dans le cadre du cours de Programmation réseau dans les Jeux Vidéo de l'UQAC, encadré par L. Da Costa.
Il s'agit d'une librairie de Serialization, avec une petit code de mise en pratique.
Contributeurs:
* Oscar Trosseau
* Florent Bogacz
* Hippolyte Gossoin 

## Instructions
Pour utiliser le projet, téléchargez le en local, puis générez et configurez le projet avec Cmake.  
Une fois cela fait, allez dans le dossier Build, puis ouvrez le fichier TP1_Reseau_Serialization.sln avec Visual Studio 2019. Générez le projet, des fichiers .exe auront été crées dans le dossier Build\Debug.
Avez cmd, lancez le fichier TP2_PlayerSerialization.exe de la manière suivante:  
```TP2_PlayerSerialization.exe```  

### Notes
Dans le programme, on créer un objet player, qu'on compresse, sérialise, déserialise et décompresse. On affiche ses valeurs avant et après la sérialisation. Des détailles sur les différentes étapes de la compression/décompression sont affichés. Par manque de temps, nous n'avons pas pu implémenter la sérialisation d'une chaine de caractères.