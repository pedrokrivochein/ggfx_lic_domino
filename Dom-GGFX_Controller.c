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
void jogarPeca(); //Inicia o processo para o jogador jogar uma peca
int checarValidadeJogar(tipoPeca peca); //Checa a validade da peca que o jogador escolheu para ser jogada.
void trocarVezJogador(); //Troca a vez dos jogadores.
void escolherJogadorInicial(); //Escolhe o jogador que inicia com base em suas pecas.
void comprarPeca(); //Comprar uma peca.
void adicionarPecaMesaOrdenada(int lado, tipoPeca peca); //Adiciona os pecas na mesa.

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
	
	menuJogadores(); //Chama o menu para escolher a quantidade de jogadores e seus nomes.
	
	embaralharPecas(); //Embaralha as pecas.
	separarPecas(); //Separar as pecas entre os jogadores.

	escolherJogadorInicial(); //Escolhe o jogador que vai comecar com base em suas pecas.

	gameLoop(); //Loop menu jogador
}

void gameLoop(){ //Loop do jogo (Menu de acoes do jogador)
    mostrarPecasMesa();
    mostrarPecasJogador(jogadorAtual);
    char escolha = menuJogo(jogadorAtual);
	switch(escolha){
	    case '1': //Jogar uma peca
		jogarPeca();
			break;
		case '2': //Comprar pecas
		comprarPeca();
			break;
			case '3': //Voltar ao menu
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
			pecas[aux].status = 2;
            aux++;
        }
    }
    
    for(i = 0; i < 28; i++) //Adiciona essas pecas na mesa.
    	mesa[i] = pecas[i];
    
    tipoPeca pecaHolder;
    pecaHolder.status = -1;
    for(i = 0; i < 28; i++) //Adiciona essas pecas na mesa.
    	mesaOrdenada[i].status = -1;
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

		mesa[i].status = aux - 1;
	}
}

void comprarPeca(){ //Comprar pecas
	int i;
	for (i = 0; i < MAXPECA; i++){ //Roda por todas as pecas, a primeira que estiver disponivel para compra vira do jogador.
		if(mesa[i].status == 2){
			mesa[i].status = jogadorAtual;
			printf("\nPeca comprada: [%d:%d]\n", mesa[i].lado1, mesa[i].lado2);
			divisoria();
			return;
		}
	}
}

void jogarPeca(){ //Jogar peca.
	int i, aux = 1;
	int escolha = menuJogarPeca(jogadorAtual); //Chama o menu para o jogador escolher qual peca quer jogar

	if(escolha != 0){
	    for(i = 0; i < MAXPECA; i++){ //Roda pelas pecas e encontra a que o jogador escolheu no menu
	        if(mesa[i].status == jogadorAtual){
	            if(escolha == aux){
	                break;
	            }
	            aux++;
	        }
	    }

	    int checagem = checarValidadeJogar(mesa[i]); //Checa se a peca pode ser jogada.
	    if(checagem != -1){ //A peca pode ser jogada.
	    	tipoPeca pecaAux;
	        if(mesa[i].lado1 == ponta[checagem]){ //Faz a checagem em qual ponta a peca e valida e vira ela de acordo.
	        	ponta[checagem] = mesa[i].lado2;
				if(checagem == 1){ //Jogar no lado direito
	                pecaAux.lado2 = mesa[i].lado2;
	                pecaAux.lado1 = mesa[i].lado1;
	            }else{ //Jogar no lado esquerdo
	                pecaAux.lado1 = mesa[i].lado2;
	                pecaAux.lado2 = mesa[i].lado1;
	            }
	        }else{
	        	ponta[checagem] = mesa[i].lado1;
	            if(checagem == 1){ //Jogador no lado direito
	                pecaAux.lado2 = mesa[i].lado1;
	                pecaAux.lado1 = mesa[i].lado2;
	            }else{ //Jogar no lado esquerdo
	                pecaAux.lado1 = mesa[i].lado1;
	                pecaAux.lado2 = mesa[i].lado2;
	            }
	        }
	        adicionarPecaMesaOrdenada(checagem, pecaAux);
	        mesa[i].status = 3; //A peca vira da mesa.

	        printf("\n\n%s jogou a peca: [%d:%d]\n", jogadores[jogadorAtual].nome, mesa[i].lado1, mesa[i].lado2);
			
	        trocarVezJogador(); //Troca a vez dos jogadores.
	    }else{ //Caso a peca nao possa ser jogada, avisa o jogador.
	        printf("Essa peca nao pode ser jogada.\n"); //Peca invalida
	    }
	}
	divisoria();
}

