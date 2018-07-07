set(Sources Emscripten.cpp lib/chainbase.cpp)
set(PublicHeaders ${WAVM_INCLUDE_DIR}/Emscripten/Emscripten.h lib/chainbase.hpp)
include_directories(${WAVM_INCLUDE_DIR}/Emscripten)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frtti")
add_library(Emscripten STATIC ${Sources} ${PublicHeaders})

add_definitions(-DEMSCRIPTEN_API=DLL_EXPORT)

target_link_libraries(Emscripten Logging Platform Runtime)
