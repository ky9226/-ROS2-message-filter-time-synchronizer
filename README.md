# -ROS2-message-filter-time-synchronizer

#reference
https://github.com/hi-g1/ros2_message_filters_example.git 

$ ros2 run msg_sync msg1_pub\
$ ros2 run msg_sync msg2_pub\
$ ros2 run msg_sync msg_sync\
\
\
#check \
$ ros2 topic hz /msg_1\
$ ros2 topic echo /msg_1\
$ ros2 topic hz /msg_2\
$ ros2 topic echo /msg_2
