cmake_minimum_required(VERSION 3.17)
project(AssimpTest)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory (extern EXCLUDE_FROM_ALL)

include_directories(
        include
        .
)

add_executable(AssimpTest main.cpp)

if(APPLE)
    SET (CMAKE_CXX_FLAGS "-fsized-deallocation")

    find_library( COCOA_FW Cocoa )
    find_library( OPENGL_FW OpenGL )
    find_library( IOKIT_FW IOKit )
    find_library( COREFOUNDATION_FW CoreFoundation )
    find_library( COREVIDEO_FW CoreVideo )

    target_link_libraries(AssimpTest
            assimp
            libglew_static
            glfw
            ${COCOA_FW}
            ${OPENGL_FW}
            ${IOKIT_FW}
            ${COREFOUNDATION_FW}
            ${COREVIDEO_FW}
            )

elseif(WIN32)
    find_package( OpenGL REQUIRED )

    target_link_libraries(AssimpTest
            assimp
            libglew_static
            glfw

            ${OPENGL_LIBRARIES}
            )
endif()









