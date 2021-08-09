//Bibliotecas proprias

#include "domino_Model.c"
#include "domino_View.c"

//Funcoes
void iniciarJogo();
void inicializarJogo();
void gameLoop();
void criarPecas();
void embaralharPecas();

void inicializarJogo(){ //Recebe o comando o usuario no menu geral.
    char escolha = menuGeral();

    switch(escolha){
        case '1': //Iniciar jogo
        	iniciarJogo();
            break;
        case '6': //Voltar ao menu
			break;
		default:
			printf("\nEm desenvolvimento\n");
			break;
    }
}

void iniciarJogo(){ //Iniciar o jogo.
	criarPecas();
	mostrarTodasPecas();
	
	menuJogadores(); //Preparacao para Etapa 3

	gameLoop();
	
	/*
	Pedir em algum menu. (Embaralhar e mostrar pecas)
	embaralharPecas();
	mostrarTodasPecas();
	*/
}

void gameLoop(){
	char escolha = menuJogo(jogadorAtual);

	switch(escolha){
		case '1': //Mostrar Mesa
			mostrarTodasPecas();
			break;
		case '3': //Embaralhar pecas
			embaralharPecas();
			break;
		case '6': //Voltar ao menu
			inicializarJogo();
			break;
		default:
			printf("\nEm desenvolvimento\n");
			break;
	}
	gameLoop();
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
	for(i = 0; i < MAXPECA; i++){
		int n = rand() % MAXPECA;
		pecaHolder = mesa[i];
		mesa[i] = mesa[n];
		mesa[n] = pecaHolder;
	}
}
