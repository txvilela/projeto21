#include <iostream>
#ifndef  JOGO_HPP
#define JOGO_HPP

class Mesa;
class Jogador;






class  Fichas {


private:
	int fichasJogador = 0;
	int fichasMesa = 0;



public:
		
	int veResultado(Mesa& mesa, Jogador& jogador);
	int compraFichas();
	int fichasIniciais();
	void aposta(int& saldoJogador);
};


#endif
