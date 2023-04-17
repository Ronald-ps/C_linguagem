// Jogo de adivinhação de número. Verifica se o número que você colocou é muito alto ou muito baixo.
// Não tem verificação de tipo de dados, então só insira inteiros.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int gerar_num_aleatorio(){
    srand(time(0));
    return rand() % 100 + 1;
}

void verifica_palpite(int palpite, int num) {
    if (palpite > num) {
        printf("\nChutou muito alto!\n");
    } else if (palpite < num) {
        printf("\nChutou muito baixo\n");
    } else {
        printf("\nAcertou, parabéns!\n");
    }
}

int main() {
    int num, palpite, tentativas = 0;
    num = gerar_num_aleatorio();
    do
    {
        printf("Chute um número:\t\t");
        scanf("%d", &palpite);
        verifica_palpite(palpite, num);
        tentativas++;
    } while (palpite != num);
    printf("Você precisou de %d tentativas.\n\n", tentativas);
}
