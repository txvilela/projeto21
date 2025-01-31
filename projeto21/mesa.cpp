#include <iostream>
#include "mesa.hpp"

Mesa::Mesa() {}

void Mesa::mesa(const Carta& carta1, const Carta& carta2) {
	cartaMesa.push_back(carta1);
	cartaMesa.push_back(carta2);
	
}

void Mesa::mostracartamesa() const {
	std::cout << "cartas do crupie" << std::endl;
	std::cout << "XX " << cartaMesa[1] << std::endl << std::endl << std::endl;
}

void Mesa::mostratudo(){
	Baralho baralho;
	Jogador jogador;

	std::cout << std::endl << "Cartas do crupie" << std::endl;
	
	if (jogador.calculaPontos() < 21) {
		while (calculaPontosMesa() <= 17) {
			cartaMesa.push_back(baralho.darCarta());
		}
		for (const auto& carta : cartaMesa) {
			std::cout << carta << " ";
		}
		std::cout << std::endl;
		std::cout << "Pontos Mesa " << calculaPontosMesa() << std::endl;
	}
	else if(jogador.calculaPontos() > 21){
		for (const auto& carta : cartaMesa) {
			std::cout << carta << " ";
		}
		std::cout << std::endl;
		std::cout << "Pontos Mesa " << calculaPontosMesa() << std::endl;
	}
}

int Mesa::calculaPontosMesa() {
	int total = 0;
	for (const auto& cartas : cartaMesa) {
		if (cartas.numero_Carta == 1) {
			total += 11;
		}
		else if (cartas.numero_Carta >= 11 && cartas.numero_Carta <= 13) {
			total += 10;
		}
		else {
			total += cartas.numero_Carta;
		}
	}
	for (const auto& cartas : cartaMesa) {
		if (cartas.numero_Carta == 1 && total > 21) {
			total -= 10;
		}
	}
	return total;
}
//if (jogador) {
//	std::cout << std::endl;
//	std::cout << "crupier " << std::endl;
//	std::cout << "XX  " << c2 << std::endl << std::endl;
//
//}
//
//if (jogador) {
//	std::cout << c1 << "  " << c2 << std::endl;
//}
