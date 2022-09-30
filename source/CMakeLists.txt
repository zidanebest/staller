project(stallar LANGUAGES CXX)


add_library(stallar STATIC 
    " "
)

file(GLOB_RECURSE _sources 
  *.cpp 
  *.h
  *.inl
  *.hpp  
)

target_sources(stallar PRIVATE
${_sources}
)

