#include <ros/ros.h>
#include <cstdlib>
#include "problem3/problem3_msg.h"

int main(int argc, char *argv[]){
    ros::init(argc, argv, "problem3_pub");
    ros::NodeHandle nh;

    ros::Publisher first = nh.advertise<problem3::problem3_msg>("problem3", 1000);
    ros::Publisher second = nh.advertise<problem3::problem3_msg>("problem3_1",1000);
    ros::Rate loop_rate(10);
    
    problem3::problem3_msg msg1;
    problem3::problem3_msg msg2;

    srand(time(NULL));
    int num;
    int num2;

    //std::vector<u_int16_t>::iterator i;

    while(ros::ok()){
        msg1.stamp = ros::Time::now();
        num = rand() % 20 + 1;
        msg1.number = num;

        msg2.stamp = ros::Time::now();
        num2 = rand() % 20 + 1;
        msg2.number = num2;

        first.publish(msg1);
        second.publish(msg2);

        loop_rate.sleep();

    }
    return 0;
}