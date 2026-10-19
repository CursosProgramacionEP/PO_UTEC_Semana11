#include "CProfesor.h"
#include <iostream>

using namespace std;

CProfesor::CProfesor() {
    this->m_Codigo = "";
}

CProfesor::CProfesor(TipoString pCodigo, TipoString pNombres,
                     TipoString pApePaterno, TipoString pApeMaterno,
                     TipoString pCuentaCorreo) {
    this->m_Codigo = pCodigo;
    this->m_Nombres = pNombres;
    this->m_ApePaterno = pApePaterno;
    this->m_ApeMaterno = pApeMaterno;
    this->m_CuentaCorreo = pCuentaCorreo;
}

CProfesor::~CProfesor() {
}

TipoString CProfesor::getCodigo()  { return m_Codigo; }
TipoString CProfesor::getNombres() { return m_Nombres; }

void CProfesor::imprimir() {
    cout << "Datos del Profesor" << endl;
    cout << "Codigo  : " << m_Codigo << endl;
    cout << "Nombres : " << m_Nombres << endl;
    cout << "Apellido Paterno : " << m_ApePaterno << endl;
    cout << "Apellido Materno : " << m_ApeMaterno << endl;
    cout << "Correo: " << m_CuentaCorreo << endl;
}
