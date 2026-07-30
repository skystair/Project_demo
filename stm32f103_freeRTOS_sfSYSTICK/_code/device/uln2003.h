#ifndef __ULN2003_H
#define __ULN2003_H

//4涓悓port,杩炲彿IO

#define ULN2003_IOcon	GPIOA->ODR		//port璁剧疆


#define ULN2003_IOpos	0				//鏈€灏忓彿IO


#define ULN2003_SPEED_MAX	1
//#define UNL2003_SPPED_NOR	1

#define UNL2003_SPPED_NOR	40
//#define UNL2003_STEP_MAX	4

#define UNL2003_STEP_MAX	8
#define UNL2003_VALUE_OFF	(~(0xf << ULN2003_IOpos));

typedef struct{
	unsigned char ONflag;
	unsigned char FR;
	unsigned char speed;
	unsigned char steppos;
	unsigned char stepdelay;
	unsigned int tmp;
}Structdef_ULN2003;








extern Structdef_ULN2003 StrULN2003;


extern void ULN2003_tick(void);			//1ms
extern void ULN2003valueinit(void);
extern void ULN2003func(void);			//mainwhile time <1ms



extern void ULN2003_PWR(unsigned char u8ONflag);
extern void ULN2003_speedSet(unsigned char u8speed);
extern void ULN2003_FRSet(unsigned char u8FR);
#endif
