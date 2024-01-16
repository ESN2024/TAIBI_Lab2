#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include "unistd.h"

int main(){
volatile  unsigned char one = 0x01;
while(1){
	if(one > 9){
		one = 0000;
	}
	else {
		IOWR_ALTERA_AVALON_PIO_DATA(DIGIT_1_BASE,one);
		IOWR_ALTERA_AVALON_PIO_DATA(DIGIT_2_BASE,one);
		IOWR_ALTERA_AVALON_PIO_DATA(DIGIT_3_BASE,one);
		usleep(100000);
		one = one + 1;
		}

}
}