### Date: 95-09-26
### Author: Navid Hoseini

#### Changes till 95-09-24:
* This is not the regular motion editor project. This is a work in progress with the hope of adding time factor to the motion execution of the base code.
* Right now UTAustinVilla base code uses a PID controller to send incremental joint values to the server but it doesn't consider time in computation of increment values.

#### Changes till 95-09-26
* The custom skill `SKILL_MOTION_EDITOR` is defined and integrated to UTAustinVilla skill execution mechanism.
* Method `UpdateKeyframeSequenceEntry` is almost adapted to the new skill execution.

#### Changes till 95-09-27
* The UI font of the motion editor is set as `Fira Mono`
* The UI window size is shrinked so that it will be easier to work with.
* The skill execution mechanism is being modified such that single keyframe can be executed as well as executing all of the keyframes in order. But this part is still incomplete and not working.!!!!

#### Changes till 95-10-01
* It is still a work in progress. Some serious core dump errors have been solved. but there are still some issues about executing the last keyframe!!!!

#### Changes till 95-10-07
* I have changed coefficient `d` of the PID controller in `void BodyModel::initialiseEffectors()`. I have set it to zero so that it won't have any effect on the incremental joint values sent to `rcssserver3d`.
* In `KeyFrame::KeyFrame()` I have set `toWaitTime` and `toWaitTargets` to `true`.

#### Changes till 95-10-14
* I have defined a coefficient named **waitTimeCoeff** in **KeyFrame** class. This coefficient is multiplied to **KeyFrame::waitTime** variable so that the user can set realistic values for the keyframe time variable. But currently this doesn't work well with UTAustinVilla base code; i.e. UTAustinVilla kick.skl file is not executed correctly due to the division of **(targetAngle-CurrentAngle)** by **waitCycles** in **Effector::updateError** method.


#### Changes till 95-10-16### AIUT3D Motion Editor
* I have made some changes on computation of **waitCycles**. Previously, **waitCycles** could have very small values. This may cause instability in robot servos. So I added a minimum value of 0.2 to **waitCycles**. This way **waitCycles** will never be less than 0.2 and it will never cause servo vibration.
* By the way, after fixing the issue mentioned above, I was able to perform a 7 meter kick (without optimization). The kick is completely handmade.

#### Changes till 95-10-17
* I have made some changes to save/open motion file procedure. Now the time of each keyframe will be saved in milliseconds just like the format used by **RoboNewbie** team.

#### Changes till 95-10-23
* I have added the getup capability to the motion editor such that the user can command the robot to get up whenever desired. To do this I use a **if(bGetup && checkingfall())** condition. So when **bGetup** flag is false, **checkingfall** is not called and the robot won't getup.

#### Changes till 95-10-30
* I have made some changes in **selectSkill** method in order to avoid the robot shocking motion when monitor is reset. But the change didn't solve the problem completely.

#### Changes till 95-11-3
* I have added **Auto Fal Recovery** button to the motion editor. If this check box is checked, then the robot will get up automatically in case it falls. But if it is not checked, the user must command the robot to get up manually.

#### Changes till 95-11-11
* I have set **toWaitTargets** to **false** so that the motion editor behavior will be consistent with the base code.

#### Change till 95-12-1
* I have improved jerky player placement when 'Reset Monitor' button is pressed.
* Player position in the motion editor is not the same as the one in UTAustinVilla base code.
* __checkingfall__ needs to be disabled during kick execution.
* Not executing last keyframe of the skill is fixed. To fix this the condition __if(skills[skill]->done( bodyModel, worldModel) || bodyModel->useOmniWalk())__ in naobehavior.cc is modified so that the skill execution mechanism is not reset after executing __SKILL_MOTION_EDITOR__.
* Delete keyframe event handler is changed. Now after deleteing the selected keyframe, always the default keyframe for execution will be the first keyframe.


#### Changes till 96-04-04
* The body type variable (__agentBodyType__) used by motion editor is linked with the body type variable used by UTAustinVilla code. This way I managed to add toe functionality for agent type 4.

#### Changes till 96-05-14
* Thanks to my good friend Daruish Hasanpoor, I finally managed to get the motion editor menu items working on the target machines with no Qt IDE installed. To do this,
* Since the head joints are usually controlled manually in the agent program (at least in UTAustinVilla code), editing head joints are disabled in the motion editor.
