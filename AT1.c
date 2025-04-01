#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARTAS 40
#define PONTOS_VITORIA 12

typedef struct {
    int valor;
    char naipe;
} Carta;

Carta baralho[NUM_CARTAS];
int pontos_rodada = 1;
int ultimo_aumentou = -1;  
int pontos_jogador[2] = {0, 0};
int aumento_pendente = -1; 

void inicializar_baralho() {
    char naipes[] = {'E', 'C', 'O', 'P'};
    int valores[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12};
    int index = 0;
    
    for (int n = 0; n < 4; n++) {
        for (int v = 0; v < 10; v++) {
            baralho[index].valor = valores[v];
            baralho[index].naipe = naipes[n];
            index++;
        }
    }
}

void embaralhar_baralho() {
    for (int i = 0; i < NUM_CARTAS; i++) {
        int j = rand() % NUM_CARTAS;
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

void distribuir_cartas(Carta mao1[], Carta mao2[]) {
    for (int i = 0; i < 3; i++) {
        mao1[i] = baralho[i * 2];
        mao2[i] = baralho[i * 2 + 1];
    }
}

void exibir_mao(Carta mao[]) {
    for (int i = 0; i < 3; i++) {
        printf("%d de %c\n", mao[i].valor, mao[i].naipe);
    }
}

int comparar_cartas(Carta c1, Carta c2) {
    if (c1.valor > c2.valor) return 1;
    if (c1.valor < c2.valor) return -1;
    return 0;
}

void aumentar(int jogador) {
    if (aumento_pendente != -1) {
        printf("Já há um pedido de aumento pendente para o jogador %d.\n", aumento_pendente + 1);
        return;
    }

    if (ultimo_aumentou == jogador) {
        printf("Jogador %d não pode aumentar novamente!\n", jogador + 1);
        return;
    }

    aumento_pendente = jogador;  
    printf("Jogador %d fez um pedido de aumento!\n", jogador + 1);
}

void aceitar_aumento(int jogador) {
    if (aumento_pendente == -1) {
        printf("Não há aumento pendente para aceitar.\n");
        return;
    }

    if (aumento_pendente == jogador) {
        printf("Jogador %d não pode aceitar o seu próprio aumento.\n", jogador + 1);
        return;
    }

   
    if (pontos_rodada == 1) pontos_rodada = 3;
    else if (pontos_rodada == 3) pontos_rodada = 6;
    else if (pontos_rodada == 6) pontos_rodada = 9;
    else {
        printf("Não é possível aumentar mais!\n");
        return;
    }

    printf("Jogador %d aceitou o aumento! A rodada agora vale %d pontos.\n", jogador + 1, pontos_rodada);
    aumento_pendente = -1;  
    ultimo_aumentou = jogador;  
}

void recusar_aumento(int jogador) {
    if (aumento_pendente == -1) {
        printf("Não há aumento pendente para recusar.\n");
        return;
    }

    if (aumento_pendente == jogador) {
        printf("Jogador %d não pode recusar o seu próprio aumento.\n", jogador + 1);
        return;
    }

    printf("Jogador %d recusou o aumento!\n", jogador + 1);
    aumento_pendente = -1;  
}

int jogar_turno(int jogador, Carta mao[], int *vencedor_rodada) {
    int opcao;
    printf("Jogador %d, escolha sua ação:\n", jogador + 1);
    printf("1 - Aumentar\n2 - Aceitar aumento\n3 - Recusar aumento\n4 - Desistir\n5 - Jogar Carta\n6 - Terminar Turno\n");
    scanf("%d", &opcao);
    
    switch (opcao) {
        case 1: 
            aumentar(jogador);
            break;
        case 2:
            aceitar_aumento(jogador);
            break;
        case 3:
            recusar_aumento(jogador);
            break;
        case 4:
            printf("Jogador %d desistiu! Jogador %d ganha %d pontos.\n", jogador + 1, 3 - jogador, pontos_rodada);
            pontos_jogador[1 - jogador] += pontos_rodada;
            return 1;
        case 5:
            printf("Escolha uma carta para jogar (1-3): ");
            int carta;
            scanf("%d", &carta);
            printf("Jogador %d jogou %d de %c\n", jogador + 1, mao[carta - 1].valor, mao[carta - 1].naipe);
            if (*vencedor_rodada == -1 || comparar_cartas(mao[carta - 1], mao[*vencedor_rodada]) > 0) {
                *vencedor_rodada = jogador;
            }
            return 0;
        case 6:
            printf("Jogador %d terminou o turno.\n", jogador + 1);
            return 0;
        default:
            printf("Opção inválida!\n");
            return 0;
    }
    return 0;
}

void jogar_rodada() {
    Carta mao1[3], mao2[3];
    distribuir_cartas(mao1, mao2);
    
    printf("Mão do Jogador 1:\n");
    exibir_mao(mao1);
    printf("\nMão do Jogador 2:\n");
    exibir_mao(mao2);
    
    int vencedor_m1 = -1, vencedor_m2 = -1, vencedor_rodada = -1;
    int terminou = 0;
    
    for (int i = 0; i < 3 && !terminou; i++) {
        terminou = jogar_turno(0, mao1, &vencedor_rodada);
        if (!terminou) terminou = jogar_turno(1, mao2, &vencedor_rodada);
        
        if (i == 0) vencedor_m1 = vencedor_rodada;
        else if (i == 1) {
            vencedor_m2 = vencedor_rodada;
            if (vencedor_m1 == vencedor_m2) {
                pontos_jogador[vencedor_m1] += pontos_rodada;
                return;
            }
            if (vencedor_m1 == -1) return;
        }
    }
    
    pontos_jogador[vencedor_m1] += pontos_rodada;
}

int main() {
    srand(time(NULL));
    inicializar_baralho();
    embaralhar_baralho();
    
    while (pontos_jogador[0] < PONTOS_VITORIA && pontos_jogador[1] < PONTOS_VITORIA) {
        jogar_rodada();
        printf("Placar: Jogador 1 - %d | Jogador 2 - %d\n", pontos_jogador[0], pontos_jogador[1]);
    }
    
    printf("Jogador %d venceu o jogo!\n", (pontos_jogador[0] >= PONTOS_VITORIA) ? 1 : 2);
    return 0;
}
