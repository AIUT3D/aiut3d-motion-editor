#!/bin/bash

# Choose which optimization task to run
task="kick" # "walk"

# This script runs the simspark soccer simulator and an agent 

# Set the agent and monitor port randomly, to allow for multiple agents per machine
# Note: $RANDOM returns a value from 0 to 32767, ports <= 1024 are reserved for root 
# TODO: Instead of picking random ports purposely bind to available ports
export SPARK_SERVERPORT=3200 #$[$RANDOM + 1025] #3200
export SPARK_AGENTPORT=3100 #$[$RANDOM + 1025] #3100

#echo -n "It is: "
#date
#echo -n "and I am on: "
#hostname
#echo "Agent port: $SPARK_AGENTPORT, Monitor port: $SPARK_SERVERPORT"

rcssserver3d --agent-port $SPARK_AGENTPORT --server-port $SPARK_SERVERPORT >& /dev/pts/15 &
PID=$!

#To view task while it runs uncomment the following line
#<roboviz_start_script> --serverPort=$SPARK_SERVERPORT &








sleep 2  #AI lab hoseini 95-5-12 it was 5





DIR_SCRIPT="$( cd "$( dirname "$0" )" && pwd )" 
TYPE=$1
DIR_PARAMS="$( cd "$( dirname "$2" )" && pwd )"
DIR_OUTPUT="$( cd "$( dirname "$3" )" && pwd )"
PARAMS_FILE=$DIR_PARAMS/$(basename $2)
OUTPUT_FILE=$DIR_OUTPUT/$(basename $3)

rm $OUTPUT_FILE


# TODO: temporary fix!! get rid of it - because relative path dependency of skills
cd $DIR_SCRIPT/..
export LD_LIBRARY_PATH=./libs:$LD_LIBRARY_PATH



if [ $task == "kick" ]
then
    # FixedKick optimization task 
    $DIR_SCRIPT/../agentspark --unum 2 --type $TYPE --paramsfile $DIR_SCRIPT/../paramfiles/defaultParams.txt --paramsfile $DIR_SCRIPT/../paramfiles/defaultParams_t$TYPE.txt --paramsfile $PARAMS_FILE --experimentout $OUTPUT_FILE --optimize fixedKickAgent --port $SPARK_AGENTPORT --mport $SPARK_SERVERPORT &
fi

if [ $task == "walk" ]
then
# WalkForward optimization task
$DIR_SCRIPT/../agentspark --unum 2 --type $TYPE --paramsfile $DIR_SCRIPT/../paramfiles/defaultParams.txt --paramsfile $DIR_SCRIPT/../paramfiles/defaultParams_t$TYPE.txt --paramsfile $PARAMS_FILE --experimentout $OUTPUT_FILE --optimize walkForwardAgent --port $SPARK_AGENTPORT --mport $SPARK_SERVERPORT &
fi

AGENTPID=$!



#sleep 3  #AI lab hoseini 95-5-12 I commented this.






maxWaitTimeSecs=60 #AI lab hoseini 95-5-20 I changed 300 to 60
total_wait_time=0

while [ ! -f $OUTPUT_FILE ] && [ $total_wait_time -lt $maxWaitTimeSecs ]
do 
  sleep 1
  total_wait_time=`expr $total_wait_time + 1`
done 

if [ ! -f $OUTPUT_FILE ]
then
  echo -e "\nTimed out while waiting for script to complete, current wait time is $total_wait_time seconds."
  echo "Timed out while waiting for script to complete, current wait time is $total_wait_time seconds. Process ID: $6, Individual ID: $5, Generation No.: $4" >> $OUTPUT_FILE
else
  #echo -e "\nCompleted with a wait time of $total_wait_time seconds."
  echo "Completed with a wait time of $total_wait_time seconds." >> $OUTPUT_FILE
fi

#echo "Killing Simulator"
kill -s 2 $PID
#echo "Killing Agent"
kill -s 2 $AGENTPID



#sleep 2     #AI lab hoseini 95-5-12 I commented this.




echo -e "\nFinished, Process ID: $6, Individual ID: $5, Generation No.: $4"
