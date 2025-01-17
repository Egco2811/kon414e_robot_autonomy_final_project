#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
    // Initialize the ROS node
    ros::init(argc, argv, "circle_motion_node");
    ros::NodeHandle nh;

    // Create a publisher for the /cmd_vel topic
    ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 50);

    // Set the loop rate (10 Hz)
    ros::Rate loop_rate(50);

    ROS_INFO("Circle Motion Node has been started.");

    while (ros::ok())
    {
        // Create and populate the Twist message
        geometry_msgs::Twist cmd_msg;
        cmd_msg.linear.x = 1.0;  // Linear velocity in x (1 m/s)
        cmd_msg.angular.z = 1.0; // Angular velocity around z-axis (1 rad/s)

        // Publish the message
        cmd_vel_pub.publish(cmd_msg);

        ROS_INFO_ONCE("Publishing velocity commands for circular motion.");

        // Sleep for the remaining loop time
        loop_rate.sleep();
    }

    return 0;
}

