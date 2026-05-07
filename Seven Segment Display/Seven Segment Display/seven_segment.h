#ifndef __SEVEN_SEGMENT__
#define __SEVEN_SEGMENT__

#include <stdint.h>

#define NUMBER_SIZE	11

// Look at "https://www.xlitx.com/datasheet/5161AS.pdf"
// pin no on arduino -> segment
// 0 -> E
// 1 -> D
// 2 -> G
// 3 -> F
// 4 -> C
// 5 -> DP
// 6 -> B
// 7 -> A

#define NUM_0		0xdb
#define NUM_1		0x50
#define NUM_2		0xc7
#define NUM_3		0xd6
#define NUM_4		0x5c
#define NUM_5		0x9e
#define NUM_6		0x9f
#define NUM_7		0xd0
#define NUM_8		0xdf
#define NUM_9		0xde
#define NUM_DOT		0x20

uint8_t numbers[] = {NUM_0,NUM_1,NUM_2,NUM_3,NUM_4,NUM_5,NUM_6,NUM_7,NUM_8,NUM_9,NUM_DOT};

#endif //__SEVEN_SEGMENT__*