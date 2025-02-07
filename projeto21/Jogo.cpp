#include "Jogo.hpp"
#include "mesa.hpp"
#include "jogador.hpp"

int Fichas::veResultado( Mesa& mesa,  Jogador& jogador) {

	int valorJogador = jogador.calculaPontos();

	int valorMesa = mesa.calculaPontosMesa();


	return valorMesa - valorJogador;
}

void Fichas::compraFichas() {
	char res;
	std::cout << "Quer mais fichas?" << std::endl << std::endl;
	std::cin >> res;
	if (res == 's') {
		int dificuldadeFichas;
		std::cout << "Quantas fichas você quer começar (Dificuldade!!!)" << std::endl << std::endl;
		std::cout << "Você pode escolher entre: 25 / 50 / 100" << std::endl;
		std::cin >> dificuldadeFichas;
		std::cout << std::endl;

		if (dificuldadeFichas != 25 && dificuldadeFichas != 50 && dificuldadeFichas != 100) {
			std::cout << "Estcolha entre (25), (50) ou (100) Por favor!!!" << std::endl;
		}

		fichasJogador = dificuldadeFichas;

		std::cout << fichasJogador << std::endl << std::endl << std::endl;
	}
	
}


