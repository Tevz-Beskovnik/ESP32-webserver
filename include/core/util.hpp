//
// Created by Tevz on 9. 02. 24.
//

#ifndef BORED_PROGRAMING_UTIL_HPP
#define BORED_PROGRAMING_UTIL_HPP

#include <freertos/task.h>

#ifdef DEBUG
#define LOG(x) Serial.println(x);
#else
#define LOG(x)
#endif

#define X_SCHEDULE_TASK(task) schadule_task([](void* args) { task; })

TaskHandle_t schadule_task(void (*task)(void *args)) {
    TaskHandle_t handle = NULL;

    xTaskCreate(task, "Task", 10000, NULL, 1, &handle);

    return handle;
}

#endif //BORED_PROGRAMING_UTIL_HPP
