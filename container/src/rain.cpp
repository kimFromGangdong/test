#include <iostream>
#include <string>
#include <algorithm>  
#include <sstream>
using namespace std;
void rain(){
	int rows, cols;
	string nums;

	cin>>rows>>cols;
	cin.ignore();

	int grid[rows][cols];
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){s
			grid[i][j] = 0;
		}
	}
	
	getline(cin,nums);
    stringstream ss(nums);
	int arr[cols]; 	
	for (int k = 0; k < cols; k++) {
      	ss >> arr[k];
    	}
	for(int j=0;j<cols;j++)
  	{
		for(int p=rows;p>rows-arr[j]-1;p--)
		{
			if(p>=0&&p<rows){
			grid[p][j]=1;
			}
		}
	}
	
	int black = 0;
	int current = 0;
	int sum;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(black == 0&&grid[i][j]==1){
				black = 1;
				current = j;
			}
			else if(black == 1&&grid[i][j]==1){
				sum = sum + (j-current-1);
				current = j;
			}
		}
		black = 0;
	}
	cout<<sum<<endl;
}


int main(void){
	rain();
}