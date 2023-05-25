#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define FILES 10
#define SIZE 32
#define PLAY '1'
#define DIFFICULTY '2'
#define EXIT 'X'
#define MAX_FAILS 7
#define FILE_DEFAULT "Files/dif1.dat"
#define random(min, max) (rand() % (max - min + 1) + min)

typedef struct 
{
    int counter;
    char* letters;
}Fail;


typedef struct 
{
    char word[SIZE];
    float difficulty;
} Element;


void game();
void printFirstHangman(); // Falta terminar
void printHangman(int fails, char *word, int *hits);
FILE *choiceDifficulty();
void printFails(Fail F);
char *randomWord(FILE *file);
int showLetter(char *word, int *corrects, char choice);
void addFail(Fail *F, char letter);
void showVictoryMessage();

int main(){
    srand(time(NULL));
    game();
    return 0;
}


void game(){
    printFirstHangman(5);
    FILE *file = fopen(FILE_DEFAULT, "rb");
    if(file == NULL){
        printf("No es posible abrir el archivo binario.\n");
        exit(1);
    }

    printf("[1] Jugar         [2] Dificultad         [X] Salir\n\n");
    printf("Presione Enter para elegir: ");
    
    char choice;
    scanf("%c",&choice);
    toupper(choice);
    if (choice == DIFFICULTY)
    {
        file = choiceDifficulty();
    }
    else 
        if(toupper(choice) == EXIT){
            printf("\n\nEl juego ha finalizo. Gracias por jugar.\n\n");
            exit(1);
        }
    if(choice != PLAY)
        game();
    while (getchar() != '\n');

    while (1)
    {
        char *word = randomWord(file);
        int *hits = calloc(sizeof(int), strlen(word));
        Fail F;
        F.counter = 0;
        F.letters = malloc(sizeof(char));
        while (1){
            system("clear");
            printHangman(F.counter, word, hits);
            printFails(F);
            do
            {
                printf("Ingrese Letra: ");
                scanf("%c", &choice);
                choice = tolower(choice);
                while (getchar() != '\n');
            } while (choice < 'a' && choice > 'z');
            char *ptr = strchr(word, choice);
            if ((ptr != NULL) && hits[ptr - word] != 1)
            {                                       // Si se encuentra en la cadena y no fue ingresado antes
                if (showLetter(word, hits, choice)){ // Muestro letras y comparo
                    showVictoryMessage();
                    break;
                }
            }
            else{
                addFail(&F, choice); //Anda mal
                if(F.counter == MAX_FAILS){
                    printHangman(F.counter, word, hits);
                    printf("Perdiste :( La palabra era %s", word);
                    break;
                }
            }
        }
        printf("¿Quieres seguir jugando?   [S] Si     [N] No\n");
        scanf("%c", &choice);
        while (getchar() != '\n');
        if(tolower(choice) == 's')
            continue;
        break;
        }
}

void printFirstHangman() {
    const char* partesCuerpo[] = {
        "  |         | \n", //0
        "  |         O \n", //1
        "  |        /|\\\n",//2
        "  |         |  \n",//3
        "  |        / \\  \n"//4
    };

    printf("  ___________\n");
    printf("%s", partesCuerpo[0]);
    printf("%s", partesCuerpo[1]);
    printf("%s", partesCuerpo[2]);
    printf("%s", partesCuerpo[3]);
    printf("%s", partesCuerpo[4]);
    printf("  |            \n");
    printf("__|__               ELAH_RCAD_\n\n\n");
}

void printHangman(int fails, char* word, int* hits) {
    const char* partesCuerpo[] = {
        "  |         | \n", //0
        "  |         O \n", //1
        "  |         | \n", //2
        "  |        /|\n",  //3
        "  |        /|\\\n",//4
        "  |         |  \n",//5
        "  |        /  \n", //6
        "  |        / \\  \n"//7
    };
    int aux = 0;
    printf("  ___________\n");
    printf("%s", partesCuerpo[0]);
    if(fails >= 1)
        printf("%s", partesCuerpo[1]);
    else
        aux++;
    switch (fails)
    {
    case 2:
        printf("%s", partesCuerpo[2]);
        break;
    case 3:
        printf("%s", partesCuerpo[3]);
        break;
    default:
        if(fails >= 4)
            printf("%s", partesCuerpo[4]);
        else
            aux++;
    }
    if(fails >= 5)
        printf("%s", partesCuerpo[5]);
    else
        aux++;
    if (fails == 6)
        printf("%s", partesCuerpo[6]);
    else if(fails == 7)
        printf("%s", partesCuerpo[7]);
    else
        aux++;
    for (int i = 0; i < aux; i++)
        printf("  |\n");

    printf("  |            \n");
    printf("__|__               ");
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        if(hits[i] == 1)
            printf("%c", word[i]);
        else
            printf("_");
    }
    printf("\n");
}

FILE* choiceDifficulty(){
    printf("Elegir el nivel de dificultad: van del 1 (difícil) al 10 (fácil): ");
    int choice;

    while(1){
        scanf("%d",&choice);
        if(choice >= 1 && choice <= FILES){
            char name[30];
            sprintf(name, "Files/dif%d.dat", FILES + 1 - choice);
            FILE *file = fopen(name, "rb");
            return file;
        }
    }
}

void printFails(Fail F){
    printf("Letras incorrectas  [");
    for (int i = 0; i < F.counter; i++)
        printf("%c ", F.letters[i]);
    printf("]\n");
}

char* randomWord(FILE* file){
    fseek(file, 0, SEEK_END);
    size_t tot = ftell(file)/ sizeof(Element);
    fseek(file, random(0, tot - 1)*sizeof(Element), SEEK_SET);
    Element E;
    fread(&E, sizeof(Element), 1, file);
    char* word = strdup(E.word);
    return word;
}

int showLetter(char* word,int* hits, char choice){
    int counter = 0;
    int len = strlen(word);
    for (int i = 0; i < len; i++){
        if(word[i] == choice)
            hits[i] = 1;
        if(hits[i] == 1)
            counter++;
    }
    return (counter == strlen(word));
}

void addFail(Fail* F, char letter){
    int flag = 0;
    for (int i = 0; i < F->counter; i++)
    {
        if(F->letters[i] == letter){
            flag = 1;
            break;
        }
    }
    if(!flag){
        F->counter++;
        F->letters = realloc(F->letters, sizeof(char) * F->counter);
        F->letters[F->counter - 1] = letter;
    }
}

void showVictoryMessage() {
    printf("   \\o/\n");
    printf("    |           ¡Ganaste!\n");
    printf("   / \\ \n");
}