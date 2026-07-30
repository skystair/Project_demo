#ifndef __BOARDIO_H
#define __BOARDIO_H


#define TEST_LED_Pin        GPIO_Pin_9
#define TEST_LED_GPIO_Port  GPIOA

#define TEST_KEY_Pin        GPIO_Pin_13
#define TEST_KEY_GPIO_Port  GPIOC


#define TEST_KEY_READ   GPIO_ReadInputDataBit(TEST_KEY_GPIO_Port,TEST_KEY_Pin)

#define TEST_LED_ON     GPIO_SetBits(GPIOA,GPIO_Pin_9)
#define TEST_LED_OFF    GPIO_ResetBits(GPIOA,GPIO_Pin_9);

//userdefine**********************************************
//1.key--------------------------------
#define keyNUM              1
#define KEY_CH_test         0
#define KEY_CH_trig         0   //trig
#define KEY_CH_shift        1   //shift
#define KEY_CH_lock         2   //lock

//#define KEYshortinitTIM		10	//首次上电的按键延时
#define KEYshortTIM         50
#define KEYlongTIM          1500

//2.adc--------------------------------
#define ADCNUM              2
#define ADC_2ndTimes        3   //2^3

#define AD_chgV     sADCx_data[0].avg
#define AD_key      sADCx_data[1].avg

//3.led--------------------------------
#define LEDNUM              1
#define LED_FLASH_ONDELAY   500
#define LED_FLASH_OFFDELAY  500

#define LED_CH_W            0   //
#define LED_CH_R            1   //
//end of userdefine**********************************************

//task info***************************************************






//endof taskinfo**********************************************



#endif
