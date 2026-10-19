#include "CSeccion.h"
#include <iostream>

using namespace std;

CSeccion::CSeccion() {
    this->m_Curso = nullptr;
    this->m_Profesor = nullptr;
    this->m_Laboratorio = nullptr;
    this->m_Dia = 0;
    this->m_HoraInicio = 0;
    this->m_HoraFin = 0;
    this->m_NumeroMatriculados = 0;
}

CSeccion::CSeccion(CCurso* pCurso, CProfesor* pProfesor, CLaboratorio* pLaboratorio,
                   TipoEntero pDia, TipoEntero pHoraInicio, TipoEntero pHoraFin) {
    this->m_Curso = pCurso;
    this->m_Profesor = pProfesor;
    this->m_Laboratorio = pLaboratorio;
    this->m_Dia = pDia;
    this->m_HoraInicio = pHoraInicio;
    this->m_HoraFin = pHoraFin;
    this->m_NumeroMatriculados = 0;
}

// La seccion no libera a los alumnos: estan agregados, existen fuera de ella.
// El curso, el profesor y el laboratorio los libera quien los creo.
CSeccion::~CSeccion() {
    cout << "Eliminandose la seccion" << endl;
}

void CSeccion::asignarCurso(CCurso* pCurso)              { this->m_Curso = pCurso; }
void CSeccion::asignarProfesor(CProfesor* pProfesor)     { this->m_Profesor = pProfesor; }
void CSeccion::asignarLaboratorio(CLaboratorio* pLab)    { this->m_Laboratorio = pLab; }

void CSeccion::asignarHorario(TipoEntero pDia, TipoEntero pHoraInicio, TipoEntero pHoraFin) {
    this->m_Dia = pDia;
    this->m_HoraInicio = pHoraInicio;
    this->m_HoraFin = pHoraFin;
}

// Se respeta el tope de 25 alumnos y tampoco se permite repetir el codigo.
bool CSeccion::matricularAlumno(CAlumno* pAlumno) {
    if (pAlumno == nullptr) return false;
    if (m_NumeroMatriculados >= MAX_ALUMNOS) {
        cout << "No hay vacantes: la seccion ya tiene " << MAX_ALUMNOS << " alumnos" << endl;
        return false;
    }
    if (buscarAlumno(pAlumno->getCodigo()) != nullptr) {
        cout << "El alumno " << pAlumno->getCodigo() << " ya esta matriculado" << endl;
        return false;
    }
    m_ListaAlumno.push_back(pAlumno);
    m_NumeroMatriculados = (TipoEntero)m_ListaAlumno.size();
    return true;
}

CAlumno* CSeccion::buscarAlumno(TipoString pCodigo) {
    for (int i = 0; i < (int)m_ListaAlumno.size(); ++i) {
        if (m_ListaAlumno[i]->getCodigo() == pCodigo) {
            return m_ListaAlumno[i];
        }
    }
    return nullptr;
}

TipoEntero CSeccion::getNumeroMatriculados() { return m_NumeroMatriculados; }

TipoString CSeccion::getNombreDia() {
    switch (m_Dia) {
        case 1: return "Lunes";
        case 2: return "Martes";
        case 3: return "Miercoles";
        case 4: return "Jueves";
        case 5: return "Viernes";
        case 6: return "Sabado";
        default: return "Sin asignar";
    }
}

void CSeccion::imprimir() {
    cout << "Datos de la seccion" << endl;

    if (m_Curso != nullptr)        m_Curso->imprimir();
    if (m_Profesor != nullptr)     m_Profesor->imprimir();
    if (m_Laboratorio != nullptr)  m_Laboratorio->imprimir();

    cout << "Dia : " << getNombreDia() << endl;
    cout << "Hora inicio: " << m_HoraInicio << ":00" << endl;
    cout << "Hora fin : " << m_HoraFin << ":00" << endl;

    for (int i = 0; i < (int)m_ListaAlumno.size(); ++i) {
        cout << "Alumnos matriculados" << endl;
        m_ListaAlumno[i]->imprimir();
    }
}
