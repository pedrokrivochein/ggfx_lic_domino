//View - Interfaces

//Bibliotecas padrao

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaracoes funcoes
void limparBuffer();

char menuGeral(){ //Menu inicial
    char escolha;
    printf("1) Iniciar novo jogo\n2) Continuar a Jogar\n3) Salvar Jogo\n4) Carregar Jogo\n5) Regras do Jogo\n6) Sair do Jogo\n-> ");
    scanf(" %c", &escolha);
    return escolha;
}

void menuJogadores(){ //Menu apos o inicial para escolher quantidade de jogadores.
    int qtJogadores;
    do{
        printf("Quantidade de jogadores: ");
        scanf("%d", &qtJogadores);
        if(qtJogadores > 2)
            printf("Valor maximo de jogadores: 2");
        else if(qtJogadores < 1)
            printf("Valor minimo e 1");
    }while(qtJogadores > 2); 
    limparBuffer();
    printf("Nome jogador 1: ");
    fgets(jogadores[0].nome, 30, stdin);
    printf("Nome jogador 2: ");
    fgets(jogadores[1].nome, 30, stdin);
}


char menuJogo(int jogador){ //Menu de acoes dentro do jogo.
    char escolha;
    printf("Jogo de Domino (PUC-SP)");
    printf("Vez de %s", jogadores[jogador].nome);
    printf("1) Mesa de Domino\n2) Ver suas pecas\n3) Embaralhar pecas\n4) Jogar\n5) Comprar pecas\n6) Voltar menu principal");
    scanf(" %c", &escolha);
    return escolha;
}

void mostrarTodasPecas(){ //Mostrar a mesa geral.
	int i;
	for(i = 0; i < MAXPECA; i++)
		printf("[%d:%d] ", mesa[i].lado1, mesa[i].lado2);
	printf("\n");
}

void mostrarPecas(int jogador){ //Mostra as pecas de um jogador.
    int i;
	for(i = 0; i < 7; i++)
		printf("[%d:%d] ", jogadores[jogador].mao[i].lado1, jogadores[jogador].mao[i].lado2);
	printf("\n");
}

void limparBuffer(){ //Limpar buffer do teclado.
    char c;
    while ((c = fgetc(stdin)) != EOF && c != '\n'){}
}