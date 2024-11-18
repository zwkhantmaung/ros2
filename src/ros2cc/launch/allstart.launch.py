from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            executable='turtlesim_node',
            package='turtlesim',
            name='turtlesim',
            output='screen',
            emulate_tty=True,
        ),
        Node(
            executable='turtle_teleop_key',
            package='turtlesim',
            name='teleop_turtle',
            output='screen',
            prefix=['gnome-terminal --'],
        ),
        # Node(
        #     executable='mimic',
        #     package='turtlesim',
        #     name='turtle2'
        # ),
        # Node(
        #     executable='talker_int32',
        #     package='ros2cc',
        #     name='talker_int32'
        # ),
        # Node(
        #     executable='listener_int32',
        #     package='ros2cc',
        #     name='listener_int32'
        # ),
        # Node(
        #     executable='talker_str',
        #     package='ros2cc',
        #     name='talker_str'
        # ),
        # Node(
        #     executable='listener_str',
        #     package='ros2cc',
        #     name='listener_str'
        # ),
    ])

