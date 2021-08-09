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
        case '2':
        case '3':
            break;
    }
}

void iniciarJogo(){ //Iniciar o jogo.
	criarPecas();
	mostrarTodasPecas();
	
	menuJogadores();

	gameLoop();
	
	/*
	Pedir em algum menu. (Embaralhar e mostrar pecas)
	embaralharPecas();
	mostrarTodasPecas();
	*/
}

void gameLoop(){
	char escolha;
	do{
		escolha = menuJogo(jogadorAtual);

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
				printf("Em desenvolvimento");
				break;
		}

		if(jogadorAtual == 0) //Invertes a vez dos jogadores
			jogadorAtual = 1;
		else
			jogadorAtual = 0;
	}while(escolha != '6' && escolha > 0 && escolha < 7);
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