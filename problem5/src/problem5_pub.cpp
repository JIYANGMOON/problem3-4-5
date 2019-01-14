#include <ros/ros.h>
#include "problem5/problem5_msg.h"
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    ros::init(argc, argv, "problem5");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<problem5::problem5_msg>("problem5", 10);
    problem5::problem5_msg msg;

    fstream fs("/home/jiyang/Desktop/number.txt");
    fstream in_fs("/home/jiyang/Desktop/number2.txt", fstream::out);

    int n;
    int cn = 0;

    ros::Rate loop_Rate(15);
    while(fs >> n) {
        msg.num.push_back(n);
        cn++;
        loop_Rate.sleep();
    }  
    fs.close();

    msg.count = cn;

    for(int i = 0; i<msg.count; i++){
        msg.num[i] = -msg.num[i];
        in_fs << msg.num[i];
        in_fs << '\n';
    }

    for(int i = 0; i<msg.count; i++){
        ROS_INFO_STREAM(msg.num[i]);
    }
    in_fs.close();

    return 0;
}