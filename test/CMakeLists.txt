cmake_minimum_required(VERSION 3.10)

set(This HeapTest)

set(Sources
    test.cpp
)
add_executable(${This} ${Sources})  # 替換成你的測試程式碼檔案名稱

target_link_libraries(${This} PUBLIC 
    gtest_main
    Heap
)  # 替換成你的程式碼的目標名稱

add_test(
    NAME ${This}
    COMMAND ${This}
)