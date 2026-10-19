#include <iostream>
#include "CBattleBox.h"
#include "CRobot.h"
#include "CObstaculo.h"

using namespace std;

int main() {
    CBattleBox tablero(8, 12);

    // Los robots se crean en el main: el tablero solo los agrega.
    CRobot* alfa = new CRobot("Alfa", 'A', 1, 1, 5, 40);   // pesado: hace 2 de averia
    CRobot* beta = new CRobot("Beta", 'B', 6, 4, 5, 28);   // liviano: hace 1 de averia

    CObstaculo* muro = new CObstaculo("Muro", '#', 3, 2, 1);

    tablero.adicionarRobot(alfa);
    tablero.adicionarRobot(beta);
    tablero.adicionarObstaculo(muro);

    cout << "--- Tablero inicial ---" << endl;
    tablero.dibujarBattleBox();
    cout << endl;
    tablero.imprimirRobots();

    cout << "\n--- Alfa se mueve y golpea a Beta ---" << endl;
    alfa->moverse(5, 4);
    alfa->golpear(*beta);

    cout << "\n--- Beta responde el golpe ---" << endl;
    beta->golpear(*alfa);

    cout << "\n--- Beta choca con el muro ---" << endl;
    beta->Chocar(*muro);

    cout << "\n--- Tablero actualizado ---" << endl;
    tablero.dibujarBattleBox();
    cout << endl;
    tablero.imprimirRobots();

    cout << "\nObjetos en el tablero: " << tablero.getCantidadObjetos() << endl;

    cout << "\n--- Beta se retira del tablero ---" << endl;
    CRobot* retirado = tablero.removerRobot("Beta");
    if (retirado != nullptr) {
        cout << "Se retiro a " << retirado->getNombre() << endl;
    }
    tablero.imprimirRobots();

    cout << "\n--- Fin del programa ---" << endl;
    delete alfa;
    delete beta;
    delete muro;

    return 0;
}
