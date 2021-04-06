# CMakeList.txt: проект CMake для queue_deque; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("queue_deque")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (queue_deque "queue_deque.cpp" "queue_deque.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
