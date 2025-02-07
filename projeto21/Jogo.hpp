#include <iostream>
#ifndef  JOGO_HPP
#define JOGO_HPP

class Mesa;
class Jogador;






class  Fichas {


private:
	int fichasJogador;
	int fichasMesa = 1000;



public:
	Fichas() {
		fichasJogador = 0;
	}
	
	int veResultado(Mesa& mesa, Jogador& jogador);
	void compraFichas();
};

#endif
