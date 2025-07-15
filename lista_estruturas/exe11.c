#include <stdio.h>
#include <time.h>

struct Data {
    int dia, mes, ano;
};

int dias_entre_datas(struct Data d1, struct Data d2) {
    struct tm data1 = {0}, data2 = {0};

    data1.tm_mday = d1.dia;
    data1.tm_mon = d1.mes - 1;
    data1.tm_year = d1.ano - 1900;

    data2.tm_mday = d2.dia;
    data2.tm_mon = d2.mes - 1;
    data2.tm_year = d2.ano - 1900;

    time_t t1 = mktime(&data1);
    time_t t2 = mktime(&data2);

    double diff = difftime(t2, t1) / (60 * 60 * 24);
    return (int)(diff >= 0 ? diff : -diff);
}

int main() {
    struct Data d1, d2;
    printf("Digite a primeira data (dd mm aaaa): ");
    scanf("%d %d %d", &d1.dia, &d1.mes, &d1.ano);
    printf("Digite a segunda data (dd mm aaaa): ");
    scanf("%d %d %d", &d2.dia, &d2.mes, &d2.ano);

    int dias = dias_entre_datas(d1, d2);
    printf("Dias entre as datas: %d\n", dias);
    return 0;
}
