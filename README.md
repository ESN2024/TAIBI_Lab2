# TAIBI_Lab2

# I - Introduction:
Ce dépôt github contient les deux versions demandées dans le Lab2, un compteur sans timer et un compteur avec timer (par interruption).vous trouverez les deux versions dans deux branches différentes *main* et *Counter_without_timer*.


# II - L'architecture du système:
#### 1 - Architecture du design:
[Image de l'architecture sans timer ![Alt text](https://assets.digitalocean.com/articles/alligator/boo.svg "a title")]
[Image de l'architecture avec timer ![Alt text](https://assets.digitalocean.com/articles/alligator/boo.svg "a title")]
Les blocs IP utilisés (voir schéma au-dessus) sont les suivants:
- **NIOS II Core:** un softcore d'architecture Harvard et de jeu d'instruction réduit (RISC 32 bits) en mode economy.
- **Memoire RAM:** 40 ko.
- **JTAG UART:** permettant le débogage.
- **Clock:** 50 MHz.
- **Timer:** (seulement pour la version 2) bloc IP timer pour generer des interruptions avec un niveau d'interruption 1.
- **3 PIO de 4 bits en sortie**: .

#### 2 - Fichier QSYS:
##### 2.1 - Version 1 :
[Image de l'architecture]
##### 2.2 - Version 2 :
[Image de l'architecture]
Le timer gènère  une interruption de niveau 1, les paramètres de ce 
