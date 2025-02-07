#include "baralho.hpp"
#include "carta.hpp"
#include "carta.hpp"

Baralho::Baralho() {

	for (const auto& naipe_Carta : naipes) {

		for (int valor = 1; valor <= 13; valor++) {
			//if(valor == 10 || valor == 1) cartas especificas
			cartas.emplace_back(valor, naipe_Carta);

		}
		
	}
	/*for (int i = 0; i <= cartas.size(); i++) {
		std::cout << cartas << std::endl;
	}*/

}

void Baralho::imprimir() const {
	for (const auto& Carta : cartas) {
		std::cout << Carta << std::endl;


	}
}

int Baralho::NcartaAleatoria() {

	return 1 + rand() % 13;
	
}

std::string Baralho::naipcartaAleatoria() {
	return naipes[rand() % 4];
}


Carta Baralho::darCarta() {
	if (cartas.empty()) {
		throw std::runtime_error("O baralho está vazio!");
	}
	int indiceCarta = rand() % cartas.size();

	Carta cartaselecionada = cartas[indiceCarta];

	cartas.erase(cartas.begin() + indiceCarta);

	return cartaselecionada;
	
}
