#ifndef CARTA_HPP
#define CARTA_HPP

#include <iostream>


class Carta {
public:
	int numero_Carta /*= 13*/;
	std::string naipe_Carta /*= "C"*/;

	Carta(int v, const std::string& n) : numero_Carta(v), naipe_Carta(n) {}

	friend std::ostream& operator<<(std::ostream& os, const Carta& carta);

	void cartasoma() {};
};


#endif