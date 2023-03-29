#include <stdbool.h> // Para usar o tipo booleano

void limpar();
void titulo();
char trocarSimbolo(char simbolo);
void mostrarTabuleiro(char matrix[3][3]);
void preencherTabuleiro(char matrix[3][3]);
void trocarJogador(char jogadorAtual[30], char jogador1[30], char jogador2[30]);
void fazerJogada(int posicao, char matriz[3][3], char simbolo, char jogador[30]);
bool jogoAcabou(char tabuleiro[3][3], char simbolo, char jogador1[30], char jogador2[30]);
