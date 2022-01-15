file(REMOVE_RECURSE
  "testing/main.qml"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/apptesting_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
