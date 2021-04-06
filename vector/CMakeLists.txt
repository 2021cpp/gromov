# CMakeList.txt: проект CMake для vector; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("vector")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (vector "vector.cpp" "vector.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
