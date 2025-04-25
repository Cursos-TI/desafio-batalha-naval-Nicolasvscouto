#include <stdio.h>

//constantes com os valores de cada variavel importante (evitar que o valor se altere com o decorrer do codigo)
#define TAMANHO_TABULEIRO 10 // tabuleiro eh uma matriz 10x10 
#define TAMANHO_NAVIO 3 // cada navio eh representado por um vetor e o navio ocupa 3 posicoes desse vetor (3 posicoes com o valor 3    ) (que nem descrito pelo desafio iniciante)
#define AGUA 0 //para podermos diferenciar aonde cada navio esta, vamos inicializar a matriz com todos os seus indices com o valor da agua (cujo valor eh 0)
#define NAVIO 3 //constante que sera utilizada para aplicar um navio no tabuleiro


//Funcao para inicializar o tabuleiro

void iniciarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    for(int i = 0; i < TAMANHO_TABULEIRO; i++){
        for(int j = 0; j < TAMANHO_TABULEIRO; j ++){
            tabuleiro[i][j] = AGUA;
        }
    }
}

//funcao para verificar se o navio pode ser posicionado no tabuleiro

int verificarPosicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, int horizontal){
    if(horizontal){
        if(coluna + tamanho > TAMANHO_TABULEIRO){
            return 0; //nao podemos colocar algo que extrapole o tamanho da matriz
        }
        for(int i = 0; i < tamanho; i++){
            if(tabuleiro[linha][coluna + i] == NAVIO){ //evitar sobreposicao de outro navio que ja esteja no tabuleiro
                return 0;
            }
        }
    }else{
        if(linha + tamanho > TAMANHO_TABULEIRO){
            return 0; //nao podemos colocar algo que extrapole o tamanho da matriz
        }
        for(int i = 0; i < tamanho; i++){
            if(tabuleiro[linha + i][coluna] == NAVIO){ //evitar sobreposicao de outro navio que ja esteja no tabuleiro
                return 0;
            }
        }
    }
    return 1;
}
//funcao para posicionar o navio no tabuleiro

void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, int horizontal){
    if(horizontal){
        for(int i = 0; i < tamanho; i++){
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    }else{
        for(int i = 0; i < tamanho; i++){
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

//funcao para exibir o tabuleiro

void ExibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    printf("  ");
    for(int i = 0; i < TAMANHO_TABULEIRO; i++){
        printf("%d", i);
    }
    printf("\n");
    for(int i = 0; i < TAMANHO_TABULEIRO; i++){
        printf("%d", i);
        for(int j = 0; j < TAMANHO_TABULEIRO; j++){
            printf("%d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main(){
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    //agora vamos inicializar o tablueiro!
    iniciarTabuleiro(tabuleiro);

    //agora vammos definir quais sao as coordenadas do primeiro navio no tabuleiro
    int linhaNavio1 = 2;
    int colunaNavio1 = 3;
    int horizontalNavio1 = 1; // isso serve para dizer o navio estara na horizontal ou na vertical

    

    //passamos todas variaveis criadas como parametros para deixar o programa mais limpo e pratico
    if(verificarPosicao(tabuleiro, linhaNavio1, colunaNavio1, TAMANHO_NAVIO, horizontalNavio1))  {
        posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, TAMANHO_NAVIO, horizontalNavio1);
        printf("Navio horizontal posicionado em (%d, %d).\n",linhaNavio1, colunaNavio1);
    }else{
        printf("Infelizmente nao foi possivel posicionar o navio na posicao (%d, %d).\n", linhaNavio1, colunaNavio1);
    }

    //agora so repetimos o processo e definimos outro navio, porem, na vertical.

    int linhaNavio2 = 6;
    int colunaNavio2 = 1;
    int horizontalNavio2 = 0;
    
    if(verificarPosicao(tabuleiro, linhaNavio2, colunaNavio2, TAMANHO_NAVIO, horizontalNavio2))  {
        posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, TAMANHO_NAVIO, horizontalNavio2);
        printf("Navio horizontal posicionado em (%d, %d).\n",linhaNavio2, colunaNavio2);
    }else{
        printf("Infelizmente nao foi possivel posicionar o navio na posicao (%d, %d).\n", linhaNavio2, colunaNavio2);
    }

    printf("\nTabuleiro com os navios: \n");
    ExibirTabuleiro(tabuleiro);


    return 0;
}


