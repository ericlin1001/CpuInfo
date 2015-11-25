#include<iostream>
#include<fstream>
#include<unistd.h>
using namespace std;
#define Trace(m) cout<<#m"="<<(m)<<endl;
void getIdleRate(int &idle,int &total){
	char buff[10];
	int x[7];
	ifstream in("/proc/stat");
	in.sync();
	if(in==NULL){
		cerr<<"Can't open /proc/stat"<<endl;
	}
	in>>buff;//read 'cpu'
	total=0;
	for(int i=0;i<7;i++){
		in>>x[i];
		total+=x[i];
	}
	in.close();
	idle=x[3];
}
double getCpuUsage(){
	int i1,i2,t1,t2;
	getIdleRate(i1,t1);
	//Trace(i1);
	//Trace(t1);
	usleep(1000*200*1);
	getIdleRate(i2,t2);
	//Trace(i2);
	//Trace(t2);
	double rate=(double)(i2-i1)/(t2-t1);
	return 1.0-rate;
}
int main(){
//	cout<<"Hello"<<endl;
	cout<<(1-getCpuUsage())*100<<endl;
//	cout<<"Hello"<<endl;
	return 0;
}
