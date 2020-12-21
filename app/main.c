#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

/*

    Neste codigo implementaremos os seguintes semaforos que irão
     ajudar na sincronizaçao de 3 threas que irao imprimir a 
     molecula HHSOOOO
    
*/

void print_ascii_image(FILE *fptr);
void prit_ft_logo();
void *thr_Hidrogenio();
void *thr_Enxofre();
void *thr_Oxigenio();
void cria_molecula();

volatile int H = 0;
volatile int S = 0;
volatile int O = 0;

sem_t *s1;
sem_t *s2;

// semaforos nomeados sao necessario para o mac
static const char *semname1 = "Semaphore_H";
static const char *semname2 = "Semaphore_S";
static const char *semname3 = "Semaphore_O";

int main(int argc, char *argv[])
{
    // ;)
    prit_ft_logo();

    printf("Demonstarção de threads com pthreads.h\n\n\n");

    int qnt_moleculas = 0;
    int qnt_moleculas_impressas = 0;
    printf("Entre com a quantidade de momeculas que devem ser geradas: ");
    scanf("%d", &qnt_moleculas);

    // Loop para gerar as moleculas pedidas
    while (qnt_moleculas_impressas < qnt_moleculas)
    {
        cria_molecula();
        qnt_moleculas_impressas++;
        printf("\n");
    }

    //indicando que o programa acabou com sucesso
    return 0;
}

void prit_ft_logo()
{
    char *filename = "./resources/ascii-art_ft.txt";
    FILE *fptr = NULL;

    if ((fptr = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "error opening %s\n", filename);
        exit(1);
    }

    printf("\n\n\n\n\n");

    print_ascii_image(fptr);

    fclose(fptr);

    printf("\n\n\n\n\n");
}

void print_ascii_image(FILE *fptr)
{
    int MAX_LEN = 100;
    char read_string[MAX_LEN];

    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
        printf("%s", read_string);
}

void cria_molecula()
{
    H = 0;
    S = 0;
    O = 0;
    void *status;

    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    srand(time(NULL));

    // semaforos nomeados sao necessario para o mac
    s1 = sem_open(semname1, O_CREAT, 0777, 0);
    if (s1 == SEM_FAILED)
    {
        fprintf(stderr, "%s\n", "ERROR creating semaphore Semaphore_H");
        exit(EXIT_FAILURE);
    }

    // semaforos nomeados sao necessario para o mac
    s2 = sem_open(semname2, O_CREAT, 0777, 0);
    if (s2 == SEM_FAILED)
    {
        fprintf(stderr, "%s\n", "ERROR creating semaphore Semaphore_S");
        exit(EXIT_FAILURE);
    }

    while (O < 4) // Significa que a molecula ainda nao esta pronta
    {
        pthread_create(&thread1, NULL, thr_Hidrogenio, NULL);
        pthread_create(&thread2, NULL, thr_Enxofre, NULL);
        pthread_create(&thread3, NULL, thr_Oxigenio, NULL);

        pthread_join(thread1, &status);
        pthread_join(thread2, &status);
        pthread_join(thread3, &status);
    }

    sem_unlink(semname1);
    sem_unlink(semname2);
}

void *thr_Hidrogenio()
{
    for (;;)
    {
        if (H < 2)
        {
            printf("H");
            H++;
        }
        sem_post(s1);
        // Esse break independe de condiçao e garante
        // que a thread vai gerara no maximo 1 atomo
        break;
    }
}

void *thr_Enxofre()
{
    for (;;)
    {
        sem_wait(s1);
        if (S < 1 && H >= 2)
        {
            printf("S");
            S++;
        }
        sem_post(s2);
        // Esse break independe de condiçao e garante
        // que a thread vai gerara no maximo 1 atomo
        break;
    }
}

void *thr_Oxigenio()
{
    for (;;)
    {
        sem_wait(s2);
        if (O < 4 && H >= 2)
        {
            printf("O");
            O++;
        }
        // Esse break independe de condiçao e garante
        // que a thread vai gerara no maximo 1 atomo
        break;
    }
}
void cria_molecula();

volatile int H = 0;
volatile int S = 0;
volatile int O = 0;

sem_t *s1;
sem_t *s2;

// semaforos nomeados sao necessario para o mac
static const char *semname1 = "Semaphore_H";
static const char *semname2 = "Semaphore_S";
static const char *semname3 = "Semaphore_O";

int main(int argc, char *argv[])
{
    // ;)
    prit_ft_logo();

    printf("Demonstarção de threads com pthreads.h\n\n\n");

    int qnt_moleculas = 0;
    int qnt_moleculas_impressas = 0;
    printf("Entre com a quantidade de momeculas que devem ser geradas: ");
    scanf("%d", &qnt_moleculas);

    // Loop para gerar as moleculas pedidas
    while (qnt_moleculas_impressas < qnt_moleculas)
    {
        cria_molecula();
        qnt_moleculas_impressas++;
        printf("\n");
    }

    //indicando que o programa acabou com sucesso
    return 0;
}

void prit_ft_logo()
{
    char *filename = "./resources/ascii-art_ft.txt";
    FILE *fptr = NULL;

    if ((fptr = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "error opening %s\n", filename);
        exit(1);
    }

    printf("\n\n\n\n\n");

    print_ascii_image(fptr);

    fclose(fptr);

    printf("\n\n\n\n\n");
}

void print_ascii_image(FILE *fptr)
{
    int MAX_LEN = 100;
    char read_string[MAX_LEN];

    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
        printf("%s", read_string);
}

void cria_molecula()
{
    H = 0;
    S = 0;
    O = 0;
    void *status;

    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    srand(time(NULL));

    // semaforos nomeados sao necessario para o mac
    s1 = sem_open(semname1, O_CREAT, 0777, 0);
    if (s1 == SEM_FAILED)
    {
        fprintf(stderr, "%s\n", "ERROR creating semaphore Semaphore_H");
        exit(EXIT_FAILURE);
    }

    // semaforos nomeados sao necessario para o mac
    s2 = sem_open(semname2, O_CREAT, 0777, 0);
    if (s2 == SEM_FAILED)
    {
        fprintf(stderr, "%s\n", "ERROR creating semaphore Semaphore_S");
        exit(EXIT_FAILURE);
    }

    while (O < 4) // Significa que a molecula ainda nao esta pronta
    {
        pthread_create(&thread1, NULL, thr_Hidrogenio, NULL);
        pthread_create(&thread2, NULL, thr_Enxofre, NULL);
        pthread_create(&thread3, NULL, thr_Oxigenio, NULL);

        pthread_join(thread1, &status);
        pthread_join(thread2, &status);
        pthread_join(thread3, &status);
    }

    sem_unlink(semname1);
    sem_unlink(semname2);
}

void *thr_Hidrogenio()
{
    for (;;)
    {
        if (H < 2)
        {
            printf("H");
            H++;
        }
        sem_post(s1);
        // Esse break independe de condiçao e garante
        // que a thread vai gerara no maximo 1 atomo
        break;
    }
}

void *thr_Enxofre()
{
    for (;;)
    {
        sem_wait(s1);
        if (S < 1 && H >= 2)
        {
            printf("S");
            S++;
        }
        sem_post(s2);
        // Esse break independe de condiçao e garante
        // que a thread vai gerara no maximo 1 atomo
        break;
    }
}

void *thr_Oxigenio()
{
    for (;;)
    {
        sem_wait(s2);
        if (O < 4 && H >= 2)
        {
            printf("O");
            O++;
        }
        // Esse break independe de condiçao e garante
        // que a thread vai gerara no maximo 1 atomo
        break;
    }
}