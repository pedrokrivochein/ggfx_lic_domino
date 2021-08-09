//View - Interfaces

//Bibliotecas padrao

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaracoes funcoes
void limparBuffer();

char menuGeral(){ //Menu inicial
    char escolha;
    printf("1) Iniciar novo jogo\n2) Continuar a Jogar\n3) Salvar Jogo\n4) Carregar Jogo\n5) Regras do Jogo\n6) Sair do Jogo\n-> Escolha uma opcao: ");
    scanf(" %c", &escolha);
    return escolha;
}

void menuJogadores(){ //Menu apos o inicial para escolher quantidade de jogadores.
    int qtJogadores;
    do{
        printf("\nQuantidade de jogadores: ");
        scanf("%d", &qtJogadores);
        if(qtJogadores > 2)
            printf("Valor maximo de jogadores: 2");
        else if(qtJogadores < 1)
            printf("Valor minimo e 1");
    }while(qtJogadores > 2); 
    limparBuffer();
    printf("Nome jogador 1: ");
    fgets(jogadores[0].nome, 30, stdin);
    if(qtJogadores == 2){
        printf("Nome jogador 2: ");
        fgets(jogadores[1].nome, 30, stdin);
    }
}


char menuJogo(int jogador){ //Menu de acoes dentro do jogo.
    char escolha;
    printf("\nJogo de Domino (PUC-SP)\n");
    printf("Vez de: %s\n", jogadores[jogador].nome);
    printf("1) Mesa de Domino\n2) V̶e̶r̶ ̶s̶u̶a̶s̶ ̶p̶e̶c̶a̶s̶\n3) Embaralhar pecas\n4) Jogar\n5) Comprar pecas\n6) Voltar menu principal\n-> Escolha uma opcao: ");
    scanf(" %c", &escolha);
    return escolha;
}

void mostrarTodasPecas(){ //Mostrar a mesa geral.
    printf("\n");

	int i;
	for(i = 0; i < MAXPECA; i++)
		printf("[%d:%d] ", mesa[i].lado1, mesa[i].lado2);
	printf("\n");
}

void mostrarPecas(int jogador){ //Mostra as pecas de um jogador especifico.
    int i;
	for(i = 0; i < 7; i++)
		printf("[%d:%d] ", jogadores[jogador].mao[i].lado1, jogadores[jogador].mao[i].lado2);
	printf("\n");
}

void limparBuffer(){ //Limpar buffer do teclado.
    char c;
    while ((c = fgetc(stdin)) != EOF && c != '\n'){}
}