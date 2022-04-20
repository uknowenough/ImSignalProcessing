cmake_minimum_required(VERSION 3.5)

project(SignalProc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(IMGUI_DIR 3rdparty/imgui)

include_directories(include 3rdparty/imgui 3rdparty/glfw/include/GLFW)

add_executable(SignalProc src/main.cpp ${IMGUI_DIR}/imgui.cpp
               ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
               ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
               ${IMGUI_DIR}/imgui_draw.cpp
               ${IMGUI_DIR}/imgui_tables.cpp
               ${IMGUI_DIR}/imgui_widgets.cpp
               ${IMGUI_DIR}/imgui_demo.cpp)

target_link_libraries(SignalProc PUBLIC GL)
target_link_libraries(SignalProc PUBLIC glfw)
