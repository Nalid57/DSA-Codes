// pthread code for matrix multiplication

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define N 1600
#define THREADS 8

void *runner(void *param);

float mat1[N][N], mat2[N][N], res[N][N];

int main(int argc, char *argv[])
{
    int i, j, k;
    printf("Matrix multiplication using pthreads\n");
    struct timeval start, stop;

    // initialize matrices
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            float rand1 = (rand() % 100) / 2.0;
            // printf("rand1: %d", rand1);
            mat1[i][j] = rand1;
            mat2[i][j] = (rand1) / 2.0;
            res[i][j] = 0;
        }
    }

    // start timer
    gettimeofday(&start, 0);

    pthread_t tid[THREADS]; // thread id
    // pthread_attr_t attr;      // set of thread attributes
    // pthread_attr_init(&attr); // get the default attributes

    for (i = 0; i < THREADS; i++)
    {
        if (pthread_create(&tid[i], NULL, runner, (void *)i) != 0)
        {
            printf("Error creating thread");
        }
    }

    for (i = 0; i < THREADS; i++)
    {
        if (pthread_join(tid[i], NULL) != 0)
        {
            printf("Error joining thread");
        }
    }

    // stop timer
    gettimeofday(&stop, 0);
    printf("Time spent = %.6f\n\n", (stop.tv_sec + stop.tv_usec * 1e-6) - (start.tv_sec + start.tv_usec * 1e-6));
}

void *runner(void *param)
{
    int x, low, high;
    if (N >= THREADS)
    {
        x = N / THREADS;
        low = (int)param * x;
        high = low + x;
    }
    else
    {
        x = 1;
        low = (int)param;
        if (low >= N)
        {
            high = low;
        }
        else
        {
            high = low + 1;
        }
    }
    int i, j, k;
    for (i = low; i < high; i++)
    {
        for (j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
            {
                res[i][j] = res[i][j] + mat1[i][k] * mat2[k][j];
            }
        }
    }
}