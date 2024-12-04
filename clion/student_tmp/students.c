#include"students.h"

// 主函数
int main() {
    Student students[50];
    Score scores[50];
    int numStudents = 0;
    int numScores = 0;
    char id[20];
    char name[20];
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                data_entry();
                break;
            case 2: {
                int num = 0;
                clear_screen();
                printf("\n================= 学生信息管理系统 =================\n");
                printf("1.按学生基本情况浏览\n");
                printf("2.按学生成绩浏览\n");
                printf("0. 退出\n");
                printf("===================================================\n");
                printf("请选择浏览方式：");
                scanf("%d", &num);
                if (num == 1) {
                    sort_students();
                } else if (num == 2) {
                    sort_scores();
                }
                break;
            }
            case 3: {
                search();
                break;
            }
            case 4:
                delete_student();
                break;
            case 5: {
                int num = 0;
                clear_screen();
                printf("\n================= 学生信息管理系统 =================\n");
                printf("1.按学号排序\n");
                printf("2.按成绩排序\n");
                printf("0. 退出\n");
                printf("===================================================\n");
                printf("请选择排序依据：");
                scanf("%d", &num);
                if (num == 1) {
                    sort_students();
                } else if (num == 2) {
                    sort_scores();
                }
                break;
            }
            case 0:
                printf("感谢使用，再见！\n");
                break;
            default:
                printf("无效的选项，请重新选择。\n");
        }
    } while (choice != 0);
    return 0;
}

// 显示菜单函数
void displayMenu() {
    clear_screen();
    printf("\n================= 学生信息管理系统 =================\n");
    printf("*\t\t 1. 添加学生信息 \t\t*\n");
    printf("*\t\t 2. 浏览学生信息 \t\t*\n");
    printf("*\t\t 3. 查询学生信息 \t\t*\n");
    printf("*\t\t 4. 删除学生信息 \t\t*\n");
    printf("*\t\t 5. 排序功能 \t\t\t*\n");
    printf("*\t\t 0. 退出 \t\t\t*\n");
    printf("===================================================\n");
    printf("请选择操作：");
}

