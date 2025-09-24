#include <signaling.h>

void signal_handle_calculation(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data){
    xSemaphoreTake(request, portMAX_DELAY);
    data->output = data->input + 5;
    xSemaphoreGive(response);
    return;
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data){
    printf("Recieving request semaphore");
    xSemaphoreGive(request);
    printf("Returning response semaphore");
    return xSemaphoreTake(response, portMAX_DELAY);
}