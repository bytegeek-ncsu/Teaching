#steps

# 0.) Create Source and CMakeFile
# 1.)create build directory mkdir build
# 3.) cd build
# 4.) cmake .. - Genertating the build files / Configure the project
# 5.) cmake --build .
# 6.) ./Executable

cmake_minimum_required(VERSION 3.22)

#To define variables we use set(Variable_name value)

set(CMAKE_CXX_STANDARD      17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS    OFF)

#Local Variables defined for the project
set(LIBRARY_NAME Library)
set(EXECUTABLE_NAME Executable)


project(
    CppProjectTemplate
    VERSION 1.0.0
    LANGUAGES C CXX)

# adding Subdirectories

add_subdirectory(src)
add_subdirectory(inc)
add_subdirectory(app)




