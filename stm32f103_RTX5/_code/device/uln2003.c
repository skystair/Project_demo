#include "config.h"
//#include "uln2003.h"

unsigned short int ULN2003cnt;
const unsigned char u8uln2003stepvalue[UNL2003_STEP_MAX] = {0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09};
//const unsigned char u8uln2003stepvalue[UNL2003_STEP_MAX] = {0x01,0x02,0x04,0x08};
Structdef_ULN2003 StrULN2003;


void ULN2003valueinit(void);
void ULN2003func(void);

void ULN2003_tick(void);
void ULN2003_PWR(unsigned char u8ONflag);
void ULN2003_speedSet(unsigned char u8speed);
void ULN2003_FRSet(unsigned char u8FR);

void ULN2003_PWR(unsigned char u8ONflag){
	if(u8ONflag == 1){
		StrULN2003.ONflag = 1;
	}else{
		StrULN2003.ONflag = 0;
	}
}
void ULN2003_speedSet(unsigned char u8speed){
	StrULN2003.speed = u8speed;
}

void ULN2003_FRSet(unsigned char u8FR){
	if(u8FR == 1){
		StrULN2003.FR = 1;
	}else{
		StrULN2003.FR = 0;
	}
}
void ULN2003_tick(void){
	StrULN2003.stepdelay++;
}

void ULN2003valueinit(void){
	ULN2003cnt = 0;
	StrULN2003.ONflag = 1;
	StrULN2003.FR = 0;
	StrULN2003.speed = UNL2003_SPPED_NOR;
	StrULN2003.steppos = 0;
	StrULN2003.stepdelay = 0;
	
}
void ULN2003func(void){
	if(StrULN2003.ONflag == 0){
		//GPIOA->BSRR = (0x0f << 16u);
		
		ULN2003_IOcon &= UNL2003_VALUE_OFF;
		
		StrULN2003.stepdelay = 0;
	}else{
		if(StrULN2003.stepdelay > StrULN2003.speed){
			StrULN2003.stepdelay = 0;
			
			StrULN2003.tmp = ULN2003_IOcon;
			StrULN2003.tmp &= UNL2003_VALUE_OFF;
			StrULN2003.tmp |= (u8uln2003stepvalue[StrULN2003.steppos] << ULN2003_IOpos);
			
			ULN2003_IOcon = StrULN2003.tmp;
			
//			ULN2003_IOcon &= (~(0xf));
//			ULN2003_IOcon |= u8uln2003stepvalue[StrULN2003.steppos];
			
//			GPIOA->BSRR = u8uln2003step[u8uln2003steppos];
//			GPIOA->BSRR = ( ((~u8uln2003step[u8uln2003steppos]) & 0xf) << 16u);
			
			if(StrULN2003.FR == 0){
				StrULN2003.steppos++;
				if(StrULN2003.steppos >= UNL2003_STEP_MAX){
					StrULN2003.steppos = 0;
					ULN2003cnt++;
				}
			}else{
				if(StrULN2003.steppos == 0){
					StrULN2003.steppos = UNL2003_STEP_MAX;
					ULN2003cnt++;
					
				}else{
					StrULN2003.steppos--;
				}
			}
			
			if(ULN2003cnt > 1487){//510---360
				ULN2003cnt = 0;
//				if(StrULN2003.FR == 0){
//					StrULN2003.FR = 1;
//				}else{
//					StrULN2003.FR = 0;
//				}
			}
		}
	}
//	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == GPIO_PIN_RESET){
//		StrULN2003.ONflag = 1;
//	}else{
//		StrULN2003.ONflag = 0;
//	}
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == GPIO_PIN_RESET){
		StrULN2003.FR = 1;
	}else{
		StrULN2003.FR = 0;
	}
}