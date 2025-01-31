#pragma once
#include <iostream>
#include <vector>
#include "carta.hpp"

class Baralho {
private:
	std::vector <Carta> cartas;
	std::string naipes[4] = { "Cps", "Paus", "Spad", "Oros" };
	std::vector <Carta> contaCarta;


public:
	Baralho();

	void imprimir() const;

	int NcartaAleatoria();

	std::string naipcartaAleatoria();
	
	
	Carta darCarta();

};