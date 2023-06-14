#pragma once
#include"MyStack.h"
#include<string>
class url
{
public:
	url(string Url) {
		this->Url = Url;
	};
	url() { };
	~url() { };

	string Url;
private:
};

class PageView
{
public:
	PageView() { };
	~PageView() { };
	url front() {
		pages.push(rightPage);
		rightPage = frontPage;
		return frontPage;
	};
	url back() {
		url res = pages.pop();
		frontPage = rightPage;
		rightPage = res;
		return res;
	};
	void save(string Url) {
		pages.push(rightPage);
		rightPage = Url;
	}
	url rightPage;
private:
	MyStack<url> pages;
	url frontPage;
};

