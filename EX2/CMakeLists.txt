# CMakeList.txt: проект CMake для EX2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("EX2")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (EX2 "EX2.cpp" "EX2.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EX2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
