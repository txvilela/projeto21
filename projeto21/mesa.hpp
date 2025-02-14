#ifndef MESA_HPP
#define MESA_HPP


#include <iostream>
#include <vector>
#include "baralho.hpp"
#include "carta.hpp"
#include "jogador.hpp"

class Mesa {
private:
	std::vector <Carta> cartaMesa;
	double fichasMesa = 1000;



public:
	Mesa();
	void mesa(const Carta& carta1, const Carta& carta2);
	void mostracartamesa() const;
	void mostratudo();
	double calculaPontosMesa();
	double retornaSaldoFichasMesa();
};

#endif // !MESA_HPP