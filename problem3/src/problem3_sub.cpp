#include <ros/ros.h>
#include <cstdlib>
#include <math.h>
#include "problem3/problem3_msg.h"

using namespace std;

int sum = 0;

void msgCallback(const problem3::problem3_msgPtr& ptr){
    sum = ptr->number+ sum;
    ROS_INFO("first : %d", ptr->number);
    
}
void msgCallback2(const problem3::problem3_msgPtr& ptr2){
    sum += ptr2->number;
    ROS_INFO("second : %d", ptr2->number);
    ROS_INFO("sum : %d", sum);

    sum = 0;
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "problem3_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("problem3", 10, msgCallback);
    ros::Subscriber sub2 = nh.subscribe("problem3_1", 10, msgCallback2);

    ros::spin();
    return 0;

}