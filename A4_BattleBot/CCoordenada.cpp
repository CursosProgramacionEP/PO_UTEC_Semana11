#include "CCoordenada.h"

using namespace std;

CCoordenada::CCoordenada() {
    this->m_PosX = 0;
    this->m_PosY = 0;
}

// El valor de la posicion se establece por el constructor,
// tal como pide el enunciado del ejercicio 4.b.
CCoordenada::CCoordenada(TipoEntero pPosX, TipoEntero pPosY) {
    this->m_PosX = pPosX;
    this->m_PosY = pPosY;
}

CCoordenada::~CCoordenada() {
}

void CCoordenada::setPosX(TipoEntero pPosX) { this->m_PosX = pPosX; }
void CCoordenada::setPosY(TipoEntero pPosY) { this->m_PosY = pPosY; }
TipoEntero CCoordenada::getPosX() const { return m_PosX; }
TipoEntero CCoordenada::getPosY() const { return m_PosY; }
