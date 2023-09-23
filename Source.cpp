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
				valor = 1; break;
			}
			else if (p == 0) { valor = 11; break; }
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
void imprimirPuntaje(int &vJ1,int &vJ2) {
	int limiteX = 120, limiteY = 60;
	Console::SetWindowSize(limiteX, limiteY);
	Console::SetCursorPosition(100, 0);
	cout << " Victorias" << endl;
	Console::SetCursorPosition(100, 1);
	cout << "=====||=====" << endl;
	Console::SetCursorPosition(100, 2);
	cout<< "   " << vJ1 << " || " << vJ2<<"   " << endl;
	Console::SetCursorPosition(100, 3);
	cout << "=====||=====" << endl;
	Console::SetCursorPosition(0, 0);

}

int main() {
	int rondas = validarRondas();
	int j1 = 0, j2 = 0, desicionj1, desicionj2;
	int P1 = 0, P2 = 0, J1 = 0, J2 = 0, Vj1 = 0, Vj2 = 0;
	cout << ".------.------.------.------.------.------.------.------.------." << endl
		<< "|B.--. |L.--. |A.--. |C.--. |K.--. |J.--. |A.--. |C.--. |K.--. |" << endl
		<< "| :(): | :/\\: | (\\/) | :/\\: | :/\\: | :(): | (\\/) | :/\\: | :/\\: |" << endl
		<< "| ()() | (__) | :\\/: | :\\/: | :\\/: | ()() | :\\/: | :\\/: | :\\/: |" << endl
		<< "| '--'B| '--'L| '--'A| '--'C| '--'K| '--'J| '--'A| '--'C| '--'K|" << endl
		<< "`------`------`------`------`------`------`------`------`------'" << endl;
	cout << "Empieza el juego:" << endl;
	cout << "Presiona una tecla para jugar"<< endl; _getch();


	for (int i = 1; i <= rondas; i++) {
		system("cls");
		imprimirPuntaje(Vj1, Vj2);
		cout << "Ronda: " << i << endl<<"=============" << endl;

		desicionj1 = 2;
		desicionj2 = 2;
		if (j1 != 0)j1 = 0;
		if (j2 != 0)j2 = 0;

		cout << "Repartiendo carta para jugador 1: " 
			<< endl << "=============" << endl;
		darCarta(j1); 
		cout << endl
			<< "=============" <<endl;
		cout << "pulsa una tecla para la carta del segundo jugador " << endl; _getch();
		cout << "Repartiendo carta para jugador 2: " << endl
			<<"============="
			<<endl; 
		darCarta(j2);
		cout << endl
			<< "=============" << endl;
		_getch();
		system("cls");
		imprimirPuntaje(Vj1, Vj2);

		do {
			if (desicionj1 == 0) { J1 = j1; break; }


			cout << "Jugador 1, quieres otra carta? Llevas: " << j1<< endl << "[1] Si [0] No " << endl; cin >> desicionj1;


			if (desicionj1 == 1)darCarta(j1);
			if (j1 > 21) { cout << endl << "Te pasaste." << endl << endl; J1 = 0; break; }
			if (j1 == 21) { cout << "Sacaste 21!!! " << endl << endl; J1 = 21; break; }
			cout << "Presiona una tecla para continuar" << endl;
			_getch();

			system("cls");
			imprimirPuntaje(Vj1, Vj2);


		} while (desicionj1 != 2);

		do {
			if (desicionj2 == 0) { J2 = j2; break; }


			cout << "Jugador 2, quieres otra carta? Llevas: "<<j2 << endl << "[1] Si [0] No " << endl; cin >> desicionj2;


			if (desicionj2 == 1)darCarta(j2);
			if (j2 > 21) { cout << "Te pasaste." << endl << endl; J2 = 0; break; }
			if (j2 == 21) { cout << "Sacaste 21!!! " << endl << endl; J2 = 21; break; }
			cout << "Presiona una tecla para continuar" << endl;

			_getch();

			system("cls");
			imprimirPuntaje(Vj1, Vj2);


		} while (desicionj2 != 2);

		if (J1 > J2||J1==21) { cout << endl << "El jugador 1 ha ganado"; Vj1++; }
		if (J2 > J1 || J2 == 21) { cout << endl << "El jugador 2 ha ganado"; Vj2++; }
		if (J2 == J1) { cout << endl << "Ha sido un empate"; }
		_getch();

	}
	system("cls");
	imprimirPuntaje(Vj1, Vj2);

	cout << "============ " << endl
		 << "RESULTADOS: " << endl
		 << "============ " << endl
		 << "Victorias del jugador 1: " << Vj1 << endl
		 << "Victorias del jugador 2: " << Vj2 << endl;
	if (Vj1 > Vj2) { cout << "Ha ganado el jugador 1" << endl; }
	if (Vj1 < Vj2) { cout << "Ha ganado el jugador 2" << endl; }
	if (Vj1 == Vj2) { cout << "El Resultado es un Empate" << endl; }



	_getch();

}