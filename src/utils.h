#include <stdbool.h>

void preencherMatriz3x3(char matrix[3][3]);
void mostrarMatriz3x3(char matrix[3][3]);
bool casaEstaVazia(int posicao, char matrix[3][3]);
bool verificarFimDoJogo(char matrix[3][3]);
void inserirItem(char posicao, char symbol, char matrix[3][3]);
void fazerJogada(int posicao, char matriz[3][3], char simbolo);
char trocarSimbolo(char simbolo);
void limpar();
