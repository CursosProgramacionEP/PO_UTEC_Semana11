#include "CAlumno.h"
#include <iostream>

using namespace std;

CAlumno::CAlumno() {
    this->m_Codigo = "";
    this->m_Edad = 0;
    this->m_CreditosAcumulados = 0;
}

CAlumno::CAlumno(const TipoString& pCodigo, const TipoString& pNombres, const TipoString& pApePaterno, const TipoString& pApeMaterno, const TipoString& pCuentaCorreo, TipoEntero pEdad,
                 TipoEntero pCreditosAcumulados) {
    this->m_Codigo = pCodigo;
    this->m_Nombres = pNombres;
    this->m_ApePaterno = pApePaterno;
    this->m_ApeMaterno = pApeMaterno;
    this->m_CuentaCorreo = pCuentaCorreo;
    this->m_Edad = pEdad;
    this->m_CreditosAcumulados = pCreditosAcumulados;
}

CAlumno::~CAlumno() {
}

TipoString CAlumno::getCodigo() const { return m_Codigo; }
TipoString CAlumno::getNombres() const { return m_Nombres; }
TipoEntero CAlumno::getCreditosAcumulados() const { return m_CreditosAcumulados; }

void CAlumno::imprimir() const {
    cout << " Datos del Alumno" << endl;
    cout << " Codigo  : " << m_Codigo << endl;
    cout << " Nombres : " << m_Nombres << endl;
    cout << " Apellido Paterno : " << m_ApePaterno << endl;
    cout << " Apellido Materno : " << m_ApeMaterno << endl;
    cout << " Edad: " << m_Edad << endl;
    cout << " Correo: " << m_CuentaCorreo << endl;
    cout << " Creditos Acumulados : " << m_CreditosAcumulados << endl;
}
