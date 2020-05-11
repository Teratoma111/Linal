cmake_minimum_required(VERSION 3.10)

project(linal)
file(GLOB SOURCES "*.cpp")

add_executable(linal ${SOURCES})