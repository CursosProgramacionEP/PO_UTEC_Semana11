#include "CCurso.h"
#include <iostream>

using namespace std;

CCurso::CCurso() {
    this->m_Codigo = "";
    this->m_Ciclo = 0;
    this->m_Creditos = 0;
}

CCurso::CCurso(const TipoString& pCodigo, const TipoString& pNombre, const TipoString& pPreRequisito, TipoEntero pCiclo,
               TipoEntero pCreditos) {
    this->m_Codigo = pCodigo;
    this->m_Nombre = pNombre;
    this->m_PreRequisito = pPreRequisito;
    this->m_Ciclo = pCiclo;
    this->m_Creditos = pCreditos;
}

CCurso::~CCurso() {
}

TipoString CCurso::getCodigo() const { return m_Codigo; }
TipoString CCurso::getNombre() const { return m_Nombre; }
TipoEntero CCurso::getCreditos() const { return m_Creditos; }

void CCurso::imprimir() const {
    cout << "Datos del Curso" << endl;
    cout << "Codigo : " << m_Codigo << endl;
    cout << "Nombre : " << m_Nombre << endl;
    cout << "Prerequisito : " << m_PreRequisito << endl;
    cout << "Ciclo : " << m_Ciclo << endl;
    cout << "creditos : " << m_Creditos << endl;
}
