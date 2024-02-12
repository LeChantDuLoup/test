// check_node.cpp
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/String.hpp>

class CheckNode : public rclcpp::Node {
public:
  CheckNode() : Node("check_node") {
    subscriber_ = create_subscription<std_msgs::msg::String>(
      "keyboard_input", 10, std::bind(&CheckNode::keyboardCallback, this, std::placeholders::_1)
    );
    // Implement the logic to check for 'z', 'e', 'r', 't' and publish the result
  }

private:
  void keyboardCallback(const std_msgs::msg::String::SharedPtr msg) {
    // Implement the logic to check for 'z', 'e', 'r', 't' in msg->data and publish the result
  }

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<CheckNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
