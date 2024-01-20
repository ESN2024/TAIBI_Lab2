#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include "unistd.h"

//Variables utiles
volatile  unsigned short number = 0x01;
volatile  unsigned short unites, dizaines,centaines  = 0x00;


int main(){
   

while(1){
	//Enregistrer les unités
    unites = number % 10;
	//Enregistrer les dizaines
    dizaines = (number / 10) % 10; 
	//Enregistrer centaines
    centaines = number / 100;

	if(number <= 999)
	{
		// Ecrire dans l'afficheur 7seg numéro 1
		IOWR_ALTERA_AVALON_PIO_DATA(DIGIT_1_BASE,unites);
		// Ecrire dans l'afficheur 7seg numéro 2
		IOWR_ALTERA_AVALON_PIO_DATA(DIGIT_2_BASE,dizaines);
		// Ecrire dans l'afficheur 7seg numéro 3
		IOWR_ALTERA_AVALON_PIO_DATA(DIGIT_3_BASE,centaines);
		// Pause pour controler la vitesse du timer 
		usleep(10000);
		// Incrémenter
		number = number + 1;
	}
	// On rénitialise le compteur à 999
	else{
		number = 0x00;
	}

}
}