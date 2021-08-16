//Bibliotecas proprias

#include "Dom-GGFX_Model.c"
#include "Dom-GGFX_View.c"

//Funcoes
void inicializarJogo(); //Inicializa o menu inicial
void iniciarJogo(); //Inicia o jogo
void gameLoop(); //Loop do jogo (Menu de acoes do jogador)
void criarPecas(); //Gera as pecas e as coloca na mesa
void embaralharPecas(); //Embaralha as pecas da mesa
void separarPecas(); //Separar as pecas
void jogarPeca();
int checarValidadeJogar();
void trocarVezJogador();
void escolherJogadorInicial();
void comprarPeca();
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
	embaralharPecas(); //Embaralha as pecas.
	separarPecas(); //Separar as pecas.

	escolherJogadorInicial(); //Escolhe o jogador que vai comecar.

	mostrarPecasMesa(); //Mostra as pecas da mesa.
	
	menuJogadores(); //Chama o menu do nome do jogador.

	gameLoop(); //Loop menu jogador
}

void gameLoop(){ //Loop do jogo (Menu de acoes do jogador)
	char escolha = menuJogo(jogadorAtual);

	switch(escolha){
		case '1': //Mostrar Mesa
			mostrarPecasMesa();
			break;
		case '2':
			mostrarPecasJogador(jogadorAtual);
			break;
		case '3':
			jogarPeca();
			break;
		case '4':
			comprarPeca();
			break;
		case '5': //Voltar ao menu
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
			pecas[aux].status = 3;
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

void separarPecas(){ //Separa as pecas entre os jogadores.
	int i, aux = 0;
	for(i = 0; i < 14; i++){
		if(i % 7 == 0)
			aux++;

		mesa[i].status = aux;
	}
}

void comprarPeca(){
	for (int i = 0; i < MAXPECA; i++){
		if(mesa[i].status == 3){
			mesa[i].status = jogadorAtual;
			return;
		}
	}	
}

void jogarPeca(){
	int i, aux = 1;
	char escolha = menuJogarPeca(jogadorAtual);

	for(i = 0; i < MAXPECA; i++){
        if(mesa[i].status == jogadorAtual){
			if(escolha == aux){
				break;
			}
			aux++;
		}
    }

	int checagem = checarValidadeJogar(mesa[i]);
	if(checagem != -1){
		if(mesa[i].lado1 == ponta[checagem]){
			ponta[checagem] = mesa[i].lado2;
		}else{
			ponta[checagem] = mesa[i].lado1;
		}
		mesa[i].status = 4;
		trocarVezJogador();
	}else{
		printf("Peca nao pode ser colocada ainda :C"); //Peca invalida
	}

}

int checarValidadeJogar(tipoPeca peca){
	char i, aux = 0, valido = 0;
	for(i = 0; i < 2; i++){
		if(ponta[i] == peca.lado1 || ponta[i] == peca.lado2){
			aux++;
			valido = i;
		}
	}
	switch(aux){
		case 0:
			return -1;
		case 1:
			return valido;
		case 2:
			switch (menuEscolhaLado()){//Perguntar qual lado
				case '1':
					return 0;
				case '2':
					return 1;
			}

	}
}

void escolherJogadorInicial(){
	int i, max = -1, jogador;
	for(i = 0; i < 14; i++){ //Checa quem tem a dupla maior
		if(mesa[i].lado1 == mesa[i].lado2){
			if(mesa[i].lado1 > max){
				max = mesa[i].lado1;
				jogador = mesa[i].status;
			}
		}
	}

	/*
	Terminar
	Jogar a peca se encontrou
	Checar maior peca se nao encontrou
	*/
}

void trocarVezJogador(){
	if(jogadorAtual == 0)
		jogadorAtual = 1;
	else
		jogadorAtual = 0;
}