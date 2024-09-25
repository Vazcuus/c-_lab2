cmake_minimum_required(VERSION 3.12)
project(lab2 VERSION 1.0.0 LANGUAGES C)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
configure_file(version.h.in version.h)

add_executable(lab2 lab2.cpp)
set(CPAKE_PAKAGE_VERSION "1.0.0")

set_target_properties(lab2 PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(lab2
    PRIVATE "${CMAKE_BINARY_DIR}"
)
set_target_properties(lab2 PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

install(TARGETS lab2 RUNTIME DESTINATION bin)

if (APPLE)
    set(CPACK_GENERATOR ZIP)
else()
    set(CPACK_GENERATOR DEB)
endif()



set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "lab2")
set(CPACK_PACKAGE_CONTACT levkonst12@gmail.com)
set(CPACK_DEBIAN_PACKAGE_MAINTAINER levkonst12@gmail.com)

include(CPack)
