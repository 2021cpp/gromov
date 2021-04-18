# CMakeList.txt: проект CMake для HeapSort; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("HeapSort")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (HeapSort "HeapSort.cpp" "HeapSort.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
