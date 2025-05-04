#include <stdio.h>

#define NUM_QUESTOES 10 // Atualize para o número total de perguntas

int main() {
    // Definindo as perguntas, alternativas e respostas corretas
    char *perguntas[NUM_QUESTOES] = {
        "Qual e a extensao padrao dos arquivos de codigo fonte em C?",
        "Qual das seguintes opcoes e uma estrutura de controle em C?",
        "Qual e o operador usado para acessar membros de uma estrutura?",
        "Qual e a funcao usada para imprimir na tela em C?",
        "Qual e o valor de retorno da função main em C quando executada com sucesso?",
        "Qual e o operador usado para realizar a divisao inteira em C?",
        "Qual e o tipo de dado que pode armazenar um unico caractere em C?",
        "O que significa a sigla NULL em C?",
        "O que a palavra-chave extern indica em C?",
        "Qual e a estrutura de repeticao que garante que o bloco de codigo seja executado pelo menos uma vez?"
    };

    char *alternativas[NUM_QUESTOES][4] = {
        {"(1) .c", "(2) .cpp", "(3) .java", "(4) .txt"},
        {"(1) if", "(2) for", "(3) while", "(4) todas as anteriores"},
        {"(1) .", "(2) ->", "(3) *", "(4) &"},
        {"(1) printf", "(2) print", "(3) write", "(4) display"},
        {"(1) 0", "(2) 1", "(3) -1", "(4) nenhum"},
        {"(1) /", "(2) //", "(3) ||", "(4) div"},
        {"(1) char", "(2) string", "(3) int", "(4) float"},
        {"(1) Um valor inteiro", "(2) Um ponteiro que nao aponta para nenhum lugar", "(3) Um tipo de dado", "(4) Um erro de execucao"},
        {"(1) Uma variavel local", "(2) Uma variavel global", "(3) Uma funcao interna", "(4) Uma funcao externa"},
        {"(1) for", "(2) while", "(3) do while", "(4) foreach"}
    };

    int respostas_certas[NUM_QUESTOES] = {0, 3, 0, 0, 0, 0, 0, 1, 1, 2}; // Índices das respostas corretas (as posições começam em 0)
    int acertos = 0; // Contador de acertos
    int resposta_usuario; // Variável para armazenar a resposta do usuário

    printf("========================================\n");
    printf("Bem-vindo ao Quiz sobre a Linguagem C!\n");
    printf("========================================\n");

    // Loop para percorrer as perguntas
    for (int i = 0; i < NUM_QUESTOES; i++) {
        printf("Pergunta %d: %s\n", i + 1, perguntas[i]);
        
        // Exibir alternativas
        for (int j = 0; j < 4; j++) {
            printf("%s\n", alternativas[i][j]);
        }

        // Solicitar resposta do usuário
        printf("Escolha a resposta (1-4): ");
        scanf("%d", &resposta_usuario);

        // Verificar se a resposta está correta
        if (resposta_usuario - 1 == respostas_certas[i]) {
            printf("CORRETO!\n\n");
            acertos++; // Incrementar acertos
        } else {
            printf("INCORRETO! A resposta correta era: %s\n\n", alternativas[i][respostas_certas[i]]);
        }
    }

    // Exibir total de acertos
    printf("Voce acertou %d de %d perguntas.\n", acertos, NUM_QUESTOES);

    if (acertos >= 8 && acertos <= NUM_QUESTOES) {
        printf ("Parabéns! Voce e um expert em C!\n");
    } else if (acertos >= 5 && acertos < 7) {
        printf ("Voce e bom nisso!\n");
    } else {
        printf ("Continue estudando! Voce pode melhorar!\n");
    }

    return 0;
}