#ifndef _OPTIMIZATION_BEHAVIORS_H
#define _OPTIMIZATION_BEHAVIORS_H

#include "../behaviors/naobehavior.h"

bool isBallMoving(const WorldModel *worldModel);

class OptimizationBehaviorFixedKick: public NaoBehavior
{
    const string outputFile;
    double fitness;             //AI lab 95-4-13 hoseini: used in optimization process

    double timeStart;
    bool hasKicked;
    bool beamChecked;
    bool backwards;
    bool ranIntoBall;
    bool fallen;

    int kick;

    double INIT_WAIT_TIME;

    VecPosition ballInitPos;
    void initKick();
    void writeFitnessToOutputFile(double fitness);

public:

    //AI lab 95-4-13 hoseini start
    inline double GetFitness()
    {
        return fitness;
    }
    //AI lab 95-4-13 hoseini end

    //AI lab 95-4-10 hoseini start
    inline BodyModel* GetBodyModel()
    {
        return bodyModel;
    }
    //AI lab 95-4-10 hoseini end

    OptimizationBehaviorFixedKick(const std::string teamName, int uNum,
    		                      const map<string, string>& namedParams_,
								  const string& rsg_, const string& outputFile_);

    virtual void beam(double& beamX, double& beamY, double& beamAngle);
    virtual SkillType selectSkill();
    virtual void updateFitness();

};

class OptimizationBehaviorWalkForward : public NaoBehavior {
    const string outputFile;

    int run;
    double startTime;
    bool beamChecked;
    double INIT_WAIT;
    double totalWalkDist;

    void init();
    bool checkBeam();

public:

    OptimizationBehaviorWalkForward(const std::string teamName, int uNum, const map<string, string>& namedParams_, const string& rsg_, const string& outputFile_);

    virtual void beam( double& beamX, double& beamY, double& beamAngle );
    virtual SkillType selectSkill();
    virtual void updateFitness();

};

#endif
