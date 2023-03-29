#include <stdbool.h> // Para usar o tipo booleano
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void titulo() {
  printf(BBLU "-=-=-=-=-=-=-=-=-\n");
  printf("  Jogo da velha\n");
  printf("-=-=-=-=-=-=-=-=-\n" RESET);
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

void mostrarTabuleiro(char tabuleiro[3][3]) {
  // Percorre a matriz e mostra na tela

  titulo();

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

void fazerJogada(int scanPosicao, char tabuleiro[3][3], char simbolo,
                 char jogador[30]) {

  // Enquanto a casa não estiver vazia, ele não pode inserir
  while (true) {
    printf("Jogador %s (%c)\nEscolha uma posição: ", jogador, simbolo);
    scanf("%d", &scanPosicao);
    setbuf(stdin, NULL);

    if (casaEstaVazia(scanPosicao, tabuleiro)) {
      break;
    }

    if (scanPosicao > 9 || scanPosicao < 1) {
      printf(BRED "Posição inválida" RESET "\n\n");
      continue;
    }

    printf(BYEL "Casa já ocupada" RESET "\n\n");
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

void trocarJogador(char jogadorAtual[30], char jogador1[30],
                   char jogador2[30]) {

  if (strcmp(jogadorAtual, jogador1) == 0) {
    strcpy(jogadorAtual, jogador2);
  } else {
    strcpy(jogadorAtual, jogador1);
  }
}

bool tabuleiroEstaCheio(char tabuleiro[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (tabuleiro[i][j] != 'X' && tabuleiro[i][j] != 'O') {
        return false;
      }
    }
  }
  return true;
}

void verificarGanhador(char simbolo, char jogador1[30], char jogador2[30]) {
  if (simbolo == 'X') {
    printf(BGRN "O jogador %s (%c) ganhou!" RESET "\n", jogador1, simbolo);
  } else {
    printf(BGRN "O jogador %s (%c) ganhou!" RESET "\n", jogador2, simbolo);
  }
}

bool jogoAcabou(char tabuleiro[3][3], char simbolo, char jogador1[30],
                char jogador2[30]) {

  // Verifica todas as linhas
  for (int i = 0; i < 3; i++) {
    if (tabuleiro[i][0] == tabuleiro[i][1] &&
        tabuleiro[i][1] == tabuleiro[i][2]) {

      // Verifica quem ganhou
      verificarGanhador(simbolo, jogador1, jogador2);
      return true;
    }
  }

  // Verifica todas as colunas
  for (int i = 0; i < 3; i++) {
    if (tabuleiro[0][i] == tabuleiro[1][i] &&
        tabuleiro[1][i] == tabuleiro[2][i]) {

      // Verifica quem ganhou
      verificarGanhador(simbolo, jogador1, jogador2);
      return true;
    }
  }

  // Verifica a diagonal principal
  if (tabuleiro[0][0] == tabuleiro[1][1] &&
      tabuleiro[1][1] == tabuleiro[2][2]) {

    // Verifica quem ganhou
    verificarGanhador(simbolo, jogador1, jogador2);
    return true;
  }

  // Verifica a diagonal secundária
  if (tabuleiro[0][2] == tabuleiro[1][1] &&
      tabuleiro[1][1] == tabuleiro[2][0]) {

    // Verifica quem ganhou
    verificarGanhador(simbolo, jogador1, jogador2);
    return true;
  }

  // Verifica se deu velha
  if (tabuleiroEstaCheio(tabuleiro)) {
    printf(BYEL "Deu velha!" RESET "\n");
    return true;
  }

  // Se o jogo não acabou
  return false;
}
