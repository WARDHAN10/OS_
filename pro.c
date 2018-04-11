#include<stdio.h> 
//#include<conio.h>
static int n;
int i,j,totaltime=0;
float avgtat=0,avgwt=0;
int queue[];
int time=0,front=0,rear=0,q_count=0,m=0,s=0;
struct data
{
int at,bt,ct,tat,wt;
char pname[20];
float ntat;
}x;
main()
{
printf("enter the number of process\n");
scanf("%d",&n);

struct data y[n];
for(i=0;i<n;i++)
{
printf("enter the name of process %d,\n",i);
scanf("%s",&y[i].pname);
printf("enter the arrival time and burst time %d\n",i);
scanf("%d%d",&y[i].at,&y[i].bt);
}
for(i=0;i<n;i++)
{
for(j=i;j>=1;j--)
{
if(y[j].at<y[j-1].at)
{
x=y[j-1];
y[j-1]=y[j];
y[j]=x;
}
else if(y[j].at==y[j-1].at)
{
if(y[j].bt<y[j-1].bt)
{
x=y[j-1];
y[j-1]=y[j];
y[j]=x;}}
}
}
totaltime+=y[0].at+y[0].bt;
for(i=1;i<n;i++)
{
if(y[i].at>totaltime)
totaltime=y[i].at;
totaltime+=y[i].bt;
}
finding(y);
}
void finding(struct data a[])
{
int x_bt[n],flag=0,count=0,p_process;
j=0;
int tq;
printf("enter the time quantum\n");
scanf("%d",&tq);
for(i=0;i<n;i++)
{
x_bt[i]=a[i].bt;
}
time=a[0].at;
q_count=1;
push(j++);
while(time<=totaltime)
{
if(flag==1||q_count!=0)
{
if(flag==0&&count==0)
{
p_process=pop();
count=0;
flag=1;
}
x_bt[p_process]--;
if(x_bt[p_process]==0)
{
time++;
count=0;
a[p_process].ct=time;
flag=0;
q_count--;
check(a);
continue;
}
count++;
if(count==tq)
{
count=0;
time++;
check(a);
push(p_process);
flag=0;
}
else
{
time++;
check(a);
}
}
else
{
time++;
check(a);
}
}
display(a);
}
void push(int q)
{
queue[rear++]=q;
m++;
}
int pop()
{
s++;
int x;
x=queue[front++];
return x;
}
void check(struct data a[])
{
while(a[j].at<=time&&j<n)
{
q_count++;	
push(j++);
}
}
void display(struct data a[])
{
printf("n=%d	\n",n);
for(i=0;i<n;i++)
{
a[i].tat=a[i].ct-a[i].at;
a[i].wt=a[i].tat-a[i].bt;
a[i].ntat=(float)a[i].tat/a[i].bt;
}
for(i=0;i<n;i++)
{
avgtat+=a[i].tat;
avgwt+=a[i].wt;
}
avgtat=avgtat/n;
avgwt=avgwt/n;
printf("pname\tat\tbt\tct\ttat\twt\tntat\n");
for(i=0;i<n;i++)
{
printf("%s\t%d\t%d\t%d\t%d\t%d\t%f\n",a[i].pname,a[i].at,a[i].bt,a[i].ct,a[i].tat,a[i].wt,a[i].ntat);
}
printf("avgtat=%f\navgwt=%f\n",avgtat,avgwt);
}
