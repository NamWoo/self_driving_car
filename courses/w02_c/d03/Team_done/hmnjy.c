/***************************************************************

*

*	1. System Init Test 

* 

*	ÀÌÇö¹Î & È²ÁöÀ± switch on & off 

*

****************************************************************

*/



#include "2450addr.h"



#define GPGCON (*(volatile unsigned int *)0x56000060)



#define GPGDAT (*(volatile unsigned int *)0x56000064)



#define GPFCON (*(volatile unsigned int *)0x56000050)



#define GPFDAT (*(volatile unsigned int *)0x56000054)



void LED_Port_Init(void);



void LED_On_Off(int key);



int Get_Key_Polling(void);



void Main(void)



{



    int key,i=0;



    LED_Port_Init();



    while(1){

	

	//upper line switch

        GPFDAT &= ~(0x1 << 7);

        GPGDAT |= 0x1;



        key = Get_Key_Polling();

        LED_On_Off(key);



	// lower line switch

        GPFDAT |= (0x1 << 7);

        GPGDAT &= ~(0x1);



        key = Get_Key_Polling();

        LED_On_Off(key);



	// delay

        for(i =0; i < 0x8ffff; i++){}  

    }



    



}



void LED_Port_Init()



{



    GPFCON &= ~(0x3ff0);



    GPFCON |= (0x4000);



    GPGCON |= (0x1);



    GPFDAT &= ~(0X80);   



    GPGDAT &= ~(0X1);



    GPGDAT &= ~(0xf<<4);



    GPGCON |= (0x55<<10);



}





void LED_On_Off(int key)



{



        GPGDAT |= (0xf << 4);



    switch(key){

	case 0:

            (GPGDAT |= 0xf << 4);

            break;

        case 1:

            (GPGDAT &= 0xe <<4);

            break;

        case 2:

            (GPGDAT &= 0xd <<4);

            break;

        case 3:

            (GPGDAT &= 0xb <<4);

            break;

        case 4:

            (GPGDAT &= 0x7 <<4);

            break;

        case 5:    // switch all off !

	    (GPGDAT |= 0xf << 4);

            break;



      }



}



int Get_Key_Polling(){



    if((GPFDAT & 0x7 ) == 0x3)   // GPFDAT2 switch

        return 1;



    if((GPFDAT & 0xf ) == 0x7)    // GPFDAT3 switch

        return 2;



    if((GPFDAT & 0x1f ) == 0xf)   // GPFDAT4 switch

        return 3;



    if((GPFDAT & 0x3f ) == 0x1f)  // GPFDAT5 switch

        return 4;



    if((GPFDAT & 0x7f ) == 0x3f)  // GPFDAT6 switch

        return 5;    



}




