#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef  WIN32

void clear_screen() {
    system("cls");
}

#else
void clear_screen() {
    system("clear");
}
#endif

void continue_menu() {
    puts("输入回车以继续");
    getchar();
    getchar();
    clear_screen();
}

#define A_FILENAME ("A.txt")
#define B_FILENAME ("B.txt")
#define TEMP_A_FILENAME ("TEMP_A.txt")

void displayMenu();//菜单
void data_entry();//数据录入
void search();//查询功能
void search_scores();// 成绩查询函数
void search_students1();//
void search_students2();

void search_students3();

void delete_student();//删除功能
void sort_students();//排序学号
void sort_scores();//排序成绩
// 定义学生基本信息结构体
typedef struct {
    char id[20];  // 学号
    char name[50];  // 姓名
    char gender[10];  // 性别
    char dorm[20];  // 宿舍号
    char phone[20];  // 电话
} Student;

// 定义课程成绩结构体
typedef struct {
    char id[20];// 学号
    char course_id[20];// 课程编号
    char course_name[50];// 课程名称
    float credit;// 学分
    float usual_score;// 平时成绩
    float experiment_score;// 实验成绩
    float paper_score;// 卷面成绩
    float total_score;// 综合成绩
} Score;



