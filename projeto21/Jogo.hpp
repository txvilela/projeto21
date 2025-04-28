#include <iostream>
#ifndef  JOGO_HPP
#define JOGO_HPP

class Mesa;
class Jogador;






class  Fichas {


private:
	double fichasJogador = 0;
	double fichasMesa = 0;



public:
		
	double resultadojogador(Jogador& jogador);
	double resultadoMesa(Mesa& mesa);
	double compraFichas(double& saldoJogador);
	double fichasIniciais(double& saldoJogador);
	double aposta(double& saldoJogador);

};


#endif
