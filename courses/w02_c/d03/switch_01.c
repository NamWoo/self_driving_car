//#include "2450addr.h"
// 11 #include "libc.h"
 12 void Led_Init(void);
 13 void LED_Port_Init(void);
 14 void LED_ON_Off(void);
 15 void Key_Port_Init(void);
 16 int Key_Get_Pressed();
 17 
 18 void Main()
 19 {
 20 
 21         Led_Init();
 22         Key_Port_Init();
 23 
 24         while(1)
 25         {
 26                 Key_Get_Pressed();
 27         }
 28 
 29 //      if GPF2+ GPF7-  switch on GPF7+
 30 //      GPF 23456 GPF7
 31 //      GPF 23456 GPG0
 32 
 33 
 34 
 35 
 36 
 37 }


 39 //void Switch_Init()
 40 //{
 41 //  rGPFDAT &= 0x00000000;
 42 //  rGPFCON &= 0x00000000;
 43 //}
 44 
 45 
 46 void LED_Port_Init()
 47 {
 48   rGPGDAT &= ~(0xf<<4);
 49   rGPGCON |= (0x55<<8);
 50 }
 51 
 52 
 53 void LED_ON_Off()
 54 {
 55   volatile int i;
 56   rGPGDAT |= (0xf<<4);
 57   for(i=0;i<0xfffff;i++){}
 58   rGPGDAT &= ~(0xf<<4);
 59   for(i=0;i<0xfffff; i++){}
 60 }
 61 
 62 //Function
 64 void Key_Port_Init(void)
 65 {
 66         /* GPFCON -Input Mode GPF[2:6] */
 67         /* YOUR CODE HERE */
 68 
 69     rGPFDAT &= ~(0x3f<<2);      //GPFDAT[1:3] = 0, input mode
 70         rGPFUDP &= ~(0x3ff <<4);//GPFUDP[2:6] = pull up-down disable
 71         rGPFUDP |= (0x2aa <<4); //GPFUDP[2:6] = pull up enable
 72         rGPFCON &= ~(0x3ff <<4);//GPFCON[2:6} = 0, input        
 73 
 74         /* GPFCON, GPGCON - outputmode GPF7, GPG0 */
 75         /* YOUR CODE HERE */
 76         rGPFDAT |= (0x1<<7);    //GPFDAT[3] =  10 ???????
 77         rGPGDAT |= 0x1;                 //GPGDAT[0] = 01 output mode
 78 
 79         rGPFCON &= ~(0x3<<14);  //GPFCON[7] = 00 input
 80         rGPGCON &= ~0x3;                //GPGCON[0] = 00 input
 81         rGPFCON |= (0x1<<14);   //GPFCON[7] = 01 Output
 82         rGPGCON |= 0x1;                 //GPGCON[0] = 01 Output
 83 
 84 }


int Key_Get_Pressed()
 88 {
 89         int i,j, keyval;
 90         int arr[4]={4,5,6,7};
 91         /* YOUR CODE HERE */
 92         for(i=0; i<2; i++)
 93         {
 94                 rGPFDAT |= 0x1<<7;
 95                 rGPGDAT |= 0x1<<0;
 96                 (i==1)?(rGPGDAT &= ~0x1):(rGPFDAT &= ~(0x1<<7));
 97 
 98                 keyval = (~(rGPFDAT>>2) & 0xF);
 99                 /* TO DO : 입력된 키값을 확인하여 리턴하는 switch case문을 작성>    하시오 */
100 
101                 switch(keyval)
102                 {
103                         case 1:
104                                 rGPGDAT &= ~(0x1<<4);
105                                 for(i=0;i<0xffff;i++);
106                                 break;
107                         case 2:
108                                 rGPGDAT &= ~(0x1<<5);
109                                 for(i=0;i<0xffff;i++);
110                                 break;
111                         case 4:
112                                 rGPGDAT &= ~(0x1<<6);
113                                 for(i=0;i<0xffff;i++);
114                                 break;
115                         case 8:
116                                 rGPGDAT &= ~(0x1<<7);
117                                 for(i=0;i<0xffff;i++);
118                                 break;
119                         default:
120                                 rGPGDAT |= (0xf<<4);
121                 }
122 


           //Array ver
124                 for(j=0; j<4;)
125                 {
126                         if(keyval & 0x1)
127                         {
128                                 rGPGDAT &= ~( 0x1<< arr[j] );
129                                 for(i=0;i<0xffff;i++);
130                         }
131                         else
132                         {
133                                 j++;
134                                 keyval >> 1;
135                         }
136                 }
137 
138 /*
139                 for(i=0; i<2; i++)
140                 {
141                         rGPGDAT |= 0x1 <<7;
142                         rGPGDAT |= 0x1 <<0;
143                         (i==1`)?(rGPGDAT &= !0x1):
144                         */
145         }
146 
147         return 0;
148 
149 }



153 void Led_Init()
154 {
155         /* TO DO : Init GPIO port connected to LED 
156          * LED1:LED2:LED3:LED4 = GPG4:GPG5:GPG6:GPG7 */
157         /*rGPGDAT |= (0xf<<4);          //set (=OFF)  GPG4:GPG5:GPG6:GPG7
158         rGPGCON &= ~(0xff<<8);          //SET INPUT mode  GPIO 4:5:6:7
159         rGPGCON |= (0x55<<8);           //SET OUTPUT mode GPIO 4:5:6:7*/
160 
161         rGPGDAT |= (0xf << 4);
162         rGPGCON &= ~(0xff << 8);
163         rGPGCON |= (0x55 << 8);
164 
165 }
166 








