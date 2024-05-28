#ifndef WAYPOINTPANEL_H
#define WAYPOINTPANEL_H

#include <ros/ros.h>

#include <rviz/panel.h>
#include <QWidget>
#include <geometry_msgs/PoseArray.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>
#include "cd_harmony/waypoint_msg.h"
#include "cd_harmony/waypoint_group.h"
#include "cd_harmony/waypoint_array.h"




#include <QStringListModel>
#include <map>
#include <list>
namespace Ui
{
    class waypointPanel;
}
namespace waypoints
{

    class waypointPanel : public rviz::Panel
    {
        Q_OBJECT

    public:
        explicit waypointPanel(QWidget *parent = 0);
        virtual ~waypointPanel();
        void Callback(cd_harmony::waypoint_array wp_msg);
        void PublishWp();
        Ui::waypointPanel *ui;

    protected Q_SLOTS:
        void onDeleteWaypoint();
        void onNewGroup();
        void onAdd2Group();
        void onDelete2Group();
        void onRunGroup();
        void onStopGroup();
        void onGroupBox(const QString &group);
        void onLoop(int state);
        void onSaveFile();
        void onLoadFile();
        void publishPath(const std::string group);

    private:
        ros::NodeHandle n;
        ros::Subscriber sub;
        ros::Publisher pub_rviz;
        ros::Publisher pub_path;

        std::map<std::string, cd_harmony::waypoint_msg> wp_map;
        std::map<std::string, cd_harmony::waypoint_group> groups;
        std::string textGroupBox = "";
    };

} // end namespace waypoints

#endif // WAIPOINTPANEL_H
