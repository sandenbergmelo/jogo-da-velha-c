#include <stdbool.h> // Para usar o tipo booleano
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./src/color.h" // Para usar cores no terminal (ex: printf(BRED "Texto" RESET))
#include "./src/funcs.h"

int main() {
  int posicao;
  char tabuleiro[3][3];
  char jogadorAtual[30], jogador1[30], jogador2[30];
  char simbolo = 'X';

  limpar();
  titulo();

  printf("Nome do jogador 1 (X): ");
  scanf("%[^\n]s", jogador1);
  setbuf(stdin, NULL);

  printf("Nome do jogador 2 (O): ");
  scanf("%[^\n]s", jogador2);
  setbuf(stdin, NULL);

  limpar();

  preencherTabuleiro(tabuleiro);
  mostrarTabuleiro(tabuleiro);

  // Copia o nome do jogador 1 para o jogador atual
  strcpy(jogadorAtual, jogador1);

  while (true) { // Loop "infinito" de jogadas
    fazerJogada(posicao, tabuleiro, simbolo, jogadorAtual);

    if (jogoAcabou(tabuleiro, simbolo, jogador1, jogador2)) {
      break;
    }

    simbolo = trocarSimbolo(simbolo);
    trocarJogador(jogadorAtual, jogador1, jogador2);
  }

  return 0;
}
