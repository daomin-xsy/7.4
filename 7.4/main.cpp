#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
#include<iomanip>
using namespace std;
struct Student
{
    char index[50];
    char college[50];
    char name[50];
    int score[7];
    char rename[20];
    double average;
};
bool cmp( Student & a, Student & b )
{
    return a.average>b.average;
}
int main()
{
    ifstream out("/Users/s20181105303/Desktop/选手信息.txt");
    int number,i,j;
    double sum=0;
    out>>number;
    Student student[number];
    Student refereename[7];
    for(i=0;i<number;i++)
    {
        out>>student[i].index>>student[i].college>>student[i].name;
    }
    ifstream out1("/Users/s20181105303/Desktop/裁判信息.txt");
    for(i=0;i<7;i++)
    {
        out1>>refereename[i].rename;
        for(j=0;j<number;j++)
        {
            out1>>student[j].score[i];
        }
    }
    for(i=0;i<number;i++)
    {
        int max=0;
        for(j=0;j<7;j++)
        {
            if(student[i].score[j]>max)
            {
                max=student[i].score[j];
            }
        }
        for(j=0;j<7;j++)
        {
            if(student[i].score[j]==max)
            {
                student[i].score[j]=0;
                break;
            }
        }
    }
    for(i=0;i<number;i++)
    {
        int min;
        for(j=0;j<7;j++)
        {
            if(student[i].score[j]!=0)
            {
                min=student[i].score[j];
            }
        }
        for(j=0;j<7;j++)
        {
            if(student[i].score[j]<min&&student[i].score[j]!=0)
            {
                min=student[i].score[j];
            }
        }
        for(j=0;j<7;j++)
        {
            if(student[i].score[j]==min)
            {
                student[i].score[j]=0;
                break;
            }
        }
    }
    for(i=0;i<number;i++)
    {
        sum=0;
        for(j=0;j<7;j++)
        {
            sum=sum+student[i].score[j];
        }
        student[i].average=sum/5;
    }
    sort(student,student+number,cmp);   //结构体数组首地址，末地址，自定义函数 比较结构体大小
    ofstream in("/Users/s20181105303/Desktop/最终得分.txt");
    if(in.is_open())
    {
        for(i=0;i<number;i++)
        {
            in<<left<<setw(5)<<student[i].index
            <<left<<setw(15)<<student[i].college
            <<left<<setw(15)<<student[i].name
            <<left<<setw(15)<<i+1
            <<left<<setw(5)<<fixed<<setprecision(1)<<student[i].average<<endl;
        }
        out.close();
    }
    return 0;
}
