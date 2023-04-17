// Receber um array como parâmetro e verificar se existe algum número ímpar.
// Caso exista, retornar 1, se não, 0;

#include <stdio.h>

#define ARRAY_TESTE {2, 4, 6, 8, 10, 13}
#define TAMANHO_ARRAY_TESTE 6

int main()
{
  int tamanho_array = TAMANHO_ARRAY_TESTE;
  int nums[] = ARRAY_TESTE;
  for (int i = 0; i < tamanho_array; i++)
  {
    if (nums[i] % 2 == 1){
      printf("\n\tTRUE\n\n");
      return 1;
    }
  }
  printf("\n\tFALSE\n\n");
  return 0;
}
