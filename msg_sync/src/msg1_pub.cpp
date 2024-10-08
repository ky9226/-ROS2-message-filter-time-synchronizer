#include "msg_sync/msg_pub.hpp"

MsgPub::MsgPub()
: Node("msg1_publisher")
{
    first_msg_ = this->create_publisher<std_msgs::msg::Header>("msg_1", 1);
    timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&MsgPub::msg_publish, this));

    RCLCPP_INFO(this->get_logger(), "node starts");
}

void MsgPub::msg_publish()
{
    auto msg1 = std_msgs::msg::Header();
    msg1.frame_id = "first_msg";
    msg1.stamp = this->get_clock()->now();
    RCLCPP_INFO(this->get_logger(),"msg1 pub : 1 Hz");

    first_msg_->publish(msg1);
}

int main(int argc, char * argv[])
{
 rclcpp::init(argc, argv);
 auto node = std::make_shared<MsgPub>();
 rclcpp::spin(node);
 rclcpp::shutdown();
 return 0;
}
