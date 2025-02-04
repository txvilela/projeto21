#include "Jogo.hpp"

int Fichas::veResultado( Mesa& mesa,  Jogador& jogador) {

	int valorJogador = jogador.calculaPontos();

	int valorMesa = mesa.calculaPontosMesa();

	return valorMesa - valorJogador;
}