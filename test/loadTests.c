#include"loadTests.h"

void loadByteTest(void){
  int32_t address;
  int32_t value;

  address = DATA_ADDRESS/4;

  *(mem + address) = 0x04030201;

  value = lb(DATA_ADDRESS, 0);
  CU_ASSERT_EQUAL(value, 0x00000001);

  value = lb(DATA_ADDRESS, 1);
  CU_ASSERT_EQUAL(value, 0x00000002);

  value = lb(DATA_ADDRESS, 2);
  CU_ASSERT_EQUAL(value, 0x00000003);

  value = lb(DATA_ADDRESS, 3);
  CU_ASSERT_EQUAL(value, 0x00000004);
}

void loadByteUnsignedTest(void){
  int32_t address;
  int32_t value;

  address = DATA_ADDRESS/4;

  *(mem + address) = 0x00000080;

  value = lb(DATA_ADDRESS, 0);
  CU_ASSERT_EQUAL(value, 0xffffff80);

  value = lbu(DATA_ADDRESS, 0);
  CU_ASSERT_EQUAL(value, 0x00000080);
}

void loadHalfWordTest(void){
  int32_t address;
  int32_t value;

  address = DATA_ADDRESS/4;

  *(mem + address) = 0x04030201;

  value = lh(DATA_ADDRESS, 0);
  CU_ASSERT_EQUAL(value, 0x00000201);

  // Teste com constante impar, nao retorna nada pois estara desalinhado
  value = lh(DATA_ADDRESS, 1);
  CU_ASSERT_EQUAL(value, NULL);

  value = lh(DATA_ADDRESS, 2);
  CU_ASSERT_EQUAL(value, 0x00000403);

  // Teste com constante impar, nao retorna nada pois estara desalinhado
  value = lh(DATA_ADDRESS, 3);
  CU_ASSERT_EQUAL(value, NULL);
}

void loadHalfWordUnsignedTest(void){
  int32_t address;
  int32_t value;

  address = DATA_ADDRESS/4;

  *(mem + address) = 0x0000ffff;

  value = lh(DATA_ADDRESS, 0);
  CU_ASSERT_EQUAL(value, 0xffffffff);

  value = lhu(DATA_ADDRESS, 0);
  CU_ASSERT_EQUAL(value, 0x0000ffff);
}

void loadWordTest(void){
  int32_t address;
  int32_t value;

  address = DATA_ADDRESS/4;

  mem[address] = 0x04030201;
  mem[address + 1] = 0x0f0f0f0f;

  value = lw(DATA_ADDRESS, 0);
  CU_ASSERT_EQUAL(value, 0x04030201);

  // Teste com constante nao divisivel por 4
  value = lw(DATA_ADDRESS, 1);
  CU_ASSERT_EQUAL(value, NULL);

  // Teste com constante nao divisivel por 4
  value = lw(DATA_ADDRESS, 2);
  CU_ASSERT_EQUAL(value, NULL);

  // Teste com constante nao divisivel por 4
  value = lw(DATA_ADDRESS, 3);
  CU_ASSERT_EQUAL(value, NULL);

  value = lw(DATA_ADDRESS, 4);
  CU_ASSERT_EQUAL(value, 0x0f0f0f0f);
}
