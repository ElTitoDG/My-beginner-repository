cmake_minimum_required(VERSION 3.15)
project(gtkTest VERSION 0.1 LANGUAGES C)

# Set the C standard
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)

# Find GTK4 package using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)

# Collect all source files in the 'src' directory
file(GLOB SOURCE_FILES src/*.c)

# Define the executable name separately from the project name
set(EXECUTABLE_NAME "myapp")

# Include and Link Dirs
include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})

# Add the executable
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

# Link the executable with GTK4 libraries
target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${GTK4_LIBRARIES})

# Include GTK4 directories
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${GTK4_INCLUDE_DIRS})

# Add GTK4 compiler flags
target_compile_options(${EXECUTABLE_NAME} PRIVATE ${GTK4_CFLAGS_OTHER})
