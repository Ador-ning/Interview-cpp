file(REMOVE_RECURSE
  "libhttp_lib.pdb"
  "libhttp_lib.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/http_lib.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
