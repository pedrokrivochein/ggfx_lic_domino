//Bibliotecas proprias

#include "Dom-GGFX_Model.c"
#include "Dom-GGFX_View.c"

//Funcoes
void inicializarJogo(); //Inicializa o menu inicial
void iniciarJogo(); //Inicia o jogo
void gameLoop(); //Loop do jogo (Menu de acoes do jogador)
void criarPecas(); //Gera as pecas e as coloca na mesa
void embaralharPecas(); //Embaralha as pecas da mesa

void inicializarJogo(){ //Recebe o comando o usuario no menu geral.
    char escolha = menuGeral();

    switch(escolha){
        case '1': //Iniciar jogo
        	iniciarJogo();
            break;
        case '6': //Voltar ao menu
			return;
		default:
			printf("\nEm desenvolvimento\n");
			inicializarJogo();
			break;
    }
}

void iniciarJogo(){ //Iniciar o jogo.
	criarPecas(); //Gera as pecas da mesa.
	mostrarTodasPecas(); //Mostra as pecas da mesa.
	
	menuJogadores(); //Chama o menu do nome do jogador.

	gameLoop(); //Loop menu jogador
}

void gameLoop(){ //Loop do jogo (Menu de acoes do jogador)
	char escolha = menuJogo(jogadorAtual);

	switch(escolha){
		case '1': //Mostrar Mesa
			mostrarTodasPecas();
			break;
		case '3': //Embaralhar pecas e mostra-las
			embaralharPecas();
			mostrarTodasPecas();
			break;
		case '6': //Voltar ao menu
			inicializarJogo();
			return;
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
	for(i = 0; i < MAXPECA; i++){ //Escolhe um numero aleatorio e troca as pecas.
		int n = rand() % MAXPECA;
		pecaHolder = mesa[i];
		mesa[i] = mesa[n];
		mesa[n] = pecaHolder;
	}
}
