cmake_minimum_required(VERSION 3.22)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
    set(SFML_ROOT "../SFML-2.5.1")
    set(SFML_INCLUDE_DIR "../SFML-2.5.1/include")
    set(SFML_LIBRARY_DIR "../SFML-2.5.1/lib")
    #set(SFML_STATIC_LIBRARIES TRUE)
elseif(APPLE)
    set (SFML_ROOT "/opt/homebrew/Cellar/sfml/2.5.1_1")
    set(CMAKE_MODULE_PATH "${SFML_ROOT}/lib/cmake/SFML")
    set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
    set(SFML_LIBRARY_DIR "${SFML_ROOT}/lib")
endif()

set(EAGLES_INCLUDE_DIR "../../EaglesLib/include")
set(EAGLES_LIBRARY_DIR "../../EaglesLib/lib")

set(AZUL_INCLUDE_DIR "../../AzulLib/include")
set(AZUL_LIBRARY_DIR "../../AzulLib/lib")

include_directories(${SFML_INCLUDE_DIR} ${EAGLES_INCLUDE_DIR} ${AZUL_INCLUDE_DIR})
link_directories(${SFML_LIBRARY_DIR} ${EAGLES_LIBRARY_DIR} ${AZUL_LIBRARY_DIR})

find_package(SFML 2.5.1 COMPONENTS system window graphics)

add_executable(${PROJECT_NAME}  snakegame.cpp Snake.cpp Snake.h Wall.cpp Wall.h Food.cpp Food.h ../../EaglesLib/src/AnimatedWindow.cpp ../../EaglesLib/src/AnimatedRectangle.cpp)
target_link_libraries(${PROJECT_NAME} azul eagles sfml-graphics sfml-window sfml-system)

configure_file(${AZUL_INCLUDE_DIR}/../resources/azul.png azul.png COPYONLY)
configure_file(${AZUL_INCLUDE_DIR}/../resources/cap.png cap.png COPYONLY)
configure_file(${AZUL_INCLUDE_DIR}/../resources/RobotoMono-Regular.ttf RobotoMono-Regular.ttf COPYONLY)

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_ROOT}/bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()