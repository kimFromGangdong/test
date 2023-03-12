/*

#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

class Car
{
private:
    int inTime;
    string number;
    string inOut;
    int totalFee = 0;
    int innOut;
    int totalTime;
public:
    Car(string carTime, string carNumber, string carInOut)
        :number(carNumber),inOut(carInOut)
        {
            inTime = stringToTime(carTime);
        }
    //차 번호를 return한다
    //1. 차를 out할때
    //2. 차의 inout을 판별할때 사용
    string returnString()
    {

        return number;
        
    }
    int gimmeString()
    {
 
        return stoi(number);
        
    }
    int stringToTime(string rawTime)
    {
        //시각을 분으로 치환해준다
        int originalTime;
        originalTime = stoi(rawTime.substr(0,2))*60+stoi(rawTime.substr(3,2));

        return originalTime;
        
    }   
    void resetIntime(string rawTime)
    {
        inTime = stringToTime(rawTime);

    }
    void in()
    {

        innOut = 0;
        //out = 1
        //in = 0
    }
    void out()
    {
        innOut = 1;

    }
    int inOut2()
    {
        return innOut;
        
    }
    
    void totaltime(string thisTime)
    {
        int newtime = stringToTime(thisTime);
        totalTime = totalTime+ newtime-inTime;

    }
    int showtime()
    {
  
        return totalTime;
        
    }
    void totalMoney(int baseMin,int baseFee,int singleMin,int singleFee)
    {
        if (this->showtime()<=baseMin){
            totalFee = baseFee;
        }
        else{
        totalFee = baseFee+(int)ceil((float)(this->showtime()-baseMin)/(float)singleMin)*singleFee;
        }

    }
    int showFee()
    {

        return totalFee;
        
    }
};

Car * carArr [1100];
int carNum = 0;

vector<int> solution(vector<int> fees, vector<string> records) {
    int baseMin = fees[0];
    int baseFee = fees[1];
    int singleMin = fees[2];
    int singleFee = fees[3];
    int k=1;
    string lastTime = "23:59";
    for(string &record :records)
    {
        if(record.substr(11,2)=="OU")
        {
            for(int i=0;i<carNum;i++)
            {
                if(carArr[i]->returnString()==record.substr(6,4))
                {
                    carArr[i]->totaltime(record.substr(0,5));
                    carArr[i]->out();
                }
            }
            
        }
        else
        {
            if(carNum == 0){
                carArr[0] = new Car(record.substr(0,5),record.substr(6,4),record.substr(11,2));
                carNum++;
                carArr[0]->in();
            }
            else
            {
                int onOff = 0;
                int carIsHere = 0;
                for(int i=0;i<carNum;i++)
                {
                    if(carArr[i]->returnString()==record.substr(6,4))
                    {
                        onOff = 1;
                        carIsHere = i;
                    }
                }
                
                if(onOff == 1)
                { 
                    carArr[carIsHere]->resetIntime(record.substr(0,5));
                    carArr[carIsHere]->in();
                }
                else
                {
                    carArr[carNum] = new Car(record.substr(0,5),record.substr(6,4),record.substr(11,2));
                    carArr[carNum]->in();
                    carNum++;
                }
                
            }
            
            
        }
    }
    for(int i=0;i<carNum;i++){
        if(carArr[i]->inOut2()==0)
        {
            carArr[i]->totaltime(lastTime);
        }
    }
    for(int i=0;i<carNum;i++)
    {
        carArr[i]->totalMoney(baseMin,baseFee,singleMin,singleFee);
    }
    vector<int> answer;
    for(int i = 0; i<carNum;i++)
    {
        answer.emplace_back(carArr[i]->gimmeString());
    }
    sort(answer.begin(), answer.end());
    for(int k=0;k<answer.size();k++)
    {
        for(int i = 0; i<carNum;i++)
        {
            if(carArr[i]->gimmeString()==answer[k])
            {
                answer[k] = carArr[i]->showFee();
            }
        }
    }
    
    return answer;
}
*/