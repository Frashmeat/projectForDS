#include<iostream>
#include<functional>
#include"PageView.h"
#include"MyStack.h"
#include"LRU.h"
#include"MyListQueue.h"
#include"TimerManager.h"
#include"AbsBinaryTree.cpp"
#include"CharMatche.h"
#include"Map.h"
using namespace std;

void App1Window() {
	cout << "1.创建" << endl;
	cout << "2.插入" << endl;
	cout << "3.删除" << endl;
	cout << "4.查找" << endl;
	cout << "5.应用" << endl;
	cout << "6.退出" << endl;
}
void funcApp1() {
	int index;
	LRU* lru = new LRU(3);
	ChainList* cl = new ChainList();
	chainList::Node n1(1);
	chainList::Node n2(2);
	chainList::Node n3(3);
	chainList::Node* ans;
	App1Window();
	while (cin>>index) {
		if (index == 6) break;
		
		switch (index)
		{
		case 1:
			cout << "1.创建" << endl;
			break;
		case 2:
			cout << "2.插入" << endl;
			cl->insertBack(&n1);
			cl->insertBack(&n2);
			cl->insertBack(&n3);
			cl->print();
			break;
		case 3:
			cout << "3.删除" << endl;
			cl->pop();
			cl->print();
			break;
		case 4:
			cout << "4.查找" << endl;
			ans = cl->getNode(1);
			cout << ans->val << endl;
			break;
		case 5:
			cout << "5.应用" << endl;
			lru->save(1);
			lru->save(2);
			lru->save(3);
			lru->print();
			lru->save(4);
			lru->print();
			lru->get(2);
			lru->print();
			break;
		default:
			cout << "重新输入" << endl;
			break;
		}
		App1Window();

	}

	delete cl;
	delete lru;
};

void App2Window() {
	cout << "1.进栈" << endl;
	cout << "2.出栈" << endl;
	cout << "3.栈顶" << endl;
	cout << "4.应用" << endl;
	cout << "5.退出" << endl;
}
void funcApp2() {
	MyStack<int> ms;
	PageView pv;
	int index;
	App2Window();
	while (cin >> index) {
		if (index == 5) break;
		switch (index)
		{
		case 1:
			ms.push(1);
			ms.push(2);
			ms.push(3);
			ms.print();
			break;
		case 2:
			ms.pop();
			ms.pop();
			//ms.pop();
			ms.print();
			break;
		case 3:
			cout << ms.GetTop() << endl;
			break;
		case 4:
			pv.save("www.a.com");
			pv.save("www.b.com");
			pv.save("www.c.com");
			cout << pv.rightPage.Url << endl;
			cout << pv.back().Url << endl;
			cout << pv.rightPage.Url << endl;
			break;
		default:
			break;
		}
		App2Window();
	}
};

void App3Window() {
	cout << "1.入列" << endl;
	cout << "2.出列" << endl;
	cout << "3.队头" << endl;
	cout << "4.队尾" << endl;
	cout << "5.应用" << endl;
	cout << "6.退出" << endl;

}
void test() {
	cout << "func done test " << " time : 3000 ";
}
void test2() {
	cout << "func done test " << " time : 5000 ";
}
void test3() {
	cout << "func done test " << " time : 7500 ";
}
void funcApp3() {
	int index;
	MyListQueue<int> mlq;
	TimerManager tm;
	App3Window();
	while (cin >> index) {
		if (index == 6) break;
		switch (index)
		{
		case 1:
			mlq.push(1);
			mlq.push(2);
			mlq.push(3);
			mlq.print();
			break;
		case 2:
			mlq.poll();
			mlq.print();
			break;
		case 3:
			cout<<mlq.GetFront()<<endl;
			break;
		case 4:
			cout << mlq.end->val << endl;
			break;
		case 5:
			tm.commit(test, 3000);
			tm.commit(test2, 5000);
			tm.commit(test3, 7500);
			tm.start();
			cout << endl;
			break;
		default:
			break;
		}
		App3Window();
	}
};

