#include"storeTests.h"

void storeByteTest(void){

  int32_t address;
  int8_t value;

  address = DATA_ADDRESS/4;
  value = 0x0a;

  sb(DATA_ADDRESS, 0, value);
  CU_ASSERT_EQUAL(mem[address], 0x0000000a);

  sb(DATA_ADDRESS, 1, value);
  CU_ASSERT_EQUAL(mem[address], 0x00000a0a);

  //Teste com constante passando para o indice seguinte na memoria
  sb(DATA_ADDRESS, 4, value);
  CU_ASSERT_EQUAL(mem[address + 1], 0x0000000a);
}

void storeHalfWordTest(void){
  /*
   * Teste para halfwords.
   * Constantes impares nao alteram a memoria de forma desalinhada.
   * Apenas constantes pares causam alteracao dos dados.
   * */

  int32_t address;
  int16_t value;
  int32_t wontchangevalue; // Valor usado para verificar a nao alteracao da memoria

  address = DATA_ADDRESS/4;
  value = 0xffff;
  wontchangevalue = 0xaaaa;

  sh(DATA_ADDRESS, 0, value);
  CU_ASSERT_EQUAL(mem[address], 0x0000ffff); //store first halfword

  // Teste com constante impar, valor permanece o mesmo que anterior
  sh(DATA_ADDRESS, 1, value);
  CU_ASSERT_EQUAL(mem[address], 0x0000ffff); 

  sh(DATA_ADDRESS, 2, value);
  CU_ASSERT_EQUAL(mem[address], 0xffffffff); //store second halfword

  // Teste com constante impar, valor permanece o mesmo que anterior
  sh(DATA_ADDRESS, 3, value);
  CU_ASSERT_EQUAL(mem[address], 0xffffffff);

  // Teste com constante passando do indice atual da memoria
  // Comparacao feita com o indice seguinte
  sh(DATA_ADDRESS, 4, value);
  CU_ASSERT_EQUAL(mem[address+1], 0x0000ffff);
}

void storeWordTest(void){
  /*
   * Teste para words.
   * Apenas constantes divisiveis por 4 causam alteracao dos dados.
   * */

  int32_t address;
  int32_t value;
  int32_t wontchangevalue; // Valor usado para verificar a nao alteracao da memoria

  address = DATA_ADDRESS/4;
  value = 0xffffffff;
  wontchangevalue = 0xaaaaaaaa;

  sw(DATA_ADDRESS, 0, value);
  CU_ASSERT_EQUAL(mem[address], 0xffffffff); //store first word

  // Teste constante nao divisivel por 4, valor se mantem inalterado
  sw(DATA_ADDRESS, 1, wontchangevalue);
  CU_ASSERT_EQUAL(mem[address], 0xffffffff); 

  sw(DATA_ADDRESS, 2, wontchangevalue);
  CU_ASSERT_EQUAL(mem[address], 0xffffffff); 

  sw(DATA_ADDRESS, 3, wontchangevalue);
  CU_ASSERT_EQUAL(mem[address], 0xffffffff);

  // Teste com constante passando do indice atual da memoria
  // Comparacao feita com o indice seguinte
  sw(DATA_ADDRESS, 4, value);
  CU_ASSERT_EQUAL(mem[address+1], 0xffffffff); //store second word
}
