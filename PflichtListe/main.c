#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum Datatype{STRING, INTEGER};

struct stack{
    union{
        int nmbr;
        char *word;

    }data;
    enum Datatype type;
    struct stack *next;

};
struct stack *top = NULL;

void pushint(int element){
    struct stack *newele = malloc(sizeof(struct stack));
    newele->data.nmbr = element;
    newele->type = INTEGER;
    newele->next = top;
    top = newele;


}
void pushstring(char *element){
    struct stack *newele = malloc(sizeof(struct stack));
    newele->data.word = strdup(element);
    newele->type = STRING;
    newele->next = top;
    top = newele;

}
void *pop(){
    if(top == NULL){
        return NULL;
    }
    struct stack *helper = top;
    top = helper->next;
    void *memoryloc;
    if(helper->type == INTEGER){
        memoryloc = &helper->data.nmbr;

    }
    else{
        memoryloc = helper->data.word;

    }
    free(helper);
    return memoryloc;

}


void addint(){
    int amount;
    printf("\nMenge an zu speichernden integer angeben:\n");
    scanf("%i", &amount);
    for(int i = 0; i < amount; i++){
        int element;
    printf("\n Zu speichernde Integer angeben und mit Enter bestätigen:");
    scanf("%i", &element);
    pushint(element);
    }

}
void addstring(){
    int amount;
    printf("\nMenge an zu speichernden Strings angeben:\n");
    scanf("%i", &amount);
    for(int i = 0; i < amount; i++){
        char element[20];
        printf("\n Zu speichernde Strings angeben und mit Enter bestätigen (max. 20 Zeichen):\n");
        scanf("%s", element);
        pushstring(element);
    }

}

void add(){
    int choice;
    printf("\n1 um Integer zu speichern, 2 um Strings zu speichern, 3 um zurück ins Hauptmenü zu kommen\n");
    scanf("%i", &choice);
    if(choice == 1){
        addint();

    }
    else if(choice == 2){
        addstring();

    }
    else{
        return;

    }

}

void fetch(){
    for(int i = 0; i == 0;){
        if(top->type == INTEGER){
            printf("\n%i\n", top->data.nmbr);

        }
        else{
            printf("\n%s\n", top->data.word);

        }
        pop();
        if(top == NULL){
            printf("Der Stack ist leer");
            i = 1;
        }
    }

}


int main() {
    for(int i = 0; i==0;) {
        int choice;
        printf("\n1 um Daten zu Speichern, 2 um Daten abzurufen, 3 um das Programm zu beenden\n");
        scanf("%i", &choice);
        if (choice == 1) {
            add();

        } else if (choice == 2) {
            fetch();

        }
        else{
            i = 1;

        }
    }

}
