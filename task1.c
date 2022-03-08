#include <stdio.h>
#define N 35

int main() {
    unsigned int inst, v[N], i = 0, aux;
    unsigned int nr = 0, bit1, bit2, dim;
    scanf("%u", &inst);

    // transformam in binar

    while (inst > 0) {
        v[i++] = inst % 2;
        inst /= 2;
    }

    for (; i < 32; i++)
        v[i] = 0;

    // am format vectorul cu biti

    for (i = 0; i <= 15; i++) {
        aux = v[i];
        v[i] = v[31 - i];
        v[31 - i] = aux;
    }

    // numarul de instructiuni: 3 biti

    nr = 2 * 2 * v[0] + 2 * v[1] + v[2] + 1;
    printf("%u", nr);

    // operatii

    for (i = 0; i < nr; i++) {
        bit1 = v[3 + i * 2];
        bit2 = v[4 + i * 2];
        if (bit1 == 0 && bit2 == 0)
            printf(" +");
        else if (bit1 == 0 && bit2 == 1)
            printf(" -");
        else if (bit1 == 1 && bit2 == 0)
            printf(" *");
        else
            printf(" /");
    }

    // dimensiune
    nr *= 2;
    nr += 3;
    dim = 2 * 2 * 2 * v[nr] + 2 * 2 * v[nr + 1] + 2 * v[nr + 2] + v[nr + 3] + 1;
    printf(" %u\n", dim);
}
