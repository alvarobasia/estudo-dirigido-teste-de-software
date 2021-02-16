//
// Created by alvaro on 2/5/21.
//

#ifndef UNTITLED_TIPOSDETRIANGULO_H
#define UNTITLED_TIPOSDETRIANGULO_H


enum TiposDeTriangulo {
    RETANGULO = 1,
    EQUILATERO = 2,
    ISOCELES = 3,
    ESCALENO = 4,
    INDEFINIDO = 5
};

inline const char* TiposDeTrianguloString(TiposDeTriangulo t)
{
    switch (t)
    {
        case RETANGULO:   return "RETANGULO";
        case EQUILATERO:   return "EQUILATERO";
        case ISOCELES: return "ISOCELES";
        case ESCALENO: return "ESCALENO";
        default:      return "INDEFINIDO";
    }
}

#endif //UNTITLED_TIPOSDETRIANGULO_H
