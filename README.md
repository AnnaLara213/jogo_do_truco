# Jogo de Truco

## Descrição
Este é um **jogo de Truco** implementado em **C** para dois jogadores. O objetivo do jogo é ser o primeiro a alcançar **12 pontos**, com cada rodada valendo pontos que podem aumentar conforme as ações dos jogadores. O jogo segue as regras tradicionais do Truco, com a adição de opções estratégicas como **aumentar a pontuação** e **desistir da rodada**.

---

## Regras Básicas

- O jogo começa com os jogadores recebendo **3 cartas** cada, distribuídas aleatoriamente de um **baralho de 40 cartas**.
- O **Jogador 1** pode **pedir um aumento** de pontos para a rodada, que será **aceito ou recusado** pelo **Jogador 2**.
- O valor da rodada pode ser **aumentado** de **1 ponto** para **3**, depois para **6** e, por fim, para **9 pontos**. Não é possível aumentar mais após atingir 9 pontos.
- Os jogadores podem **desistir** da rodada a qualquer momento, concedendo os pontos ao adversário.
- Cada jogador joga **uma carta por vez**. O vencedor da rodada é determinado pela carta de **maior valor**, de acordo com a hierarquia do Truco.

---

## Funcionalidades

### 1. **Embaralhamento do Baralho**
O baralho é embaralhado aleatoriamente antes do início de cada rodada.

### 2. **Distribuição das Cartas**
Cada jogador recebe **3 cartas** para jogar durante a rodada.

### 3. **Aumento de Pontos**
O jogador pode **solicitar um aumento** na pontuação da rodada, mas o adversário tem a opção de **aceitar** ou **recusar** esse aumento.

### 4. **Exibição das Cartas**
As cartas de cada jogador são exibidas, permitindo ao jogador escolher qual carta jogar.

### 5. **Desistência**
O jogador pode **desistir** da rodada, concedendo os pontos da rodada ao adversário.

### 6. **Jogada de Cartas**
O jogador escolhe uma carta para jogar e tenta **vencer a rodada** com a carta de maior valor.

---

## Como Jogar

1. **Início do Jogo**: O jogo começa com o embaralhamento do baralho e a distribuição das cartas para os jogadores.
2. **Durante o Turno**: O jogador pode escolher uma das seguintes opções:
   - **Aumentar**: Solicitar um aumento na pontuação da rodada.
   - **Aceitar Aumento**: Aceitar o aumento solicitado pelo adversário.
   - **Recusar Aumento**: Recusar o aumento solicitado pelo adversário.
   - **Desistir**: Desistir da rodada e conceder os pontos ao adversário.
   - **Jogar uma Carta**: Jogar uma carta da mão e tentar vencer a rodada.
   - **Terminar Turno**: Finalizar o turno sem jogar.
3. O jogo continua até que um dos jogadores alcance **12 pontos**, vencendo a partida.

---

## Estrutura do Código

- **Função `inicializar_baralho()`**: Inicializa o baralho de 40 cartas.
- **Função `embaralhar_baralho()`**: Embaralha o baralho antes de cada rodada.
- **Função `distribuir_cartas()`**: Distribui 3 cartas para cada jogador no início de uma rodada.
- **Função `aumentar()`**: Permite a um jogador pedir um aumento na pontuação da rodada.
- **Função `jogar_turno()`**: Controla as ações de cada jogador durante um turno.
- **Função `jogar_rodada()`**: Gerencia o fluxo de uma rodada completa.

---

## Objetivo

O objetivo é ser o primeiro a atingir **12 pontos**, vencendo as rodadas através de jogadas estratégicas com as cartas, aumento de pontos e decisões durante o jogo.



