#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(demo, LOG_LEVEL_DBG);

#define STACK_SIZE 1024

#define PRIO_L 7
#define PRIO_M 5
#define PRIO_H 3
#define PRIO_C (-1)
#define DELAYED_START_MS 3000

void t_low_fn(void *p1, void *p2, void *p3)
{
    while (1) {
        LOG_INF("T_LOW running");
        k_msleep(300);
    }
}

void t_med_fn(void *p1, void *p2, void *p3)
{
    while (1) {
        LOG_INF("T_MED running");
        k_msleep(200);
    }
}

void t_high_fn(void *p1, void *p2, void *p3)
{
    while (1) {
        LOG_INF("T_HIGH running");
        k_msleep(100);
    }
}

void t_coop_fn(void *p1, void *p2, void *p3)
{
    while (1) {
        for (int i = 0; i < 5; i++) {
            volatile uint32_t sum = 0;

            for (int j = 0; j < 1000; j++) {
                sum += j;
            }

            LOG_INF("T_COOP running, iteration=%d/5", i+1);
        }
        k_yield();
    }
}

K_THREAD_DEFINE(thread_low, STACK_SIZE, t_low_fn,
                NULL, NULL, NULL, PRIO_L, 0, 0);
K_THREAD_DEFINE(thread_med, STACK_SIZE, t_med_fn,
                NULL, NULL, NULL, PRIO_M, 0, 0);
K_THREAD_DEFINE(thread_high, STACK_SIZE, t_high_fn,
                NULL, NULL, NULL, PRIO_H, 0, 0);

K_THREAD_DEFINE(thread_coop, STACK_SIZE, t_coop_fn,
                NULL, NULL, NULL, PRIO_C, 0, DELAYED_START_MS);

int main(void)
{
    return 0;
}

