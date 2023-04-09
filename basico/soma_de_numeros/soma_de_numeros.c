// Receber números e devolver a soma deles.
// Exercício bom para lidar com arrays.

#include <stdio.h>

#define TAMANHO_MAXIMO 80

void receber_numeros(int lista[], int *quantidade)
{
  int opcao = 1;
  do
  {
    printf("Insira um número inteiro:\t");
    scanf("%d", &lista[*quantidade]);
    printf("Insira '0' para encerrar a inserção de números ou '1' para continuar\t");
    scanf(" %d", &opcao);

    (*quantidade)++;
  } while (opcao == 1 && *quantidade < TAMANHO_MAXIMO - 1);
}

int somar_numeros(int lista[], int indice_maximo){
  int soma = 0;
  for (int i = 0; i < indice_maximo; i++)
  {
    soma += lista[i];
  }
  return soma;
}

void main(){
  int lista[TAMANHO_MAXIMO];
  int quantidade = 0;
  receber_numeros(lista, &quantidade);
  int soma = somar_numeros(lista, quantidade);
  printf("A soma dos números inseridos é: %d\n\n", soma);
}
