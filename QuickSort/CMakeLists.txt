# CMakeList.txt: проект CMake для QuickSort; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("QuickSort")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (QuickSort "QuickSort.cpp" "QuickSort.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
