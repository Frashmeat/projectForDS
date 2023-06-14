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
            if (nextarr[i - 1] == 0)//如果前一个next为0，则这个只可能是0或1
            {
                if (one[i] == one[0])
                    nextarr[i] = 1;
                else
                    nextarr[i] = 0;
            }
            else//不然就是上一个next的数值+1或0
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

        int cs1 = 0;//匹配成功个数
        int* nextarr = renext(one);
        int x = 0;
        while (x < all.length() && cs1 != one.length())//当没有对主串all全部遍历并且没有成功匹配时
        {
            if (all[x] == one[cs1])
                cs1++;
            else
                cs1 = nextarr[cs1];
            x++;
        }
        if (cs1 == one.length())//cs1即是匹配成功的字符数量，当与子串长度一致时就匹配成功
            return true;
        else
            return false;

	};
	vector<string> words;
};
