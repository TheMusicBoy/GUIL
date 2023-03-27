include(FetchContent)

set(SFML_VERSION "2.5.1")

FetchContent_Declare(
    sfml
    GIT_REPOSITORY  https://github.com/SFML/SFML.git
    GIT_TAG         ${SFML_VERSION}
)

FetchContent_GetProperties(sfml)

if(NOT sfml_POPULATED)
    message("SFML populating...")

    FetchContent_Populate(sfml) 
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

FetchContent_Declare(
    ec
    GIT_REPOSITORY  https://github.com/TheMusicBoy/EventController.git
)

FetchContent_GetProperties(ec)

if(NOT ec_POPULATED)
    message("Event Controller populating...")

    FetchContent_Populate(ec)
    add_subdirectory(${ec_SOURCE_DIR} ${ec_BINARY_DIR})
endif()