#include "CCurso.h"
#include <iostream>

using namespace std;

CCurso::CCurso() {
    this->m_Codigo = "";
    this->m_Ciclo = 0;
    this->m_Creditos = 0;
}

CCurso::CCurso(TipoString pCodigo, TipoString pNombre,
               TipoString pPreRequisito, TipoEntero pCiclo,
               TipoEntero pCreditos) {
    this->m_Codigo = pCodigo;
    this->m_Nombre = pNombre;
    this->m_PreRequisito = pPreRequisito;
    this->m_Ciclo = pCiclo;
    this->m_Creditos = pCreditos;
}

CCurso::~CCurso() {
}

TipoString CCurso::getCodigo()   { return m_Codigo; }
TipoString CCurso::getNombre()   { return m_Nombre; }
TipoEntero CCurso::getCreditos() { return m_Creditos; }

void CCurso::imprimir() {
    cout << "Datos del Curso" << endl;
    cout << "Codigo : " << m_Codigo << endl;
    cout << "Nombre : " << m_Nombre << endl;
    cout << "Prerequisito : " << m_PreRequisito << endl;
    cout << "Ciclo : " << m_Ciclo << endl;
    cout << "creditos : " << m_Creditos << endl;
}
