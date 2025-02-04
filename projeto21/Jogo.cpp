#include "Jogo.hpp"

int Fichas:: veResultado() {
	Mesa mesa;
	Jogador jogador;
	int valorJogador;
	valorJogador = jogador.calculaPontos();

	int valorMesa;

	valorMesa = mesa.calculaPontosMesa();

	int valorT;
	valorT = valorMesa - valorJogador;
	
	return valorT;
}