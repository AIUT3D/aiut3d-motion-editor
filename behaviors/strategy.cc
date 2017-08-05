#include "naobehavior.h"
#include "../rvdraw/rvdraw.h"

extern int agentBodyType;

//AI lab Hoseini 95-07-02 start
///the method below is modified to be used in motion editor project
void NaoBehavior::beam( double& beamX, double& beamY, double& beamAngle )
{
//    kick_xoffset	-0.18758631052473101
//    kick_yoffset	-0.08133614974057074
    beamX = -0.18758631052473101; //- 0.19;
    beamY = -0.025;//-0.055;
    beamAngle = 0;
}
//AI lab Hoseini 95-07-02 end


SkillType NaoBehavior::selectSkill()
{
    static double start = 0.0;
    if(worldModel->getPlayMode() == PM_BEFORE_KICK_OFF)
    {
        start = worldModel->getTime();
    }
    double current = worldModel->getTime();

    if(worldModel->getPlayMode() == PM_PLAY_ON &&
       current - start > beamTime && skills[SKILL_MOTION_EDITOR]->getNumberOfKeyframes() > 0)
    {
        return SKILL_MOTION_EDITOR;
    }
    return SKILL_STAND;
}
