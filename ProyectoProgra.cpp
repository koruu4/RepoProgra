#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int fnMenu();
int fnElegirJugadorInicial();
void fnJugadorContraJugador();
// int fnJugadorContraComputadora();
void construirTablero();
void construirTablero()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i < 5 && i % 2 != 0)
            {
                cout << "___";
            }
            else
            {
                cout << "   ";
            }
            if (j < 2)
            {
                cout << "|";
            }
        }
        cout << endl;
    }
}

int fnElegirJugadorInicial()
{
    int vNumero;
    srand(time(0));
    vNumero = 1 + rand() % (2 + 1 - 1);
    return vNumero;
}
int fnMenu()
{
    int op;
    cout << "------------------------------------" << endl;
    cout << "   BIENVENIDO AL JUEGO DE TOTITO    " << endl;
    cout << "------------------------------------" << endl;
    cout << "Ingrese modo de juego:" << endl;
    cout << "1 | Jugador contra jugador..." << endl;
    cout << "2 | Jugador contra computadora..." << endl;
    cout << "3 | Salir..." << endl;
    cout << "Ingrese opcion de juego = ";
    cin >> op;
    return op;
}
void fnJugadorContraJugador()
{
    int jugadorInicialEscoger;
    string jugadorInicial, jugadorSecundario;
    construirTablero();
    string nombreJugador1;
    string nombreJugador2;
    cin.ignore();
    cout << "Ingrese nombre de primer jugador = ";
    getline(cin, nombreJugador1);
    cout << "Ingrese nombre de segundo jugador = ";
    getline(cin, nombreJugador2);
    jugadorInicialEscoger = fnElegirJugadorInicial();
    if (jugadorInicialEscoger == 1)
    {
        jugadorInicial = nombreJugador1;
        jugadorSecundario = nombreJugador2;
    }
    else
    {
        jugadorInicial = nombreJugador2;
        jugadorSecundario = nombreJugador1;
    }
    cout << "El jugador que empezara jugando es " << jugadorInicial << endl;
}
int main()
{
    int opcion = fnMenu();
    switch (opcion)
    {
    case 1:
        fnJugadorContraJugador();
        break;
    case 2:
        // fnJugadorContraComputadora();
        break;
    case 3:
        break;
    default:
        cout << "Porfavor, ingrese una opcion correcta..." << endl;
    }
    return 0;
}