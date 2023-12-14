add_library(dynarray dynarray.cpp dynarray.hpp)
set_property(TARGET dynarray PROPERTY CXX_STANDARD 20)
target_include_directories(dynarray PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS dynarray)