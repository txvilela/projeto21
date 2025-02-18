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
	double saldoFichas;

public:
	Jogador();

	size_t retornaNumeroCartas();

	bool maoJogador(const Carta& carta1, const Carta& carta2, Baralho& baralho);
	bool resposta();
	void mostraCarta(const std::vector <Carta>& cartasjogador, const std::string& Titulo);
	double calculaPontos();
	double retornaSaldoFichas();
	void comprafichas();
	void ganhou(double& saldo, double& aposta, double pontosJo, double pontosMe);
	void inicioFichas();
	double condicaoDeVitoria(double& aposta, double& saldo, double pontosJo, double pontosMe);
	double valorAposta();
};

#endif // !JOGADOR_HPP