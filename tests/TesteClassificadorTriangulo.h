//
// Created by alvaro on 2/7/21.
//

#ifndef TRIANGULO_TRIANGULOTESTS_H
#define TRIANGULO_TRIANGULOTESTS_H

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include "../domain/ClassificadorTriangulo.h"
#include "../utils/TestaTriangulo.h"


class TesteClassificadorTriangulo : public CppUnit::TestFixture  {

private:
    ClassificadorTriangulo * triangulo;
public:
    void setUp() override
    {

    }

    void tearDown() override
    {
        delete triangulo;
    }


    void testeTrianguloEquilatero()
    {

        TestaTriangulo testaTriangulo;
        triangulo = (new ClassificadorTriangulo(5,5,5));
        triangulo->setTeste(&testaTriangulo);
        CPPUNIT_ASSERT(triangulo->getTipo() == "EQUILATERO" );
        triangulo->setAllValues(598,598,598);
        CPPUNIT_ASSERT(triangulo->getTipo() == "EQUILATERO" );
        triangulo->setAllValues(1,1,1);
        CPPUNIT_ASSERT(triangulo->getTipo() == "EQUILATERO" );
        triangulo->setAllValues(25,25,25);
        CPPUNIT_ASSERT(triangulo->getTipo() == "EQUILATERO" );
        triangulo->setAllValues(9,9,9);
        CPPUNIT_ASSERT(triangulo->getTipo() == "EQUILATERO" );
    }

    void testeTrianguloEscaleno()
    {
        TestaTriangulo testaTriangulo;
        triangulo = (new ClassificadorTriangulo(5,7,8));
        triangulo->setTeste(&testaTriangulo);
        CPPUNIT_ASSERT(triangulo->getTipo() == "ESCALENO" );
        triangulo->setAllValues(968,965,699);
        CPPUNIT_ASSERT(triangulo->getTipo() == "ESCALENO" );
        triangulo->setAllValues(2,4,3);
        CPPUNIT_ASSERT(triangulo->getTipo() == "ESCALENO" );
        triangulo->setAllValues(25,24,19);
        CPPUNIT_ASSERT(triangulo->getTipo() == "ESCALENO" );
        triangulo->setAllValues(15,12,11);
        CPPUNIT_ASSERT(triangulo->getTipo() == "ESCALENO" );
    }

    void testeTrianguloIsoceles()
    {
        TestaTriangulo testaTriangulo;
        triangulo = (new ClassificadorTriangulo(5,8,8));
        triangulo->setTeste(&testaTriangulo);
        CPPUNIT_ASSERT(triangulo->getTipo() == "ISOCELES" );
        triangulo->setAllValues(1586,1586,963);
        CPPUNIT_ASSERT(triangulo->getTipo() == "ISOCELES" );
        triangulo->setAllValues(2,2,1);
        CPPUNIT_ASSERT(triangulo->getTipo() == "ISOCELES" );
        triangulo->setAllValues(25,25,20);
        CPPUNIT_ASSERT(triangulo->getTipo() == "ISOCELES" );
        triangulo->setAllValues(17,17,16);
        CPPUNIT_ASSERT(triangulo->getTipo() == "ISOCELES" );
    }

    void testeTrianguloRetangulo()
    {
        TestaTriangulo testaTriangulo;
        triangulo = (new ClassificadorTriangulo(3,4,5));
        triangulo->setTeste(&testaTriangulo);
        CPPUNIT_ASSERT(triangulo->getTipo() == "RETANGULO" );
        triangulo->setAllValues(8,6,10);
        CPPUNIT_ASSERT(triangulo->getTipo() == "RETANGULO" );
        triangulo->setAllValues(24,25,7);
        CPPUNIT_ASSERT(triangulo->getTipo() == "RETANGULO" );
    }

    void testeTrianguloInvalido()
    {
        TestaTriangulo testaTriangulo;
        triangulo = (new ClassificadorTriangulo(3,10,4));
        triangulo->setTeste(&testaTriangulo);
        CPPUNIT_ASSERT_THROW(triangulo->getTipo(), TrianguloInvalidoException );
        triangulo->setAllValues(-8,6,10);
        CPPUNIT_ASSERT_THROW(triangulo->getTipo(), TrianguloInvalidoException );
        triangulo->setAllValues(1256,150,90);
        CPPUNIT_ASSERT_THROW(triangulo->getTipo(), TrianguloInvalidoException );
        triangulo->setAllValues(0,0,0);
        CPPUNIT_ASSERT_THROW(triangulo->getTipo(), TrianguloInvalidoException );
    }

    void testeTrianguloNaoFoiInjetadoComOValidador()
    {
        TestaTriangulo testaTriangulo;
        triangulo = (new ClassificadorTriangulo(3,10,4));
        triangulo->setTeste(NULL);
        CPPUNIT_ASSERT_THROW(triangulo->getTipo(), TrianguloInvalidoException );
        triangulo->setAllValues(3,4,5);
        CPPUNIT_ASSERT_THROW(triangulo->getTipo(), TrianguloInvalidoException );
        triangulo->setAllValues(10,10,10);
        CPPUNIT_ASSERT_THROW(triangulo->getTipo(), TrianguloInvalidoException );
        triangulo->setAllValues(16,16,9);
        CPPUNIT_ASSERT_THROW(triangulo->getTipo(), TrianguloInvalidoException );
    }
static CppUnit::Test *suite()
    {
        CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "TestesTriangulo" );
        suiteOfTests->addTest( new CppUnit::TestCaller<TesteClassificadorTriangulo>(
                "Teste se o triangulo é isoceles",
                &TesteClassificadorTriangulo::testeTrianguloIsoceles ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<TesteClassificadorTriangulo>(
                "Teste se o triangulo é equilátero",
                &TesteClassificadorTriangulo::testeTrianguloEquilatero ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<TesteClassificadorTriangulo>(
                "Teste se o triangulo é escaleno",
                &TesteClassificadorTriangulo::testeTrianguloEscaleno ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<TesteClassificadorTriangulo>(
                "Teste se o triangulo é retângulo",
                &TesteClassificadorTriangulo::testeTrianguloRetangulo ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<TesteClassificadorTriangulo>(
                "Teste se o triangulo é inválido",
                &TesteClassificadorTriangulo::testeTrianguloInvalido ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<TesteClassificadorTriangulo>(
                "Teste se o triangulo é não foi injetado com validador",
                &TesteClassificadorTriangulo::testeTrianguloNaoFoiInjetadoComOValidador ) );
        return suiteOfTests;
    }

};
#endif //TRIANGULO_TRIANGULOTESTS_H
