/* Check whether the given matrix is sparse matrix or not, if so then print in alternative form for storage. */
#include <stdio.h>
#include <conio.h>
main()
{
    int matrix[20][20], m, n, total_elements, total_zeros = 0, i, j;
    printf("\n Enter Number of rows and columns: ");
    scanf("%d %d", &m, &n);
    total_elements = m * n;
    printf("\n Enter data for sparse matrix: ");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0)
            {
                total_zeros++;
            }
        }
    }
    if (total_zeros > total_elements / 2)
    {
        printf("\n Given Matrix is Sparse Matrix..");
        printf("\n The Representaion of Sparse Matrix is: \n");
        printf("\n Row \t Col \t Value ");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (matrix[i][j] != 0)
                {
                    printf("\n %d \t %d \t %d", i, j, matrix[i][j]);
                }
            }
        }
    }
    else
        printf("\n Given Matrix is Not a Sparse Matrix..");
}