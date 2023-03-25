#include <stdbool.h> // Para usar o tipo booleano

void limpar();
char trocarSimbolo(char simbolo);
void mostrarTabuleiro(char matrix[3][3]);
void preencherTabuleiro(char matrix[3][3]);
void trocarJogador(char jogadorAtual[20], char jogador1[20], char jogador2[20]);
void fazerJogada(int posicao, char matriz[3][3], char simbolo, char jogador[20]);
bool jogoAcabou(char tabuleiro[3][3], char simbolo, char jogador1[20], char jogador2[20]);
