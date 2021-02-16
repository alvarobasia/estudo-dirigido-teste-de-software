project(Triangulo)
cmake_minimum_required(VERSION 3.17)
set(COVERAGE g++ main.cpp -lcppunit --coverage -o Triangulo)
set(BUILD_COVERAGE lcov -t "result" -o coverage.info -c -d . && genhtml -o Coverage coverage.info )
set(CLEAR_COVERAGE rm *.gcda *.gcno *.info )

add_custom_target(coverage ${COVERAGE})
add_custom_target(build-coverage ${BUILD_COVERAGE})
add_custom_target(clear-coverage ${CLEAR_COVERAGE})
add_executable(Triangulo main.cpp)

target_link_libraries(Triangulo cppunit)