cmake_minimum_required(VERSION 3.6)
project(opengltutorial)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp ShaderProgram.cpp ShaderProgram.h DebugLog.cpp DebugLog.h FpsLimiter.cpp FpsLimiter.h InputHandler.cpp InputHandler.h maths_funcs.cpp maths_funcs.h maths_funcs.cpp maths_funcs.h)
add_executable(opengltutorial ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} )
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${GLFW_LIBRARIES} GLEW)

target_link_libraries(${PROJECT_NAME})

add_custom_command(TARGET opengltutorial POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Shaders
        $<TARGET_FILE_DIR:opengltutorial>/Shaders)
