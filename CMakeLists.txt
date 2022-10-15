cmake_minimum_required(VERSION 3.23)
project(PentagonalRubixSolver)

set(CMAKE_CXX_STANDARD 14)

add_executable(PentagonalRubixSolver main.cpp rubix/RubixCube.cpp rubix/RubixCube.h rubix/RubixSide.cpp rubix/RubixSide.h rubix/colorParser.cpp rubix/colorParser.h)
