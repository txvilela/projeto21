#ifndef BARALHO_HPP
#define BARALHO_HPP




#include <iostream>
#include <vector>

class Carta;

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

#endif 