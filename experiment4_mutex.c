#include <stdio.h>
#include <pthread.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
int slots = 5;

void *park(void *id) {
    pthread_mutex_lock(&m);
    slots--;
    printf("Vehicle %ld: Slots=%d\n", (long)id, slots);
    pthread_mutex_unlock(&m);
    return NULL;
}

int main(void) {
    int n;
    printf("Enter vehicles: ");
    scanf("%d", &n);

    pthread_t t[n];
    for (long i = 1; i <= n; i++)
        pthread_create(&t[i - 1], NULL, park, (void *)i);

    for (int i = 0; i < n; i++)
        pthread_join(t[i], NULL);

    pthread_mutex_destroy(&m);
    return 0;
}
