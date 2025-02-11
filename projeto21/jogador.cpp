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

int Jogador::calculaPontos() {
	int total = 0;
	for (const auto& cartas : cartasjogador) {
		if (cartas.numero_Carta == 1) {
			total += 11;
		}
		else if (cartas.numero_Carta >= 11 && cartas.numero_Carta <= 13) {
			total += 10;
		}
		else{
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

int Jogador::retornaSaldoFichas() {
	return saldoFichas;
}

void Jogador::comprafichas() {
	
	play.saldoFichas = fichas.compraFichas();
	 std::cout << play.retornaSaldoFichas() << "  SALDO FICHAS" << std::endl;
}

