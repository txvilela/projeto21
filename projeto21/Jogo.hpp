#pragma once
#include <iostream>
#include "mesa.hpp"
#include "jogador.hpp"


class  Fichas {

private:
	int fichasJogador;
	int fichasMesa = 1000;



public:
	Fichas() {
		fichasJogador = 0;
	}

	int veResultado(Mesa& mesa, Jogador& jogador);
};