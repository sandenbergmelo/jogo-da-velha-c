#include <stdbool.h> // Para usar o tipo booleano

bool casaEstaVazia(int posicao, char matrix[3][3]);
bool verificarFimDoJogo(char matrix[3][3]);
void preencherTabuleiro(char matrix[3][3]);
void mostrarTabuleiro(char matrix[3][3]);
void inserirItem(char posicao, char symbol, char matrix[3][3]);
void fazerJogada(int posicao, char matriz[3][3], char simbolo);
char trocarSimbolo(char simbolo);
void limpar();
