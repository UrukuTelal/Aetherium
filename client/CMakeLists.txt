file(GLOB CLIENT_SRC CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/gui/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/platform/*.cpp"
)

add_executable(client ${CLIENT_SRC} "android/jni/bridge.cpp" "platform/android/android_platform.cpp" "platform/android/android_platform.h"  "platform/windows/windows_platform.cpp" "platform/windows/windows_platform.h" "platform/linux/linux_platform.cpp" "platform/linux/linux_platform.h" "platform/platform.cpp" "platform/platform.h")

target_include_directories(client PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${SDL2_SOURCE_DIR}/include
)

target_link_libraries(client
    engine
    shared
    SDL2-static
    $<TARGET_NAME_IF_EXISTS:SDL2main>
)
