#include<reg51.h>

sbit led = P1^0;
sbit sw = P3^2;

void main(){
	led = 1;
	sw = 0;
	
	while(1){
		if(sw == 1){
			led = 0;
			while(sw == 1);
		}
		else{
			led = 1;
		}
	}
}
	