set(INCROOT ${PROJECT_SOURCE_DIR}/include/GUIL/Handlers)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Handlers)

set(SRC
    ${INCROOT}/global.hpp
    ${INCROOT}/global_handlers.hpp
    ${SRCROOT}/global_handlers.cpp
    ${INCROOT}/window.hpp
    ${INCROOT}/window_handlers.hpp
    ${SRCROOT}/window_handlers.cpp
    ${INCROOT}/keyboard.hpp
    ${INCROOT}/keyboard_handlers.hpp
    ${SRCROOT}/keyboard_handlers.cpp
    ${INCROOT}/mouse.hpp
    ${INCROOT}/mouse_handlers.hpp
    ${SRCROOT}/mouse_handlers.cpp
)

add_library(gui-handlers ${SRC})
target_link_libraries(gui-handlers PUBLIC tmbel)
target_include_directories(gui-handlers PUBLIC ${PROJECT_SOURCE_DIR}/include)