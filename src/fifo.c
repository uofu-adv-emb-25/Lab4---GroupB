#include <fifo.h>

void fifo_worker_handler(QueueHandle_t requests, QueueHandle_t results, int id)
{
    struct request_msg data = {};
    if(xQueueReceive(requests, &data, 0xffff))
    {
        data.output = data.input + 5;
        data.handled_by = id;
        xQueueSendToBack(results, &data, 0xffff);
    }
    return;
}