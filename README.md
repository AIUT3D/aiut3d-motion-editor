### AIUT3D Motion Editor

* This repository is a motion editor for RoboCup 3D soccer simulation developed by AIUT3D team. It is based on UT Austin Villa base code:
__https://github.com/LARG/utaustinvilla3d__.

* The motion editor can be used to design arbitrary key frame based motions for simulated Nao robot.

* It is developed in the hope of being useful for RoboCup 3D soccer simulation teams.

#### Build Requirements
* Tested on Ubuntu 14.04 LTS and 16.04 LTS
* Please install simspark and rcssserver3d according to http://simspark.sourceforge.net/wiki/index.php/Installation_on_Linux#Ubuntu.
* Please install qt5-default package:

`sudo apt-get install qt5-default`
* Please install RoboViz available at https://github.com/magmaOffenburg/RoboViz
#### Build
* cd to the motion editor root directory.
* Run the following commands in the terminal:

`cmake .`

`make`
#### Run
* Start rcssserver3d
* Run Roboviz
* Run the following command in the terminal:

`./motionEditor`
* Set Nao body type
* Reset Monitor by clicking
![reset button](./icon32x32/reset-icon32x32.png)
on the motion editor window. It is recommended to perform reset twice so that the robot beam will be done correctly.
* Now you can start your motion design.
* To add new keyframe to the list of keyframes, click
![add key frame button](./icon32x32/add-icon32x32.png) button.
* To remove a keyframe, select it from keyframes list and then click
![delete key frame button](./icon32x32/Close-2-icon32x32.png)
* To edit/play a single keyframe, just select it from the keyframes list by clicking it. After being selected, the keyframe effect can be observed via RoboViz. Moreover, you can edit the joint values for the selected keyframe.
* You can also play the keyframes successively from the beginning to the end by clicking
![play button](./icon32x32/play-icon-32x32.png)
* Buttons
![arrow up button](./icon32x32/Arrows-Up-icon32x32.png)
and
![arrow down button](./icon32x32/Arrows-Down-icon32x32.png)
are supposed to move a keyframe up or down in the keyframes list. But this feature is not implemented yet. So pressing these two button has no effect for now.
* In case of a fall, you can instruct the robot to get up by clicking
<img src="./icon32x32/getup512x512.png" width="32"> button.
* `Auto Fall Recovery` checkbox specifies whether the robot should get up automatically in case of a fall or not. Please note that if the designed motion causes the accelerometer values on x or y axis to increase more than 6.5m/s^2, a fall will be detected by UTAustinVilla base code which means the designed motion execution will be aborted. So a word of advice is to keep `Auto Fall Recovery` off if you want to design unstable motions such as long range kicks.
* Please note that the motion editor only works when the rcssserver3d play mode is `PlayOn`. So if the play mode is something different, it must be set to `PlayOn` manually via RoboViz.
#### Motion file format
* The created motions will be saved in a text file. Each line of the file will represent the joint values (in degrees) for one keyframe and . The order of the saved values for one keyframe (one line of motion file) are as follows:
* t     // Keyframe execution time (milliseconds)
* he1   // Head yaw
* he2   // Head pitch
* lae1  // Left shoulder pitch
* lae2  // Left shoulder roll
* lae3  // Left elbow yaw
* lae4  // Left elbow roll
* lle1  // Left hip yaw-pitch
* lle2  // Left hip roll
* lle3  // Left hip pitch
* lle4  // Left knee pitch
* lle5  // Left ankle pitch
* lle6  // Left ankle roll
* rle1  // Right hip yaw-pitch
* rle2  // Right hip roll
* rle3  // Right hip pitch
* rle4  // Right knee pitch
* rle5  // Right ankle pitch
* rle6  // Right ankle roll
* rae1  // Right shoulder pitch
* rae2  // Right shoulder roll
* rae3  // Right elbow yaw
* rae4  // Right elbow roll
* lle7  // Left toe pitch
* rle7  // Right toe pitch

#### Sample kick motion
* A sample kick motion for Nao type 0 is availabe in `createdKicks` folder. After setting body type, the sample kick can be loaded by Ctrl+o shortcut or using `file` menu.
