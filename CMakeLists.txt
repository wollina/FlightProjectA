cmake_minimum_required(VERSION 3.13)
project(FlightProjectA)

set(CMAKE_CXX_STANDARD 14)

add_executable(FlightProjectA main.cpp LexerClass.cpp LexerClass.h ParserClass.cpp ParserClass.h Command.h DefineVarCommand.cpp DefineVarCommand.h symTblClass.cpp symTblClass.h ConditionParser.h ConditionParser.cpp ifCommand.cpp ifCommand.h loopCommand.cpp loopCommand.h assignmentCommand.cpp assignmentCommand.h printCommand.h printCommand.cpp OpenServerCommand.h OpenServerCommand.cpp)