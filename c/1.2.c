#include <stdio.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 4

typedef struct {
    int current_floor;
    int destinations[MAX_PASSENGERS];
    int num_passengers;
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->current_floor = 1;
    elevator->num_passengers = 0;
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        elevator->destinations[i] = 0;
    }
}

void addPassenger(Elevator *elevator, int destination) {
    if (elevator->num_passengers < MAX_PASSENGERS) {
        elevator->destinations[elevator->num_passengers] = destination;
        elevator->num_passengers++;
    }
}

void moveElevator(Elevator *elevator, int destination) { 
    int time = 0; // 记录电梯运行时间
    int current_floor = elevator->current_floor;
    
    while (current_floor != destination) {
        printf("电梯经过 %d 楼，当前时间：%d，乘客数量：%d\n", current_floor, time, elevator->num_passengers);
        if (current_floor < destination) {
            current_floor++;
        } else {
            current_floor--;
        }
        time++;
    }

    // 更新电梯状态
    elevator->current_floor = destination;
    for (int i = 0; i < elevator->num_passengers; i++) {
        if (elevator->destinations[i] == destination) {
            // 乘客在目的楼层出电梯，减少乘客数量
            elevator->num_passengers--;
            for (int j = i; j < elevator->num_passengers; j++) {
                elevator->destinations[j] = elevator->destinations[j + 1];
            }
            elevator->destinations[elevator->num_passengers] = 0;
            i--;
        }
    }

    printf("电梯停在 %d 楼，当前时间：%d，乘客数量：%d\n", destination, time, elevator->num_passengers);
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);

    int A, B, C;
    printf("请输入等待电梯的楼层号A（1-10）：");
    scanf("%d", &A);
    printf("请输入电梯目标楼层号B（1-10）：");
    scanf("%d", &B);
    printf("请输入电梯当前所在楼层号C（1-10）：");
    scanf("%d", &C);

    // 模拟乘客添加请求
    addPassenger(&elevator, A);
    
    // 模拟电梯运动
    moveElevator(&elevator, B);

    return 0;
}