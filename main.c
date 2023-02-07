#include <stdio.h>
#include <stddef.h>
#include "test_lllifo.h"
#include "test_cbfifo.h"
#include "lllifo.h"
#include "cbfifo.h"
int main()
{
  
  int result_lllifo, result_cbfifo;
  result_lllifo = test_lllifo();
  result_cbfifo = test_cbfifo();
  if(result_lllifo == 1 && result_cbfifo == 1)
  {
    printf("\nall tests successfully passed\n");
  }
  else
  {
    printf("\nFailed test cases\n");
  }

  return 0;
}
