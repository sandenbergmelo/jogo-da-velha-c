#include <stdbool.h> // Para usar o tipo booleano
#include <stdio.h>
#include <stdlib.h>

#include "./src/utils.h"

int main() {
  int posicao;
  char jogo[3][3];
  char simbolo = 'X';

  limpar();

  preencherMatriz3x3(jogo);
  mostrarMatriz3x3(jogo);

  while (true) {
    fazerJogada(posicao, jogo, simbolo);
    simbolo = trocarSimbolo(simbolo);
  }

  return 0;
}
