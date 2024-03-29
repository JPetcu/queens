// Queens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <memory>
#include <iostream>
class Queen
{
	int i, j, n;
public:
	Queen(int m)
	{
		i = -1;
		j = -1;
		n = m;
	}
	void set(int a, int b)
	{
		i = a;
		j = b;
	}
	int getN()
	{
		return n;
	}
	bool intersects(std::vector<std::shared_ptr<Queen>> otherQ)
	{
		for(int i=0; i<n; i++)
		{
			if (otherQ[i]->i != -1)
			{
				if (this->i == otherQ[i]->i || this->j == otherQ[i]->j)
					return true;
				if (abs(otherQ[i]->i - this->i) == abs(otherQ[i]->j - this->j))
					return true;
			}
		}
		return false;
	}
	int getI()
	{
		return i;
	}
	int getJ()
	{
		return j;
	}
};
class Board
{
	std::vector<std::shared_ptr<Queen>> queens;
	int n;
public:
	Board(int n)
	{
		this->n = n;
		for(int i =0 ;i<n;i++)
		{
			queens.emplace_back(new Queen(n));
		}
	}
	void solve()
	{
		int indexI = 0, indexJ = 0;
		while(indexI != n && indexJ !=n)
		{
			for(int i=0; i<n;i++)
			{
				queens[i]->set(indexI, indexJ);
				if(!queens[i]->intersects(queens))
				{
					if (indexI == n - 1 && indexJ != n - 1)
					{
						indexI = 0;
						indexJ++;
						return;
					}
					else
						indexI++;
					i--;
					continue;
					
					
				}
				indexI++;
				if(indexI == n)
				{
					indexI = 0;
					indexJ++;
				}
			}
		}
		
		
	}
	void print()
	{
		for(int i=0;i<n;i++)
		{
			std::cout << queens[i]->getI() <<" "<< queens[i]->getJ() << "\n";
		}
	}
};

int main()
{
	Board B(8);
	B.solve();
	B.print();
    return 0;
}

