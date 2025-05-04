#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Jogo simples: Adivinhe o número de 1 a 100
int main() {
    int numSecreto, palpite, tentativas = 0;

    srand(time(NULL));
    numSecreto = rand() % 100 + 1; // Número aleatório entre 1 e 100

    printf("Bem-vindo ao jogo de adivinhar o numero!\n");
    printf("Tente adivinhar o numero de 1 a 100.\n");

    do {
        printf("Digite seu palpite: ");
        scanf("%d", &palpite);
        tentativas++;

        if (palpite < numSecreto) {
            printf("Muito baixo! Tente um numero maior.\n");
        } else if (palpite > numSecreto) {
            printf("Muito alto! Tente um numero menor.\n");
        } else {
            printf("Parabens! Voce acertou o numero em %d tentativas.\n", tentativas);
        }
    } while (palpite != numSecreto);

    return 0;
}
