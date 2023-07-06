set(This Heap)

set(Headers
    heap.h
)

set(Sources
    heap.cpp
    main.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

target_include_directories(${This} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})