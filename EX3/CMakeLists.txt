# CMakeList.txt: проект CMake для EX3; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("EX3")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (EX3 "EX3.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EX3 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