int checarValidadeJogar(tipoPeca peca){ //Checa a validade de uma peca ser jogada.
	char i, aux = 0, valido = 0;
	for(i = 0; i < 2; i++){ //Checa se nas pontas existe uma peca de mesmo valor.
		if(ponta[i] == peca.lado1 || ponta[i] == peca.lado2){
			aux++;
			valido = i;
		}
	}
	switch(aux){ //Verifica qual lado esta disponivel.
		case 0:
			return -1;
		case 1:
			return valido;
		case 2: //Se dois lados estao disponiveis, da ao jogador a possibilidade de escolher qual lado quer jogar.
			switch (menuEscolhaLado()){//Perguntar qual lado
				case '1':
					return 0;
				case '2':
					return 1;
			}

	}
}

void escolherJogadorInicial(){ //Roda pelas pecas dos jogadores e encontra a peca inicial.
	int i, max = -1, pecaAux;
	for(i = 0; i < 14; i++){ //Checa quem tem a dupla maior
		if(mesa[i].lado1 == mesa[i].lado2){
			if(mesa[i].lado1 > max){
				max = mesa[i].lado1;
				pecaAux = i;
			}
		}
	}
	
	if(pecaAux != -1){ //Caso tenha encontrado uma peca dupla o jogador inicia com essa peca.
		divisoria();
		printf("\n%s iniciou com a peca: [%d:%d]\n\n", jogadores[mesa[pecaAux].status].nome, mesa[pecaAux].lado1, mesa[pecaAux].lado1);
		jogadorAtual = mesa[pecaAux].status; //Jogador atual vira o que possui a peca.
		mesa[pecaAux].status = 3; //Ele joga a peca na mesa.
		trocarVezJogador(); //Troca a vez do jogador.
		
		
		for(i = 0; i < 2; i++) ponta[i] = max; //Adiciona as pecas da ponta.
		tipoPeca pecaHolder;
		pecaHolder.lado1 = max;
		pecaHolder.lado2 = max;
		adicionarPecaMesaOrdenada(0, mesa[pecaAux]);
		return;
	}
	
	max = -1;
	for(i = 0; i < 14; i++){ //Checa quem tem a maior peca somando os dois lados.
		if(mesa[i].lado1 + mesa[i].lado2 > max){
			max = mesa[i].lado1;
			pecaAux = i;
		}
	}
	
	divisoria();
	printf("\n\nJogador %s iniciou com a peca: [%d:%d]\n\n", jogadores[mesa[pecaAux].status].nome, mesa[pecaAux].lado1, mesa[pecaAux].lado2);
	jogadorAtual = mesa[pecaAux].status; //Jogador atual vira o que possui a peca.
	mesa[pecaAux].status = 3; //Ele joga a peca na mesa.
	trocarVezJogador(); //Troca a vez do jogador.
	
	//Adiciona as pecas na ponta.
	ponta[0] = mesa[pecaAux].lado1;
	ponta[1] = mesa[pecaAux].lado2;
	adicionarPecaMesaOrdenada(0, mesa[pecaAux]);
}

void trocarVezJogador(){ //Troca a vez entre os jogadores.
	if(jogadorAtual == 0)
		jogadorAtual = 1;
	else
		jogadorAtual = 0;
}

void adicionarPecaMesaOrdenada(int lado, tipoPeca peca){ //Adicionar uma peca a mesa ordenada.
	int i;
	if(lado == 0){ //Jogar na esquerda
		for(i = 26; i >= 0; i--){ //Joga todas as pecas para uma posicao na frente
			mesaOrdenada[i + 1] = mesaOrdenada[i];
		}
		
		mesaOrdenada[0] = peca; //Coloca a peca na primeira posicao
		
	}else{
		for(i = 0; i < 28; i++){ //Encontra um lugar vazio no final da lista e coloca a peca
			if(mesaOrdenada[i].status == -1){
				mesaOrdenada[i] = peca;
				break;
			}
		}
	}
	
	pecasJogadas++; //Aumenta o numero de pecas jogadas.
}