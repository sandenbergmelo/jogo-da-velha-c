#include <stdbool.h> // Para usar o tipo booleano
#include <stdio.h>
#include <stdlib.h>

#include "funcs.h"

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
  int cont = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      // Joga o número int para a matriz convertido em char
      matriz[i][j] = cont + '0';
      cont++;
    }
  }
}

bool casaEstaVazia(int posicao, char matriz[3][3]) {
  char simbolo;

  // Converte o número de 1 a 9 em uma posição da matriz
  switch (posicao) {
  case 1:
    simbolo = matriz[0][0];
    break;
  case 2:
    simbolo = matriz[0][1];
    break;
  case 3:
    simbolo = matriz[0][2];
    break;
  case 4:
    simbolo = matriz[1][0];
    break;
  case 5:
    simbolo = matriz[1][1];
    break;
  case 6:
    simbolo = matriz[1][2];
    break;
  case 7:
    simbolo = matriz[2][0];
    break;
  case 8:
    simbolo = matriz[2][1];
    break;
  case 9:
    simbolo = matriz[2][2];
    break;
  default:
    return false;
  }

  if (simbolo == 'X' || simbolo == 'O') { // Se a casa não estiver vazia
    return false;
  }

  return true;
}

void mostrarMatriz3x3(char matriz[3][3]) { // Percorre a matriz e mostra na tela
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("[%c]   ", matriz[i][j]);
    }
    printf("\n\n");
  }
}

void inserirItem(char posicao, char simbolo, char matriz[3][3]) {
  // Percorre a matriz e insere o símbolo na posição desejada
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      char item = matriz[i][j];

      if (item == posicao) {
        matriz[i][j] = simbolo;
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

    if (scanPosicao > 9 || scanPosicao < 1) {
      printf("Posição inválida\n");
      continue;
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

  int numeroDeCasasOcupadas = 0;
  for (int i = 0; i < 3; i++) { // Verifica se todas as casas estão preenchidas
    for (int j = 0; j < 3; j++) {
      if (matriz[i][j] == 'X' || matriz[i][j] == 'O') {
        numeroDeCasasOcupadas++;
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

  if (numeroDeCasasOcupadas == 9) { // Se todas as casas estiverem preenchidas
    return true;
  }

  return false;
}
