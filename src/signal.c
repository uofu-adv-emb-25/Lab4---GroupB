#include <signaling.h>

void signal_handle_calculation(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data){
    xSemaphoreTake(request, 0x1111);
    data->output = data->input + 5;
    xSemaphoreGive(response);
    return;
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data){
    xSemaphoreGive(request);
    return xSemaphoreTake(response, 0x1111);
}