#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include "unistd.h"
#include "alt_types.h"
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_timer.h"
#include "sys/alt_irq.h"
#include "sys/alt_sys_init.h"

//variables globales
volatile  unsigned short number = 0x01;
volatile  unsigned short unites = 0x00;
volatile  unsigned short dizaines = 0x00;
volatile  unsigned short centaines = 0x00;


// La fonction Interrupt Sub-Routine
static void handle_interrupts(void* context)
{   
	unites = number % 10;
    dizaines = (number / 10) % 10; 
    centaines = number / 100;
	if(number <= 999)
	{
		IOWR_ALTERA_AVALON_PIO_DATA(DIGIT_1_BASE,unites);
		IOWR_ALTERA_AVALON_PIO_DATA(DIGIT_2_BASE,dizaines);
		IOWR_ALTERA_AVALON_PIO_DATA(DIGIT_3_BASE,centaines);
		number = number + 1;
	}
	else{
		number = 0x00;
	}
	// Clear the interrupt
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);

}



// Initialisation des interruptions
static void init_interruption()
{

	// Start the timer (continous - start - ito?)
		//register to HAL
	alt_irq_register( TIMER_0_IRQ, NULL, (void*)handle_interrupts);


	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, ALTERA_AVALON_TIMER_CONTROL_CONT_MSK
			                                   | ALTERA_AVALON_TIMER_CONTROL_START_MSK
											   | ALTERA_AVALON_TIMER_CONTROL_ITO_MSK);

}



int main(){


init_interruption();
while(1){};
return 0;

}