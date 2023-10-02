#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main(){
	vector<pair<int, int> > vect;
	vect.push_back(make_pair(1, 2));
	vect.push_back(make_pair(1, 3));
	auto it = find(vect.begin(), vect.end(), make_pair(1, 3));
	cout<<it-vect.begin()<<endl;
	string s = "";
	s = s+"{" + to_string(1) + "-" + to_string(2) + "}";
	cout<<s<<endl;
	return 0;
}