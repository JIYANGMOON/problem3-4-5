#include <ros/ros.h>
#include "problem4/problem4_msg.h"
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
    ros::init(argc, argv, "problem4");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<problem4::problem4_msg>("problem4",10);

    problem4::problem4_msg msg;

    fstream fs("/home/jiyang/Desktop/number.txt");

    int n;
    int cn = 0;

    ros::Rate loop_rate(15);
    while(fs >> n){
        msg.num.push_back(n);
        cn++;
        loop_rate.sleep();
    }

    msg.count = cn;
    
    pub.publish(msg); 
    for(int i = 0; i<msg.count; i++){
        ROS_INFO_STREAM(msg.num[i]);
    }

    return 0;

}