from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            executable='turtlesim_node',
            package='turtlesim',
            name='turtle1'
        ),
        Node(
            executable='mimic',
            package='turtlesim',
            name='turtle2'
        ),
    ])

