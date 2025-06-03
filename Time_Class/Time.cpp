#include <iostream>
using namespace std;

// Time class -------------------------------------------
class Time{
    int hr;
    int min;
    int sec;
public:
    Time(int h = 0 , int m = 0 , int s = 0 ){ //copy constructor
       hr = h;
       min = m;
       sec = s;
    }
    // functions declaration-----------------------------
    friend istream & operator>>(istream &is,Time &t);
    friend ostream & operator<<(ostream &os,Time &t);
    friend Time operator+(Time &t1, Time &t2);
    friend Time operator-(Time &t1, Time &t2);
};
// input fuction definition-------------------------------
istream & operator>>(istream &is,Time &t){
    cout<<"Enter hour : ";
    is>>t.hr;
    cout<<"Enter minute : ";
    is>>t.min;
    cout<<"Enter second : ";
    is>>t.sec;
    return is;
}
// output function definition-----------------------------
ostream & operator<<(ostream &os,Time &t){
    os<<t.hr<<":"<<t.min<<":"<<t.sec<<endl;
    return os;
}
// Add time function definition---------------------------
Time operator+(Time &t1, Time &t2){
    Time t;
    int total_sec = (t1.hr + t2.hr) * 3600 + (t1.min + t2.min) * 60 + (t1.sec + t2.sec);
    t.hr = total_sec/3600;
    t.min = (total_sec%3600)/60;
    t.sec = (total_sec%3600)%60;
    return t;
}
//Duration between time function definition-----------------
Time operator-(Time &t1, Time &t2){
    Time t;
    int t1_sec = (t1.hr * 3600) + (t1.min * 60) + t1.sec;
    int t2_sec = (t2.hr * 3600) + (t2.min * 60) + t2.sec;
    int duration;
    if(t1_sec > t2_sec){
        duration = t1_sec - t2_sec;
    }
    else{
        duration = t2_sec - t1_sec;
    }
    t.hr = duration/3600;
    t.min = (duration%3600)/60;
    t.sec = (duration%3600)%60;
    return t;
}
// main function-----------------------------------------------
int main(){

    Time t1,t2,t3;
    cout<<"Enter start time: \n";
    cin>>t1;
    cout<<"Enter End time : \n";
    cin>>t2;
    t3 = t1+t2;
    cout<<"Addition of time : "<<t3<<endl;
    t3 = t1-t2;
    cout<<"Duration between time : "<<t3<<endl;

    return 0;
}