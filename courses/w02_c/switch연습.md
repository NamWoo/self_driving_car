init
```c
/* GPFCON -Input Mode GPF[2:6] */

rGPFDAT &= ~(0x3f<<2);	//GPFDAT[1:3] = 0, input mode
rGPFUDP &= ~(0x3ff <<4);//GPFUDP[2:6] = pull up-down disable
rGPFUDP |= (0x2aa <<4);	//GPFUDP[2:6] = pull up enable
rGPFCON &= ~(0x3ff <<4);//GPFCON[2:6} = 0, input	

/* GPFCON, GPGCON - outputmode GPF7, GPG0 */

rGPFDAT |= (0x1<<7);	//GPFDAT[3] = 10 ???????
rGPGDAT |= 0x1;			//GPGDAT[0] = 01 output mode

rGPFCON &= ~(0x3<<14);	//GPFCON[7] = 00 input
rGPGCON &= ~0x3;		//GPGCON[0] = 00 input
rGPFCON |= (0x1<<14);	//GPFCON[7] = 01 Output
rGPGCON |= 0x1;			//GPGCON[0] = 01 Output
```

```c
rGPFDAT |= 0x1<<7;  //GPFDAT[3] = 10 ????
rGPGDAT |= 0x1<<0;  //GPGDAT[0] = 01
(i==1)?(rGPGDAT &= ~0x1):(rGPFDAT &= ~(0x1<<7));
        //GPGDAT &= ~0x1)       //GPGDAT[0] AB 중 B만 0으로
        //GPFDAT &= ~(0x1<<7)   //GPFDAT[3] AB 중 A만 0으로

keyval = (~(rGPFDAT>>2) & 0xF); //
```

```c
rGPFDAT &= ~(0x3f<<2);	//GPFDAT[1:3] = 0, input mode
rGPFCON &= ~(0x3ff <<4);//GPFCON[2:6} = 0, input	
```