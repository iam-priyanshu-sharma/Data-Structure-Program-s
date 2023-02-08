#include <stdio.h>
#include <conio.h>
void towers_of_hanoi(int n, char *a, char *b, char *c);
int cnt = 0;
int main(void)
{
    int n;
    printf("Enter number of discs: ");
    scanf("%d", &n);
    towers_of_hanoi(n, "Tower 1", "Tower 2", "Tower 3");
    getch();
}
void towers_of_hanoi(int n, char *a, char *b, char *c)
{
    if (n == 1)
    {
        ++cnt;
        printf("\n%5d: Move disk 1 from %s to %s", cnt, a, c);
        return;
    }
    else
    {
        towers_of_hanoi(n - 1, a, c, b);
        ++cnt;
        printf("\n%5d: Move disk %d from %s to %s", cnt, n, a, c);
        towers_of_hanoi(n - 1, b, a, c);
        return;
    }
}