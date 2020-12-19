
#ifndef __UTILS_H__
#define __UTILS_H__

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

struct number
{
	int value;
	int turnlastspoken;
};

vector<int> loaddata()
{
	//string s = "0,13,16,17,1,10,6";
	string s = "0,3,6";
	stringstream ss(s);
	vector<int> v;
	while(getline(ss,s,','))
	{
		v.push_back(std::stoi(s));
	}
	return v;
}


void insertionsort(vector<number>& v, number n)
{
	if (v.size() == 0)
	{
		v.push_back(n);
		return;
	}
	for (auto it = v.begin(); it != v.end(); it++)
	{
		if (n.value < it->value)
		{
			v.insert(it--,n);
			return;
		}
	}
	v.push_back(n);
}

int binarysearch(vector<number>& v, int item, int low, int high)
{
	if (high <= low) return item == v[low].value ? low : -1;
	
	int mid = (low+high)/2;

	if (item == v[mid].value) return mid;
	if (item > v[mid].value) return binarysearch(v, item, mid+1, high);
	return binarysearch(v,item,low,mid-1);
}

number createnumber(int value,int turn)
{
	number a;
	a.value = value;
	a.turnlastspoken = turn;
	return a;
}

void printv(vector<number>& v)
{
	for (number n : v) cout << n.value << " ";
	cout << endl;
}

int playturn(vector<number>& v, int turn, int spoken_number)
{
	int size = v.size();
	int idx = binarysearch(v,spoken_number,0,size-1);
	if (idx != -1)
	{
		int turnlastspoken = v[idx].turnlastspoken;
		//cout << "### " << spoken_number << ": " << turn << ": " << turnlastspoken << endl;
		v[idx].turnlastspoken = turn;
		return turn - turnlastspoken;
	}
	else
	{
		number a = createnumber(spoken_number,turn);
		insertionsort(v,a);
		return 0;
	}
}

#endif


