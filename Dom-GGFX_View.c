//View - Interfaces

//Bibliotecas padrao

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Declaracoes funcoes
void limparBuffer(); //Limpa o buffer do teclado.

char menuGeral(){ //Menu inicial
    printf("\n---DOMINO ETAPA 3---\n");
    printf("\n-----GRUPO GGFX-----\n\n");

    char escolha;
    printf("1) Iniciar novo jogo\n2) Continuar a Jogar - EM BREVE\n3) Salvar Jogo - EM BREVE\n4) Carregar Jogo - EM BREVE\n5) Regras do Jogo - EM BREVE\n6) Sair do Jogo\n-> Escolha uma opcao: ");
    scanf(" %c", &escolha);
    return escolha;
}

void menuJogadores(){ //Menu apos o inicial para escolher quantidade de jogadores
    int qtJogadores;
    do{ //Roda enquanto a quantidade de jogadores nao for valida
        printf("\nQuantidade de jogadores (Max. 2): ");
        scanf("%d", &qtJogadores);
        if(qtJogadores > 2)
            printf("Valor maximo de jogadores: 2");
        else if(qtJogadores < 1)
            printf("Valor minimo de jogadores: 1");
    }while(qtJogadores > 2 || qtJogadores < 1); 
    
    limparBuffer();
    
    printf("Nome jogador 1: ");
    fgets(jogadores[0].nome, 100, stdin);
    jogadores[0].nome[strlen(jogadores[0].nome) - 1] = '\0'; //Remove o \n no final da string.
    
    strcpy(jogadores[1].nome, "Computador"); //Caso o jogador nao escolha 2 jogadores, o nome do 2 fica computador.
    
    if(qtJogadores == 2){
        printf("Nome jogador 2: ");
        fgets(jogadores[1].nome, 100, stdin);
        jogadores[1].nome[strlen(jogadores[1].nome) - 1] = '\0'; //Remove o \n no final da string.
    }
}


char menuJogo(int jogador){ //Menu de acoes dentro do jogo
    char i, escolha, count = 0;
    printf("\nJogo de Domino (GGFX)\n");
    printf("Vez de: %s\n", jogadores[jogador].nome);
    
    for (i = 0; i < MAXPECA; i++){ //Roda pelas pecas e ve quantas estao disponiveis para compra.
        if(mesa[i].status == 2)
            count++;
    }
    
    printf("1) Mesa de Domino\n2) Ver suas pecas\n3) Jogar\n4) Comprar pecas (Restante: %d)\n5) Voltar menu principal\n-> Escolha uma opcao: ", count);
    scanf(" %c", &escolha);
    return escolha;
}

int menuJogarPeca(int jogador){ //Menu para jogar a peca.
    int escolha;

    int i, aux = 1;
    printf("\n");
	for(i = 0; i < MAXPECA; i++){ //Roda pelas pecas do jogador e as numera para que ele possa escolher entre uma.
        if(mesa[i].status == jogador){
		    printf("(%d):[%d:%d] ", aux, mesa[i].lado1, mesa[i].lado2);
		    aux++;
		}
    }
    printf("(%d):Voltar para o menu", aux);
    limparBuffer();
    
    printf("\n-> ");
    scanf("%d", &escolha);
    if(escolha >= aux)
        return 0;
    else
    	return escolha;
}

char menuEscolhaLado(){ //Menu de escolha para qual lado ele quer jogar a peca.
    char escolha;

    do{ //Garante que o usuario escolha 1 ou 2
        printf("Qual lado voce deseja jogar?\n1 - Esquerda\n2 - Direita\n-> ");
        scanf(" %c", &escolha);
    } while(escolha != '1' && escolha != '2');

    return escolha;
}

void mostrarPecasMesa(){ //Mostrar a mesa geral
    printf("\nPecas jogadas: ");

	int i;
	for(i = 0; i < MAXPECA; i++){ //Mostra todas as pecas na mesa.
        if(mesa[i].status == 3)
		    printf("[%d:%d] ", mesa[i].lado1, mesa[i].lado2);
    }
	printf("\n");
	
	printf("Pecas na ponta:\n"); //Mostra so as pecas da ponta.

    printf("    _________________________________\n"
            "   /                                 \\\n"
            "  /          [%d:%d]     [%d:%d]          \\\n"
            " /                                     \\\n"
            "/_______________________________________\\\n"
            "|_______________________________________|\n"
            "     |                             |     \n"
            "     |                             |     \n"
            "     |                             |     \n", ponta[0], ponta[2], ponta[3], ponta[1]);
}

void mostrarPecasJogador(int jogador){ //Mostra as pecas de um jogador especifico.
    int i;
    printf("\nPecas: ");
	for(i = 0; i < MAXPECA; i++){
        if(mesa[i].status == jogador)
		    printf("[%d:%d] ", mesa[i].lado1, mesa[i].lado2);
    }
	printf("\n");
}

void limparBuffer(){ //Limpar buffer do teclado.
    char c;
    while ((c = fgetc(stdin)) != EOF && c != '\n'){}
}