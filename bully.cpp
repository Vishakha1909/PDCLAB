#include <iostream>

using namespace std;
class BullyAlgoExample
{  public:
static int numberOfProcess;
static int priorities[100];
static int status[100];
static int cord;

static void electProcess(int ele);

};
int BullyAlgoExample::numberOfProcess;
int BullyAlgoExample::priorities[100];
int BullyAlgoExample::status[100];
int BullyAlgoExample::cord;
void BullyAlgoExample::electProcess(int ele)
{
ele = ele - 1;
cord = ele + 1;
for(int i = 0; i<numberOfProcess; i++)
        {
    if(priorities[ele]<priorities[i])
            {
cout<<"\nElection message is sent from: "<<(ele+1)<<" to "<<(i+1);
if(status[i]==1)
    electProcess(i+1);
            }
        }
}
int main()
{
    cout<<"Enter total number of processes: ";
    cin>>BullyAlgoExample::numberOfProcess;
    int i;
    for(i = 0; i<BullyAlgoExample::numberOfProcess; i++)
        {
cout<<"Status for process "<<(i+1)<<":";
cin>>BullyAlgoExample::status[i];
cout<<"Priority of process "<<(i+1)<<":";
cin>>BullyAlgoExample::priorities[i];
        }

cout<<"\nEnter process which will initiate election: ";
int ele;
cin>>ele;


        // call electProcess() method
BullyAlgoExample::electProcess(ele);
cout<<"\nAfter electing process the final coordinator is: "<<BullyAlgoExample::cord;


    return 0;
}
