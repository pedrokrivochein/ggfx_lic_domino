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
    
    if(pecasParaCompra > 0)
        printf("\n1) Jogar\n2) Comprar pecas (Restante: %d)\n3) Voltar menu principal\n-> Escolha uma opcao: ", pecasParaCompra);
    else
        printf("\n1) Jogar\n2) Passar\n3) Voltar menu principal\n-> Escolha uma opcao: ");
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
    printf("\nMesa do jogo: ");

	int i, j;
	
	printf("\n");

    printf("    ________");
    
    for(i=0; i < pecasJogadas; i++)
        printf("_____");
    
    printf("\n   /        ");
    
    for(i=0; i < pecasJogadas; i++)
        printf("     ");
        
    printf("\\");
    printf("\n  /     "); 
    
    for(i = 0; i < MAXPECA; i++){ //Mostra todas as pecas na mesa.
        if(mesaOrdenada[i].status != -1)
		    printf("[%d:%d]", mesaOrdenada[i].lado1, mesaOrdenada[i].lado2);
    }
    
    printf("     \\");

    printf("\n /            ");
    for(i=0; i < pecasJogadas; i++)
        printf("     ");
        
    printf("\\");

    printf("\n/______________");
    for(i=0; i < pecasJogadas; i++)
        printf("_____");
        
    printf("\\");

    printf("\n|______________");
    for(i=0; i < pecasJogadas; i++)
        printf("_____");
        
    printf("|");
    
    for(j = 0; j < 3; j++){
        printf("\n     |    ");
        for(i=0; i < pecasJogadas; i++)
            printf("     ");
        printf("|     ");
    }
}

void mostrarPecasJogador(int jogador){ //Mostra as pecas de um jogador especifico.
    int i;
    printf("\nPecas de %s: ", jogadores[jogador].nome);
	for(i = 0; i < MAXPECA; i++){
        if(mesa[i].status == jogador)
		    printf("[%d:%d] ", mesa[i].lado1, mesa[i].lado2);
    }
	printf("\n");
}

void divisoria(){ //Monta as divisorias entre cada jogada
    int k;
    printf("\n-=-=-=-=-=-=-=-=-=-=-");
    if(pecasJogadas != 0)
        for(k = 1; k < pecasJogadas; k++)
            printf("=-=-=-");
    printf("\n");
}

void limparBuffer(){ //Limpar buffer do teclado.
    char c;
    while ((c = fgetc(stdin)) != EOF && c != '\n'){}
}