// 数据录入功能
void data_entry() {
    FILE *fp_a = fopen(A_FILENAME, "a");
    FILE *fp_b = fopen(B_FILENAME, "a");
    if (fp_a == NULL || fp_b == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    int num_students;
    printf("请输入学生的数量: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_students; i++) {
        Student student;
        Score score;

        printf("请输入第 %d 个学生的信息:\n", i + 1);
        printf("学号: ");
        scanf("%s", student.id);
        printf("姓名: ");
        scanf("%s", student.name);
        printf("性别: ");
        scanf("%s", student.gender);
        printf("宿舍号: ");
        scanf("%s", student.dorm);
        printf("电话: ");
        scanf("%s", student.phone);

        printf("请输入该生的成绩信息:\n");
        printf("课程编号: ");
        scanf("%s", score.course_id);
        printf("课程名称: ");
        scanf("%s", score.course_name);
        printf("学分: ");
        scanf("%f", &score.credit);
        printf("平时成绩: ");
        scanf("%f", &score.usual_score);
        printf("实验成绩: ");
        scanf("%f", &score.experiment_score);
        printf("卷面成绩: ");
        scanf("%f", &score.paper_score);

        // 计算总成绩
        score.total_score = score.usual_score * 0.3 + score.experiment_score * 0.3 + score.paper_score * 0.4;

        // 写入文件
        fprintf(fp_a, "%s %s %s %s %s\n", student.id, student.name, student.gender, student.dorm, student.phone);
        fprintf(fp_b, "%s %s %s %.2f %.2f %.2f %.2f %.2f\n", student.id, score.course_id, score.course_name,
                score.credit,
                score.usual_score, score.experiment_score, score.paper_score, score.total_score);
    }

    fclose(fp_a);
    fclose(fp_b);
    printf("数据录入成功！\n");
    continue_menu();
}

// 按学号排序
void sort_students() {
    // 读取学生信息
    FILE *fp_a = fopen(A_FILENAME, "r");
    if (fp_a == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    int num_students = 0;
    Student students[100];
    while (fscanf(fp_a, "%s %s %s %s %s", students[num_students].id, students[num_students].name,
                  students[num_students].gender, students[num_students].dorm, students[num_students].phone) != EOF) {
        num_students++;
    }
    fclose(fp_a);
    // 使用冒泡排序按学号排序学生信息
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = 0; j < num_students - i - 1; j++) {
            if (strcmp(students[j].id, students[j + 1].id) > 0) {
                // 交换学生信息
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    // 输出排序后的学生信息
    printf("按学号排序后的学生信息:\n");
    for (int i = 0; i < num_students; i++) {
        printf("学号: %s, 姓名: %s, 性别: %s, 宿舍号: %s, 电话: %s\n",
               students[i].id, students[i].name, students[i].gender, students[i].dorm, students[i].phone);
    }
    continue_menu();
}

//按成绩排序
void sort_scores() {
    FILE *fp;
    Score score;
    Score scores[100]; // 假设最多有100个学生成绩信息
    int count = 0; // 记录学生成绩信息的数量

    // 打开文件以读取方式
    fp = fopen(B_FILENAME, "r");
    if (fp == NULL) {
        printf("无法打开文件！\n");
        exit(1);
    }

    // 逐行读取学生成绩信息，并存储到数组中
    while (fscanf(fp, "%49s %49s %99s %f %f %f %f %f", score.id, score.course_id, score.course_name, &score.credit,
                  &score.usual_score, &score.experiment_score, &score.paper_score, &score.total_score) == 8) {
        scores[count] = score;
        count++;
    }

    fclose(fp);

    // 使用简单的冒泡排序按综合成绩降序排序
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (scores[j].total_score < scores[j + 1].total_score) {
                // 交换两个学生成绩信息的位置
                Score temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }

    // 输出排序后的学生成绩信息
    printf("按综合成绩降序浏览学生成绩信息如下：\n");
    for (int i = 0; i < count; i++) {
        printf("学号：%s，课程编号：%s，课程名称：%s，学分：%.2f，综合成绩：%.2f\n",
               scores[i].id, scores[i].course_id, scores[i].course_name, scores[i].credit, scores[i].total_score);
    }
    continue_menu();
}

// 删除功能
void delete_student() {
    char id[20];
    char name[20];
    printf("请输入要删除学生的学号或姓名: ");
    scanf("%s", id);

    // 在A.TXT中查找学生信息
    FILE *fp_a = fopen(A_FILENAME, "r");
    FILE *temp_a = fopen("TEMP_A_FILENAME", "w");
    if (fp_a == NULL || temp_a == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    int found = 0;
    Student student;
    while (fscanf(fp_a, "%s %s %s %s %s", student.id, student.name, student.gender, student.dorm, student.phone) !=
           EOF) {
        if (strcmp(student.id, id) == 0 || strcmp(student.name, id) == 0) {
            found = 1;
            continue;
        }
        fprintf(temp_a, "%s %s %s %s %s\n", student.id, student.name, student.gender, student.dorm, student.phone);
    }

    fclose(fp_a);
    fclose(temp_a);
    remove(A_FILENAME);
    rename("TEMP_A_FILENAME", A_FILENAME);

    if (!found) {
        printf("未找到该学生信息！\n");
        return;
    }

    // 在B.TXT中删除学生成绩信息
    FILE *fp_b = fopen(B_FILENAME, "r");
    FILE *temp_b = fopen("temp_B.txt", "w");
    if (fp_b == NULL || temp_b == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    Score score;
    while (fscanf(fp_b, "%s %s %f %f %f %f %f", score.id, score.course_id, &score.credit,
                  &score.usual_score, &score.experiment_score, &score.paper_score, &score.total_score) != EOF) {
        if (strcmp(score.id, id) != 0) {
            fprintf(temp_b, "%s %s %.2f %.2f %.2f %.2f %.2f\n", score.id, score.course_id, score.credit,
                    score.usual_score, score.experiment_score, score.paper_score, score.total_score);
        }
    }

    fclose(fp_b);
    fclose(temp_b);
    remove(B_FILENAME);
    rename("temp_B.txt", B_FILENAME);

    printf("删除成功！\n");
}

//查询功能
void search() {
    int choice;
    int choice2;
    char keyword[20];
    char id[20];
    FILE *fp = NULL;

    printf("================= 学生信息查询系统 =================\n");
    printf("1. 学生基本信息查询\n");
    printf("2. 学生成绩查询\n");
    printf("0. 退出\n");
    printf("===================================================\n");
    printf("请选择操作：");
    scanf("%d", &choice);
    clear_screen();
    switch (choice) {
        case 1:
            printf("================= 学生信息查询系统 =================\n");
            printf("1. 学号查询\n");
            printf("2. 姓名查询\n");
            printf("3. 宿舍号查询\n");
            printf("0. 退出\n");
            printf("===================================================\n");
            printf("请选择操作：");
            scanf("%d", &choice2);
            switch (choice2) {
                case 1:
                    printf("请输入要查询学生的学号：");
                    scanf("%s", id);
                    search_students1(fp, id);
                    break;
                case 2:
                    printf("请输入要查询学生的姓名：");
                    scanf("%s", id);
                    search_students2(fp, id);
                    break;
                case 3:
                    printf("请输入要查询学生的宿舍号：");
                    scanf("%s", id);
                    search_students3(fp, id);
                    break;
                case 0:
                    printf("感谢使用，再见！\n");
                    break;
                default:
                    printf("无效的选项，请重新选择。\n");
            }
        case 2:
            printf("请输入学号：");
            scanf("%s", id);
            search_scores(fp, id); // 假设学生成绩信息保存在 B_FILENAME 文件中
            break;
        case 0:
            printf("感谢使用，再见！\n");
            break;
        default:
            printf("无效的选项，请重新选择。\n");
    }
}

// 学生基本信息查询函数
void search_students1(FILE *fp, const char *keyword) {
    Student student;
    int found = 0;

    // 以只读方式打开文件
    fp = fopen(A_FILENAME, "r");
    if (fp == NULL) {
        printf("无法打开文件！\n");
        exit(1);
    }

    // 逐行读取学生信息，查找匹配的记录
    while (fread(&student, sizeof(Student), 1, fp)) {
        if (strcmp(student.id, keyword) == 0) {
            printf("学号：%s，姓名：%s，性别：%s，宿舍号：%s，电话：%s\n",
                   student.id, student.name, student.gender, student.dorm, student.phone);
            found = 1;
        }
    }

    if (!found) {
        printf("未找到匹配的记录。\n");
    }

    fclose(fp);
}

// 学生基本信息查询函数
void search_students2(FILE *fp, const char *keyword) {
    Student student;
    int found = 0;

    // 以只读方式打开文件
    fp = fopen(A_FILENAME, "r");
    if (fp == NULL) {
        printf("无法打开文件！\n");
        exit(1);
    }

    // 逐行读取学生信息，查找匹配的记录
    while (fread(&student, sizeof(Student), 1, fp)) {
        if (strcmp(student.name, keyword) == 0) {
            printf("学号：%s，姓名：%s，性别：%s，宿舍号：%s，电话：%s\n",
                   student.id, student.name, student.gender, student.dorm, student.phone);
            found = 1;
        }
    }

    if (!found) {
        printf("未找到匹配的记录。\n");
    }

    fclose(fp);
}

// 学生基本信息查询函数
void search_students3(FILE *fp, const char *keyword) {
    Student student;
    int found = 0;

    // 以只读方式打开文件
    fp = fopen(A_FILENAME, "r");
    if (fp == NULL) {
        printf("无法打开文件！\n");
        exit(1);
    }

    // 逐行读取学生信息，查找匹配的记录
    while (fread(&student, sizeof(Student), 1, fp)) {
        if (strcmp(student.dorm, keyword) == 0) {
            printf("学号：%s，姓名：%s，性别：%s，宿舍号：%s，电话：%s\n",
                   student.id, student.name, student.gender, student.dorm, student.phone);
            found = 1;
        }
    }

    if (!found) {
        printf("未找到匹配的记录。\n");
    }

    fclose(fp);
}

// 学生成绩查询函数
void search_scores(FILE *fp, const char *student_id) {
    Score score;
    float total_credit = 0;
    float total_score = 0;

    // 以只读方式打开文件
    fp = fopen(B_FILENAME, "r");
    if (fp == NULL) {
        printf("无法打开文件！\n");
        exit(1);
    }

    // 在课程成绩文件中查找学号对应的成绩信息
    while (fread(&score, sizeof(Score), 1, fp)) {
        if (strcmp(score.id, student_id) == 0) {
            printf("学号：%s，课程编号：%s，课程名称：%s，学分：%.2f，综合成绩：%.2f\n",
                   score.id, score.course_id, score.course_name, score.credit, score.total_score);
            total_credit += score.credit;
            total_score += score.total_score;
        }
    }

    if (total_credit > 0) {
        printf("该学生总学分为 %.2f，总综合成绩为 %.2f\n", total_credit, total_score);
    } else {
        printf("未找到该学生的成绩信息。\n");
    }

    fclose(fp);
}