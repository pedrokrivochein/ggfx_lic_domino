//Bibliotecas proprias

#include "domino_Model.c"
#include "domino_View.c"

//Funcoes
void iniciarJogo();
void inicializarJogo();
void criarPecas();
void embaralharPecas();

void inicializarJogo(){ //Recebe o comando o usuario no menu geral.
    char escolha = menuGeral();

    switch(escolha){
        case '1':
        	iniciarJogo();
            break;
        case '2':
        case '3':
            break;
    }
}

void iniciarJogo(){ //Iniciar o jogo.
	criarPecas();
	mostrarTodasPecas();
	
	menuJogadores();
	
	/*
	Pedir em algum menu. (Embaralhar e mostrar pecas)*/
	embaralharPecas();
	mostrarTodasPecas();
}

void criarPecas(){
    int i, j, aux = 0;

    for(i = 0; i <= 6; i++){ //Gera as 28 pecas.
        for(j = i; j <= 6; j++){
        	pecas[aux].lado1 = i;
            pecas[aux].lado2 = j;
            aux++;
        }
    }
    
    for(i = 0; i < 28; i++) //Adiciona essas pecas na mesa.
    	mesa[i] = pecas[i];
}

void embaralharPecas(){ //Embaralha as pecas na mesa.
	tipoPeca pecaHolder;
	
	int i;
    	
	srand(time(NULL));
	for(i = 0; i < 28; i++){
		int n = rand() % 28;
		pecaHolder = mesa[i];
		mesa[i] = mesa[n];
		mesa[n] = pecaHolder;
	}
}
