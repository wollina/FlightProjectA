cmake_minimum_required(VERSION 3.13)
project(FlightProjectA)

set(CMAKE_CXX_STANDARD 14)

add_executable(FlightProjectA main.cpp cmake-build-debug/LexerClass.cpp cmake-build-debug/LexerClass.h cmake-build-debug/ParserClass.cpp cmake-build-debug/ParserClass.h cmake-build-debug/Command.h cmake-build-debug/DefineVarCommand.cpp cmake-build-debug/DefineVarCommand.h cmake-build-debug/symTblClass.cpp cmake-build-debug/symTblClass.h cmake-build-debug/ConditionParser.h cmake-build-debug/ifCommand.cpp cmake-build-debug/ifCommand.h cmake-build-debug/loopCommand.cpp cmake-build-debug/loopCommand.h cmake-build-debug/assignmentCommand.cpp cmake-build-debug/assignmentCommand.h)