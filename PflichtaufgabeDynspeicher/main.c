#include <stdlib.h>
#include <stdio.h>

struct Array {
    int size;
    int capacity;
    int *nmbr;
    int zaehler;

};
int linearsearch(struct Array *array,int element){
    array->zaehler++;
    //lineare suche des elements im array index wird mit i zurückgegeben oder -1 wenn fehlgeschlagen
    for(int i = 0; i < array->size; i++){
        if(array->nmbr[i] == element){
            return i;

        }

    }
    return -1;

}

void insert(struct Array *array, int element){
    array->zaehler++;
    //Platz im Array wird getestet und ggf mit realloc "erweitert"
    if(array->size == array->capacity){
        array->capacity += 2;
        array->nmbr = realloc(array->nmbr, sizeof(int) * array->capacity);

    }
    array->nmbr[array->size] = element;
    array->size++;

}

void delete(struct Array *array, int element){
    array->zaehler++;
    //index wird in gesucht durch such funktion
    int index = linearsearch(array, element);
    if(index >= 0) {
        //Jedes element "rechts" vom zu löschenden wird um eins nach links verschoben das zu löschende element wird einfach überschrieben
        for (int i = index; i < array->size - 1; i++) {
            array->nmbr[i] = array->nmbr[i + 1];

        }
        array->size--;
        //Platz im array wird getestet und verkleinert wenn zu groß
        if (array->size == array->capacity - 2) {
            array->capacity -= 2;
            array->nmbr = realloc(array->nmbr, sizeof(int) * array->capacity);

        }
    }
    else{
        printf("\nElement ist nicht im array\n");
        return;
    }



}


int main(){
    struct Array array;
    //Struct wird erstellt und belegt
    array.size = 0;
    array.capacity = 10;
    array.nmbr = malloc(sizeof(int) * array.capacity);
    array.zaehler = 0;

    for(int i = 1; i == 1;){
        int choice = 0;
        printf("\n1 um Elemente hinzuzufuegen, 2 um ein Element zu suchen, 3 um ein Element zu loeschen oder 4 um das Programm zu beenden\n");
        scanf("%i", &choice);
        if (choice == 1){
            int choice2;
            printf("\nWie viele Elemente sollen hinzugefuegt werden?\n");
            scanf("%i", &choice2);
            for(int x = 0; x < choice2; x++){
                int helper = 0;
                printf("\nHinzuzufuegende Zahl eingeben\n");
                scanf("%i", &helper);
                insert(&array, helper);

            }

        }
        else if(choice == 2){
            int helper, index;
            printf("\nZu suchendes Element eingeben\n");
            scanf("%i", &helper);
            index = linearsearch(&array, helper);
            if(index >= 0) {
                printf("\nDie gesuchte Zahl ist an Stelle: %i \n", index);
            }
            else{
                printf("\nDie gesuchte Zahl ist nicht im array\n");
            }
        }
        else if(choice == 3){
            int helper;
            printf("\nZu loeschendes Element eingeben:\n");
            scanf("%i", &helper);
            delete(&array, helper);

        }
        else if(choice == 4){
            i = 0;

        }
        else{
            printf("\n Falsche Eingabe\n");

        }
    }
    printf("Die Funktionen wurden %i mal verwendet", array.zaehler);

}