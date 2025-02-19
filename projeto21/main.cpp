#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "chama_mesa.hpp"
#include "baralho.hpp"
#include "mesa.hpp"
#include "jogador.hpp"
#include "Jogo.hpp"

int main() {
	srand(static_cast<unsigned int>(time(0)));

	
	
		
	
	
	Baralho baralho;
	Mesa mesa;
	Jogador jogador;
	Fichas fichas;

	//baralho.imprimir();
	/*fichas.fichasIniciais();*/
	while (true) {
		std::cout << jogador.retornaSaldoFichas(jogador) << " volta do lup " << std::endl; // debug

		jogador.inicioFichas(jogador);
	
		double aposta = jogador.valorAposta(jogador);

		std::cout  << std::endl << std::endl;

		mesa.mesa(baralho.darCarta(), baralho.darCarta());
		mesa.mostracartamesa();


		if (!jogador.maoJogador(baralho.darCarta(), baralho.darCarta(), baralho)) {
			mesa.mostratudo();
		}

		/*std::cout << fichas.resultadojogador(jogador) << std::endl << std::endl;
		std::cout << fichas.resultadoMesa(mesa) << std::endl << std::endl;*/

		double resJoga = fichas.resultadojogador(jogador);
		double resMesa = fichas.resultadoMesa(mesa);


		double saldo = jogador.retornaSaldoFichas(jogador);

		std::cout << saldo << "  SALDO MAIN     " << std::endl;
		//double aposta = fichas.aposta(saldo);

		jogador.ganhou(saldo, aposta , resJoga, resMesa);

		jogador.comprafichas(jogador);


		std::cout << jogador.retornaSaldoFichas(jogador) << std::endl;
		//chama_Mesa(baralho.darCarta(), baralho.darCarta(), baralho.darCarta(), baralho.darCarta());
		std::cout << "Quer parar?" << std::endl;
		std::string respostinha;
		std::cin >> respostinha;

		

		if (respostinha == "ok") {
			return 0;
		}
	}

}
