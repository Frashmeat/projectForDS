#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Point {
public:
	~Point() {

	};
	Point(int val, vector<Point*> points) :val(val), connectedPoints(points) {};

	Point(int val, initializer_list<Point*> points) {
		this->val = val;
		connectedPoints = points;
	};
	Point(int val) :val(val) {};
	void addConnect(vector<Point*> points);
	void addConnect(initializer_list<Point*> points);
	void addConnectedPoint(Point* p);
	Point* getConnectedPoint() {
		return this->connectedPoints[0];
	};
	Point* getNextPoint() {
		if (index >= connectedPoints.size()) {
			index = 0;
			return this->connectedPoints[index];
		}
		else {
			return this->connectedPoints[index];
		}
	}
	void printConnection() {
		for (Point* p : connectedPoints) {
			cout << p->val << endl;
		}
	};
	int val;
	vector<Point*> connectedPoints;
	bool isVisited = false;
	int index;
};
class Map
{
public:
	Map(Point* p) {
		map.push_back(p);
	};
	~Map() {

	};
	void addPoint(Point* p) {
		map.push_back(p);
	};
	/*void addPoint(int val)
	{
		Point* p = new Point(val);
		map.push_back(p);
	}*/
	void deletePoint(int val) {
		map.erase(remove_if(map.begin(), map.end(), [=](Point* p) {
			return p->val == val;
			}), map.end());
	};
	Point* DFSbyVal(int val);
	Point* BFSbyVal(int val);
	void DFSPrint();
	void BFSPrint();
	void loadOrder();
	vector<Point*> load;
private:
	void DFSP(Point* p);
	void BFSP();
	void DFSL(Point* p);
	Point* DFS(Point* p, int val);
	Point* BFS(int val);
	void makePointsUnvisited() {
		for (Point* p: map) {
			p->isVisited = false;
		}
	}
	vector<Point*> map;
};

