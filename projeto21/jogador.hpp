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
	std::vector <Carta> Cartasjogador;
	double saldoFichas;

public:
	Jogador();

	size_t retornaNumeroCartas(const std::vector <Carta>& cartasjogador);

	bool maoJogador(const Carta& carta1, const Carta& carta2, Baralho& baralho);
	bool resposta();
	void mostraCarta(const std::vector <Carta>& cartasjogador, const std::string& Titulo);
	double calculaPontos();
	double retornaSaldoFichas(Jogador& jogador);
	void comprafichas(Jogador& jogador);
	void ganhou(double& saldo, double& aposta, double pontosJo, double pontosMe);
	void inicioFichas(Jogador& jogador);
	double condicaoDeVitoria(double& aposta, double& saldo, double pontosJo, double pontosMe);
	double valorAposta(Jogador& jogador);
};

#endif // !JOGADOR_HPP