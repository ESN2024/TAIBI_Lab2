#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include "unistd.h"
#include "alt_types.h"
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_timer.h"
#include "sys/alt_irq.h"
#include "sys/alt_sys_init.h"

//Variables utiles
volatile  unsigned short number = 0x01;
volatile  unsigned short unites,dizaines,centaines = 0x00;



// La fonction Interrupt Sub-Routine
static void handle_interrupts(void* context)
{   
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
		// Incrémenter
		number = number + 1;
	}
	// On rénitialise le compteur à 999
	else{
		number = 0x00;
	}
	// Ecrire dans le registre status pour réinitialiser l'interruption
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);

}



// Initialisation des interruptions
static void init_interruption()
{

	//Enregistrement de la fonction ISR handle_interrupts
	alt_irq_register( TIMER_0_IRQ, NULL, (void*)handle_interrupts);

	// Démarrer le timer en utilisant le registre control, les bits activés sont (ito - cont - start)
	// ALTERA_AVALON_TIMER_CONTROL_ITO_MSK : masque pour gérérer une requète d'interruption 
	// ALTERA_AVALON_TIMER_CONTROL_START_MSK : masque pour commencer le timer
	// ALTERA_AVALON_TIMER_CONTROL_CONT_MSK : masque pour mettre le timer en mode continue, l'arret est effectuer par le bit stop du meme registre
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, ALTERA_AVALON_TIMER_CONTROL_CONT_MSK
			                                   | ALTERA_AVALON_TIMER_CONTROL_START_MSK
											   | ALTERA_AVALON_TIMER_CONTROL_ITO_MSK);

}



int main(){
//Initialisation
init_interruption();

while(1){};

return 0;

}