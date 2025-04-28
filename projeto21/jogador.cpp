#include <iostream>
#include "jogador.hpp"
#include "baralho.hpp"
#include "carta.hpp"
#include "mesa.hpp"
#include "Jogo.hpp"

Jogador jogador;
Mesa mesa;
Fichas fichas;

Jogador::Jogador(){}

bool Jogador::maoJogador(const Carta& carta1, const Carta& carta2, Baralho& baralho) {
	jogador.Cartasjogador.clear();
	jogador.Cartasjogador.push_back(carta1);
	jogador.Cartasjogador.push_back(carta2);
	
	//std::cout << "Cartas adicionadas: " << jogador.Cartasjogador.size() << std::endl; // Debug

	mostraCarta(jogador.Cartasjogador, "Suas Cartas");

			
	while (true) {
		if (calculaPontos() > 21) {
			std::cout << "Você estourou!!!" << std::endl;
			return false;
		}
		if (resposta())  {
			jogador.Cartasjogador.push_back(baralho.darCarta());
			mostraCarta(jogador.Cartasjogador, "Suas Cartas");
		}
		else{
			mostraCarta(jogador.Cartasjogador, "Suas Cartas finais!!!");
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
		if (jogador.Cartasjogador.size() == 2) {
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
		for (const auto& cartas : jogador.Cartasjogador) {
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
		for (const auto& cartas : jogador.Cartasjogador) {
			if (cartas.numero_Carta == 1 && total > 21) {
				total -= 10;
			}
		}
		return total;
	}

double Jogador::retornaSaldoFichas(Jogador& jogador) {
	return saldoFichas;
}


void Jogador::inicioFichas(Jogador& jogador) {
	if (jogador.retornaSaldoFichas(jogador) <= 0) {

		jogador.saldoFichas = fichas.fichasIniciais(jogador.saldoFichas);

		std::cout << "Você começa com " << jogador.retornaSaldoFichas(jogador) << " fichas seu objetivo é zerar as " << mesa.retornaSaldoFichasMesa() << " fichas da mesa" << std::endl << std::endl;
		/*std::cout << play.retornaSaldoFichas() << "  SALDO FICHAS" << std::endl;*/

		/*play.saldoFichas -= fichas.aposta(play.saldoFichas);*/

		std::cout << jogador.retornaSaldoFichas(jogador) << "  SALDO FICHAS" << std::endl;
	}

}
double Jogador::valorAposta(Jogador& jogador) {
	double aposta = fichas.aposta(jogador.saldoFichas);
	jogador.saldoFichas -= aposta;

	std::cout << jogador.retornaSaldoFichas(jogador) << "  SALDO FICHAS" << std::endl;
	return aposta;
}

void Jogador::comprafichas(Jogador& jogador) {
	
	//play.saldoFichas = fichas.compraFichas(play.saldoFichas); // so para testar se esta discontando as fichas do lugar certo
	 std::cout << jogador.retornaSaldoFichas(jogador) << "  SALDO FICHAS" << std::endl;
}

void Jogador::ganhou(double& saldoJ, double& apostaJ, double pontosJo, double pontosMe) {
	double vitoria = jogador.condicaoDeVitoria(apostaJ, saldoJ, pontosJo, pontosMe);
	std::cout << vitoria << " VITORIA" << std::endl;
	std::cout << saldoJ << "saldoJ" << std::endl;

	saldoJ += vitoria;
}

size_t Jogador::retornaNumeroCartas(const std::vector <Carta>& cartasjogador) {
	//std::cout << "Chamei retornaNumeroCartas(): " << cartasjogador.size() << std::endl; // Debug
	return cartasjogador.size();

}

double Jogador::condicaoDeVitoria(double& aposta, double& saldo, double pontosJo, double pontosMe) {
	std::cout << std::endl << std::endl;

	std::cout << pontosJo << "    " << pontosMe << " os pontos " << std::endl;
	if (pontosJo <= 21) {
		//std::cout <<  " numero de cartas " << retornaNumeroCartas(jogador.Cartasjogador) << std::endl;
		if (pontosJo == 21 && retornaNumeroCartas(jogador.Cartasjogador) == 2) {
			saldo += aposta + (aposta * 1.5);
			std::cout << saldo << " Parabés você fez um Blackjack!!! " << std::endl;
			return saldo;
		}

		else if (pontosMe > 21) {
			saldo += aposta + aposta;
			std::cout << saldo << " Parabés você ganhou!!! " << std::endl;
			return saldo;
		}
		
		else if (pontosJo > pontosMe) {
			saldo += aposta + aposta;
			std::cout << saldo << " Parabés você ganhou!!! " << std::endl;
			return saldo;			
		}

		else if(pontosJo == pontosMe && pontosMe <= 21){
			saldo += aposta;
			std::cout << saldo << " empate!!! " << std::endl;
			return saldo;
		}
		else{
			std::cout << saldo << " Perdeu!!! " << std::endl;
			return saldo;
		}
	}
	
}
