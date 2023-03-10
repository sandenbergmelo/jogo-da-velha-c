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

void preencherMatriz3x3(char matriz[3][3]) {
  int cont = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      // Joga o número int para a matriz convertido em char
      matriz[i][j] = cont + '0';
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

void mostrarMatriz3x3(char matriz[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("[%c]   ", matriz[i][j]);
    }
    printf("\n\n");
  }
}

void inserirItem(char posicao, char symbol, char matriz[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      char item = matriz[i][j];

      if (item == posicao) {
        matriz[i][j] = symbol;
      }
    }
  }
}

void fazerJogada(int scanPosicao, char matriz[3][3], char simbolo) {
  // Enquanto a casa não estiver vazia, ele não pode inserir
  while (true) {
    printf("Posição: ");
    scanf("%d", &scanPosicao);
    setbuf(stdin, NULL);

    if (casaEstaVazia(scanPosicao, matriz)) {
      break;
    }

    printf("Posição já ocupada\n");
  }

  // (scanPosicao + '0') => converte int para char
  inserirItem(scanPosicao + '0', simbolo, matriz);

  limpar();
  mostrarMatriz3x3(matriz);
}

char trocarSimbolo(char simbolo) {
  if (simbolo == 'X') {
    return 'O';
  }
  return 'X';
}

bool verificarFimDoJogo(char matriz[3][3]) {
  // Testa as linhas para ver se tem 3 X ou 3 O
  bool testeLinha1 =
      matriz[0][0] == matriz[0][1] && matriz[0][1] == matriz[0][2];
  bool testeLinha2 =
      matriz[1][0] == matriz[1][1] && matriz[1][1] == matriz[1][2];
  bool testeLinha3 =
      matriz[2][0] == matriz[2][1] && matriz[2][1] == matriz[2][2];

  // Testa as colunas para ver se tem 3 X ou 3 O
  bool testeColuna1 =
      matriz[0][0] == matriz[1][0] && matriz[1][0] == matriz[2][0];
  bool testeColuna2 =
      matriz[0][1] == matriz[1][1] && matriz[1][1] == matriz[2][1];
  bool testeColuna3 =
      matriz[0][2] == matriz[1][2] && matriz[1][2] == matriz[2][2];

  // Testa as diagonais para ver se tem 3 X ou 3 O
  bool testeDiagonalPrincipal =
      matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2];
  bool testeDiagonalSecundaria =
      matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0];

  int elementos = 0;
  for (int i = 0; i < 3; i++) { // Verifica se todas as casas estão preenchidas
    for (int j = 0; j < 3; j++) {
      if (matriz[i][j] == 'X' || matriz[i][j] == 'O') {
        elementos++;
      }
    }
  }

  if (testeLinha1 || testeLinha2 || testeLinha3) { // Se alguma linha for igual
    return true;
  }

  if (testeColuna1 || testeColuna2 ||
      testeColuna3) { // Se alguma coluna for igual
    return true;
  }

  if (testeDiagonalPrincipal ||
      testeDiagonalSecundaria) { // Se alguma diagonal for igual
    return true;
  }

  if (elementos == 9) { // Se todas as casas estiverem preenchidas
    return true;
  }

  return false;
}
