add_subdirectory(csv)
#add_subdirectory(xml)

set(plugin_src plugin_manager.cpp)
add_library(plugins ${plugin_src})
