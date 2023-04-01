add_executable(guil-example main.cpp)

set_target_properties(guil-example PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(guil-example PUBLIC gui-lib)