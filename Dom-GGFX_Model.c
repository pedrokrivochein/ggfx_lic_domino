//Modelo (Estruturas, Variaveis Globais, etc..)

#define MAXPECA 28

typedef struct peca{
    int lado1, lado2;
} tipoPeca;

tipoPeca pecas[MAXPECA]; //Pecas geral
tipoPeca mesa[MAXPECA]; //Mesa do jogo

typedef struct jogador{
    char nome[100];
    tipoPeca mao[7];
} tipoJogador;

tipoJogador jogadores[2]; //Lista de jogadores
int jogadorAtual = 0; //Jogador atual para jogar
