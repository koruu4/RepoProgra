#include <iostream>
#include <stdlib.h>
#include <time.h>  //eleccion random de primera ronda
#include <conio.h> //system clear y gotoxy ;p
#include <cstring> // Para memcpy
using namespace std;
string jugadorInicial, jugadorSecundario, jugadorAux;
char repetirPartida, signoTablero1, signoTablero2, signoTableroaux;
string nombreJugador1;
string nombreJugador2;
int turno = 0, contadorPartidas = 1;
char tablero[3][3]{{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char valoresIniciales[3][3]{{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
int fnMenu();                                 // se muestra menu con 2 tipos de juego
int fnElegirJugadorInicial();                 // se elige primer jugador solo en primera partida, se pide signo deseado
int fnVerificarGanador();                     // Solo se verifica si alguien ganó la partida
void fnIdentificarGanador(int turnoAnterior); // Se toma en cuenta en que turno se esta para obtener quien gano
void fnJugadorContraJugador();                // toda la funcion de este modo de juego
char fnPosiblesJugadas();                     // muestra jugadas posibles y disponibles
void fnActualizarTurnos(int x, int y);        // despues de comprobar disponibilidad imprime turno
int fnVerificarJugada(char jugada);           // verifica si la jugada enviada es posible o no
void fnJugadorContraComputadora();            // version del juego solo contra la computadora
void construirTablero();                      // construye tablero
void construirTablero()
{
    cout << "     0   1   2" << endl;
    cout << "   -------------" << endl;

    cout << " 0"
         << " | " << tablero[0][0] << " | " << tablero[0][1] << " | "
         << tablero[0][2] << " | " << endl;
    cout << "   -------------" << endl;

    cout << " 1"
         << " | " << tablero[1][0] << " | " << tablero[1][1] << " | "
         << tablero[1][2] << " | " << endl;
    cout << "   -------------" << endl;

    cout << " 2"
         << " | " << tablero[2][0] << " | " << tablero[2][1] << " | "
         << tablero[2][2] << " | " << endl;
    cout << "   -------------" << endl;
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
char fnPosiblesJugadas()
{
    cout << endl;
    cout << "OPCIONES DEL JUEGO" << endl;
    int contador = 0;
    string opciones = "abcdefghi";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << opciones[contador] << " - [" << i << ", " << j << "]";
            if (tablero[i][j] != ' ')
            {
                cout << " OCUPADO";
            }
            cout << endl;

            contador++;
        }
    }
    if (turno % 2 == 0)
    {
        cout << jugadorInicial;
    }
    else
    {
        cout << jugadorSecundario;
    }

    cout << ", elige una jugada: ";
    return getch();
}
char fnPosiblesJugadasComputadora()
{
    cout << endl;
    cout << "OPCIONES DEL JUEGO" << endl;
    int contador = 0;
    string opciones = "abcdefghi";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << opciones[contador] << " - [" << i << ", " << j << "]";
            if (tablero[i][j] != ' ')
            {
                cout << " OCUPADO";
            }
            cout << endl;

            contador++;
        }
    }
    char vLetra;
    int vNumeroJugada;
    srand(time(0));
    vNumeroJugada = 1 + rand() % (9 + 1 - 1);
    if (vNumeroJugada == 1)
    {
        vLetra = 'a';
    }
    if (vNumeroJugada == 2)
    {
        vLetra = 'b';
    }
    if (vNumeroJugada == 3)
    {
        vLetra = 'c';
    }
    if (vNumeroJugada == 4)
    {
        vLetra = 'd';
    }
    if (vNumeroJugada == 5)
    {
        vLetra = 'e';
    }
    if (vNumeroJugada == 6)
    {
        vLetra = 'f';
    }
    if (vNumeroJugada == 7)
    {
        vLetra = 'g';
    }
    if (vNumeroJugada == 8)
    {
        vLetra = 'h';
    }
    if (vNumeroJugada == 9)
    {
        vLetra = 'i';
    }
    return vLetra;
}
int fnVerificarJugada(char jugada)
{
    if (jugada >= 'a' && jugada <= 'i')
    {
        switch (jugada)
        {
        case 'a':
            if (tablero[0][0] == ' ')
            {
                fnActualizarTurnos(0, 0);
                return 1;
            }
            break;
        case 'b':
            if (tablero[0][1] == ' ')
            {
                fnActualizarTurnos(0, 1);
                return 1;
            }
            break;
        case 'c':
            if (tablero[0][2] == ' ')
            {
                fnActualizarTurnos(0, 2);
                return 1;
            }
            break;
        case 'd':
            if (tablero[1][0] == ' ')
            {
                fnActualizarTurnos(1, 0);
                return 1;
            }
            break;
        case 'e':
            if (tablero[1][1] == ' ')
            {
                fnActualizarTurnos(1, 1);
                return 1;
            }
            break;
        case 'f':
            if (tablero[1][2] == ' ')
            {
                fnActualizarTurnos(1, 2);
                return 1;
            }
            break;
        case 'g':
            if (tablero[2][0] == ' ')
            {
                fnActualizarTurnos(2, 0);
                return 1;
            }
            break;
        case 'h':
            if (tablero[2][1] == ' ')
            {
                fnActualizarTurnos(2, 1);
                return 1;
            }
            break;
        case 'i':
            if (tablero[2][2] == ' ')
            {
                fnActualizarTurnos(2, 2);
                return 1;
            }
            break;
        }
    }
    return 0;
}
void fnActualizarTurnos(int x, int y)
{
    if (turno % 2 == 0)
    {
        tablero[x][y] = signoTablero1;
    }
    else
    {
        tablero[x][y] = signoTablero2;
    }
    turno++;
}
int fnVerificarGanador()
{
    // verticales
    if (tablero[0][0] != ' ' && tablero[0][0] == tablero[0][1] && tablero[0][0] == tablero[0][2])
    {
        return 1;
    }
    if (tablero[1][0] != ' ' && tablero[1][0] == tablero[1][1] && tablero[1][0] == tablero[1][2])
    {
        return 1;
    }
    if (tablero[2][0] != ' ' && tablero[2][0] == tablero[2][1] && tablero[2][0] == tablero[2][2])
    {
        return 1;
    }
    // horizontales
    if (tablero[0][0] != ' ' && tablero[0][0] == tablero[1][0] && tablero[0][0] == tablero[2][0])
    {
        return 1;
    }
    if (tablero[0][1] != ' ' && tablero[0][1] == tablero[1][1] && tablero[0][1] == tablero[2][1])
    {
        return 1;
    }
    if (tablero[0][2] != ' ' && tablero[0][2] == tablero[1][2] && tablero[0][2] == tablero[2][2])
    {
        return 1;
    }
    // diagonales
    if (tablero[0][0] != ' ' && tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2])
    {
        return 1;
    }
    if (tablero[0][2] != ' ' && tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0])
    {
        return 1;
    }
    return 0;
}
void fnIdentificarGanador(int turnoAnterior)
{
    cout << "FELICIDADESS!!!" << endl;
    if (turnoAnterior % 2 == 0)
    {
        cout << "El ganador es : " << jugadorInicial << "[" << signoTablero1 << "]" << endl;
    }
    else
    {
        cout << "El ganador es : " << jugadorSecundario << "[" << signoTablero2 << "]" << endl;
        jugadorAux = jugadorInicial;
        jugadorInicial = jugadorSecundario;
        jugadorSecundario = jugadorAux;
        signoTableroaux = signoTablero1;
        signoTablero1 = signoTablero2;
        signoTablero2 = signoTablero1;
    }
}
void fnJugadorContraJugador()
{
    int numeroDeTurnos = 0, banderaJugada = 0, banderaGanador = 0;
    if (contadorPartidas == 1)
    {
        int jugadorInicialEscoger;
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
        cout << "Primer jugador, porfavor elija que signo usar o/x = ";
        cin >> signoTablero1;
        do
        {
            cout << "Segundo jugador, porfavor elija que signo usar o/x = ";
            cin >> signoTablero2;
            if (signoTablero2 == signoTablero1)
            {
                cout << "Porfavor, ingrese un signo distinto " << endl;
            }
        } while (signoTablero2 == signoTablero1);
    }
    if (contadorPartidas > 1)
    {
        memcpy(tablero, valoresIniciales, sizeof(valoresIniciales));
        numeroDeTurnos = 0, banderaJugada = 0, banderaGanador = 0, turno = 0;
    }
    while (numeroDeTurnos < 9 && banderaGanador == 0)
    {
        system("cls");
        construirTablero();
        banderaJugada = fnVerificarJugada(fnPosiblesJugadas());
        if (banderaJugada == 1)
        {
            banderaGanador = fnVerificarGanador();
            numeroDeTurnos++;
        }
    }
    cout << endl;
    system("cls");
    construirTablero();
    if (banderaGanador == 1)
    {
        fnIdentificarGanador(numeroDeTurnos - 1);
    }
    else
    {
        cout << "EL JUEGO TERMINO EN UN EMPATE..." << endl;
    }
}
void fnJugadorContraComputadora()
{
    int numeroDeTurnos = 0, banderaJugada = 0, banderaGanador = 0, vNumeroSigno;
    if (contadorPartidas == 1)
    {
        int jugadorInicialEscoger;
        nombreJugador2 = "Computadora :P";
        cin.ignore();
        cout << "Ingrese nombre de jugador = ";
        getline(cin, nombreJugador1);
        jugadorInicialEscoger = fnElegirJugadorInicial();
        if (jugadorInicialEscoger == 1)
        {
            jugadorInicial = nombreJugador1;
            jugadorSecundario = nombreJugador2;
            cout << "El jugador que empezara jugando es " << jugadorInicial << endl;
            cout << "Primer jugador, porfavor elija que signo usar o/x = ";
            cin >> signoTablero1;
            if (signoTablero1 == 'x')
            {
                signoTablero2 = 'o';
            }
            else
            {
                signoTablero2 = 'x';
            }
        }
        else
        {
            jugadorInicial = nombreJugador2;
            jugadorSecundario = nombreJugador1;
            cout << "El jugador que empezara jugando es " << jugadorInicial << endl;
            srand(time(0));
            vNumeroSigno = 1 + rand() % (2 + 1 - 1);
            if (vNumeroSigno == 1)
            {
                signoTablero1 = 'x';
                signoTablero2 = 'o';
            }
            else
            {
                signoTablero1 = 'o';
                signoTablero2 = 'x';
            }
            cout << "El jugador utilizara el signo " << signoTablero1<<endl;
            cout << "La computadora utilizara el signo " << signoTablero2<<endl;
            system("cls"); 
        }
    }
    if (contadorPartidas > 1)
    {
        memcpy(tablero, valoresIniciales, sizeof(valoresIniciales));
        numeroDeTurnos = 0, banderaJugada = 0, banderaGanador = 0, turno = 0;
    }
    while (numeroDeTurnos < 9 && banderaGanador == 0)
    {
        system("cls");
        construirTablero();
        if ((turno % 2 == 0 && jugadorInicial == nombreJugador2) || (turno % 2 != 0 && jugadorSecundario == nombreJugador2))
        {
            char vLetra;
            int vNumeroJugada;
            do
            {
                srand(time(0));
                vNumeroJugada = 1 + rand() % (9 + 1 - 1);
                if (vNumeroJugada == 1)
                {
                    vLetra = 'a';
                }
                if (vNumeroJugada == 2)
                {
                    vLetra = 'b';
                }
                if (vNumeroJugada == 3)
                {
                    vLetra = 'c';
                }
                if (vNumeroJugada == 4)
                {
                    vLetra = 'd';
                }
                if (vNumeroJugada == 5)
                {
                    vLetra = 'e';
                }
                if (vNumeroJugada == 6)
                {
                    vLetra = 'f';
                }
                if (vNumeroJugada == 7)
                {
                    vLetra = 'g';
                }
                if (vNumeroJugada == 8)
                {
                    vLetra = 'h';
                }
                if (vNumeroJugada == 9)
                {
                    vLetra = 'i';
                }
                banderaJugada = fnVerificarJugada(vLetra);
            } while (banderaJugada == 0);
            if (banderaJugada == 1)
            {
                banderaGanador = fnVerificarGanador();
                numeroDeTurnos++;
            }
        }
        else if ((turno % 2 == 0 && jugadorInicial == nombreJugador1) || (turno % 2 != 0 && jugadorSecundario == nombreJugador1))
        {
            banderaJugada = fnVerificarJugada(fnPosiblesJugadas());
            if (banderaJugada == 1)
            {
                banderaGanador = fnVerificarGanador();
                numeroDeTurnos++;
            }
        }
        cout << endl;
        system("cls");
        construirTablero();
        if (banderaGanador == 1)
        {
            fnIdentificarGanador(numeroDeTurnos - 1);
        }
        else
        {
            cout << "EL JUEGO TERMINO EN UN EMPATE..." << endl;
        }
    }
}

int main()
{
    int opcion = fnMenu();
    switch (opcion)
    {
    case 1:
        do
        {
            fnJugadorContraJugador();
            cout << "Desea volver a jugar? s/n = ";
            cin >> repetirPartida;
            system("cls");
            contadorPartidas++;
        } while (repetirPartida == 's');
        cout << "FIN DEL JUEGO :P" << endl;
        break;
    case 2:
        do{ 
        fnJugadorContraComputadora();
        cout << "Desea volver a jugar? s/n = ";
            cin >> repetirPartida;
            system("cls");
            contadorPartidas++;
        } while (repetirPartida == 's');
        cout << "FIN DEL JUEGO :P" << endl;
        break;
    case 3:
        break;
    default:
        cout << "Porfavor, ingrese una opcion correcta..." << endl;
    }
    return 0;
}