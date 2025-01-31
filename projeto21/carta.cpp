#include "carta.hpp"

std::ostream& operator<<(std::ostream& os, const Carta& carta) {
	if (carta.numero_Carta == 11) {
		os << "J";
	}
	else if (carta.numero_Carta == 12) {
		os << "Q";
	}
	else if (carta.numero_Carta == 13) {
		os << "K";
	}
	else if (carta.numero_Carta == 1) {
		os << "A";
	}
	else {
		os << carta.numero_Carta;
	}

	os << " " << carta.naipe_Carta;
	return os;
}
