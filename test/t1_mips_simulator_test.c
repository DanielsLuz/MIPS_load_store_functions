#include"CUnit/CUnit.h"
#include"storeTests.h"
#include"loadTests.h"
#define LIMIT_INDEX 10

int32_t mem[MEM_SIZE];

void printMem(){
  int i = 0;

  printf("*******\n");
  printf(" .data \n");
  printf("*******\n");
  i = 2048;
  while(i != 2058){
    printf("%08x\n", mem[i++]);
  }
}

int init_suite(void){ 
  return 0; 
}

int clean_suite(void){ 
  return 0; 
}


int main (void) {
  CU_pSuite storeSuite = NULL;
  CU_pSuite loadSuite = NULL;

  /* Initialize CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* Add suite to registry */
  storeSuite = CU_add_suite("Store_Functions_Suite", init_suite, clean_suite);
  if (NULL == storeSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Add byte tests to suite */
  if ((NULL == CU_add_test(storeSuite, "storeByteTest", storeByteTest))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Add half word tests to suite */
  if ((NULL == CU_add_test(storeSuite, "storeHalfWordTest", storeHalfWordTest))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Add word tests to suite */
  if ((NULL == CU_add_test(storeSuite, "storeWordTest", storeWordTest))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  loadSuite = CU_add_suite("Load_Functions_Suite", init_suite, clean_suite);
  if (NULL == loadSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(loadSuite, "loadByteTest", loadByteTest))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(loadSuite, "loadByteUnsignedTest", loadByteUnsignedTest))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(loadSuite, "loadHalfWordTest", loadHalfWordTest))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(loadSuite, "loadHalfWordUnsignedTest", loadHalfWordUnsignedTest))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(loadSuite, "loadWordTest", loadWordTest))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Run tests using Basic interface */
  CU_basic_run_tests();

  /* Clean up registry and return */
  CU_cleanup_registry();
  return CU_get_error();
}
