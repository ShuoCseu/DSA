#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// 线程函数
void* thread_func(void* arg) {
    int thread_num = *((int*)arg);
    printf("I am thread %d\n", thread_num);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_nums[3] = {1, 2, 3};

    // 创建线程
    for (int i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, thread_func, &thread_nums[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    // 等待线程完成
    for (int i = 0; i < 3; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            return 2;
        }
    }

    return 0;
}
