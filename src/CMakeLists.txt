set(INCROOT ${PROJECT_SOURCE_DIR}/include/GUIL/)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

set(SRC
    ${INCROOT}/render_object.hpp
    ${SRCROOT}/render_object.cpp
)

add_library(gui-lib ${SRC})
set_target_properties(gui-lib PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(gui-lib PUBLIC
    tmbel 
    sfml-graphics 
    sfml-window 
    sfml-audio 
    sfml-system
)