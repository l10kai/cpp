#include <stdio.h>

// 定义学生信息的结构体
struct Student {
    int student_id;
    char name[5];
    int score1;
    int score2;
    int score3;
};

// 函数：输入一个学生的数据记录
void input(struct Student *student) {
    scanf("%d %s %d %d %d", &student->student_id, student->name, &student->score1, &student->score2, &student->score3);
}

// 函数：打印一个学生的数据记录
void print(struct Student student) {
    printf("%d,%s,%d,%d,%d\n", student.student_id, student.name, student.score1, student.score2, student.score3);
}

int main() {
    int N;
    scanf("%d", &N);

    // 声明一个数组来存储学生信息
    struct Student students[N];

    // 输入学生信息
    for (int i = 0; i < N; i++) {
        input(&students[i]);
    }

    // 输出学生信息
    for (int i = 0; i < N; i++) {
        print(students[i]);
    }

    return 0;
}
