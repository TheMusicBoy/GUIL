set(INCROOT ${PROJECT_SOURCE_DIR}/include/)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

set(SRC

)

add_library(mwf-lib ${SRC})
set_target_properties(mwf-lib PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(mwf-lib PUBLIC tmbel)
target_link_libraries(mwf-lib PUBLIC sfml-graphics sfml-window sfml-audio sfml-system)