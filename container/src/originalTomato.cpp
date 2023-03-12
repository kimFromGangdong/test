/*
#include <iostream>
#include <string>
#include <algorithm>  
#include <sstream>
using namespace std;


int normalTomato(void)
{
  int rows, cols;
  int ones =0;
  string nums;

   cin>>cols>>rows;
   cin.ignore();


  int grid[rows][cols];
  
  for(int i=0;i<rows;i++)
  {
    int arr[cols];
    getline(cin,nums);
    stringstream ss(nums);
	  
    for (int j = 0; j < cols; j++) {
      ss >> arr[j];
    }
    for(int j=0;j<cols;j++) {
      grid[i][j]=arr[j];
    }
  }
	
  
  int days=1;

int previous = 0; //전날의 1의 개수를 저장함
int numOnes = 0; 
int minusOnes = 0;
int ripeNum; //오늘의 1의 개수를 저장
	for(int i=0;i<rows;i++){
	  for(int j=0;j<cols;j++){
		  if(grid[i][j]==-1){
			  minusOnes++;
		  }
		  else if(grid[i][j]==1){
			  numOnes++;
		  }
	  }
	}
	if ((cols*rows-numOnes)==minusOnes){
		cout<<"0"<<endl;
		return 0;
	}
    while(ripeNum<(cols*rows)){		
	ripeNum =0;
	
	for(int i=0;i<rows;i++){
	  for(int j=0;j<cols;j++){
		  if(grid[i][j]==1){
			  if(j-1>=0&&grid[i][j-1]==0)
			  {
				  grid[i][j-1]=2;
			  }
			  if(j+1<cols&&grid[i][j+1]==0)
			  {
				  grid[i][j+1]=2;
			  }
			  if(i+1<rows&&grid[i+1][j]==0)
			  {
				  grid[i+1][j]=2;
			  }
			  if(i-1>=0&&grid[i-1][j]==0)
			  {
				  grid[i-1][j]=2;
			  }
		  }
	  }
	}
	for(int i=0;i<rows;i++){
	  for(int j=0;j<cols;j++){
		  if(grid[i][j]==1||grid[i][j]==2){
			  ripeNum+=1;
			  grid[i][j]=1;
		  }
	  }
	}
	
	if (previous==ripeNum&&previous<(cols*rows)-minusOnes){
		
		cout<<"-1"<<endl;
		return 0;
	}
	if(previous==(cols*rows-minusOnes)){
	cout<<days-1<<endl;
		return 0;
	}
	previous = ripeNum;
	days+=1;
    
	}
cout<<days-1<<endl;

return 0;	
}

int main()
{
	normalTomato();

}
*/