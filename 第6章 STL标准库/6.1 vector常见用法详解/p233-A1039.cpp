//
// Created by Jarson's mac on 2021/12/25.
//
/*
Zhejiang University has 40000 students and provides 2500 courses. Now given the student name lists of all the courses,
 you are supposed to output the registered course list for each student who comes for a query.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers: N (≤40,000),
 the number of students who look for their course lists, and K (≤2,500), the total number of courses. Then the
 student name lists are given for the courses (numbered from 1 to K) in the following format: for each course i,
 first the course index i and the number of registered students Ni(≤200) are given in a line. Then in the next line,
 Ni student names are given. A student name consists of 3 capital English letters plus a one-digit number.
 Finally the last line contains the N names of students who come for a query. All the names and numbers in a line are separated by a space.

Output Specification:
For each test case, print your results in N lines. Each line corresponds to one student, in the following format:
 first print the student's name, then the total number of registered courses of that student, and finally the indices
 of the courses in increasing order. The query results must be printed in the same order as input. All the data in a line
 must be separated by a space, with no extra space at the end of the line.

Sample Input:
11 5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9
!结尾无空行


Sample Output:
ZOE1 2 4 5
ANN0 3 1 2 5
BOB5 5 1 2 3 4 5
JOE4 1 2
JAY9 4 1 2 4 5
FRA8 3 2 4 5
DON2 2 4 5
AMY7 1 5
KAT3 3 2 4 5
LOR6 4 1 2 4 5
NON9 0
!结尾无空行
*/

/*
 这类题目正常的思路是读取每门课的学生姓名，并给出n个学生的姓名，按顺序给出每个学生的选课情况

 读取每门课的所有选课学生，将课程编号加入所有选择该门课的学生中去。

 有两个问题：1.学生是通过姓名的方式给出的
                     2.学生数和课程数的乘积过大，会导致开数组会有"内存超限"的问题

对于第一个问题会采用STL 中的map去实现姓名和学生编号之间的映射，但本题的最后一组数据庞大，map和string会超时。因此本题使用字符串hash进行求解

对于第二个问题则需要建立vector数组来存放不同学生选择的所有学生课程的编号。

 注意点：
 1.数据量庞大，不要用cin和cout进行输入和输出
 2.使用二维数组，会导致最后一组数据超限，因此需要用vector来减少空间消耗。
 * */



#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 40010;//总人数
const int M = 26*26*26*10 + 1;//由姓名散列成的数字上界
vector<int> selectCourse[M];//每个学生选择的课程编号

//hash函数，将字符串name转换成数字
int getID(char name[])
{
    int id = 0;
    for(int i = 0; i < 3; i++)
    {
        //以26为进制
        id = id * 26 + (name[i] - 'A');
    }
    //将字符数字转换为int数字
    id = id * 10 + (name[3] - '0');
    return id;
}


int main()
{
    char name[5];
    int n, k;//人数及课程
    scanf("%d%d", &n, &k);
    for(int i = 0; i < k; i++)
    {
        int course, x;//课程编号与选课人数
        scanf("%d%d", &course, &x);
        for(int j = 0; j < x; j++)
        {
            scanf("%s", name);
            int id = getID(name);//将姓名散列成一个整数作为一个编号
            selectCourse[id].push_back(course);//每一行push_back
        }
    }
    for(int i = 0; i < n; i++)//n个查询
    {
        scanf("%s", name);
        int id = getID(name);
        sort(selectCourse[id].begin(), selectCourse[id].end());//从小到大排序
        printf("%s %d", name, selectCourse[id].size());
        for(int j = 0; j < selectCourse[id].size(); j++)
        {
            printf(" %d", selectCourse[id][j]);
        }
        printf("\n");
    }
    return 0;
}

