#include "msg_sync/msg_sync.hpp"
#include <iostream>


MsgSync::MsgSync() :
    Node("msg_sync_node"),
    
    msg1_sub_(this->create_subscription<StampedHeaderMsg>(
        "/msg_1", 1, std::bind(&MsgSync::msg1Callback, this, std::placeholders::_1))),
    msg2_sub_(this->create_subscription<StampedHeaderMsg>(
        "/msg_2", 1, std::bind(&MsgSync::msg2Callback, this, std::placeholders::_1)))
{
}

void MsgSync::msg1Callback(const StampedHeaderMsg::SharedPtr msg1)
{
    std::cout << "Topic: /msg_1, Timestamp: " 
              << msg1->stamp.sec << "." << msg1->stamp.nanosec << std::endl;
}

void MsgSync::msg2Callback(const StampedHeaderMsg::SharedPtr msg2)
{
    // msg_2의 타임스탬프와 주제 이름 출력
    std::cout << "Topic: /msg_2, Timestamp: " 
              << msg2->stamp.sec << "." << msg2->stamp.nanosec << std::endl;

}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MsgSync>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}



// #include "msg_sync/msg_sync.hpp"
// #include <iostream>

// MsgSync::MsgSync() :
//     Node("msg_sync_node"),
//     msg1_sub_(this, "/msg_1"),
//     msg2_sub_(this, "/msg_2"),
//     approximate_sync_(ApproximateSyncPolicy(5), msg1_sub_, msg2_sub_)
// {
//     approximate_sync_.registerCallback(&MsgSync::approximateSyncCallback, this);
// }


// void MsgSync::approximateSyncCallback(
//     const StampedHeaderMsg& msg1,
//     const StampedHeaderMsg& msg2)
// {
//     std::cout << "Message 1: [Timestamp: " << msg1.stamp.sec << "." << msg1.stamp.nanosec << "]" << std::endl;
//     std::cout << "Message 2: [Timestamp: " << msg2.stamp.sec << "." << msg2.stamp.nanosec << "]" << std::endl;
// }

// int main(int argc, char * argv[])
// {
//  rclcpp::init(argc, argv);
//  auto node = std::make_shared<MsgSync>();
//  rclcpp::spin(node);
//  rclcpp::shutdown();
//  return 0;
// }
