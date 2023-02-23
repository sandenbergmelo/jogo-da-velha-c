#include <stdbool.h> // Para usar o tipo booleano
#include <stdio.h>
#include <stdlib.h>

#include "./src/utils.h"

int main() {
  int posicao;
  char jogo[3][3];

  limpar();

  preencherMatriz3x3(jogo);
  mostrarMatriz3x3(jogo);

  // Enquanto o usuário não a casa não estiver vazia, ele não pode inserir
  while (true) {
    printf("Posição: ");
    scanf("%d", &posicao);
    setbuf(stdin, NULL);
    if (casaEstaVazia(posicao, jogo)) {
      break;
    }

    printf("Posição já ocupada\n");
  }

  inserirItem(posicao + '0', 'X', jogo);

  limpar();
  mostrarMatriz3x3(jogo);

  return 0;
}
