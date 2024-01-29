#include "stdio.h"
#include <cstring>

// We use `const char` here to ensure these strings are immutable.
const char *titles[] = {"A Tale of Two Cities",
                  "Wuthering Heights", "Don Quixote",
                  "Odyssey", "Moby-Dick", "Hamlet",
                  "Gulliver's Travels",
                  "this is a super duper long string"};

char ** getBestBook(char *bestBooks) {
    char *bestBooks_ptr = bestBooks;
    // This also works, as we are obtaining a ptr at the first element of the char array.
    // char *bestBooks_ptr = &bestBooks[0];

    // this is the double pointer
    char **bestBooks_ptr2 = &bestBooks_ptr;

    // Since we are storing a pointer into `bestBooks_ptr2[0]`, we do not need to use `&`
    // on the rvalue.
    // We need to cast the pointer to `(char *)` from `(const char *)`.
    bestBooks_ptr2 = (char **)&titles[0];

    return bestBooks_ptr2;
}

char ** getBestBook2() {
    char **bestBooks[3];
    bestBooks[0] = (char **)&titles[7];

    return *bestBooks;
}

int main()
{
    char bestBooks[3];
    char **book = getBestBook(bestBooks);
    printf("Output: ");
    printf("%s / len: (%lu) / mem: (%lu)\n", *book, strlen(*book), sizeof(*book));

    char **book2 = getBestBook2();
    printf("Output: ");
    printf("%s / len: (%lu) / mem: (%lu)\n", book2[0], strlen(book2[0]), sizeof(book2[0]));
};
