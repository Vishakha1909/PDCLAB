#include<iostream>

using namespace std;

int main()
{
    int n,i;
    cout<<"Enter the number of nodes n : ";
    cin>>n;
    int c_node;
    int server_hour[n],server_min[n],server_seconds[n];
    int client_hour[n],client_min[n],client_seconds[n];
    cout<<"Which node is the coordinator node? [0,..,n-1] : ";
    cin>>c_node;
    int avg_hour, avg_min, avg_sec;
    int sum_hour = 0, sum_min = 0, sum_sec = 0;
    for(i = 0 ; i < n ; i++) {
            cout<<"Enter the hour returned by the node "<<i+1<<" : ";
            cin>>server_hour[i];
            sum_hour += server_hour[i];
            cout<<"Enter the minute returned by the node: "<<i+1<<" : ";
            cin>>server_min[i];
            sum_min += server_min[i];
            cout<<"Enter the seconds returned by the node: "<<i+1<<" : ";
            cin>>server_seconds[i];
            sum_sec += server_seconds[i];
            cout<<"\n";
    }
    avg_hour = sum_hour/n;
    avg_min = sum_min/n;
    avg_sec = sum_sec/n;
    cout<<"The average time is : "<<avg_hour<<":"<<avg_min<<":"<<avg_sec<<"\n";
    int diff_hour[n], diff_min[n], diff_sec[n];
    for(i = 0 ; i < n ; i++) {
        diff_sec[i] = avg_sec - server_seconds[i];
        diff_min[i] = avg_min - server_min[i];
        diff_hour[i] = avg_hour - server_hour[i];
    }
    for(i = 0 ; i < n ; i++) {
        cout<<"The time to be adjusted for node "<<i+1<<" is : "<<diff_hour[i]<<":"<<diff_min[i]<<":"<<diff_sec[i]<<"\n";
    }
}
