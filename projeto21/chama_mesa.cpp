#include <string>
#include <iostream>
#include "chama_mesa.hpp"
#include "baralho.hpp"


void chama_Mesa(const Carta& cartaCrupier1, const Carta& cartaCrupier2, const Carta& cartaCadeira1, const Carta& cartaCadeira2) {

	std::cout << "                  " << " cropiê" << "                  " << std::endl;
	std::cout << "                  " << "   " << cartaCrupier1<< " " << cartaCrupier2 << "  " << "                  " << std::endl;
	std::cout << "                  " << "        " << "                  " << std::endl;
	std::cout << "                  " << "        " << "                  " << std::endl;
	std::cout << "     cadeira1     " << "        " << "       cadeira2   " << std::endl;
	std::cout << "      " << cartaCadeira1 << "         " << "        " << "        " << cartaCadeira2 << "         " << std::endl;
}
