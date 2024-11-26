#include <stdio.h>
#include <wchar.h>

struct Student{
    int sid;
    wchar_t name[1000];
    int s1;
    int s2;
    int s3;
    int s4;
};

void input(struct Student *student){
    wscanf(L"%d %ls %d %d %d",&student->sid, student->name, &student->s1, &student->s2, &student->s3);
}

void print(struct Student student) {
    wprintf(L"%d,%ls,%d,%d,%d\n", student.sid, student.name, student.s1, student.s2, student.s3);
}


 int main(){
    int N;
    scanf("%d",&N);
    struct Student students[N];

     for (int i = 0; i < N; i++) {
        input(&students[i]);
    }
     for (int i = 0; i < N; i++) {
        print(students[i]);
    }
return 0;
 }
