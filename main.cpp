#include <iostream>
#include "Sala.h"
#include "Pelicula.h"
#include "Boleto.h"

using namespace std;

int main(){
    system("color 0E");
    cout <<"Autores: Hanner Joan Delgado Espino\n"
           "         Byron Geovanny Jaramillo Namicela\n"
           "         Tobar Soberon Justin Edu\n"
           "         Jorge Sebastian Reinoso Reyes\n";
    int opcion, numeroSala, posicion, totalBoletos, idBuscar, columna;
    char fila;

    bool continuar = true;

    int idPelicula[] = { 1, 2, 3, 4, 5 };

    std::string hora[] = { "14:30", "16:00", "18:20", "16:15", "11:30" };

    std::string titulo[] = { "El Rey Leon", "Spiderma: Lejos de Casa", "Annabelle 3: Vuelve a Casa", "Avengers: End Game", "Toy Story 4" };

    int duracion[] = { 117, 130, 106, 188, 104 };

    bool estreno[] = { true, true, false, false, false};

    Sala sala[5];

    Pelicula pelicula(idPelicula, titulo, duracion, estreno, hora);

    Boleto boletos[25];

    const float precioBoleto = 3.15f;

    while (continuar) {

        cout << "- - M I   C I N E - -" << endl<<endl;

        cout << "--------- MENU PRINCIPAL -----" << endl;
        cout << "1. Mostrar Cartelera\n2. Mostrar Sala\n3. Comprar Boletos\n4. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1:

                cout << "\n\n- - C A R T E L E R A - -" << endl << endl;

                 pelicula.mostrarPeliculas();

                break;

            case 2:

                cout << "Ingrese el numero de sala: ";
                cin >> numeroSala;

                posicion = pelicula.buscarPelicula(numeroSala);

                if (posicion != -1) {

                    pelicula.mostrarPelicula(posicion);

                    cout << "\n- - A S I E N T O S - -" << endl;

                    sala[posicion].mostrarSala();

                }else {

                    cout << "No se encontro la sala del cine" << endl;

                }

                break;

            case 3:

                cout << "Ingrese el ID de la pelicula: ";
                cin >> idBuscar;

                do {

                    cout << "Ingrese el numero de boletos: ";
                    cin >> totalBoletos;

                    if (totalBoletos < 1) {

                        cout << "El numero de boletos no pueden ser negativos" << endl;

                    }

                } while (totalBoletos < 1);

                posicion = pelicula.buscarPelicula(idBuscar);

                if (posicion != -1) {

                    cout << "\nSeleccione los asientos" << endl;

                    for (int i = 0; i < totalBoletos; i++) {

                        sala[posicion].modificarSalar();

                        fila = sala[posicion].getFila();

                        columna = sala[posicion].getColumna();

                        boletos[i] = Boleto(idBuscar, pelicula, fila, columna);

                    }

                    std::cout << "\nTOTAL DE LA COMPRA: " << endl;

                    for (int i = 0; i < totalBoletos; i++) {

                        cout << "\n\nBoleto #" << i + 1 <<endl;

                        cout << "\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;

                        boletos[i].mostrarBoleto();

                        cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;

                    }

                    cout << "\nTOTAL: " << ((float)totalBoletos * precioBoleto);

                }else {

                    std::cout << "No se encontro la sala del cine" << endl;

                }

                break;

            case 4:

                continuar = false;

                std::cout << "Saliendo del programa" << std::endl;

                break;

            default: cout << "Opcion invalida" << endl;

        }

        if (opcion != 4) {

            cout << endl;
            system("pause");
            system("cls");

        }

    }

}
