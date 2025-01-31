#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "chama_mesa.hpp"
#include "baralho.hpp"
#include "mesa.hpp"
#include "jogador.hpp"

int main() {
	
	while (true) {
	
	srand(static_cast<unsigned int>(time(0)));
	
	
	Baralho baralho;
	Mesa mesa;
	Jogador jogador;

	//baralho.imprimir();
	
		mesa.mesa(baralho.darCarta(), baralho.darCarta());
		mesa.mostracartamesa();


		if (!jogador.maoJogador(baralho.darCarta(), baralho.darCarta(), baralho)) {
			mesa.mostratudo();
		}
		//chama_Mesa(baralho.darCarta(), baralho.darCarta(), baralho.darCarta(), baralho.darCarta());
		std::cout << "Quer parar?" << std::endl;
		std::string respostinha;
		std::cin >> respostinha;

		if (respostinha == "ok") {
			return false;
		}
	}

}