#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // 用于sleep函数

#define MAX_FLOORS 10
#define MAX_PASSENGERS 4
#define MAX_ELEVATORS 2

typedef struct {
    int current_floor;
    int destinations[MAX_PASSENGERS];
    int num_passengers;
} Elevator;

typedef struct {
    int start_floor;
    int end_floor;
    int interval;
} PassengerRequest;

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
    int time = 0;
    int current_floor = elevator->current_floor;

    while (current_floor != destination) {
        printf("电梯经过 %d 楼，当前时间：%d，乘客数量：%d\n", current_floor, time, elevator->num_passengers);
        if (current_floor < destination) {
            current_floor++;
        } else {
            current_floor--;
        }
        time++;
        usleep(500000); // 每层楼停留0.5秒
    }

    elevator->current_floor = destination;
    for (int i = 0; i < elevator->num_passengers; i++) {
        if (elevator->destinations[i] == destination) {
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

void handlePassengerRequests(Elevator elevators[], PassengerRequest requests[], int num_requests) {
    int current_time = 0;
    int current_request = 0;

    while (current_request < num_requests) {
        for (int i = 0; i < MAX_ELEVATORS; i++) {
            if (requests[current_request].interval <= current_time) {
                int start_floor = requests[current_request].start_floor;
                int end_floor = requests[current_request].end_floor;
                int elevator_floor = elevators[i].current_floor;

                if (start_floor < end_floor) {
                    // 向上请求
                    if (elevator_floor <= start_floor) {
                        addPassenger(&elevators[i], start_floor);
                    }
                } else if (start_floor > end_floor) {
                    // 向下请求
                    if (elevator_floor >= start_floor) {
                        addPassenger(&elevators[i], start_floor);
                    }
                }

                current_request++;
            }
        }

        // 更新电梯状态
        for (int i = 0; i < MAX_ELEVATORS; i++) {
            moveElevator(&elevators[i], elevators[i].destinations[0]);
        }

        current_time++;
        usleep(1000000); // 1秒时间模拟
    }
}

int main() {
    Elevator elevators[MAX_ELEVATORS];
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        initializeElevator(&elevators[i]);
    }

    int num_requests;
    printf("请输入乘客请求的数量：");
    scanf("%d", &num_requests);

    PassengerRequest requests[num_requests];
    for (int i = 0; i < num_requests; i++) {
        printf("请输入第 %d 个乘客请求的起始楼层、目的楼层和间隔时间（秒）：", i + 1);
        scanf("%d %d %d", &requests[i].start_floor, &requests[i].end_floor, &requests[i].interval);
    }

    handlePassengerRequests(elevators, requests, num_requests);

    return 0;
}
