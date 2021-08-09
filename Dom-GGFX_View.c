//View - Interfaces

//Bibliotecas padrao

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaracoes funcoes
void limparBuffer(); //Limpa o buffer do teclado.

char menuGeral(){ //Menu inicial
    printf("\n---DOMINO ETAPA 1---\n");
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
    fgets(jogadores[0].nome, 30, stdin);
    if(qtJogadores == 2){
        printf("Nome jogador 2: ");
        fgets(jogadores[1].nome, 30, stdin);
    }
}


char menuJogo(int jogador){ //Menu de acoes dentro do jogo
    char escolha;
    printf("\nJogo de Domino (GGFX)\n");
    printf("Vez de: %s\n", jogadores[jogador].nome);
    printf("1) Mesa de Domino\n2) Ver suas pecas - EM BREVE\n3) Embaralhar pecas\n4) Organizar as pecas\n5) Jogar - EM BREVE\n6) Comprar pecas - EM BREVE\n7) Voltar menu principal\n-> Escolha uma opcao: ");
    scanf(" %c", &escolha);
    return escolha;
}

void mostrarTodasPecas(){ //Mostrar a mesa geral
    printf("\nMesa: ");

	int i;
	for(i = 0; i < MAXPECA; i++)
		printf("[%d:%d] ", mesa[i].lado1, mesa[i].lado2);
	printf("\n");
}

void mostrarPecas(int jogador){ //Mostra as pecas de um jogador especifico. (Em breve - Etapa 3)
    int i;
	for(i = 0; i < 7; i++)
		printf("[%d:%d] ", jogadores[jogador].mao[i].lado1, jogadores[jogador].mao[i].lado2);
	printf("\n");
}

void limparBuffer(){ //Limpar buffer do teclado.
    char c;
    while ((c = fgetc(stdin)) != EOF && c != '\n'){}
}
