#include <stdbool.h> // Para usar o tipo booleano
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void limpar() {
// Limpa a tela de acordo com o sistema operacional
#ifdef _WIN32
  system("cls");
  return;
#else
  system("clear");
#endif
}

void preencherMatriz3x3(char matrix[3][3]) {
  int cont = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      // Joga o número int para a matrix convertido em char
      matrix[i][j] = cont + '0';
      cont++;
    }
  }
}

bool casaEstaVazia(int posicao, char matriz[3][3]) {
  char symbol;

  // Converte o número de 1 a 8 em uma posição da matriz
  switch (posicao) {
  case 0:
    symbol = matriz[0][0];
    break;
  case 1:
    symbol = matriz[0][1];
    break;
  case 2:
    symbol = matriz[0][2];
    break;
  case 3:
    symbol = matriz[1][0];
    break;
  case 4:
    symbol = matriz[1][1];
    break;
  case 5:
    symbol = matriz[1][2];
    break;
  case 6:
    symbol = matriz[2][0];
    break;
  case 7:
    symbol = matriz[2][1];
    break;
  case 8:
    symbol = matriz[2][2];
    break;
  default:
    printf("Posição inválida\n");
    return false;
  }

  if (symbol == 'X' || symbol == 'O') {
    return false;
  }

  return true;
}

void mostrarMatriz3x3(char matrix[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("[ %c ]", matrix[i][j]);
    }
    printf("\n");
  }
}

void inserirItem(char posicao, char symbol, char matrix[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      char item = matrix[i][j];

      if (item == posicao) {
        matrix[i][j] = symbol;
      }
    }
  }
}

void fazerJogada(int posicao, char matriz[3][3], char simbolo) {
  // Enquanto a casa não estiver vazia, ele não pode inserir
  while (true) {
    printf("Posição: ");
    scanf("%d", &posicao);
    setbuf(stdin, NULL);

    if (casaEstaVazia(posicao, matriz)) {
      break;
    }

    printf("Posição já ocupada\n");
  }

  // (posicao + '0') => converte int para char
  inserirItem(posicao + '0', simbolo, matriz);

  limpar();
  mostrarMatriz3x3(matriz);
}
