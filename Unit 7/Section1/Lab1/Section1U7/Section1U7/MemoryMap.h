/*
 * MemoryMap.h
 *
 * Created: 9/4/2024 12:13:38 PM
 *  Author: VTE
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_

#define PIND	 *(volatile unsigned char*)(0x30)
#define DDRD	 *(volatile unsigned char*)(0x31)
#define PORTD	 *(volatile unsigned char*)(0x32)

#endif /* MEMORYMAP_H_ */