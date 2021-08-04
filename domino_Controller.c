//Bibliotecas proprias

#include "domino_Model.c"
#include "domino_View.c"

//Funcoes
void inicializarJogo(){
    char escolha = menuGeral();

    switch(escolha){
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
    }
}

void criarPecas(){
    int i, j, aux = 0;

    for(i = 0; i <= 6; i++){
        pecas[aux].lado1 = i;
        for(j = 0; j <= 6; j++){
            pecas[aux].lado2 = j;
        }
        aux++;
    }
}

void embaralharPecas(){
    int valor;
    srand(time(NULL));
    valor = rand() % 28;
}