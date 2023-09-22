#include <ros/ros.h>
#include <std_msgs/Float32MultiArray.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "wbc");
    ros::NodeHandle nh;

    ros::Publisher my_publisher = nh.advertise<std_msgs::Float32MultiArray>("/tauList", 1);
    ros::Rate loop_rate(10); // Rate at which to publish

    while (ros::ok()) {
        std_msgs::Float32MultiArray tauList;
        tauList.data.resize(12); // Set the size of the data array to 12

        // Populate the data array with random doubles
        for (int i = 0; i < 12; ++i) {
            tauList.data[i] = (static_cast<double>(rand()) / RAND_MAX) * 70 - 35; // Random double between -35 and 35
        }

        my_publisher.publish(tauList);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}



