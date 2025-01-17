# Multi Sensor 3D SLAM

## Project Description
This project involves the use of a multi-sensor system for 3D SLAM (Simultaneous Localization and Mapping) using Agilex Scout Mini in a Gazebo simulation environment. The goal is to create a point cloud map of the environment using various sensors and compare the results based on quality metrics.

### Sensors
1. **3D LiDAR**:
   - 360° horizontal and 30° vertical Field of View (FOV)
   - 0.5° horizontal and vertical resolution
   - 50m range
   - 10Hz refresh rate

2. **RGBD Camera**:
   - 120° FOV
   - 5m depth range
   - 30Hz frame rate

### Objectives
1. Use the **Office Earthquake** Gazebo world for simulation.
2. Create a **Point Cloud Map** of the environment using an algorithm such as Octomap ([octomap ROS Wiki](http://wiki.ros.org/octomap)).
3. Perform SLAM using the following configurations:
   - a) Only RGBD camera-based SLAM
   - b) Only 3D LiDAR-based SLAM
   - c) Both 3D LiDAR and RGBD camera-based SLAM
4. Compare the quality of the generated 3D maps using metrics like:
   - **Point cloud density**
   - **Peak Signal-to-Noise Ratio (PSNR)**
   - **Structural Similarity Index (SSIM)**

---

## How to Run the Simulation

### Step 1: Launch the simulation
```bash
roslaunch scout_gazebo_sim scout_earthquake.launch
```

### Step 2: Control the robot
```bash
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```

### Step 3: Mapping using Octomap Server

#### For RGBD Camera:
```bash
rosrun octomap_server octomap_server_node cloud_in:=/rgbd/depth/points _frame_id:=odom _debug:=true
```

#### For 3D LiDAR:
```bash
rosrun octomap_server octomap_server_node cloud_in:=/lidar/points _frame_id:=odom _debug:=true
```

### Step 4: Save the Point Cloud as PCD File
```bash
rosrun pcl_ros pointcloud_to_pcd input:=/octomap_point_cloud_centers _prefix:="output"
```

### Step 5: Open the PCD File
```bash
pcl_viewer filename.pcd
```

---
