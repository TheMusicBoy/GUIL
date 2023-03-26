set(INCROOT ${PROJECT_SOURCE_DIR}/include/GUIL/)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

add_subdirectory(Handlers)

set(SRC
    ${INCROOT}/render_object.hpp
    ${SRCROOT}/render_object.cpp
    ${INCROOT}/render.hpp
    ${SRCROOT}/render.cpp
    ${INCROOT}/controller.hpp
    ${SRCROOT}/controller.cpp
)

add_library(gui-lib ${SRC})
set_target_properties(gui-lib PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(gui-lib PUBLIC ${PROJECT_SOURCE_DIR}/include/)
target_link_libraries(gui-lib PUBLIC
    gui-handlers
    tmbel 
    sfml-graphics 
    sfml-window 
    sfml-audio 
    sfml-system
)