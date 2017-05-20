cmake_minimum_required(VERSION 3.7)
project(OpenGLBook)

set(CMAKE_CXX_STANDARD 14)


set(SOURCE_FILES main.cpp main.cpp ShaderProgram.cpp ShaderProgram.h SOIL/src/image_DXT.c SOIL/src/image_DXT.h SOIL/src/image_helper.c SOIL/src/image_helper.h SOIL/src/stb_image_aug.c SOIL/src/stb_image_aug.h SOIL/src/SOIL.c SOIL/src/SOIL.h SOIL/src/stbi_DDS_aug.h SOIL/src/stbi_DDS_aug_c.h Camera.h Camera.h shader.hpp stb_image.hpp Mesh.cpp Mesh.hpp Model.cpp Model.hpp)
add_executable(OpenGLBook ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(assimp REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)


include_directories(${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} )
include_directories(${ASSIMP_INCLUDE_DIRS})
include_directories(${GLFW_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${GLFW_LIBRARIES} GLEW)

target_link_libraries(${PROJECT_NAME} ${GLFW_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SOIL_LIBRARIES})

add_custom_command(TARGET OpenGLBook POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Shaders
        $<TARGET_FILE_DIR:OpenGLBook>/Shaders)

add_custom_command(TARGET OpenGLBook POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Assets
        $<TARGET_FILE_DIR:OpenGLBook>/Assets)
