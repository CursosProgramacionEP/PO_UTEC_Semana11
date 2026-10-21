#include "CLaboratorio.h"
#include <iostream>

using namespace std;

CLaboratorio::CLaboratorio() {
    this->m_Codigo = "";
    this->m_NroPiso = 0;
    this->m_NroComputadoras = 0;
}

CLaboratorio::CLaboratorio(const TipoString& pCodigo, TipoEntero pNroPiso,
                           TipoEntero pNroComputadoras) {
    this->m_Codigo = pCodigo;
    this->m_NroPiso = pNroPiso;
    this->m_NroComputadoras = pNroComputadoras;
}

CLaboratorio::~CLaboratorio() {
}

TipoString CLaboratorio::getCodigo() const { return m_Codigo; }
TipoEntero CLaboratorio::getNroComputadoras() const { return m_NroComputadoras; }

void CLaboratorio::imprimir() const {
    cout << "Datos del Laboratorio" << endl;
    cout << "Codigo : " << m_Codigo << endl;
    cout << "Numero Piso: " << m_NroPiso << endl;
    cout << "Numero Computadoras: " << m_NroComputadoras << endl;
}
