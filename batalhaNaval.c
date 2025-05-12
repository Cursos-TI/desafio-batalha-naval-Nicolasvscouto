#include <stdio.h>
#include <stdlib.h> // Para usar a função abs (valor absoluto)

// Constantes
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Funcao para inicializar o tabuleiro
void iniciarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Funcao para verificar se uma coordenada esta dentro dos limites do tabuleiro
int dentroDoTabuleiro(int linha, int coluna) {
    return (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO);
}

// Funcao para criar a matriz de habilidade em cone
void criarHabilidadeCone(int habilidade[7][7]) {
    int centro = 3;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (i >= centro && j >= centro - i + centro && j <= centro + i - centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Funcao para criar a matriz de habilidade em cruz
void criarHabilidadeCruz(int habilidade[7][7]) {
    int centro = 3;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Funcao para criar a matriz de habilidade em octaedro (losango)
void criarHabilidadeOctaedro(int habilidade[7][7]) {
    int centro = 3;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Funcao para aplicar a habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[7][7], int linhaOrigem, int colunaOrigem) {
    int tamanhoHabilidade = 7;
    int centroHabilidade = tamanhoHabilidade / 2;

    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTabuleiro = linhaOrigem - centroHabilidade + i;
                int colunaTabuleiro = colunaOrigem - centroHabilidade + j;
                if (dentroDoTabuleiro(linhaTabuleiro, colunaTabuleiro)) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
                }
            }
        }
    }
}

// Funcao para exibir o tabuleiro
void ExibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int habilidadeCone[7][7];
    int habilidadeCruz[7][7];
    int habilidadeOctaedro[7][7];

    // Inicializar o tabuleiro
    iniciarTabuleiro(tabuleiro);

    // Posicionar alguns navios para visualização
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;
    tabuleiro[6][1] = NAVIO;
    tabuleiro[7][1] = NAVIO;
    tabuleiro[8][1] = NAVIO;

    // Criar as matrizes de habilidade
    criarHabilidadeCone(habilidadeCone);
    criarHabilidadeCruz(habilidadeCruz);
    criarHabilidadeOctaedro(habilidadeOctaedro);

    // Definir pontos de origem para as habilidades
    int linhaOrigemCone = 2;
    int colunaOrigemCone = 7;
    int linhaOrigemCruz = 7;
    int colunaOrigemCruz = 5;
    int linhaOrigemOctaedro = 4;
    int colunaOrigemOctaedro = 2;

    // Aplicar as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeCone, linhaOrigemCone, colunaOrigemCone);
    aplicarHabilidade(tabuleiro, habilidadeCruz, linhaOrigemCruz, colunaOrigemCruz);
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, linhaOrigemOctaedro, colunaOrigemOctaedro);

    // Exibir o tabuleiro com as habilidades aplicadas
    printf("Tabuleiro com habilidades:\n");
    ExibirTabuleiro(tabuleiro);

    return 0;
}