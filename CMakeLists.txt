cmake_minimum_required (VERSION 2.6)
project(cookiebot)
set (cookiebot_VERSION_MAJOR 0)
set (cookiebot_VERSION_MINOR 0)
option (MOD_GZIP "Enable Module compression with gzip" ON)
option (MOD_BZ2 "Enable Module compression with bz2" ON)
option (MOD_XZ "Enable Module compression with xz/lzma" ON)
configure_file (
  "${PROJECT_SOURCE_DIR}/cookiebot_conf.h.in"
  "${PROJECT_BINARY_DIR}/cookiebot_conf.h"
  )
include_directories("${PROJECT_BINARY_DIR}")
add_executable(cookiebot cookiebot.cpp)
