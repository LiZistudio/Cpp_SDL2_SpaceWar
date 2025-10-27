#标题
cmake_minimum_required(VERSION 3.10.0)
project(SDLSpaceWar VERSION 0.1.0 LANGUAGES C CXX)

#如果是Windows平台，则：
#include_directories("D:/SDL2Library/SDL2/include")
#link_directories("D:/SDL2Library/SDL2/lib/x64")
#查找并载入SDL2的cmake预设
find_package(SDL2 REQUIRED)

#添加可执行文件
add_executable(SDLSpaceWar main.cpp)

#链接SDL2库
target_link_libraries(SDLSpaceWar 
                        SDL2::SDL2 
                        SDL2::SDL2main)
