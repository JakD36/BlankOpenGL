IF(MSVC)
    SET(CMAKE_CXX_FLAGS "/EHsc")
ENDIF(MSVC)

set(BUILD_SHARED_LIBS OFF)

add_subdirectory(glew ${CMAKE_BINARY_DIR}/extern/glew)
add_subdirectory(assimp ${CMAKE_BINARY_DIR}/extern/assimp)
add_subdirectory(glfw ${CMAKE_BINARY_DIR}/extern/glfw)

target_compile_options(glfw PUBLIC -w)
target_compile_options(assimp PUBLIC -w)
