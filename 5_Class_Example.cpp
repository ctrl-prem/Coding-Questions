// class example

#include <bits/stdc++.h> 
#include<iostream>

#include<algorithm>

using namespace std;

class Fraction {

    // Complete the class
    public:
    int Num;
    int Den;
    Fraction(int n, int d){
        Num=n;
        Den=d;
    }
    void add(Fraction a){
        Num=(Num*a.Den)+(a.Num*Den);
        Den=Den*a.Den;
    }
    void multiply(Fraction a){
        Num=Num*a.Num;
        Den=Den*a.Den;
    }
    int gcd(int a, int b){
        if (b == 0)
            return a;
        return gcd(b, a % b); 
    }
    void simplify(){
        int h=gcd(Num, Den);
        Num=Num/h;
        Den/=h;
    }
    void print(){
        // cout<<"Hello"<<endl;
        cout<<Num<<"/"<<Den<<endl;
    }

};

int main() {

    //Write your code here
    int a, b;
    cin>>a>>b;
    Fraction f1(a, b);
    int q;
    
    cin>>q;
    while(q>0){
        int choice, c, d;
        cin>>choice>>c>>d;
        Fraction f2(c, d);
        if(choice==1){
            f1.add(f2);
            f1.simplify();
            f1.print();
        }
        else if(choice==2){
            f1.multiply(f2);
            f1.simplify();
            f1.print();
        }
        q--;
    }
    return 0;
}