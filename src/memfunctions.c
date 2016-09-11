#include<stdlib.h>
#include"../headers/memfunctions.h"

extern int32_t mem[MEM_SIZE];

int32_t lw(int32_t address, int16_t kte){
  if(kte % 4 == 0){
    int8_t *p = (int8_t*) mem;
    int32_t *t = (int32_t*) (p + address + kte);
    return *t;
  }
  return NULL;
}

int32_t lh(int32_t address, int16_t kte){
  if(kte % 2 == 0){
    int8_t *p = (int8_t*) mem;
    int16_t *t = (int16_t*) (p + address + kte);
    return *t;
  }
  return NULL;
}

int32_t lhu(int32_t address, int16_t kte){
  if(kte % 2 == 0){
    int8_t *p = (int8_t*) mem;
    int16_t *t = (int16_t*) (p + address + kte);
    return *t & 0x0000ffff;
  }
  return NULL;
}

int32_t lb(int32_t address, int16_t kte){
  int8_t *p = (int8_t*) mem;
  return *(p + address + kte);
}

int32_t lbu(int32_t address, int16_t kte){
  int8_t *p = (int8_t*) mem;
  return *(p + address + kte) & 0x000000ff;
}

void sw(int32_t address, int16_t kte, int32_t dado){
  if(kte % 4 == 0){
    int8_t *p = (int8_t*) mem;
    int32_t *t = (int32_t*) (p + address + kte);
    *t = dado;
  }
}

void sh(int32_t address, int16_t kte, int16_t dado){
  if(kte % 2 == 0){
    int8_t *p = (int8_t*) mem;
    int16_t *t = (int16_t*) (p + address + kte);
    *t = dado;
  }
}

void sb(int32_t address, int16_t kte, int8_t dado){
  int8_t *p = (int8_t*) mem;
  *(p + address + kte) = dado;
}
