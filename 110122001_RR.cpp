#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string.h>
#include <queue>

using namespace std;

struct Process {
	int arrival_time;
	int burst_time;
};

queue<Process> SelectionFunction(Process *p, int n, int quantum_time) {
	int time_current = 0;
	int flag_c = 1;
	queue<Process> pQueue;
	int flag[100];
	sortByArrivalTime(p, n);
	for (int i = 0; i < n; i++) { 
		flag[i] = 1;
		waiting_time[i] = p[i].arrival_time;
	}
	while (check(flag, n))
	{
		for (int i = 0; i < n; i++) {
			if (time_current >= p[i].arrival_time && flag[i] == 1) {
				pQueue.push(p[i]);
				if (flag_c == 1) {
					time_current = p[i].arrival_time;
					flag_c = 0;
				}
				pStart_time.push(time_current); 
				p[i].burst_time -= quantum_time;
				if (p[i].burst_time <= 0) {
					flag[i] = 0;
					ave_turnaround_time += time_current + (p[i].burst_time + quantum_time);
				}
				ave_waiting_time += (time_current - waiting_time[i]);
				if (p[i].burst_time < 0) {
					time_current += p[i].burst_time + quantum_time;
				}
				else {
					time_current += quantum_time;
				}
				waiting_time[i] = time_current;
			}
		}
	}
}
