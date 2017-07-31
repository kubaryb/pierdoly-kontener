// pierdoly-kontener.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <initializer_list>

int numOb = 0;

template<class typ>
class kont
{
	typ *tab;
	int len;
	static int ile;
	void new_member() { ++numOb; std::cout << numOb << "\n"; };
	void del_member() { --numOb; std::cout << numOb << "\n"; };
public:
	kont()
		:tab(nullptr), len(0)
	{
		++ile;
		std::cout << "Created object. Actual number of objects: " << ile << "\n";
		new_member();
	}
	kont(const std::initializer_list<typ> &lista)
		:kont()
	{
		len = lista.size();
		tab = new typ[len];
		int i(0);
		for (auto x : lista)
		{
			tab[i] = x;
			++i;
		}
	}
	friend std::ostream& operator<<(std::ostream& out, const kont<typ>& a)
	{
		for (int i = 0;i < a.len;++i)
		{
			out << a.tab[i] << " ";
		}
		return out;
	}
	virtual ~kont()
	{
		delete[]tab;
		--ile;
		std::cout << "Object deleted. Actual number of objects: " << ile << "\n";
		del_member();
	}
};

template<class typ>
int kont<typ>::ile = 0;

int main()
{
	kont<char> tab;
	kont<int> tab2{ 2,2,5,2,1,2,5,6 };
	std::cout << tab2 << "\n";
    return 0;
}

