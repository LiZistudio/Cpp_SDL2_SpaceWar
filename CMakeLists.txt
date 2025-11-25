#标题
cmake_minimum_required(VERSION 3.10.0)
project(SDLSpaceWar VERSION 0.1.0 LANGUAGES C CXX)

# Workaround: allow configuring packages whose config files use very old cmake_minimum_required
# (等价于在命令行添加 -DCMAKE_POLICY_VERSION_MINIMUM=3.5)
if(NOT DEFINED CMAKE_POLICY_VERSION_MINIMUM)
    set(CMAKE_POLICY_VERSION_MINIMUM 3.5 CACHE STRING "Allow older package config cmake_minimum_required")
endif()

#设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#设置编译选项
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#设置可执行程序的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})

set(TARGET ${PROJECT_NAME}-${CMAKE_SYSTEM_NAME})

#如果是Windows平台，则：
#include_directories("D:/SDL2Library/SDL2/include")
#link_directories("D:/SDL2Library/SDL2/lib/x64")
#查找并载入SDL2的cmake预设
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

#添加可执行文件
add_executable(${TARGET} 
                source/main.cpp
                source/Game.cpp
                source/SceneMain.cpp
                )

#链接SDL2库
target_link_libraries(${TARGET} 
                        ${SDL2_LIBRARIES}
                        SDL2_image::SDL2_image
                        SDL2_mixer::SDL2_mixer
                        SDL2_ttf::SDL2_ttf
                        )
