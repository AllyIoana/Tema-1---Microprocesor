#include <stdio.h>
#include <math.h>
#define N 35

int main() {
    unsigned int inst, v[N], aux;
    unsigned int nr = 0, bit1, bit2, nrb, nec;
    unsigned short x, mask;
    int op[N] = {0}, nrop, i = 0, j, k, rezultat, suma, produs, dim, dim2;
    char semn[N];
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

    // operatii

    nrop = 0;
    for (i = 0; i < nr; i++) {
        bit1 = v[3 + i * 2];
        bit2 = v[4 + i * 2];
        if (bit1 == 0 && bit2 == 0)
            semn[++nrop] = '+';
        else if (bit1 == 0 && bit2 == 1)
            semn[++nrop] = '-';
        else if (bit1 == 1 && bit2 == 0)
            semn[++nrop] = '*';
        else
            semn[++nrop] = '/';
    }

    // dimensiune

    nrb = nr * 2 + 3;
    dim = 8 * v[nrb] + 4 * v[nrb + 1] + 2 * v[nrb + 2] + v[nrb + 3] + 1;

    // numere de introdus (necesare)

    nec = ((nr + 1) * dim) / 16;
    if (((nr + 1) * dim) % 16 != 0)
        nec++;

    // introducere numere

    nrop = 0;
    dim2 = 0;
    for (i = 1; i <= nec; i++) {
        scanf("%hu", &x);
        mask = pow(2, 15);
        while (mask > 0 && nrop < nr + 1) {
            if (dim2 == 0)
                dim2 = dim;
            nrop++;
            while (dim2 > 0) {
                if ((mask & x) == mask)
                    op[nrop] = op[nrop] + pow(2, dim2 - 1);
                mask = mask >> 1;
                dim2--;
                if (mask == 0) {
                    nrop--;
                    break;
                }
            }
        }
    }

    // calculam operatiile prioritare

    for (i = 1; i < nrop; i++)
        if (semn[i] == '*' || semn[i] == '/') {
            j = 0;
            produs = op[i];
            while ((semn[i + j] == '*' || semn[i + j] == '/') && i + j < nrop) {
                switch (semn[i + j]) {
                case '*':
                    produs *= op[i + j + 1];
                    break;
                case '/':
                    produs /= op[i + j + 1];
                    break;
                }
                j++;
            }
            op[i] = produs;
            for (k = i + 1; k <= i + j; k++)
                op[k] = 1;
            i = i + j - 1;
        }

    // calcul final

    rezultat = op[1];
    for (i = 1; i < nrop + 1; i++) {
        switch (semn[i]) {
        case '+':
            rezultat += op[i + 1];
            break;
        case '-':
            rezultat -= op[i + 1];
            break;
        case '*':
            rezultat *= op[i + 1];
            break;
        case '/':
            rezultat /= op[i + 1];
            break;
        }
    }
    printf("%d\n", rezultat);
}
