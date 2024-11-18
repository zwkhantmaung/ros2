#include "rclcpp/rclcpp.hpp"
#include "custommsg/srv/csrv.hpp"

#include <memory>

void add(const std::shared_ptr<custommsg::srv::Csrv::Request> request,
          std::shared_ptr<custommsg::srv::Csrv::Response>      response)
{
  response->sum = request->a + request->b + request->c;
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %d" " b: %d" " c: %d",
                request->a, request->b, request->c);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%d]", response->sum);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_two_ints_server");

  rclcpp::Service<custommsg::srv::Csrv>::SharedPtr service =
    node->create_service<custommsg::srv::Csrv>("csrv", &add);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add two ints.");

  rclcpp::spin(node);
  rclcpp::shutdown();
}