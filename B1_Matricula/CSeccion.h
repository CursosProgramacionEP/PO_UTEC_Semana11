#ifndef CSECCION_H
#define CSECCION_H

#include <vector>
#include "Tipos.h"
#include "CCurso.h"
#include "CProfesor.h"
#include "CLaboratorio.h"
#include "CAlumno.h"

class CSeccion {
private:
    CCurso*          m_Curso;         // una seccion tiene asignado un curso
    CProfesor*       m_Profesor;      // el profesor es parte de la seccion
    CLaboratorio*    m_Laboratorio;   // la seccion tiene asignado un laboratorio
    std::vector<CAlumno*> m_ListaAlumno;   // a lo mas 25 alumnos registrados
    TipoEntero       m_Dia;
    TipoEntero       m_HoraInicio;
    TipoEntero       m_HoraFin;
    TipoEntero       m_NumeroMatriculados;

public:
    static const TipoEntero MAX_ALUMNOS = 25;

    CSeccion();
    CSeccion(CCurso* pCurso, CProfesor* pProfesor, CLaboratorio* pLaboratorio,
             TipoEntero pDia, TipoEntero pHoraInicio, TipoEntero pHoraFin);
    ~CSeccion();

    void asignarCurso(CCurso* pCurso);
    void asignarProfesor(CProfesor* pProfesor);
    void asignarLaboratorio(CLaboratorio* pLaboratorio);
    void asignarHorario(TipoEntero pDia, TipoEntero pHoraInicio, TipoEntero pHoraFin);

    bool       matricularAlumno(CAlumno* pAlumno);
    CAlumno*   buscarAlumno(const TipoString& pCodigo) const;
    TipoEntero getNumeroMatriculados() const;
    TipoString getNombreDia() const;

    void imprimir() const;
};

#endif
