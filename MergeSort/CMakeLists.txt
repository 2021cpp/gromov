# CMakeList.txt: проект CMake для MergeSort; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("MergeSort")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (MergeSort "MergeSort.cpp" "MergeSort.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
