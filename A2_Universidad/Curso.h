#ifndef CURSO_H
#define CURSO_H

#include <string>

class Curso {
private:
    std::string nombre;
    std::string codigo;

public:
    Curso();
    Curso(const std::string& nombre, const std::string& codigo);
    ~Curso();

    void set_nombre(const std::string& nombre);
    void set_codigo(const std::string& codigo);
    std::string get_nombre() const;
    std::string get_codigo() const;

    void imprimir() const;
};

#endif
