#include<stdio.h>

int main()  
{  
    int i, NOP, sum=0, count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];  
    float avg_wt, avg_tat;  

    printf("Nhap so luong process: ");  
    scanf("%d", &NOP);  
    y = NOP;
  
    for(i=0; i<NOP; i++)  
    {  
     	printf("\nNhap Arrival time va Burst time cho process[%d]\n", i+1);  
     	printf("Arrival time: "); 
     	scanf("%d", &at[i]);  
        	printf("Burst time: \t"); 
        	scanf("%d", &bt[i]);  
        	temp[i] = bt[i];  
    }  

    printf("Nhap Time Quantum cho process: \t");  
    scanf("%d", &quant);  

    printf("\nProcess No \t Burst Time \t TAT \t Waiting Time");  
    for(sum=0, i = 0; y!=0; )  
    {  
        	if(temp[i] <= quant && temp[i] > 0)   
        	{  
            	sum = sum + temp[i];  
            	temp[i] = 0;  
            	count=1;  
        	}     
        	else if(temp[i] > 0)  
        	{  
          	temp[i] = temp[i] - quant;  
            	sum = sum + quant;    
        	}  
        	if(temp[i]==0 && count==1)  
        	{  
          	y--;  
            	printf("\nProcess No[%d] \t %d\t\t %d\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
            	wt = wt + sum - at[i] - bt[i];  
            	tat = tat + sum - at[i];  
            	count = 0;     
        	}  
        	if(i == NOP-1)  
        	{  
          	i = 0;  
        	}  
        	else if(at[i+1] <= sum)  
        	{  
          	i++;  
        	}  
        	else  
        	{  
     		i = 0;  
        	}  
    }  
    avg_wt = wt * 1.0 / NOP;  
    avg_tat = tat * 1.0 / NOP;  
    printf("\nThoi gian doi trung binh: \t%.2f", avg_wt);  
    printf("\nThoi gian hoan thanh trung binh: \t%.2f", avg_tat);  

    return 0;
}

