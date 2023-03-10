#include <stdbool.h> // Para usar o tipo booleano
#include <stdio.h>
#include <stdlib.h>

#include "./src/funcs.h"

int main() {
  int posicao;
  char tabuleiro[3][3];
  char simbolo = 'X';

  limpar();

  preencherMatriz3x3(tabuleiro);
  mostrarMatriz3x3(tabuleiro);

  while (true) { // Loop "infinito" de jogadas
    fazerJogada(posicao, tabuleiro, simbolo);
    simbolo = trocarSimbolo(simbolo);

    if (verificarFimDoJogo(tabuleiro)) { // Se o jogo acabou
      printf("Fim de jogo\n");
      break;
    }
  }

  return 0;
}
