//Header File
#ifndef bit_math_h
#define bit_math_h

#define SET_BIT(reg,bit) reg = reg|(1<<bit)
#define CLR_BIT(reg,bit) reg = reg &(~(1<<bit))
#define TOG_BIT(reg,bit) reg = reg^(1<<bit)
#define GET_BIT(reg,bit)       (reg>>bit)&1
#define SRR_BIT(reg,bit) 	   (reg%2)*128+(reg>>1)
#define SLR_BIT(reg,bit)       (reg|128)+(reg<<1)
#define KNOW_NUMBER(bit)        bit&(bit-1)

#endif