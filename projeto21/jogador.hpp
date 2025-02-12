#ifndef JOGADOR_HPP
#define JOGADOR_HPP


#include <iostream>
#include <vector>
#include <string>


//#include "Jogo.hpp"

class Carta;
class Baralho;

class Jogador {
private:
	std::vector <Carta> cartasjogador;
	int saldoFichas;

public:
	Jogador();
	bool maoJogador(const Carta& carta1, const Carta& carta2, Baralho& baralho);
	bool resposta();
	void mostraCarta(const std::vector <Carta>& cartasjogador, const std::string& Titulo);
	int calculaPontos();
	int retornaSaldoFichas();
	void comprafichas();
	void inicioFichas();
};

#endif // !JOGADOR_HPP