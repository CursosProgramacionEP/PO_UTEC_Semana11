#include <iostream>
#include <vector>
#include "Documento.h"
#include "Capitulo.h"

using namespace std;

int main() {
    // Los capitulos se preparan y se entregan al documento por valor.
    vector<Capitulo> capitulos;
    capitulos.push_back(Capitulo(1, "Introduccion a las relaciones"));
    capitulos.push_back(Capitulo(2, "Asociacion"));
    capitulos.push_back(Capitulo(3, "Composicion"));

    Documento doc("Relaciones entre clases", capitulos);
    doc.agregar_capitulo(Capitulo(4, "Agregacion"));

    doc.imprimir();
    cout << "\nTotal de capitulos: " << doc.cantidad_capitulos() << endl;

    cout << "\n--- Fin del programa ---" << endl;
    return 0;
}
