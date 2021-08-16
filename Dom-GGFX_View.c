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
    char escolha, count = 0;
    printf("\nJogo de Domino (GGFX)\n");
    printf("Vez de: %s\n", jogadores[jogador].nome);
    for (int i = 0; i < MAXPECA; i++){
        if(pecas[i].status == 4)
            count ++;
    }
    printf("1) Mesa de Domino\n2) Ver suas pecas\n3) JogarE\n4) Comprar pecas (Restante: %d)\n5) Voltar menu principal\n-> Escolha uma opcao: ", count);
    scanf(" %c", &escolha);
    return escolha;
}

char menuJogarPeca(int jogador){
    char escolha;

    int i;
	for(i = 0; i < MAXPECA; i++){
        if(mesa[i].status == jogador)
		    printf("%d: [%d:%d] ",i + 1, mesa[i].lado1, mesa[i].lado2);
    }
    printf("\n-> ");
    scanf(" %c", &escolha);
    return escolha;
}

char menuEscolhaLado(){
    char escolha;

    do{ //Garante que o usuario escolha 1 ou 2
        printf("Qual lado voce deseja jogar?\n1 - Esquerda\n2 - Direita\n-> ");
        scanf(" %c", &escolha);
    } while(escolha != '1' && escolha != '2');

    return escolha;
}

void mostrarPecasMesa(){ //Mostrar a mesa geral
    printf("\nMesa: ");

	int i;
	for(i = 0; i < MAXPECA; i++){
        if(mesa[i].status == 4)
		    printf("[%d:%d] ", mesa[i].lado1, mesa[i].lado2);
    }
	printf("\n");


    printf("    _________________________________\n"
            "   /                                 \\\n"
            "  /          [%d:%d]     [%d:%d]          \\\n"
            " /                                     \\\n"
            "/_______________________________________\\\n"
            "|_______________________________________|\n"
            "     |                             |     \n"
            "     |                             |     \n"
            "     |                             |     \n", 3,3,4,5);
}

void mostrarPecasJogador(int jogador){ //Mostra as pecas de um jogador especifico. (Em breve - Etapa 3)
    int i;
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