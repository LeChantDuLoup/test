// display_node.cpp
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/String.hpp>

class DisplayNode : public rclcpp::Node {
public:
  DisplayNode() : Node("display_node") {
    subscriber_ = create_subscription<std_msgs::msg::String>(
      "check_result", 10, std::bind(&DisplayNode::checkCallback, this, std::placeholders::_1)
    );
    // Implement the logic to display '1' in the application when a key is used
  }

private:
  void checkCallback(const std_msgs::msg::String::SharedPtr msg) {
    // Implement the logic to display '1' when a key is used
  }

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<DisplayNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
