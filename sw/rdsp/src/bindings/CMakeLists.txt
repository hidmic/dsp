
matlab_add_mex(
  NAME mex_rdsp_filter
  OUTPUT_NAME rdsp_filter
  SRC mex_rdsp_filter.cpp
)

target_include_directories(mex_rdsp_filter
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    ${EIGEN3_INCLUDE_DIRS}
)

target_link_libraries(mex_rdsp_filter
  msgpackc-cxx
)

install(
  TARGETS mex_rdsp_filter
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)
