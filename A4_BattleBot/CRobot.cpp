#include "CRobot.h"
#include <iostream>

using namespace std;

CRobot::CRobot() {
    this->m_Nombre = "sin nombre";
    this->m_Color = 'R';
    this->m_Vidas = 3;
    this->m_Peso = 30;
}

// La coordenada se construye en la lista de inicializacion:
// nace junto con el robot y muere con el.
CRobot::CRobot(TipoString pNombre, TipoCaracter pColor,
               TipoEntero pPosX, TipoEntero pPosY)
    : m_Coordenada(pPosX, pPosY) {
    this->m_Nombre = pNombre;
    this->m_Color = pColor;
    this->m_Vidas = 3;
    this->m_Peso = 30;
}

CRobot::CRobot(TipoString pNombre, TipoCaracter pColor,
               TipoEntero pPosX, TipoEntero pPosY,
               TipoEntero pVidas, TipoEntero pPeso)
    : m_Coordenada(pPosX, pPosY) {
    this->m_Nombre = pNombre;
    this->m_Color = pColor;
    this->m_Vidas = pVidas;
    this->m_Peso = pPeso;
}

CRobot::~CRobot() {
    cout << "Eliminandose el robot " << m_Nombre << endl;
}

void CRobot::setNombre(TipoString pNombre) { this->m_Nombre = pNombre; }
void CRobot::setVidas(TipoEntero pVidas)   { this->m_Vidas = pVidas; }

void CRobot::moverse(TipoEntero pPosX, TipoEntero pPosY) {
    m_Coordenada.setPosX(pPosX);
    m_Coordenada.setPosY(pPosY);
}

// Un robot pesado hace mas averia que uno liviano.
void CRobot::golpear(CRobot &pEnemigo) {
    TipoEntero averia = (m_Peso >= 35) ? 2 : 1;
    pEnemigo.setVidas(pEnemigo.getVidas() - averia);
    cout << m_Nombre << " golpea a " << pEnemigo.getNombre()
         << " (-" << averia << " vidas, quedan "
         << pEnemigo.getVidas() << ")" << endl;
}

void CRobot::Chocar(CObstaculo &pObstaculo) {
    m_Vidas = m_Vidas - pObstaculo.getDureza();
    cout << m_Nombre << " choca contra " << pObstaculo.getNombre()
         << " (-" << pObstaculo.getDureza() << " vidas, quedan "
         << m_Vidas << ")" << endl;
}

TipoString   CRobot::getNombre() { return m_Nombre; }
TipoEntero   CRobot::getPosX()   { return m_Coordenada.getPosX(); }
TipoEntero   CRobot::getPosY()   { return m_Coordenada.getPosY(); }
TipoCaracter CRobot::getColor()  { return m_Color; }
TipoEntero   CRobot::getVidas()  { return m_Vidas; }
TipoEntero   CRobot::getPeso()   { return m_Peso; }

TipoString CRobot::mostrarPosicion() {
    return "(" + to_string(getPosX()) + ", " + to_string(getPosY()) + ")";
}
