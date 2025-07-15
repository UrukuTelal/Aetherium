# engine/CMakeLists.txt
file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/core/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/core/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/net/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/net/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/render/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/render/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/world/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/world/*.h"
)

if(ENGINE_SRC)
    add_library(engine STATIC ${ENGINE_SRC})
    target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
else()
    add_library(engine INTERFACE)
    target_include_directories(engine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
endif()
