#include "CBattleBox.h"
#include <iostream>

using namespace std;

CBattleBox::CBattleBox() {
    this->m_Altura = 10;
    this->m_Ancho = 10;
    this->m_CantRobots = 0;
    this->m_CantObstaculos = 0;
    m_Plano.assign(m_Altura, vector<TipoCaracter>(m_Ancho, '.'));
}

CBattleBox::CBattleBox(TipoEntero pAltura, TipoEntero pAncho) {
    this->m_Altura = pAltura;
    this->m_Ancho = pAncho;
    this->m_CantRobots = 0;
    this->m_CantObstaculos = 0;
    m_Plano.assign(m_Altura, vector<TipoCaracter>(m_Ancho, '.'));
}

// Agregacion: el tablero no destruye a los robots ni a los obstaculos,
// solo deja de apuntarlos. Los libera quien los creo.
CBattleBox::~CBattleBox() {
    cout << "Eliminandose el BattleBox" << endl;
}

void CBattleBox::adicionarRobot(CRobot* pRobot) {
    m_Robots.push_back(pRobot);
    m_CantRobots = (TipoEntero)m_Robots.size();
}

void CBattleBox::adicionarObstaculo(CObstaculo* pObstaculo) {
    m_Obstaculos.push_back(pObstaculo);
    m_CantObstaculos = (TipoEntero)m_Obstaculos.size();
}

// Saca el robot del tablero y devuelve su puntero para que
// el main decida que hacer con el. No se hace delete aqui.
CRobot* CBattleBox::removerRobot(TipoString pNombre) {
    for (int i = 0; i < (int)m_Robots.size(); ++i) {
        if (m_Robots[i]->getNombre() == pNombre) {
            CRobot* encontrado = m_Robots[i];
            m_Robots.erase(m_Robots.begin() + i);
            m_CantRobots = (TipoEntero)m_Robots.size();
            return encontrado;
        }
    }
    return nullptr;
}

CRobot* CBattleBox::buscarRobot(TipoString nombre) {
    for (int i = 0; i < (int)m_Robots.size(); ++i) {
        if (m_Robots[i]->getNombre() == nombre) {
            return m_Robots[i];
        }
    }
    return nullptr;
}

void CBattleBox::imprimirRobots() {
    cout << "Robots en el BattleBox (" << m_CantRobots << "):" << endl;
    for (int i = 0; i < (int)m_Robots.size(); ++i) {
        cout << "  " << m_Robots[i]->getColor() << " "
             << m_Robots[i]->getNombre()
             << " en " << m_Robots[i]->mostrarPosicion()
             << " | vidas: " << m_Robots[i]->getVidas()
             << " | peso: " << m_Robots[i]->getPeso() << endl;
    }
}

TipoEntero CBattleBox::getAltura() { return m_Altura; }
TipoEntero CBattleBox::getAncho()  { return m_Ancho; }

TipoEntero CBattleBox::getCantidadObjetos() {
    return m_CantRobots + m_CantObstaculos;
}

// Vuelca las posiciones actuales de robots y obstaculos sobre el plano.
void CBattleBox::actualizarBattleBox() {
    m_Plano.assign(m_Altura, vector<TipoCaracter>(m_Ancho, '.'));

    for (int i = 0; i < (int)m_Obstaculos.size(); ++i) {
        TipoEntero x = m_Obstaculos[i]->getPosX();
        TipoEntero y = m_Obstaculos[i]->getPosY();
        if (x >= 0 && x < m_Ancho && y >= 0 && y < m_Altura) {
            m_Plano[y][x] = m_Obstaculos[i]->getSimbolo();
        }
    }

    for (int i = 0; i < (int)m_Robots.size(); ++i) {
        TipoEntero x = m_Robots[i]->getPosX();
        TipoEntero y = m_Robots[i]->getPosY();
        if (x >= 0 && x < m_Ancho && y >= 0 && y < m_Altura) {
            m_Plano[y][x] = m_Robots[i]->getColor();
        }
    }
}

void CBattleBox::dibujarBattleBox() {
    actualizarBattleBox();
    for (int i = 0; i < m_Altura; ++i) {
        for (int j = 0; j < m_Ancho; ++j) {
            cout << m_Plano[i][j] << ' ';
        }
        cout << endl;
    }
}
