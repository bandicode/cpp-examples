
set(EXAMPLES_COMMON_PREFIX ${CMAKE_CURRENT_LIST_DIR})

set(STRING_EXAMPLES TRUE CACHE BOOL "Set to true to generate the 'string' examples")

if(${STRING_EXAMPLES})
  add_subdirectory(string)
endif()