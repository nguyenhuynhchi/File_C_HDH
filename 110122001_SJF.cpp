







#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

struct Process {
	int name;
	int burst_time;
	int arrival_time;
};

static double avg_turn_around_time = 0;
static double avg_waitting_time = 0;

void swap(Process &p1, Process &p2){
	Process tmp;
	tmp = p1;
	p1 = p2;
	p2 = tmp;
}

void sortByArrivalTime(Process *p, int n){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(p[i].arrival_time < p[j].arrival_time){
				swap(p[i], p[j]);
			}
		}
	}
}

void Input(Process *p, int n){
	for(int i=0; i<n; i++){
		cout << "--------------------\n";
		cout << "Nhap ID Process: "; cin>> p[i].name;
		cout << "Nhap Arrival Time: "; cin>> p[i].arrival_time;
		cout << "Nhap Burst Time: "; cin>> p[i].burst_time;
	}
}

void sortByBurstTime(Process *p, int n, int time_current){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(p[i].burst_time < p[j].burst_time && p[i].arrival_time <= time_current){
				swap(p[i], p[j]);
			}
		}
	}
}

void SelectionFunction(Process *p, int n){
	int time_current;
	// Sort theo arrival_time
	sortByArrivalTime(p, n);
	// Ham lua chonj quyet dinh xem process nao vao queue truoc;
	time_current = p[n-1].arrival_time;
	for(int i=0; i<n; n--){
		time_current += p[n-1].burst_time;
		avg_waitting_time += time_current - p[n-1].arrival_time - p[n-1].burst_time;
		avg_turn_around_time += (time_current - p[n-1].arrival_time);
		cout << p[n-1].name <<"\t\t" << p[n-1].arrival_time << "\t\t" << p[n-1].burst_time << "\t\t" << time_current - p[n-1].burst_time << "\t\t" << time_current - p[n-1].arrival_time << "\t\t" << (time_current) << endl;
		sortByBurstTime(p, n-1, time_current);
	}
}

int main(){
	Process *p = new Process[100];
	queue<Process> pQueue;
	int n;
	cout << "Nhap so luong process: "; cin >> n;
	Input(p, n);
	cout << "PName\t\tArrTime\t\tBurTime\t\tStart\t\tTAT\t\tFinish\n";
	SelectionFunction(p,n);
	cout <<"Thoi gian dap ung trung binh: " << avg_waitting_time/n << endl;
	cout <<"Thoi gian hoan thanh trung binh: " << avg_turn_around_time/n << endl;
	return 0;
}
















