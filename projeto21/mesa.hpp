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



public:
	Mesa();
	void mesa(const Carta& carta1, const Carta& carta2);
	void mostracartamesa() const;
	void mostratudo();
	int calculaPontosMesa();
};

#endif // !MESA_HPP