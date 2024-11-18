#include <rclcpp/rclcpp.hpp>
#include <turtlesim/msg/pose.hpp>

class TurtlePoseSubscriber : public rclcpp::Node {
public:
    TurtlePoseSubscriber() : Node("turtle_pose_subscriber") {
        subscription_ = this->create_subscription<turtlesim::msg::Pose>(
            "/turtle1/pose", 10,
            [this](const turtlesim::msg::Pose::SharedPtr msg) {
                RCLCPP_INFO(this->get_logger(), "Turtle Position - x: %.2f, y: %.2f, theta: %.2f",
                            msg->x, msg->y, msg->theta);
            });
    }

private:
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscription_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TurtlePoseSubscriber>());
    rclcpp::shutdown();
    return 0;
}
