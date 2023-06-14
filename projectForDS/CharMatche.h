#pragma once
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class CharMatche
{
public:
	CharMatche() { };
	~CharMatche() { };
	void save(const string& word) {
		words.emplace_back(word);
	};
	vector<string> find(const string& word) {
		vector<string> ans;
		for (string& temp : words) {
			if (kmp(temp, word)) {
				ans.push_back(temp);
			}
		}
        return ans;
	};
private:
    int* renext(string one)
    {
        int* nextarr = new int[one.length() + 2];
        nextarr[0] = 0;
        for (int i = 1; i < one.length(); i++)
        {
            if (nextarr[i - 1] == 0)//���ǰһ��nextΪ0�������ֻ������0��1
            {
                if (one[i] == one[0])
                    nextarr[i] = 1;
                else
                    nextarr[i] = 0;
            }
            else//��Ȼ������һ��next����ֵ+1��0
            {
                if (one[i] == one[nextarr[i - 1]])
                    nextarr[i] = nextarr[i - 1] + 1;
                else
                    nextarr[i] = 0;
            }
        }
        return nextarr;
    }
	bool kmp(string all,string one) {

        int cs1 = 0;//ƥ��ɹ�����
        int* nextarr = renext(one);
        int x = 0;
        while (x < all.length() && cs1 != one.length())//��û�ж�����allȫ����������û�гɹ�ƥ��ʱ
        {
            if (all[x] == one[cs1])
                cs1++;
            else
                cs1 = nextarr[cs1];
            x++;
        }
        if (cs1 == one.length())//cs1����ƥ��ɹ����ַ������������Ӵ�����һ��ʱ��ƥ��ɹ�
            return true;
        else
            return false;

	};
	vector<string> words;
};
