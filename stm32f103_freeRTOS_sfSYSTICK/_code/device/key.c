#include "config.h"

keyStruct keystr[keyNUM];
//瀹氫箟鎸夐敭璇诲彇
unsigned char keyRead_test(void){
    return TEST_KEY_READ;
}

//浼犻€掓寜閿鍙栧嚱鏁般€佽缃暱鎸夈€佺煭鎸夋椂闂磎s
void keybspinit(void){
    GPIO_InitTypeDef    GPIO_str;
    GPIO_str.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_str.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_str.GPIO_Pin = GPIO_Pin_13;
    GPIO_Init(GPIOC,&GPIO_str);
    
    GPIO_str.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_str.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;
    GPIO_Init(GPIOA,&GPIO_str);
}
void keyvalinit(void){
    memset(&keystr,0,sizeof(keyStruct) *keyNUM);
    
    for(unsigned char i = 0;i<keyNUM;i++){
        keystr[i].Sdelay = KEYshortTIM;
        keystr[i].Ldelay = KEYlongTIM;
    }
    keystr[KEY_CH_trig].pRfunc = &keyRead_test;
}

void key_init(void){
    keybspinit();
    keyvalinit();
}
//1mstick++
void key_tick(void){
    unsigned char i;
    for(i = 0;i< keyNUM;i++){
        keystr[i].u16tick++;
        keystr[i].u16Rtick++;
    }
}

unsigned int keyXvalread(unsigned char ch,unsigned char valnum){
return  keyValread(&keystr[ch],valnum);
}
//func
void key_func(void){
    keyShortPressCHK(&keystr[KEY_CH_test]);
}