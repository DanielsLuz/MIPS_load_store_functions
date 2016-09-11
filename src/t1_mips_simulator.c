#include<stdio.h>
#include<stdlib.h>
#include"../headers/memfunctions.h"

int32_t mem[MEM_SIZE];

void read(int32_t initialAdress, char* filename, int32_t readSize){
  FILE *file;
  file = fopen(filename, "rb");
  int8_t *p = (int8_t*) mem;

  fread((p + initialAdress), 4, readSize, file);
}

void readBinaries(){
  read(TEXT_ADDRESS, "mars/text.bin", TEXT_LIMIT);
  read(DATA_ADDRESS, "mars/data.bin", DATA_LIMIT);
}

void printMem(){
  int32_t value;
  printf("*******\n");
  printf(" .text \n");
  printf("*******\n");
  int i = 0;
  while(value = lw(TEXT_ADDRESS, i)){
    printf("%08x\n", value);
    i += 4;
  }

  printf("*******\n");
  printf(" .data \n");
  printf("*******\n");
  i = 0;
  while(value = lw(DATA_ADDRESS, i)){
    printf("%08x\n", value);
    i += 4;
  }
}

int main(){
  readBinaries();
  printMem();
}
