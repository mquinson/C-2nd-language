project(MyProject)
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall")
add_executable(prog main.c point.c point.h)
