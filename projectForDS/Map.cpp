#include "Map.h"

void Point::addConnect(vector<Point*> points)
{
	for (Point* p : points) {
		this->connectedPoints.push_back(p);
	}
}

void Point::addConnect(initializer_list<Point*> points)
{
	for (Point* p : points) {
		this->connectedPoints.push_back(p);
	}

}

void Point::addConnectedPoint(Point* p)
{
	this->connectedPoints.push_back(p);

}

Point* Map::DFSbyVal(int val)
{
	makePointsUnvisited();
	return DFS(map.front(), val);;
}

Point* Map::BFSbyVal(int val)
{	
	makePointsUnvisited();
	return BFS(val);
}

void Map::DFSPrint()
{
	makePointsUnvisited();
	DFSP(map.front());
}

void Map::BFSPrint()
{
	makePointsUnvisited();
	BFSP();
}

void Map::loadOrder()
{
	makePointsUnvisited();
	load.clear();
	DFSL(map.front());
	for (int i = load.size() - 1; i >= 0; i--) {
		cout << load[i]->val << " ";
	}
	cout << '\n';
}



void Map::DFSP(Point* p)
{
	if (p->isVisited) return;
	p->isVisited = true;
	cout << p->val << endl;
	for (Point* connectedP : p->connectedPoints) {
		DFSP(connectedP);
	}
	return;
}

void Map::BFSP()
{
	queue<Point*> temp;
	temp.push(map.front());
	while (!temp.empty()) {
		Point* tp = temp.front();
		temp.pop();
		cout << tp->val << endl;
		tp->isVisited = true;
		for (Point* p : tp->connectedPoints) {
			if (p->isVisited == false);
			temp.push(p);
		}
	}
	return;
}

void Map::DFSL(Point* p)
{
	if (p->isVisited) return;
	p->isVisited = true;
	load.push_back(p);
	for (Point* connectedP : p->connectedPoints) {
		DFSL(connectedP);
	}
	return;
}

Point* Map::DFS(Point* p, int val)
{
		if (p->isVisited) return nullptr;
		p->isVisited = true; 
		if (p->val == val) return p;
		for (Point* connectedP : p->connectedPoints) {
			auto res = DFS(connectedP, val);
			if (res) return res;
		}
		return nullptr;
}

Point* Map::BFS(int val)
{
	queue<Point*> temp;
	temp.push(map.front());
	while (!temp.empty()) {
		Point* tp = temp.front();
		temp.pop();
		if (tp->val == val) return tp;
		tp->isVisited = true;
		for (Point* p : tp->connectedPoints) {
			if (p->isVisited == false);
			temp.push(p);
		}
	}
	return nullptr;
}
