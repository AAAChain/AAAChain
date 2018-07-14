file(GLOB SRCS *.cpp)

add_executable(TestChainbase ${SRCS})

target_link_libraries(TestChainbase Emscripten libgtest libgmock)

