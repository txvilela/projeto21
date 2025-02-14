#include <iostream>
#include "jogador.hpp"
#include "baralho.hpp"
#include "carta.hpp"
#include "mesa.hpp"
#include "Jogo.hpp"

Jogador play;
Mesa mesa;
Fichas fichas;

Jogador::Jogador(){}

bool Jogador::maoJogador(const Carta& carta1, const Carta& carta2, Baralho& baralho) {
	cartasjogador.push_back(carta1);
	cartasjogador.push_back(carta2);
	
	mostraCarta(cartasjogador, "Suas Cartas");

			
	while (true) {
		if (calculaPontos() > 21) {
			std::cout << "Você estourou!!!" << std::endl;
			return false;
		}
		if (resposta())  {
			cartasjogador.push_back(baralho.darCarta());
			mostraCarta(cartasjogador, "Suas Cartas");
		}
		else{
			mostraCarta(cartasjogador, "Suas Cartas finais!!!");
			return false;
		}
	}

}

void Jogador::mostraCarta(const std::vector <Carta>& cartasjogador, const std::string& Titulo) {
	std::cout << Titulo << std::endl;
	for (const auto& cartas : cartasjogador) {
		std::cout << cartas << " ";
	}
	
	std::cout << std::endl;
	std::cout << "Seus pontos " << calculaPontos() << std::endl;
	

}

bool Jogador::resposta() {
	char resposta;
	if (calculaPontos() == 21) {
		std::cout << std::endl;
		if (cartasjogador.size() == 2) {
			std::cout << "Blackjack!!!" << std::endl << std::endl;
		}
			return false;
		}

		std::cout << std::endl << "Vai querer outra carta? (s/n)" << std::endl;
		std::cin >> resposta;
		resposta = std::tolower(resposta);
		std::cout << std::endl;

		while (resposta != 'n' && resposta != 's') {
			std::cout << "apenas s ou n!" << std::endl;
			std::cin >> resposta;
			resposta = std::tolower(resposta);
		}
		return resposta == 's';
	}


	double Jogador::calculaPontos() {
		int total = 0;
		for (const auto& cartas : cartasjogador) {
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
		for (const auto& cartas : cartasjogador) {
			if (cartas.numero_Carta == 1 && total > 21) {
				total -= 10;
			}
		}
		return total;
	}

double Jogador::retornaSaldoFichas() {
	return saldoFichas;
}


void Jogador::inicioFichas() {
	if (play.retornaSaldoFichas() <= 0) {

		play.saldoFichas = fichas.fichasIniciais(play.saldoFichas);

		std::cout << "Você começa com " << play.retornaSaldoFichas() << " fichas seu objetivo é zerar as " << mesa.retornaSaldoFichasMesa() << " fichas da mesa" << std::endl << std::endl;
		/*std::cout << play.retornaSaldoFichas() << "  SALDO FICHAS" << std::endl;*/

		/*play.saldoFichas -= fichas.aposta(play.saldoFichas);*/

		std::cout << play.retornaSaldoFichas() << "  SALDO FICHAS" << std::endl;
	}

}
double Jogador::valorAposta() {
	double aposta = fichas.aposta(play.saldoFichas);
	play.saldoFichas -= aposta;

	std::cout << play.retornaSaldoFichas() << "  SALDO FICHAS" << std::endl;
	return aposta;
}

void Jogador::comprafichas() {
	
	//play.saldoFichas = fichas.compraFichas(play.saldoFichas); // so para testar se esta discontando as fichas do lugar certo
	 std::cout << play.retornaSaldoFichas() << "  SALDO FICHAS" << std::endl;
}

void Jogador::condicaoDeVitoria(Jogador& jogador, double& aposta, double& saldo) {
	int pontos = fichas.resultadojogador(jogador);
		if (pontos == 21) {
			saldo += aposta + (aposta * 1.5);
		 std::cout << saldo << "SALDO TOTAL!!MULTIPLICADO " << std::endl;

		
	}
	
}
