#include <stdio.h>


struct climate{
    double temperature;
    int pressure;
    int humidity;
};

void insertClimate(struct climate* data, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter Temperature:");
        scanf("%lf",&data[i].temperature);
        printf("Enter Pressure:");
        scanf("%d",&data[i].pressure);
        printf("Enter Humidity:");
        scanf("%d",&data[i].humidity);
    }
}

void writeClimateToFile(struct climate* data, int size, const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "Temperature,Pressure,Humidity\n");
    for (int i = 0; i < size; i++) {
        fprintf(fp, "%lf;%d;%d\n", data[i].temperature, data[i].pressure, data[i].humidity);
    }

    fclose(fp);
    printf("Data written to %s\n", filename);
}

int main() {
    struct climate data[5];

    insertClimate(data,5);
    writeClimateToFile(data, 5, "climate_data.csv");

    return 0;
}
