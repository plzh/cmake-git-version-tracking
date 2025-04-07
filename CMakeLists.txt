cmake_minimum_required(VERSION 3.2...3.27)
project(cmake_git_version_tracking
    LANGUAGES C)

# Define the two required variables before including
# the source code for watching a git repository.
set(PRE_CONFIGURE_FILE "git.h.in")
set(POST_CONFIGURE_FILE "${CMAKE_CURRENT_BINARY_DIR}/git.h")
include(git_watcher.cmake)

# Mark the library as header-only by not compiling any source files.
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# The C99 standard is only required because we're using <stdbool.h>.
# This could be removed if it's a problem for users, but would require the
# cmake configure() commands to translate true/false literals to 1/0.
set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 99)
