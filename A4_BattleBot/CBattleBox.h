#ifndef CBATTLEBOX_H
#define CBATTLEBOX_H

#include <vector>
#include "Tipos.h"
#include "CRobot.h"
#include "CObstaculo.h"

class CBattleBox {
private:
    TipoEntero m_Altura;
    TipoEntero m_Ancho;
    TipoEntero m_CantRobots;
    TipoEntero m_CantObstaculos;
    std::vector<std::vector<TipoCaracter>> m_Plano;
    std::vector<CRobot*>     m_Robots;       // agregacion
    std::vector<CObstaculo*> m_Obstaculos;   // agregacion

public:
    CBattleBox();
    CBattleBox(TipoEntero pAltura, TipoEntero pAncho);
    virtual ~CBattleBox();

    void       adicionarRobot(CRobot* pRobot);
    void       adicionarObstaculo(CObstaculo* pObstaculo);
    CRobot*    removerRobot(const TipoString& pNombre);
    CRobot*    buscarRobot(const TipoString& nombre) const;
    void       imprimirRobots() const;
    TipoEntero getAltura() const;
    TipoEntero getAncho() const;
    TipoEntero getCantidadObjetos() const;
    void       dibujarBattleBox();
    void       actualizarBattleBox();
};

#endif
