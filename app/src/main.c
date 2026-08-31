#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(demo, LOG_LEVEL_DBG);

#define STACK_SIZE 1024

#define PRIO 5
#define ITERATIONS 1000000

static volatile uint32_t counter;

K_MUTEX_DEFINE(lock);

static void worker_fn(void *p1, void *p2, void *p3)
{
    for (int i = 0; i < ITERATIONS; i++) {
        k_mutex_lock(&lock, K_FOREVER);
        counter++;
        k_mutex_unlock(&lock);
    }
}

K_THREAD_DEFINE(thread_a, STACK_SIZE, worker_fn,
                NULL, NULL, NULL, PRIO, 0, 0);
K_THREAD_DEFINE(thread_b, STACK_SIZE, worker_fn,
                NULL, NULL, NULL, PRIO, 0, 0);

int main(void)
{
    k_thread_join(thread_a, K_FOREVER);
    k_thread_join(thread_b, K_FOREVER);

    LOG_INF("Counter: %u  Expected: %u  Lost: %u", counter, ITERATIONS * 2, ITERATIONS * 2 - counter);
    return 0;
}
