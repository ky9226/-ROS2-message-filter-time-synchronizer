#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/header.hpp>
#include <message_filters/subscriber.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/synchronizer.h>

using StampedHeaderMsg = std_msgs::msg::Header;
using StampedHeaderMsgSubscriber = message_filters::Subscriber<StampedHeaderMsg>;
using ApproximateSyncPolicy = message_filters::sync_policies::ApproximateTime<StampedHeaderMsg, StampedHeaderMsg>;
using ApproximateSync = message_filters::Synchronizer<ApproximateSyncPolicy>;

class MsgSync : public rclcpp::Node
{
public:
    MsgSync();

private:
    void msg1Callback(const StampedHeaderMsg::SharedPtr msg1);
    void msg2Callback(const StampedHeaderMsg::SharedPtr msg2);
    
rclcpp::Subscription<StampedHeaderMsg>::SharedPtr msg1_sub_;
    rclcpp::Subscription<StampedHeaderMsg>::SharedPtr msg2_sub_;

    // message_filters::Subscriber<StampedHeaderMsg> msg1_sub_;
    // message_filters::Subscriber<StampedHeaderMsg> msg2_sub_;
    // ApproximateSync approximate_sync_;

    void approximateSyncCallback(
    	const StampedHeaderMsg& msg1,
    	const StampedHeaderMsg& msg2
    );
};
