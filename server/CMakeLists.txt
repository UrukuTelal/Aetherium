file(GLOB SERVER_SRC CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/worldsync/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/auth/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/admin/*.cpp"
)

add_executable(server ${SERVER_SRC})

target_include_directories(server PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${enet_SOURCE_DIR}/include
)

target_link_libraries(server
    engine
    shared
    enet
)
