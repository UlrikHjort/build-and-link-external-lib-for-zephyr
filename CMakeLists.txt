cmake_minimum_required(VERSION 3.13.1)
find_package(Zephyr REQUIRED HINTS $ENV(ZEPHYR_BASE))
project(zephyr_app)


ADD_SUBDIRECTORY(lib)
TARGET_SOURCES(app PRIVATE src/main.c)
include_directories(lib/include/)
TARGET_LINK_LIBRARIES(app PRIVATE thelib)

