//View - Interfaces

//Bibliotecas padrao

#include <stdio.h>
#include <string.h>
#include <time.h>

//Declaracoes funcoes


void mostrarTodasPecas();

char menuGeral(){
    char escolha;
    printf("1) Iniciar novo jogo\n2) Continuar a Jogar\n3) Salvar Jogo\n4) Carregar Jogo\n5) Regras do Jogo\n6) Sair do Jogo\n");
    scanf(" %c", &escolha);
    return escolha;
}

char menuJogadores(){
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


char menuJogo(int jogador){
    char escolha;
    printf("Jogo de Domino (PUC-SP)");
    printf("Vez de %s", jogadores[jogador].nome);
    printf("1) Mesa de Domino\n2) Ver suas pecas\n3) Comprar pecas\n4) Jogar\n5) Voltar menu principal");
        scanf(" %c", &escolha);
    return escolha;
}

void mostrarPecas(int jogador){


}

char limparBuffer(){
    char limparbuffer;
    while ((limparbuffer = fgetc(stdin)) != EOF && limparbuffer != '\n'){};
}