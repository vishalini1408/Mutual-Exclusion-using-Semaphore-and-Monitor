#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s;
int balance = 1000;

void *withdraw(void *a) {
    long id = (long)a;
    sem_wait(&s);
    balance -= 100;
    printf("Customer %ld: Balance=%d\n", id, balance);
    sem_post(&s);
    return NULL;
}

int main(void) {
    int n;
    printf("Enter customers: ");
    scanf("%d", &n);

    pthread_t t[n];
    sem_init(&s, 0, 1);

    for (long i = 1; i <= n; i++)
        pthread_create(&t[i - 1], NULL, withdraw, (void *)i);

    for (int i = 0; i < n; i++)
        pthread_join(t[i], NULL);

    sem_destroy(&s);
    return 0;
}
