#include<iostream>
using namespace std;
int main(){
	int a[100],size,i,key,pos,flag=0;
	cout<<"Enter the size of the array:"<<endl;
	cin>>size;
	cout<<"Enter the elements in array:";
	for(i=0;i<size;i++){
		cin>>a[i];
	}
	cout<<"Enter the key:";
	cin>>key;
	for(i=0;i<size;i++){
		if(a[i]==key){
			pos=i+1;
			flag=1;
			break;
		}
	}
	if(flag==1){
		cout<<"The number found at position:"<<pos;
	}
	else{
		cout<<"The number not found";
		}
	return 0;
}
