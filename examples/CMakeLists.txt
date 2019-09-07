
set(EXAMPLES_COMMON_PREFIX ${CMAKE_CURRENT_LIST_DIR})

set(LANGUAGE_EXAMPLES TRUE CACHE BOOL "Set to true to generate the 'language' examples")
set(LIBRARY_EXAMPLES TRUE CACHE BOOL "Set to true to generate the 'library' examples")
set(MEMORY_EXAMPLES TRUE CACHE BOOL "Set to true to generate the 'memory' examples")
set(PREPROCESSOR_EXAMPLES TRUE CACHE BOOL "Set to true to generate the 'preprocessor' examples")
set(STL_EXAMPLES TRUE CACHE BOOL "Set to true to generate the 'stl' examples")
set(STRING_EXAMPLES TRUE CACHE BOOL "Set to true to generate the 'string' examples")

if(${LANGUAGE_EXAMPLES})
  add_subdirectory(language)
endif()

if(${LIBRARY_EXAMPLES})
  add_subdirectory(library)
endif()

if(${MEMORY_EXAMPLES})
  add_subdirectory(memory)
endif()

if(${PREPROCESSOR_EXAMPLES})
  add_subdirectory(preprocessor)
endif()

if(${STL_EXAMPLES})
  add_subdirectory(stl)
endif()

if(${STRING_EXAMPLES})
  add_subdirectory(string)
endif()