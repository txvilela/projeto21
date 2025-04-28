#include "Jogo.hpp"
#include "mesa.hpp"
#include "jogador.hpp"


double Fichas::resultadojogador( Jogador& jogador) {

	double valorJogador = jogador.calculaPontos();
		return valorJogador;
}

double Fichas::resultadoMesa(Mesa& mesa) {

	double valorMesa = mesa.calculaPontosMesa();
	return valorMesa;
}

double Fichas::compraFichas(double& saldoJogador) {
	char res;
	std::cout << "SUAS FICHAS!!!" << std::endl << saldoJogador << std::endl << std::endl << std::endl;
	std::cout << "Quer mais fichas? (s/n)" << std::endl << std::endl;
	std::cin >> res;
	res = std::tolower(res);

	while (res != 's' && res != 'n') {
		std::cout << "Por favor responda apenas s ou n" << std::endl;
		std::cin >> res;
		res = std::tolower(res);
		std::cout << std::endl;
	}

	if (res == 's') {
		double dificuldadeFichas;
		
		/*std::cout << "Quantas fichas você quer começar (Dificuldade!!!)" << std::endl << std::endl;*/
		std::cout << "Você pode escolher entre: 25 / 50 / 100" << std::endl;
		std::cin >> dificuldadeFichas;
		std::cout << std::endl;
		
		if (dificuldadeFichas != 25 && dificuldadeFichas != 50 && dificuldadeFichas != 100) {
			std::cout << "Estcolha entre (25), (50) ou (100) Por favor!!!" << std::endl;
		}

		saldoJogador += dificuldadeFichas;

		std::cout << saldoJogador << std::endl << std::endl << std::endl;

		return saldoJogador;
	}
	else{

		return saldoJogador;
	}
	
}

double Fichas::fichasIniciais(double& saldoJogador) {
	Jogador jogador;
	Mesa mesa;
	double escolhaJogador;
	std::cout << "Quantas fichas você quer começar?" << std::endl << "Você pode escolher entre 100/500/1000" << std::endl << std::endl;
	std::cin >> escolhaJogador;
	
	while (escolhaJogador != 100 && escolhaJogador != 500 && escolhaJogador != 1000) {
		std::cout << "Por favor digite entre os três valoeres (100/500/1000)!" << std::endl;
		std::cin >> escolhaJogador;
	}
	saldoJogador += escolhaJogador;
	

	return saldoJogador;
	

}

double Fichas::aposta(double& saldoJogador) {
	Jogador jogador;
	Mesa mesa;

	
	double aposta;

	std::cout << "Qual será sua aposta (Valor minimo 25 fichas)" << std::endl;
	std::cin >> aposta;

	
	while (aposta < 25) {
		std::cout << "VALOR MINIMO 25 FICHAS!!!!" << std::endl;
		std::cin >> aposta;
	}
	

	
	while (aposta > saldoJogador) {
		std::cout << saldoJogador << std::endl;
		std::cout << "Você não tem saldo para essa aposta" << std::endl;
		std::cin >> aposta;
		
	}

	  
	 return aposta;


	 //std::cout << saldoJogador << std::endl;

	 /*std::cout << std::endl << std::endl << std::endl;
	 std::cout << saldoJogador << std::endl;
	 std::cout << std::endl << std::endl << std::endl;
	*/
}




