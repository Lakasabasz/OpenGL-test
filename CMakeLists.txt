cmake_minimum_required(VERSION 3.12)

project(zabawa-opengl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glew REQUIRED)

add_executable(zabawa-opengl main.cpp)
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glm::glm)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${GLEW_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${GLEW_INCLUDE_DIRS})
