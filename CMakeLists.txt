cmake_minimum_required(VERSION 2.8)

file(GLOB helloworld_SRC
        "*.h"
        "*.cpp"
        )

add_executable(helloworld ${helloworld_SRC})