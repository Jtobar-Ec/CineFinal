#include <iostream>
#include <cctype>
#include <iomanip>
#include "Sala.h"
#include <iostream>
using namespace std;
Sala::Sala() {

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            sala[i][j] = 'O';

        }

    }

}

void Sala::mostrarSala() {

    for (int i = 1; i <= 5; i++) {

        cout << setw(4) << i;

    }


    for (int i = 0; i < 5; i++) {

        cout << ((char)(65 + i));

        for (int j = 0; j < 5; j++) {

            cout <<setw(3) << sala[i][j];

        }

        cout << endl;

    }

}

int Sala::obtenerFila(char fila) {

    int filaPosicion;

    switch (fila) {


        case 'A': filaPosicion = 0; break;

        case 'B': filaPosicion = 1; break;

        case 'C': filaPosicion = 2; break;

        case 'D': filaPosicion = 3; break;

        case 'E': filaPosicion = 4; break;

    }

    return filaPosicion;

}

void Sala::modificarSalar() {

    int filaPos;

    do{

        do {

            cout << "Ingrese el asiento: ";
            cin >> fila >> columna;

            fila = toupper(fila);

            if (fila < 'A' or fila > 'E' or columna < 1 or columna > 5) {

                cout << "El lugar que esta eligiendo no existe" << endl;

            }

        } while (fila < 'A' or fila > 'E' or columna < 1 or columna > 5);

        columna -= 1;

        filaPos = obtenerFila(fila);

        if (sala[filaPos][columna] == 'X') {

            cout << "El asiento ya esta ocupado" << endl;

        }

    } while (sala[filaPos][columna] == 'X');

    sala[filaPos][columna] = 'X';

}

int Sala::getColumna() {

    return columna + 1;

}

char Sala::getFila() {

    return fila;

}
