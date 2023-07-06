cmake_minimum_required(VERSION 3.10)
project(YourProjectName)

# 設定 C++ 版本
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

# 添加 Google Test 的目錄路徑
add_subdirectory(googletest)

# 添加你的程式碼所在的目錄
add_subdirectory(src)

# 添加測試程式碼所在的目錄
add_subdirectory(test)