void App4Window() {
	cout << "1.创建" << endl;
	cout << "2.遍历" << endl;
	cout << "3.双亲" << endl;
	cout << "4.兄弟" << endl;
	cout << "5.孩子" << endl;
	cout << "6.应用" << endl;
	cout << "7.退出" << endl;
}
void funcApp4() {
	int index;
	AbsBinaryTree<int> abt;
	BinaryTreeNode<int> bt(3);
	BinaryTreeNode<int> bh(2);
	BinaryTreeNode<int> b(1);
	
	CharMatche cm;
	vector<string> ans;
	App4Window();
	while (cin >> index) {
		if (index == 7) break;
		switch (index)
		{
		case 1:
			abt.InitTree();
			break;
		case 2:
			abt.getHead()->PreOrder(abt.getHead());
			cout << "\n";
			abt.getHead()->InOrder(abt.getHead());
			cout << "\n";
			abt.getHead()->postOrder(abt.getHead());
			cout << "\n";
			break;
		case 3:
			cout<<abt.findParent(&bh)->val<<endl;
			//cout << abt.findParent(&bh)->val << endl;
			if (abt.findParent(&b) != nullptr) {
				cout << abt.findParent(&b)->val << endl;
			}
			break;
		case 4:
			cout << abt.findBrother(&bt)->val << endl;
			break;
		case 5:
			cout << abt.findLeftChildren(&bh)->val << endl;
			//cout << abt.findRightChildren(&bh)->val << endl;
			break;
		case 6:
			cm.save("test1word");
			cm.save("test2word");
			cm.save("test3word");
			cm.save("tast3word");
			cm.save("taet3word");

			ans = cm.find("test");

			for (string& temp : ans) {
				cout << temp << " ";
			}
			cout << '\n';
			break;
		default:
			break;
		}
		App4Window();
	}
};
//

void App5Window() {
	cout << "1.创建" << endl;
	cout << "2.dfs" << endl;
	cout << "3.bfs" << endl;
	cout << "4.第一个邻接点" << endl;
	cout << "5.下一个邻接点" << endl;
	cout << "6.应用" << endl;
	cout << "7.退出" << endl;
}
void func5() {
	Point p1(1);
	Point p2(2);
	Point p3(3);

	cout << "文件1 -> 文件2" <<'\n';
	cout << "文件1 -> 文件3" <<'\n';
	p1.addConnect({ &p2,&p3 });
	cout << "文件2 -> 文件3" <<'\n';
	p2.addConnectedPoint(&p3);

	Map m(&p1);
	m.addPoint(&p2);
	m.addPoint(&p3);
	cout << " 加载顺序" << endl;
	m.loadOrder();
}
void funcApp5() {
	Point p1(1);
	Point p2(2);
	Point p3(3);
	Point* temp;
	Map m(&p1);
	m.addPoint(&p2);
	m.addPoint(&p3);
	int index;
	App5Window();
	while (cin>>index) {
		if (index == 7) break;
		switch (index)
		{
		case 1:
			p1.addConnectedPoint(&p2);
			p1.addConnectedPoint(&p3);
			p2.addConnectedPoint(&p3);
			break;
		case 2:
			m.DFSPrint();
			break;
		case 3:
			m.BFSPrint();
			break;
		case 4:
			temp = m.BFSbyVal(1);
			cout << temp->getConnectedPoint()->val << endl;
			break;
		case 5:
			temp = m.BFSbyVal(1);
			cout << temp->getNextPoint()->val << endl;
			break;
		case 6:
			func5();
			break;
		default:
			break;
		}
		App5Window();
	}
};



int main() {
	//funcApp1();
	//funcApp2();
	funcApp3();
	//funcApp4();
	//funcApp5();
	system("pause");
	return 0;
}