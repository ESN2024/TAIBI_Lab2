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
Dans cette version Le timer gènère  une interruption de niveau 1, les paramètres de ce 

# III - Progrès:
#### 1 - Platform Designer :
Sur Platform Designer, les étapes suivantes ont été effectuées dans leur ordre :
-   Câblage des composants comme montré dans la figure ci-dessus.
-   Définition du Reset/Exception de la mémoire sur l'IP du softcore.
-   Désactivation de l'initialisation de la mémoire.
-   Attribution des adresses à la mémoire.
-   Génération du système en QSYS.

#### 2 - Quartus :
Après l'implémntation du squelette du code VHDL offert par Plateform Designer.le fichier *bin_to_7seg.vhd* a été ajouté au projet, ce dernier contient le code VHDL de l'afficheur 7 segments. La programmation sur la carte a été effectuée après les étapes suivantes :
-   L'ajout de 3 sorties de 7 bits : *leds_digit_1*, *leds_digit_2* et *leds_digit_3* dans le fichier *TAIBI_Lab2.vhd*
-   L'instanciation un seul Nios2 et 3 composants *bin_to_7seg* dans *TAIBI_Lab2.vhd*.
-   Assignation des broches.
-   Choix de *TAIBI_Lab2.vhd* comme Top Level Entity.
-   Compilation.
-   Programmation sur la carte .

#### 3 - Nios2 Command Shell :
Comme vu en cours, il est indispensable de générer le BSP/HAL, puis de créer un Makefile pour le programme logiciel que nous utilisons ensuite pour la programmation du Compteur.
> Remarque: Pour cette étape j'ai utilisé les commandes shell su cours.

#### 4 - Program C :
Ma stratégie pour effectuer ce TP a été réparties par plusieurs étape, pour passer d'une étape à l'autre j'ai effectué des tests de validation. Consultez les commits pour revenir à une étape précise. 

**Étape 0 :** Afficher un nombre (codé en dur) sur un seul afficheur 7 seg.

**Validation 0:** L'Intéraction entre les différents blocs IP : Nios2, RAM, digit_1.

**Étape 1 :**: Coder le compteur et le convertisseur BCD en software, puis tester.

**Validation 1**: Le compteur (1 - 999) est fonctionnel.

**Étape 2 :** De la mème façon que dans le Lab1, pour créer des interruptions générés par un timer chaque second (période réglée sur QSYS), deux fonctions sont introduites :
-   *handle_interrupts()* : Contient l'affichage d'un message sans *usleep()*
-   *init_interruption()* : l'enregistrement de la fonction ISR handle_interrupts() + L'utilisation des masques définis dans le fichier *altera_avalon_timer_regs.h* pour générer une requète d'interruption, mettre le timer en mode continu puis démarrer le timer 

**Validation 2 :** L'interruption est validée, chaque second j'ai un message qui s'affiche sur le *nios2-terminal*.

**Étape 3 :** L'ajout du compteur dans la fonction.

**Étape 4 :** Refactoring du code

# IV - Résultats:
La video ci-dessous montre une démonstration du compteur sans timer :
[Video]
La video ci-dessous montre une démonstration du compteur avec timer :
[Video]
# V - Conclusion:
L'utilisation de l'interruption dans le Lab1 a été très utile, car ce deuxième Lab2 constitue une application directe de l'interruption par timer. L'utilisation des macros fournies par le BSP est également très utile, car cela facilite la manipulation des registres.
