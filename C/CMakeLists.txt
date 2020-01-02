cmake_minimum_required(VERSION 3.10)

include(FindPkgConfig)
pkg_check_modules(LIBUBOOTENV libubootenv>=0.2 REQUIRED)

add_executable(sample sample.c)
target_link_libraries(sample ${LIBUBOOTENV_LIBRARIES})

install (TARGETS sample DESTINATION bin)
