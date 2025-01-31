#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "baralho.hpp"
#include "carta.hpp"
#include "mesa.hpp"

class Jogador {
private:
	std::vector <Carta> cartasjogador;

public:
	Jogador();
	bool maoJogador(const Carta& carta1, const Carta& carta2, Baralho& baralho);
	bool resposta();
	void mostraCarta(const std::vector <Carta>& cartasjogador, const std::string& Titulo);
	int calculaPontos();
};

