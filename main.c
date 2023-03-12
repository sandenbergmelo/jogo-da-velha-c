#include <stdbool.h> // Para usar o tipo booleano
#include <stdio.h>
#include <stdlib.h>

#include "./src/color.h" // Para usar cores no terminal (ex: printf(BRED "Texto" RESET))
#include "./src/funcs.h"

int main() {
  int posicao;
  char tabuleiro[3][3];
  char simbolo = 'X';

  limpar();

  preencherTabuleiro(tabuleiro);
  mostrarTabuleiro(tabuleiro);

  while (true) { // Loop "infinito" de jogadas
    fazerJogada(posicao, tabuleiro, simbolo);
    simbolo = trocarSimbolo(simbolo);

    if (verificarFimDoJogo(tabuleiro)) { // Se o jogo acabou
      printf(BGRN "Fim de jogo!" RESET "\n");
      break;
    }
  }

  return 0;
}
