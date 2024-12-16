cmake_minimum_required(VERSION 3.10)

project(test-lvgl)

# Uncomment if the program needs debugging
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -ggdb")

set(CMAKE_C_STANDARD 99) # LVGL officially supports C99 and above
set(CMAKE_CXX_STANDARD 17) #C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LVGL REQUIRED lvgl)
pkg_check_modules(LIBDRM REQUIRED libdrm)

add_executable(test-lvgl main.c mouse_cursor_icon.c)

target_include_directories(test-lvgl PUBLIC ${LIBDRM_INCLUDE_DIRS})
target_include_directories(test-lvgl PUBLIC ${LVGL_INCLUDE_DIRS})
target_include_directories(test-lvgl PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(test-lvgl lvgl lvgl_thorvg lvgl_demos lvgl_examples ${LIBDRM_LIBRARIES} m pthread)
install(TARGETS test-lvgl LIBRARY DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_custom_target (run COMMAND ${EXECUTABLE_OUTPUT_PATH}/test-lvgl DEPENDS test-lvgl)
