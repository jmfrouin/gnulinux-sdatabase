set(xml_src xml.cpp)
add_library(xml SHARED ${xml_src}) 
target_link_libraries(xml plugins tools)
