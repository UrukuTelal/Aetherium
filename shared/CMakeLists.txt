# shared/CMakeLists.txt
file(GLOB_RECURSE SHARED_SRC CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/protocol/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/protocol/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/sim/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/sim/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/config/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/config/*.h"
)


if(SHARED_SRC)
    add_library(shared STATIC ${SHARED_SRC})
    target_include_directories(shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
else()
    add_library(shared INTERFACE)
    target_include_directories(shared INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
endif()
