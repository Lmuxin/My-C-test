# include"stdafx.h"
# include<iostream>





class bank
{
    int noOfServer;
    int arrivalLow;
    int arrivalHigh;
    int serviceTimeHigh;
    int customNum;


    struct eventT{
    int time;
    int type;
    bool operator<(const eventT &e)const {
    return time<e.time;
    }
};

public :
    bank();
    void simulate();
    };

    bank::bank(){
    cout<<"�������̨��:";
    cin>>noOfServer;

    cout<<"�����뵽��ʱ�����������ޣ���;
    cin>>arrivalLow>>arrivalHigh;

    cout<<"���������ʱ��������ޣ�";
    cin>>serviceTimeLow>>seriviceHigh;

    cout<<"������ģ��Ĺ˿���Ŀ:";
    cin>>customNum;

    srand(time(NULL));
    }

    void bank::simulate(){
    int serverBusy=0;
    int currentTime=0;
    int totalWaitTime=0;
    int totalServeTime=0;
    int serveTime;
    linkQueue<eventT>waitQueue;
    priorityQueue<eventT>eventQueue;
    eventT currentEvent;


    int i;
    currentEvent.time=0;
    currentEvent.type=0;
    for(i=0;i<customNum;i++){
        currentEvent.time+=arrivalLow+(arrivalHigh-arrivalLow+1)*rand()/(RAND_MAX-1);
        eventQueue.enQueue(currentEvent);
        }
    while(!eventQueue.isEmpty()){
        currentEvent=eventQueue.deQueue();
        currentTime=currentEvent.time;
        switch(currentEvent.type){
    case 0:
        if(serverBusy!=noOfServer){
            ++serverBusy;
            serveTime=serviceTimeLow+(serviceTimeHigh-serviceTimeLow+1)*rand()/(RAND_MAX-1);
            totalServeTime+=serveTime;
            currentEvent.time+=serveTime;
            currentEvent.type=1;
            eventQueue.enQueue(currentEvent);
            }
            else
                waitQueue.enQueue(currentEvent);
            break;
    case 1:
        if(!waitQueue.isEmpty()){


            currentEvent=waitQueue.deQueue();
            totalWaitTime+=currentTime_currentEvent.time;
            serveTime=serviceTimeLow+(serviceTimeHigh-serviceTimeLow+1)*rand()/(RAND_MAX-1);
            totalServeTime+=serveTime;
            currentEvent.time=currentTime+serveTime;
            currentEvent.type=1;
            eventQueue.enQueue(currentEvent);
        }

        else
            --serveBusy;
        break;



        }

    }
    cout<<"�˿�ƽ���ȴ�ʱ�䣺"<<totalWaitTime/customNum<<endl;
    cout<<"����̨ƽ������ʱ�䣺"<<totalServeTime/noOfServer<<endl;



}


























