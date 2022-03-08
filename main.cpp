#include <iostream>
using namespace std;
class Process
{

public:
    int ArrivalTime[5],BrustTime[5],ProcessNo[5],WaitingTime[5],N=5,TurnTime;
    float Average;

    Process()
    {
        Memory();
    }

    void Memory();
    void init();
    void Sorting();
    void Print();
    void FinalSorting();
    void WaitTime();
};

void Process::Memory()
{
    for (int i = 0; i < N; ++i) {
        ArrivalTime[i]=0;
    }
    for (int i = 0; i < N; ++i) {
        BrustTime[i]=0;
    }
    for (int i = 0; i < N; ++i) {
        ProcessNo[i]=0;
    }
    for (int i = 0; i < N; ++i) {
        WaitingTime[i]=0;
    }
}

void Process::init() {

    for (int i = 0; i < N; ++i) {
        ProcessNo[i] = i;
    }
    for (int i = 0; i < N; i++) {
        cout << "Enter Arrival Time : ";
        cin >> ArrivalTime[i];
    }
    for (int i = 0; i <=1; i++) {
        cout << "Enter Brust Time : ";
        cin >> BrustTime[i];
        if(i==1)
        {
            for (int j = i; j < N-1; ++j) {
                BrustTime[j+1]=BrustTime[j-1]+BrustTime[j];

            }
        }
    }
}

void Process::Sorting()
{
    int First,Second,B1,B2,P1,P2;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N-1; ++j) {
            if(ArrivalTime[j]>ArrivalTime[i])
            {
                First=ArrivalTime[i];
                B1=BrustTime[i];
                P1=ProcessNo[i];
                Second=ArrivalTime[j];
                B2=BrustTime[j];
                P2=ProcessNo[j];
                ArrivalTime[i]=Second;
                ArrivalTime[j]=First;
                BrustTime[i]=B2;
                BrustTime[j]=B1;
                ProcessNo[i]=P2;
                ProcessNo[j]=P1;
            }
        }

    }
}

void Process::FinalSorting()
{
    int First,Second,B1,B2,P1,P2,W1,W2;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N-1; ++j) {
            if(ProcessNo[j]>ProcessNo[i])
            {
                First=ArrivalTime[i];
                B1=BrustTime[i];
                P1=ProcessNo[i];
                W1=WaitingTime[i];
                Second=ArrivalTime[j];
                B2=BrustTime[j];
                P2=ProcessNo[j];
                W2=WaitingTime[j];
                ArrivalTime[i]=Second;
                ArrivalTime[j]=First;
                BrustTime[i]=B2;
                BrustTime[j]=B1;
                ProcessNo[i]=P2;
                ProcessNo[j]=P1;
                WaitingTime[i]=W2;
                WaitingTime[j]=W1;
            }
        }

    }
}

void Process::WaitTime()
{
    float TotalTime=0,Sum=0;
    for (int i = 0; i < N; ++i) {
        if(i==0)
        {
            WaitingTime[i]=0;
        }
        if(i==1)
        {
            WaitingTime[i]=BrustTime[i-1]-ArrivalTime[i];
            Sum=BrustTime[i-1]+BrustTime[i];

        }
        if(i>1)
        {
            WaitingTime[i]=Sum-ArrivalTime[i];
            Sum=Sum+BrustTime[i];
        }

    }
    for (int i = 0; i < N; ++i) {
        TotalTime=TotalTime+WaitingTime[i];
    }
   TurnTime=(TotalTime+Sum)/N;
    Average=TotalTime/N;
}

void Process::Print()
{
    cout<<endl;
    cout<<"ProcessNo"<<"      "<<"ArrivalTime"<<"   "<<"BrustTime"<<"    "<<"WaitingTime"<<endl;
    for (int i = 0; i <N; ++i) {
        cout<<"   "<<ProcessNo[i]<<"              "<<ArrivalTime[i]<<"              "<<BrustTime[i]<<"         "<<WaitingTime[i];
        cout<<endl;

    }
    cout<<"Average Time is : "<<Average<<endl;
    cout<<"Turnaround Time is : "<<TurnTime<<endl;
}

int main() {
    Process P;
    P.init();
    P.Sorting();
    P.WaitTime();
    P.FinalSorting();
    P.Print();
    return 0;
}