cmake_minimum_required(VERSION 3.30)
project(sdl3Test VERSION 0.1 LANGUAGES CXX)
# Define the executable name
set(EXECUTABLE_NAME "myapp")

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the SDL3 package
option(MYGAME_VENDORED "Use vendored libraries" OFF)

if(MYGAME_VENDORED)
    add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
else()
    find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
endif()

# Collect all source files in the 'src' directory
file(GLOB SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp)

# Collect all resource files in the 'assets' directory
file(GLOB_RECURSE RESOURCE_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/assets/*")

# Set the application icon
set(APP_ICON "${CMAKE_SOURCE_DIR}/assets/icon.icns")

# Set properties for resource files to be placed in the Resources folder
foreach(RESOURCE_FILE ${RESOURCE_FILES})
    # Skip directories
    if (IS_DIRECTORY ${RESOURCE_FILE})
        continue()
    endif()

    # Determine the relative path of the resource file
    file(RELATIVE_PATH RELATIVE_PATH_TO_FILE "${CMAKE_SOURCE_DIR}/assets" ${RESOURCE_FILE})
    get_filename_component(RELATIVE_DIR "${RELATIVE_PATH_TO_FILE}" DIRECTORY)

    # Set the destination within the Resources folder, preserving the directory structure
    set_source_files_properties(${RESOURCE_FILE} PROPERTIES
        MACOSX_PACKAGE_LOCATION "Resources/${RELATIVE_DIR}"
        HEADER_FILE_ONLY TRUE
    )
endforeach()

# Set properties for the application icon
set_source_files_properties(${APP_ICON} PROPERTIES
    MACOSX_PACKAGE_LOCATION "Resources"
    HEADER_FILE_ONLY TRUE
)

# Add the executable and include resource files
add_executable(${EXECUTABLE_NAME} MACOSX_BUNDLE
    ${SOURCE_FILES}
    ${RESOURCE_FILES}
    ${APP_ICON}
)

# Link SDL3 library
target_link_libraries(${EXECUTABLE_NAME} PRIVATE SDL3::SDL3)

# Set bundle properties
set_target_properties(${EXECUTABLE_NAME} PROPERTIES
    MACOSX_BUNDLE_ICON_FILE "icon.icns"
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.yourcompany.myapp"
    MACOSX_BUNDLE_BUNDLE_VERSION "${PROJECT_VERSION}"
    MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
    MACOSX_BUNDLE_LONG_VERSION_STRING "${PROJECT_VERSION}"
    MACOSX_BUNDLE_COPYRIGHT "(C) 2025 Your Company Name"
)

# Installation rules
install(TARGETS ${EXECUTABLE_NAME} BUNDLE DESTINATION .)
