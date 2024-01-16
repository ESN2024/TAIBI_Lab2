#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include "unistd.h"

int main(){
volatile  unsigned short number = 0x01;
volatile  unsigned short unites = 0x00;
volatile  unsigned short dizaines = 0x00;
volatile  unsigned short centaines = 0x00;

   

while(1){
    unites = number % 10;
    dizaines = (number / 10) % 10; 
    centaines = number / 100;
	if(number <= 999)
	{
		IOWR_ALTERA_AVALON_PIO_DATA(DIGIT_1_BASE,unites);
		IOWR_ALTERA_AVALON_PIO_DATA(DIGIT_2_BASE,dizaines);
		IOWR_ALTERA_AVALON_PIO_DATA(DIGIT_3_BASE,centaines);
		usleep(10000);
		number = number + 1;
	}
	else{
		number = 0x00;
	}

}
}