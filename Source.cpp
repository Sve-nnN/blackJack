#include "iostream"
#include "conio.h"
#include "time.h"
using namespace System;
using namespace std;



int crearCarta() {
	Random r;
	int carta = r.Next(1, 13);

	return carta;
}
void darCarta(int& jugador) {
	int size = 4;
	int p = 2;
	int carta = crearCarta();
	int valor = carta;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j == 0 || i == 0 || j == size - 1 || i == size - 1)cout << "*";
			else if (i == 1 && j == 1)cout << carta;
			else cout << " ";
		}
		cout << endl;
	}
	if (carta == 11 || carta == 12 || carta == 13)valor = 10;
	if (carta == 1) {
		cout << "Sacaste un As" << endl; do {
			cout << "SELECCIONA SU VALOR: " << endl << "[1] 1" << endl << "[0] 11" << endl; cin >> p;
			if (p == 1) {
				valor == 1; break;
			}
			else if (p == 0) { valor == 11; break; }
			else cout << "Elige un valor correcto" << endl;
		} while (p != 1 && p != 0);

	}
	jugador = jugador + valor;
	cout << "Carta dada: " << carta << " Llevas: " << jugador << endl;
}
int validarRondas() {
	int rondas;

	do {
		cout << "Introduce el numero de rondas a jugar: "; cin >> rondas;
	} while (rondas < 5 || rondas > 10);
	return rondas;
}
void imprimirPuntaje(int &pJ1,int &pJ2) {
	int limiteX = 120, limiteY = 60;
	Console::SetWindowSize(limiteX, limiteY);
	Console::SetCursorPosition(100, 0);
	cout << "   PUNTAJES" << endl;
	Console::SetCursorPosition(100, 1);
	cout << "===============" << endl;
	Console::SetCursorPosition(100, 2);
	cout<< "   " << pJ1 << " || " << pJ2<<"   " << endl;
}

int main() {
	int rondas = validarRondas();
	int j1 = 0, j2 = 0, desicionj1, desicionj2;
	int P1 = 0, P2 = 0, J1 = 0, J2 = 0, Vj1 = 0, Vj2 = 0;

	cout << "Empieza el juego:" << endl;


	for (int i = 1; i <= rondas; i++) {
		system("cls");
		imprimirPuntaje(Vj1, Vj2);
		cout << "Ronda: " << i << endl << endl;

		desicionj1 = 2;
		desicionj2 = 2;
		if (j1 != 0)j1 = 0;
		if (j2 != 0)j2 = 0;
		cout << "Repartiendo carta para jugador 1: " << endl; darCarta(j1);
		cout << "pulsa una tecla para la carta del segundo jugador " << endl; _getch();
		cout << "Repartiendo carta para jugador 2: " << endl; darCarta(j2);

		do {
			if (desicionj1 == 0) { J1 = j1; break; }

			if (j1 > 21) { cout << "Te pasaste." << endl; break; }
			if (j1 == 21) { cout << "Ganaste!!!!! " << endl; break; }
			cout << "Jugador 1, quieres otra carta?" << endl << "[1] Si [0] No " << endl; cin >> desicionj1;


			if (desicionj1 == 1)darCarta(j1);

		} while (desicionj1 != 2);

		do {
			if (desicionj2 == 0) { J2 = j2; break; }

			if (j2 > 21) { cout << "Te pasaste." << endl; break; }
			if (j2 == 21) { cout << "Ganaste!!!!! " << endl; break; }
			cout << "Jugador 2, quieres otra carta?" << endl << "[1] Si [0] No " << endl; cin >> desicionj2;


			if (desicionj2 == 1)darCarta(j2);

		} while (desicionj2 != 2);

		if (J1 > J2 && j1 < 21) { cout << endl << "El jugador 1 ha ganado"; Vj1++; }
		else if (J2 > J1 && j2 < 21) { cout << endl << "El jugador 2 ha ganado"; Vj2++; } _getch();

	}
	cout << "RESULTADOS: " << endl;
	cout << "Victorias del jugador 1: " << Vj1 << endl;
	cout << "Victorias del jugador 2: " << Vj2 << endl;
	if (Vj1 > Vj2) { cout << "Ha ganado el jugador 1"; }
	else cout << "Ha ganado el jugador 2";



	system("pause");

}