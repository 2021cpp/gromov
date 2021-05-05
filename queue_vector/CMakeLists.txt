# CMakeList.txt: проект CMake для queue_list; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("queue_list")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (queue_list "queue_list.cpp" "queue_list.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
