#include "CLaboratorio.h"
#include <iostream>

using namespace std;

CLaboratorio::CLaboratorio() {
    this->m_Codigo = "";
    this->m_NroPiso = 0;
    this->m_NroComputadoras = 0;
}

CLaboratorio::CLaboratorio(TipoString pCodigo, TipoEntero pNroPiso,
                           TipoEntero pNroComputadoras) {
    this->m_Codigo = pCodigo;
    this->m_NroPiso = pNroPiso;
    this->m_NroComputadoras = pNroComputadoras;
}

CLaboratorio::~CLaboratorio() {
}

TipoString CLaboratorio::getCodigo() { return m_Codigo; }
TipoEntero CLaboratorio::getNroComputadoras() { return m_NroComputadoras; }

void CLaboratorio::imprimir() {
    cout << "Datos del Laboratorio" << endl;
    cout << "Codigo : " << m_Codigo << endl;
    cout << "Numero Piso: " << m_NroPiso << endl;
    cout << "Numero Computadoras: " << m_NroComputadoras << endl;
}
