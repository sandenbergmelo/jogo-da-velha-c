#include <stdbool.h> // Para usar o tipo booleano
#include <stdio.h>
#include <stdlib.h>

#include "color.h" // Para usar cores no terminal (ex: printf(BRED "Texto" RESET))
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

void preencherTabuleiro(char tabuleiro[3][3]) {
  /*
   * Preenche a matriz com números de 1 a 9
   * para que o usuário possa escolher a posição
   */
  int cont = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      // Joga o número int para a matriz convertido em char
      tabuleiro[i][j] = cont + '0';
      cont++;
    }
  }
}

bool casaEstaVazia(int posicao, char tabuleiro[3][3]) {
  char simbolo;

  // Converte o número de 1 a 9 em uma posição da matriz
  switch (posicao) {
  case 1:
    simbolo = tabuleiro[0][0];
    break;
  case 2:
    simbolo = tabuleiro[0][1];
    break;
  case 3:
    simbolo = tabuleiro[0][2];
    break;
  case 4:
    simbolo = tabuleiro[1][0];
    break;
  case 5:
    simbolo = tabuleiro[1][1];
    break;
  case 6:
    simbolo = tabuleiro[1][2];
    break;
  case 7:
    simbolo = tabuleiro[2][0];
    break;
  case 8:
    simbolo = tabuleiro[2][1];
    break;
  case 9:
    simbolo = tabuleiro[2][2];
    break;
  default:
    return false;
  }

  if (simbolo == 'X' || simbolo == 'O') { // Se a casa não estiver vazia
    return false;
  }

  return true;
}

void mostrarTabuleiro(char tabuleiro[3][3]) { // Percorre a matriz e mostra na tela

  // Título
  printf(BBLU "-=-=-=-=-=-=-=-=-\n");
  printf("  Jogo da velha\n");
  printf("-=-=-=-=-=-=-=-=-\n" RESET);

  for (int i = 0; i < 3; i++) { // Mostra a matriz na tela
    for (int j = 0; j < 3; j++) {
      printf("[%c]   ", tabuleiro[i][j]);
    }
    printf("\n\n");
  }
}

void inserirItem(char posicao, char simbolo, char tabuleiro[3][3]) {
  // Percorre a matriz e insere o símbolo na posição desejada
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      char item = tabuleiro[i][j];

      if (item == posicao) {
        tabuleiro[i][j] = simbolo;
      }
    }
  }
}

void fazerJogada(int scanPosicao, char tabuleiro[3][3], char simbolo) {
  // Enquanto a casa não estiver vazia, ele não pode inserir
  while (true) {
    printf("Posição: ");
    scanf("%d", &scanPosicao);
    setbuf(stdin, NULL);

    if (casaEstaVazia(scanPosicao, tabuleiro)) {
      break;
    }

    if (scanPosicao > 9 || scanPosicao < 1) {
      printf(BRED "Posição inválida" RESET "\n");
      continue;
    }

    printf(BYEL "Casa já ocupada" RESET "\n");
  }

  // (scanPosicao + '0') => converte int para char
  inserirItem(scanPosicao + '0', simbolo, tabuleiro);

  limpar();
  mostrarTabuleiro(tabuleiro);
}

char trocarSimbolo(char simbolo) {
  if (simbolo == 'X') {
    return 'O';
  }
  return 'X';
}

bool verificarFimDoJogo(char tabuleiro[3][3]) {
  // Testa as linhas para ver se tem 3 X ou 3 O
  bool testeLinha1 =
      tabuleiro[0][0] == tabuleiro[0][1] && tabuleiro[0][1] == tabuleiro[0][2];
  bool testeLinha2 =
      tabuleiro[1][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[1][2];
  bool testeLinha3 =
      tabuleiro[2][0] == tabuleiro[2][1] && tabuleiro[2][1] == tabuleiro[2][2];

  // Testa as colunas para ver se tem 3 X ou 3 O
  bool testeColuna1 =
      tabuleiro[0][0] == tabuleiro[1][0] && tabuleiro[1][0] == tabuleiro[2][0];
  bool testeColuna2 =
      tabuleiro[0][1] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][1];
  bool testeColuna3 =
      tabuleiro[0][2] == tabuleiro[1][2] && tabuleiro[1][2] == tabuleiro[2][2];

  // Testa as diagonais para ver se tem 3 X ou 3 O
  bool testeDiagonalPrincipal =
      tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2];
  bool testeDiagonalSecundaria =
      tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0];

  int numeroDeCasasOcupadas = 0;
  for (int i = 0; i < 3; i++) { // Verifica se todas as casas estão preenchidas
    for (int j = 0; j < 3; j++) {
      if (tabuleiro[i][j] == 'X' || tabuleiro[i][j] == 'O') {
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
