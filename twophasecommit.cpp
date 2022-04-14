#include<iostream>

using namespace std;


int main()
{
    int num_nodes,c_index;
    cout<<"Enter the number of nodes: ";
    cin>>num_nodes;
    cout<<"\nEnter the index of the coordinator node: ";
    cin>>c_index;
    cout<<"The coordinator node S"<<c_index<<" sends request to all the nodes...";
    int ones = 0,zeros = 0,temp;
    for(int i = 0 ; i < num_nodes ; i++) {
        if(i == c_index) {
            continue;
        }
        cout<<"\nEnter the value returned by node "<<i<<": ";
        cin>>temp;
        if(temp == 1) {
            ones++;
        }
        else
            zeros++;
    }
    cout<<"\nThe final decision messages from coordinator node "<<c_index<<" ->\n";
    if(ones > zeros) {
        for(int i = 0 ; i < num_nodes ; i++) {
            if(i == c_index)
                continue;
            cout<<"Node "<<i<<" : COMMIT\n";
        }
    }
    else {
        for(int i = 0 ; i < num_nodes ; i++) {
            if(i == c_index)
                continue;
            cout<<"Node "<<i<<" : ABORT\n";
        }
    }
}
