cmake_minimum_required(VERSION 3.20)
project(untitled6)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled6 extension/operators,templates,5Rules.cpp
        structural/flyWeight.cpp
        structural/adapter.cpp
        structural/bridge.cpp
        structural/adapter.cpp
        structural/composite.cpp
        structural/decorator.cpp
        structural/proxy.cpp
        creational/factory.cpp
        creational/abstractFactory.cpp
        creational/prototype.cpp
        creational/builder.cpp
        creational/singleton.cpp)
