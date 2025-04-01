# jogo_do_truco
Objetivo
Criar um programa em C que implemente um jogo de Truco para dois jogadores, com interface em texto.

Regras e Estrutura do Jogo
Baralho
O jogo usa um baralho com 40 cartas, composto por:

4 naipes: Espadas, Copas, Ouros e Paus

10 cartas por naipe: de 1 a 7 e de 10 a 12 (sem cartas 8 e 9)

Hierarquia das cartas (da mais forte para a mais fraca):

4 de paus (Zap)

7 de copas

1 de espadas (Espadão)

1 de paus (Pé)

Depois, na ordem: 7, 6, 5, 4, 3, 2, 12, 11 e 10

Estrutura do Jogo
O jogo é dividido em rodadas e turnos.

Vence o jogador que atingir 12 pontos primeiro.

Rodadas
Cada rodada vale inicialmente 1 ponto. Esse valor pode ser alterado para 3, 6 ou 9 pontos com a ação de "Aumentar".

Cada rodada é disputada em 3 mãos. Uma mão representa uma disputada de maior carta entre os dois jogadores. O jogador que vencer duas mãos ganha a rodada.

Critérios de desempate:

Se a primeira mão empatar, o jogador com a maior carta na segunda mão vence a rodada.

Se a segunda mão também empatar, a rodada termina sem vencedor.

Se a primeira mão tiver um vencedor e a segunda empatar, joga-se uma terceira mão.

Se a terceira mão empatar, o vencedor da primeira mão vence a rodada.

Turnos e Ações
Em uma mão, cada jogador joga um turno. 

Durante o turno, o jogador pode:

Aumentar – Propõe aumentar o valor da rodada para 3, 6 ou 9 pontos. Esssa ação deve estar disponível apenas se o jogador não foi o último a propor aumento na rodada.

Aceitar – Aceita o pedido de aumento. Essa ação deve estar disponível apenas se o adversário solicitou o aumento em seu último turno.

Desistir – Termina a rodada, dando o ponto ao adversário (não pode ser desfeito). Se o jogador adversário solicitou o aumento, essa ação recusa o aumento e termina a rodada. Essa ação deve estar disponível apenas se o jogador não escolheu outra ação no mesmo turno. 

Jogar Carta – Essa ação pode ser executada pelo jogador apenas uma vez por turno. Se o adversário pediu aumento, essa opção só aparece após o jogador aceitar o pedido de aumento.  Quando essa ação é selecionada pelo jogador, deve ser apresentado uma interface de texto para que ele escolha a carta jogada dentre as cartas em sua mão. 

Terminar Turno – Finaliza o turno e passa para o adversário. Essa ação deve estar disponível apenas se o jogador já executou outra ação no turno.

Conclusões:
Uma mão termina nas seguintes condições:

O segundo jogador encerra seu turno (ação terminar turno)
Um jogador executa a ação desistir 
Uma rodada termina nas seguintes condições:

A terceira mão termina.
A segunda mão  termina com um dos jogadores com vitória do mesmo jogador que ganhou a primeira mão.
A segunda mão termina depois da primeira mão ter terminado com empate.
O jogo termina quando no final de uma rodada o saldo de pontos de um dos jogadores é atualizado para 12 pontos .

Preparação da rodada 
No início de cada rodada, o programa deve:

Distribuir 3 cartas para cada jogador, aleatoriamente.

Interface
O programa deve mostrar claramente:

Última carta jogada pelo adversário

Número da rodada e da mão atual

Pontuação dos jogadores e valor da rodada

Cartas na mão do jogador
