#ifndef CBATTLEBOX_H
#define CBATTLEBOX_H

#include <vector>
#include "Tipos.h"
#include "CRobot.h"
#include "CObstaculo.h"

using namespace std;

class CBattleBox {
private:
    TipoEntero m_Altura;
    TipoEntero m_Ancho;
    TipoEntero m_CantRobots;
    TipoEntero m_CantObstaculos;
    vector<vector<TipoCaracter>> m_Plano;
    vector<CRobot*>     m_Robots;       // agregacion
    vector<CObstaculo*> m_Obstaculos;   // agregacion

public:
    CBattleBox();
    CBattleBox(TipoEntero pAltura, TipoEntero pAncho);
    virtual ~CBattleBox();

    void       adicionarRobot(CRobot* pRobot);
    void       adicionarObstaculo(CObstaculo* pObstaculo);
    CRobot*    removerRobot(TipoString pNombre);
    CRobot*    buscarRobot(TipoString nombre);
    void       imprimirRobots();
    TipoEntero getAltura();
    TipoEntero getAncho();
    TipoEntero getCantidadObjetos();
    void       dibujarBattleBox();
    void       actualizarBattleBox();
};

#endif
