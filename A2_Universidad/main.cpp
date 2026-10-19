#include <iostream>
#include "Universidad.h"
#include "Alumno.h"
#include "Curso.h"

using namespace std;

int main() {
    // Los objetos se crean aqui: el main es el dueno de la memoria.
    Curso* poo   = new Curso("Programacion II", "CS1112");
    Curso* calc  = new Curso("Calculo I", "MA1001");
    Curso* fisica= new Curso("Fisica I", "FI1001");

    Alumno* ana  = new Alumno("Ana Torres", "A2026001");
    Alumno* luis = new Alumno("Luis Costa", "A2026002");

    Universidad utec("UTEC");

    // La universidad agrega alumnos y cursos
    utec.agregar_alumno(ana);
    utec.agregar_alumno(luis);
    utec.agregar_clase(poo);
    utec.agregar_clase(calc);
    utec.agregar_clase(fisica);

    // El alumno agrega los cursos en los que se matricula
    ana->agregar_clase(poo);
    ana->agregar_clase(calc);
    luis->agregar_clase(poo);
    luis->agregar_clase(fisica);

    utec.imprimir_alumno();
    cout << endl;
    utec.imprimir_clase();
    cout << endl;
    ana->imprimir_clase();
    cout << endl;
    luis->imprimir_clase();

    cout << "\n--- Fin del programa ---" << endl;
    // Un mismo curso esta en varias listas, pero se libera una sola vez.
    delete ana;
    delete luis;
    delete poo;
    delete calc;
    delete fisica;

    return 0;
}
