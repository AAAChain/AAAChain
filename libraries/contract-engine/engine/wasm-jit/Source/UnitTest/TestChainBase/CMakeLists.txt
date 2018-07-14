file(GLOB SRCS *.cpp)

add_executable(TestChainBase ${SRCS})
FIND_PACKAGE(Boost 1.66 REQUIRED COMPONENTS
    thread
    filesystem
    system
    iostreams)

target_link_libraries(TestChainBase Emscripten libgtest libgmock ${Boost_LIBRARIES} )
target_include_directories( TestChainBase PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../Emscripten/lib )

