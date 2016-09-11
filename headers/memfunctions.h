#include<stdlib.h>

#define MEM_SIZE 4096
#define TEXT_ADDRESS 0x00000000
#define TEXT_LIMIT   0x00000FFC
#define DATA_ADDRESS 0x00002000
#define DATA_LIMIT   0x00003FFF

int32_t lw(int32_t address, int16_t kte);
int32_t lh(int32_t address, int16_t kte);
int32_t lb(int32_t address, int16_t kte);
int32_t lhu(int32_t address, int16_t kte);
int32_t lbu(int32_t address, int16_t kte);
void sw(int32_t address, int16_t kte, int32_t dado);
void sh(int32_t address, int16_t kte, int16_t dado);
void sb(int32_t address, int16_t kte, int8_t dado);
