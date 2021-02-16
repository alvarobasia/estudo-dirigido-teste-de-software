//
// Created by alvaro on 2/5/21.
//

#ifndef UNTITLED_TESTATRIANGULO_H
#define UNTITLED_TESTATRIANGULO_H
#include "../interfaces/ITestaTriangulo.h"
#include <cmath>

using namespace std;

class TestaTriangulo: public ITestaTriangulo {
public:
    bool testa_lado_triangulo(float ladoTestado, float primeiroLado, float segundoLado) {
        bool primeira_condicao = (abs(primeiroLado - segundoLado) ) < ladoTestado;
        bool segunda_condicao = (primeiroLado + segundoLado) > ladoTestado;
        if(primeira_condicao &&  segunda_condicao){
            return true;
        }
        return false;
    }
};


#endif //UNTITLED_TESTATRIANGULO_H
