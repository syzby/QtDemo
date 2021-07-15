set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

set(APP_NAME "DirView")

add_executable(${APP_NAME}
main.cpp
${UI_FILES}
${TS_FILES}
)

target_link_libraries(${APP_NAME} PRIVATE Qt5::Widgets)
