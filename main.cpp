#include <iostream>
#include <cppunit/TestResult.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include "domain/ClassificadorTriangulo.h"
#include "utils/TestaTriangulo.h"
#include "tests/TesteClassificadorTriangulo.h"


using namespace CppUnit;


int main() {
    CppUnit::TestResult result;
    CppUnit::TextUi::TestRunner runner;
    runner.addTest( TesteClassificadorTriangulo::suite() );
    runner.run();
    return 0;
}
