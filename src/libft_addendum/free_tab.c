#include <stdlib.h> // free

void free_tab(char **tab) {
        int i;

        i=0;
        while (tab[i])
                free(tab[i++]);
        free(tab);
}
