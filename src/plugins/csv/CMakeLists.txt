set(csv_src csv.cpp)
add_library(csv SHARED ${csv_src}) 
target_link_libraries(csv plugins tools)
