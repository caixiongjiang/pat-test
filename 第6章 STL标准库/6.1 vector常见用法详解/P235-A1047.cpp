//
// Created by Jarson's mac on 2021/12/25.
//
/*
Zhejiang University has 40,000 students and provides 2,500 courses. Now given the registered course list of each student,
 you are supposed to output the student name lists of all the courses.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 numbers: N (≤40,000), the total number of students,
 and K (≤2,500), the total number of courses. Then N lines follow, each contains a student's name (3 capital English letters plus
 a one-digit number), a positive number C (≤20) which is the number of courses that this student has registered, and then followed
 by C course numbers. For the sake of simplicity, the courses are numbered from 1 to K.

Output Specification:
For each test case, print the student name lists of all the courses in increasing order of the course numbers. For each course,
 first print in one line the course number and the number of registered students, separated by a space. Then output the students'
 names in alphabetical order. Each name occupies a line.

Sample Input:
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5
!结尾无空行

Sample Output:
1 4
ANN0
BOB5
JAY9
LOR6
2 7
ANN0
BOB5
FRA8
JAY9
JOE4
KAT3
LOR6
3 1
BOB5
4 7
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
5 9
AMY7
ANN0
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
结尾无空行

 注意点：
 1.使用string容易超时，数据范围很大的情况下一般用char数组存放数据
 2.如果排序时直接对字符串进行排序，那么会导致大量的字符串移动，非常容易超时。因此比较合适的做法是
 使用字符串的下标来代替字符串本身来进行排序，这样消耗的时间少的多
 3.strcmp的返回值不一定是-1, 0, +1，也有可能是其他正数和负数。因此在写cmp函数时不能写strcmp的返回值等于-1，
 而必须写小于0，飞则不具有普适性
*/


#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 40010;//最大学生人数
const int maxc = 2510;//最大课程门数

char name[maxn][5];//maxn个学生
vector<int> course[maxc];//course[i]存放第i门课的所有学生编号

bool cmp(int a, int b)
{
    //strcmp函数是string compare(字符串比较)的缩写，用于比较两个字符串并根据比较结果返回整数。
    // 基本形式为strcmp(str1,str2)，若str1 == str2，则返回零；
    // 若str1 < str2，则返回负数；
    // 若str1 > str2，则返回正数。
    return strcmp(name[a], name[b]) < 0;//按照姓名字典序从小到大排序
}

int main()
{
    int n, k, c, courseID;
    scanf("%d%d", &n, &k);//学生人数及课程数
    for(int i = 0; i < n; i++)
    {
        scanf("%s %d", name[i], &c);//学生姓名及选课数
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &courseID);//学生选的课程编号
            course[courseID].push_back(i);//将学生i加入courseID门课中
        }
    }
    for(int i = 1; i <= k; i++){
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp);//对第i门课的学生按照字典序进行排序
        for(int j = 0; j < course[i].size(); j++)
        {
            printf("%s\n", name[course[i][j]]);
        }
    }
    return 0;
}
