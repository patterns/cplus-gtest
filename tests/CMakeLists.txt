






include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/52eb8108c5bdec04579160ae17225d66034bd723.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
  points_test
  sample_test.cc
  points_test.cc
)
target_link_libraries(points_test
  housing
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(points_test)
