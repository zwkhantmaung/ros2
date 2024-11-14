cmake_minimum_required(VERSION 3.8)
project(ros2cc)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


add_executable(talker_str src/publisher_str.cpp)
ament_target_dependencies(talker_str rclcpp std_msgs)

add_executable(listener_str src/subscriber_str.cpp)
ament_target_dependencies(listener_str rclcpp std_msgs)


add_executable(talker_int32 src/publisher_int32.cpp)
ament_target_dependencies(talker_int32 rclcpp std_msgs)

add_executable(listener_int32 src/subscriber_int32.cpp)
ament_target_dependencies(listener_int32 rclcpp std_msgs)


install(TARGETS
  talker_str
  listener_str
  talker_int32
  listener_int32
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()

