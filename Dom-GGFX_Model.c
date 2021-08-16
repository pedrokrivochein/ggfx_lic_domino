//Modelo (Estruturas, Variaveis Globais, etc..)

#define MAXPECA 28

typedef struct peca{
    int lado1, lado2;
    int status; //0 - Jogador 1 | 1 - Jogador 2 | 3 - Compra | 4 - Mesa
} tipoPeca;

tipoPeca pecas[MAXPECA]; //Pecas geral
tipoPeca mesa[MAXPECA]; //Mesa do jogo

int ponta[2]; //Pecas na ponta.

typedef struct jogador{
    char nome[100];
} tipoJogador;

tipoJogador jogadores[2]; //Lista de jogadores
int jogadorAtual = 0; //Jogador atual para jogar
