cmake_minimum_required(VERSION 3.25)

project(
    asciify
    VERSION 0.1.0
    LANGUAGES CXX
)

# ------------------------------------------------------------
# Global configuration
# ------------------------------------------------------------

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ------------------------------------------------------------
# Library target (core logic)
# ------------------------------------------------------------

add_library(asciify_core
    src/image_loader.cpp
    src/ascii_mapper.cpp
)

target_include_directories(asciify_core
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# Warnings (production habit)
if (MSVC)
    target_compile_options(asciify_core PRIVATE /W4 /permissive-)
else()
    target_compile_options(asciify_core PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()

# ------------------------------------------------------------
# Executable target (CLI / app)
# ------------------------------------------------------------

add_executable(asciify
    src/main.cpp
)

target_link_libraries(asciify
    PRIVATE
        asciify_core
)

# ------------------------------------------------------------
# (Future) testing hook
# ------------------------------------------------------------
# enable_testing()
# add_subdirectory(tests)
