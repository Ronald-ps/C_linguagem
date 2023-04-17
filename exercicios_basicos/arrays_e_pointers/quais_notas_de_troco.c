// Função recebe um valor que deve ser dado como troco (um inteiro)
// e calcula quantas notas de 100, 50, 20, 10, 5, e moedas de 1 devem ser dadas.

// Exercício para usar ponteiros.

#include <stdio.h>
#include <stdlib.h>

#define TROCO 498

int *calcula_quant_notas(int troco, int notas[],int tamanho_array_notas){
  int *quant_notas = malloc(tamanho_array_notas * sizeof(int));
  for (int i = 0; i < tamanho_array_notas; i++){
    int nota_atual = notas[i];
    if (troco < nota_atual)
    {
      quant_notas[i] = 0;
      continue;
    }
    quant_notas[i] = troco / nota_atual;
    troco %= nota_atual;
  }
  return quant_notas;
}

void printa_array(int* quant_notas, int notas[], int tamanho_array){
  for (int i = 0; i < tamanho_array; i++){
    printf("\n\t%d é a quantidade de notas de %d\n", quant_notas[i], notas[i]);
  }
}

int main(){
  int troco = TROCO;
  int notas[] = {100, 50, 20, 10, 5, 1};
  int tamanho_array_notas = 6;
  int *quantidade_notas = calcula_quant_notas(troco, notas, tamanho_array_notas);
  printa_array(quantidade_notas, notas, tamanho_array_notas);
  free(quantidade_notas);
  return 0;
}
