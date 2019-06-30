
set(EXAMPLES_COMMON_PREFIX ${CMAKE_CURRENT_LIST_DIR})

set(MEMORY_EXAMPLES TRUE CACHE BOOL "Set to true to generate the 'memory' examples")
set(STRING_EXAMPLES TRUE CACHE BOOL "Set to true to generate the 'string' examples")

if(${MEMORY_EXAMPLES})
  add_subdirectory(memory)
endif()

if(${STRING_EXAMPLES})
  add_subdirectory(string)
endif()