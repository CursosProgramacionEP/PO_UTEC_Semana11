#include "CProfesor.h"
#include <iostream>

using namespace std;

CProfesor::CProfesor() {
    this->m_Codigo = "";
}

CProfesor::CProfesor(const TipoString& pCodigo, const TipoString& pNombres, const TipoString& pApePaterno, const TipoString& pApeMaterno, const TipoString& pCuentaCorreo) {
    this->m_Codigo = pCodigo;
    this->m_Nombres = pNombres;
    this->m_ApePaterno = pApePaterno;
    this->m_ApeMaterno = pApeMaterno;
    this->m_CuentaCorreo = pCuentaCorreo;
}

CProfesor::~CProfesor() {
}

TipoString CProfesor::getCodigo() const { return m_Codigo; }
TipoString CProfesor::getNombres() const { return m_Nombres; }

void CProfesor::imprimir() const {
    cout << "Datos del Profesor" << endl;
    cout << "Codigo  : " << m_Codigo << endl;
    cout << "Nombres : " << m_Nombres << endl;
    cout << "Apellido Paterno : " << m_ApePaterno << endl;
    cout << "Apellido Materno : " << m_ApeMaterno << endl;
    cout << "Correo: " << m_CuentaCorreo << endl;
}
