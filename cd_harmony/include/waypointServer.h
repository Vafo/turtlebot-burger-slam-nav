#ifndef WAYPOINTSERVER_H
#define WAYPOINTPANEL_H

#include "ros/ros.h"
#include <geometry_msgs/PoseArray.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <std_msgs/String.h>
#include <ros/package.h>
#include <boost/foreach.hpp>
#include <iostream>
#include <fstream>

#include "cd_harmony/waypoint_msg.h"
#include "cd_harmony/waypoint_group.h"
#include "cd_harmony/waypoint_array.h"
#include "cd_harmony/Save_Wp.h"
#include "cd_harmony/Load_Wp.h"
#include "cd_harmony/Run_Wp.h"
#include "cd_harmony/Stop_Wp.h"
#include "cd_harmony/Delete_Wp.h"
#include "cd_harmony/Groups_Wp.h"
#include "cd_harmony/Wp_2_Group.h"

#define foreach BOOST_FOREACH

using namespace std;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

class WaypointServer
{
public:
    WaypointServer();
    bool SaveWp(cd_harmony::Save_Wp::Request &req, cd_harmony::Save_Wp::Response &res);
    bool LoadWp(cd_harmony::Load_Wp::Request &req, cd_harmony::Load_Wp::Response &res);
    void CallbackGr(cd_harmony::waypoint_group gr_msg);
    void CallbackWp(cd_harmony::waypoint_msg wp_msg);
    void PublishWp();
    bool RunWp(cd_harmony::Run_Wp::Request &req, cd_harmony::Run_Wp::Response &res);
    bool StopWp(cd_harmony::Stop_Wp::Request &req, cd_harmony::Stop_Wp::Response &res);
    bool DeleteWp(cd_harmony::Delete_Wp::Request &req, cd_harmony::Delete_Wp::Response &res);
    bool GroupOptionWp(cd_harmony::Groups_Wp::Request &req, cd_harmony::Groups_Wp::Response &res);
    bool WpGroup(cd_harmony::Wp_2_Group::Request &req, cd_harmony::Wp_2_Group::Response &res);
    void onLoop(int state);

protected:
    ros::NodeHandle n;

    //services
    ros::ServiceServer srv_save;
    ros::ServiceServer srv_load;
    ros::ServiceServer srv_run_wp;
    ros::ServiceServer srv_stop_wp;
    ros::ServiceServer srv_delete_wp;
    ros::ServiceServer srv_groups_wp;
    ros::ServiceServer srv_wp_2_group;
    // for save/ load files
    std::string path;

    bool stop;

    //internal variables
    std::map<std::string, cd_harmony::waypoint_msg> wp_map;
    std::map<std::string, cd_harmony::waypoint_group> groups;

    ros::Subscriber sub_wp;
    ros::Subscriber sub_gr;
    ros::Publisher pub_wp;
    ros::Publisher pub_gr;
    ros::Publisher pub_debug;
};

#endif
