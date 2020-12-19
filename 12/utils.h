
#ifndef __UTILS_H__
#define __UTILS_H__


#include <exception>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct instruct
{
	char action;
	int value;
};

struct nav
{
	std::pair<int,int> xy;
	int degree;
};

instruct parse(std::string s)
{
	instruct ins;
	ins.action = s[0];
	ins.value = std::stoi(s.substr(1));
	return ins;
}

vector<instruct> loaddata()
{
	ifstream ifile("./input.txt");
	string line;
	vector<instruct> holder;
	while (getline(ifile,line)) holder.push_back(parse(line));
	return holder;
}

void moveForward(nav& navigate, int value)
{
	switch (abs(navigate.degree))
	{
		case 0:
			navigate.xy.second += value;
			break;
		case 90:
			navigate.xy.first += value;
			break;
		case 180:
			navigate.xy.second -= value;
			break;
		case 270:
			navigate.xy.first -= value;
			break;
	};
}

void moveDegree(nav& navigate, const instruct& ins)
{
	int n = ins.value / 90;
	int dir = ins.action == 'R' ? 1 : -1;
	while (n != 0)
	{
		if (navigate.degree == 360 && ins.action == 'R') navigate.degree = 0;
		if (navigate.degree == 0 && ins.action == 'L') navigate.degree = 360;
		navigate.degree = (navigate.degree + dir*90);
		n--;
	}
	navigate.degree %= 360;
}


void moveDir(nav& navigate, const instruct& ins)
{
	switch (ins.action)
	{
		case 'N':
			navigate.xy.second += ins.value;
			break;
		case 'E':
			navigate.xy.first += ins.value;
			break;
		case 'S':
			navigate.xy.second -= ins.value;
			break;
		case 'W':
			navigate.xy.first -= ins.value;
			break;
	};
}

void move(nav& navigate, const instruct& ins)
{
	if (ins.action == 'F') moveForward(navigate, ins.value);
	else if (ins.action == 'R' || ins.action == 'L') moveDegree(navigate,ins);
	else moveDir(navigate, ins); 
}


int navigate(vector<instruct>& v)
{
	nav navigate;
	navigate.degree = 90;
	navigate.xy.first = 0;
	navigate.xy.second = 0;
	
	for (auto ins : v)
	{
		move(navigate,ins);
	}
	
	return abs(navigate.xy.first) + abs(navigate.xy.second);
}


void moveShip(nav& ship, nav& waypoint, const instruct& ins)
{
	ship.xy.first += waypoint.xy.first*ins.value;
	ship.xy.second += waypoint.xy.second*ins.value;
}

void rotateWaypoint(nav& waypoint, const instruct& ins)
{
	moveDegree(waypoint,ins);

	switch (waypoint.degree)
	{
		case 0:
			std::swap(waypoint.xy.first,waypoint.xy.second);
			waypoint.xy.first *= -1;
			break;
		case 90:
			break;
		case 180:
			std::swap(waypoint.xy.second,waypoint.xy.first);
			waypoint.xy.second *= -1;
			break;
		case 270:
			waypoint.xy.first = -(waypoint.xy.first);
			waypoint.xy.second = -(waypoint.xy.second);
			break;
	};

	waypoint.degree = 90;
}

void move2(nav& ship, nav& waypoint, const instruct& ins)
{
	if (ins.action == 'F') moveShip(ship,waypoint,ins);
	else if (ins.action == 'R' || ins.action == 'L') rotateWaypoint(waypoint,ins);
	else moveDir(waypoint, ins); 
}

int navigate2(vector<instruct>& v)
{
	nav ship;
	ship.degree = 90;
	ship.xy.first = 0;
	ship.xy.second = 0;

	nav waypoint;
	waypoint.degree = 90;
	waypoint.xy.first = 10;
	waypoint.xy.second = 1;
	
	for (auto ins : v)
	{
		move2(ship, waypoint, ins);
		std::cout <<  "ins: " << ins.action << ins.value << endl;
		std::cout << "(x,y) = " << waypoint.xy.first << "," << waypoint.xy.second;
		std::cout << "\t(x,y) = " << ship.xy.first << "," << ship.xy.second << endl;
	}
	
	return abs(ship.xy.first) + abs(ship.xy.second);
}


#endif

