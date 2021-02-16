//
// Created by alvaro on 2/4/21.
//

#ifndef UNTITLED_CLASSIFICADORTRIANGULO_H
#define UNTITLED_CLASSIFICADORTRIANGULO_H
#include <cmath>
#include <exception>
#include "../exceptions/TrianguloInvalidoException.h"
#include "../interfaces/ITestaTriangulo.h"
#include "../utils/TiposDeTriangulo.h"

using namespace std;

class ClassificadorTriangulo {
private:
    float x, y, z;
    ITestaTriangulo* teste;
public:  ClassificadorTriangulo (float x, float  y, float z){

        this->x = x;
        this->y = y;
        this->z = z;

    }


public: void setTeste(ITestaTriangulo *teste ){
        this->teste = teste;
    }


private:
    bool testeEquilatero() const{
        return (this->z == this->y) && (this->z == this->x) && (this->y == this->x);
    }

    bool testeIsoceles() const{
        return (this->z == this->y && this->x != this->z) || (this->z == this->x && this->y != this->z) || (this->y == this->x && this->y != this->z);
    }

    bool testeEscaleno() const{
        return (this->z != this->y) && (this->z != this->x) && (this->y != this->x);
    }

    bool testeRetangulo() const{
        float valores[] = {this->x, this->y, this->z};
        float hipotenusa = valores[0];
        float catetos[2];
        for(float valor : valores){
            if(hipotenusa < valor){
                hipotenusa = valor;
            }
        }
        int posicao = 0;
        for(float valor : valores){
            if(hipotenusa != valor){
                catetos[posicao] = valor;
                posicao++;
            }
        }

        return (catetos[0]*catetos[0])+(catetos[1]*catetos[1]) ==( hipotenusa*hipotenusa);
    }


public:
    const char* getTipo(){
        if(this->teste == NULL)
            throw(TrianguloInvalidoException("Teste não injetado"));
        if(!this->teste->testa_lado_triangulo(x,y,z) || !this->teste->testa_lado_triangulo(y,x,z) || !this->teste->testa_lado_triangulo(z,x,y))
            throw(TrianguloInvalidoException("Triangulo Inválido"));

        if(testeEquilatero()){
            return TiposDeTrianguloString(TiposDeTriangulo(EQUILATERO));
        }
        if(testeIsoceles()){
            return TiposDeTrianguloString(TiposDeTriangulo(ISOCELES));
        }
        if(testeRetangulo()){
            return TiposDeTrianguloString(TiposDeTriangulo(RETANGULO));
        }
        if(testeEscaleno()){
            return TiposDeTrianguloString(TiposDeTriangulo(ESCALENO));
        }
        return  TiposDeTrianguloString(TiposDeTriangulo(INDEFINIDO));
    }

    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }

    float getZ() const {
        return z;
    }

    void setAllValues(float x, float y, float z){
        this->x =x;
        this->y = y;
        this->z =z;
    }

    void setX(float x) {
        ClassificadorTriangulo::x = x;
    }

    void setY(float y) {
        ClassificadorTriangulo::y = y;

    }

    void setZ(float z) {
        ClassificadorTriangulo::z = z;

    }
};


#endif //UNTITLED_CLASSIFICADORTRIANGULO_H
