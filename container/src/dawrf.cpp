/*
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>

using namespace std;

void dwarfy()
{
	int k;
	int sum = 0;
	int first = 0;
	int second = 0;
	vector<int> dwarfs;
    for(int i = 0;i<9;i++){
		cin>>k;
		dwarfs.emplace_back(k);
	}
	sort(dwarfs.begin(),dwarfs.end());
	
	for(const auto &dwarf : dwarfs)
	{
		sum= sum+ dwarf;
	}	
	
	for(int i = 0;i<9;i++)
	{
		for(int j = 0;j<9;j++)
		{
			if(dwarfs[i]+dwarfs[j]==sum-100&&i!=j){
				first = dwarfs[i];
				second = dwarfs[j];
				break;
			}
		}
	}

	for(const auto &dwarf : dwarfs)
	{
		if(dwarf!=first && dwarf!=second)
		{
			cout<<dwarf<<endl;
		}
	}	
}
int main (void)
{
	dwarfy();
}