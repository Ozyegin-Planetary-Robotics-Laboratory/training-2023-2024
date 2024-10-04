#include <ros/ros.h>
#include <std_msgs/Float64.h>

// Define global publishers for the joint controllers
ros::Publisher joint1_pub;
ros::Publisher joint2_pub;

// Callback function to handle messages on the /set_joint_position topic
void joint_position_callback(const std_msgs::Float64::ConstPtr& msg)
{
    // Publish the received position to both joints
    joint1_pub.publish(msg);
    joint2_pub.publish(msg);
}

int main(int argc, char **argv)
{
    // Initialize the ROS node
    ros::init(argc, argv, "joint_position_publisher");
    ros::NodeHandle nh;

    // Create publishers for the joint controllers
    joint1_pub = nh.advertise<std_msgs::Float64>("/joint1_position_controller/command", 10);
    joint2_pub = nh.advertise<std_msgs::Float64>("/joint2_position_controller/command", 10);

    // Subscribe to the /set_joint_position topic
    ros::Subscriber sub = nh.subscribe("/set_joint_position", 10, joint_position_callback);

    // Spin to keep the node running
    ros::spin();
    return 0;
}
