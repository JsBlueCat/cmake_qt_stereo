cmake_minimum_required(VERSION 3.0.0)
project(STEREO_CLIB_DESKTOP VERSION 0.1.0)

include(CTest)
enable_testing()




# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "D:\\Qt\\Qt5.13.0\\5.13.0\\msvc2017_64\\lib\\cmake")
# Widgets finds its own dependencies (QtGui and QtCore).
find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS})

# Executables fail to build with Qt 5 in the default configuration
# without -fPIE. We add that here.
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

FILE(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
FILE(GLOB HEAD_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
FILE(GLOB UI_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.ui")
qt5_wrap_ui(UI_HEADERS ${UI_FILES})

add_executable(${PROJECT_NAME}
${HEAD_FILES}
${UI_HEADERS}
${SOURCE_FILES}
)
qt5_use_modules(${PROJECT_NAME} Core Widgets Gui) 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
