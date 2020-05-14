# CMakeList.txt : CMake project for Fractal generator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Fractal generator")

# Add source to this project's executable.
add_executable (CMakeTarget "main.cpp" "Generator/Generator.h" "Generator/Generator.cpp" "ImageData/Bmp.h" "ImageData/Bmp.cpp" "ImageData/ImageData.h" "Mandelbrot/Mandelbrot.h")

# TODO: Add tests and install targets if needed.
