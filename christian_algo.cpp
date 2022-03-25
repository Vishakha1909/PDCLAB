#include<iostream>

using namespace std;

string ampm(string a, int c) {
    if(c >= 12) {
        if(a == "AM") {
            a = "PM";
        }
        else
            a = "AM";
    }
    return a;
}

int calc_seconds(float rtt){
    int sec = 0;
    float div = rtt/2;
    sec = (div - int(div)) * 60;
    return sec;
}

int calc_min(float rtt, int server_min) {
    int add_min = rtt/2;
    int minutes = server_min + add_min;
    return minutes;
}

int calc_hour(int client_min,int server_hour) {
    int client_hour = server_hour;
    if(client_min > 60) {
        client_hour += 1;
        client_min = client_min - 60;
    }
    return client_hour;
}

int main() {
    int server_hour,server_min;
    float rtt;
    cout<<"Enter the hour returned by the server: ";
    cin>>server_hour;
    cout<<"Enter the minute returned by the server: ";
    cin>>server_min;
    cout<<"Enter the round trip time in minutes: ";
    cin>>rtt;
    string ap;
    cout<<"Is the time in AM/PM? : ";
    cin>>ap;

    int seconds = calc_seconds(rtt);
    int client_min = calc_min(rtt,server_min);
    int client_hour = calc_hour(client_min,server_hour);
    ap = ampm(ap,client_hour);

    cout<<"\nThe final time is: "<<client_hour<<":"<<client_min<<":"<<seconds<<" "<<ap<<"\n";
}
