file(REMOVE_RECURSE
  "Dashboard/src/app/view/MSidebar.qml"
  "Dashboard/src/app/view/main.qml"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/appDashboard_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
