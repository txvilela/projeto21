#include <iostream>
#ifndef  JOGO_HPP
#define JOGO_HPP

class Mesa;
class Jogador;






class  Fichas {


private:
	int fichasJogador = 0;
	int fichasMesa = 1000;



public:
		
	int veResultado(Mesa& mesa, Jogador& jogador);
	int compraFichas();
};

#endif
