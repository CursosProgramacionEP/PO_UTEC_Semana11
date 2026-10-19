#include <iostream>
#include "CSeccion.h"
#include "CCurso.h"
#include "CProfesor.h"
#include "CLaboratorio.h"
#include "CAlumno.h"

using namespace std;

int main() {
    // Todos los objetos se crean aqui: el main es el dueno de la memoria.
    CCurso*       poo = new CCurso("CS1002", "Programacion orientada a objetos",
                                   "CS1001", 2, 4);
    CProfesor*    teofilo = new CProfesor("P2017001", "Teofilo", "CHambilla",
                                          "AQuino", "teofilo@utec.edu.pe");
    CLaboratorio* lab = new CLaboratorio("L604", 6, 25);

    CAlumno* jorge = new CAlumno("A2017001", "Jorge", "Perez", "Perez",
                                 "jorge@utec.edu.pe", 17, 30);
    CAlumno* luis  = new CAlumno("A2017002", "Luis", "Costa", "Pinan",
                                 "luis@utec.edu.pe", 17, 15);

    // Dia 1 = Lunes, de 08:00 a 10:00
    CSeccion seccion(poo, teofilo, lab, 1, 8, 10);

    seccion.matricularAlumno(jorge);
    seccion.matricularAlumno(luis);

    seccion.imprimir();

    cout << "\nMatriculados: " << seccion.getNumeroMatriculados()
         << " de " << CSeccion::MAX_ALUMNOS << endl;

    cout << "\n--- Se intenta matricular dos veces al mismo alumno ---" << endl;
    seccion.matricularAlumno(jorge);

    cout << "\n--- Fin del programa ---" << endl;
    delete jorge;
    delete luis;
    delete poo;
    delete teofilo;
    delete lab;

    return 0;
}
