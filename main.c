#include <stdio.h>
#include <stdlib.h>

#include "./src/utils.h"

int main() {
  int posicao;
  char jogo[3][3];

  limpar();

  preencherMatriz3x3(jogo);
  mostrarMatriz3x3(jogo);

  fazerJogada(posicao, jogo, 'O');
  fazerJogada(posicao, jogo, 'X');

  return 0;
}
