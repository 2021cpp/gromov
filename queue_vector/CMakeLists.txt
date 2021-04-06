# CMakeList.txt: проект CMake для queue_vector; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("queue_vector")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (queue_vector "queue_vector.cpp" "queue_vector.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
