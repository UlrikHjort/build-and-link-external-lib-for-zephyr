project(Thelib)

include_directories(include)

file(GLOB SOURCES "src/*.c")
add_library(thelib STATIC ${SOURCES})
target_link_libraries(thelib zephyr_interface)




