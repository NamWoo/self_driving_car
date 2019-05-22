//LED init, off state
//GPG4,GPG5,GPG6,GPG7
//GPGCON OUTPUT mode 01 
//GPG4[9:8] ~ GPG7[15:14]
//all clear 0
rGPGCON &= ~(0xff<<8);	//ready 00
rGPGCON &= ~(0x55<<8);	//OUTPUT mode 01

//GPGDAT
//GPG[15:0]
rGPGDAT |= (0xf<<4);	//LED off

//KEY init
//GPG0
rGPGCON |= (0x01);		//OUTPUT mode 01 
rGPGDAT &= ~(0x0);		//GND 0
//GPF7
rGPFCON |= (0x01<<14);	//OUTPUT mode 01
rGPFDAT &= (0x0<<14);	//GND 0
//GPF[2:6]
rGPFCON &= 
