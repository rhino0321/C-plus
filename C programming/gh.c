#include <stdlib.h>
#include <stdio.h>
int m,v;
void gauss(int **, int, int, int);
void gaussinverse(int **, int, int, int);
int main()
{
    //FILE READ
    int m,n;
    FILE *in;
    in = fopen("G.txt" , "r");
    if (!in) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }
    fscanf(in , "%d\n" , &n);
    fscanf(in , "%d\n" , &m);
    int arr1[m][v],numofrow=0, numofref=1, numofcolumn=0, numofHref=m;
    int H[n-m][n], Htranspose[n][n-m], ans[m][n-m], oneindex, identity[m];
    int **arr = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        arr[i] = malloc(n * sizeof(int));
    }
    printf("G:\n");
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            fscanf(in, "%d", &arr[i][j]);
            arr1[i][j]=arr[i][j];
            printf("%d ", arr[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');

    // Gauss-Jordan(down)
    while(numofrow < m-1)
    {
        if ((arr[numofrow+numofref][numofcolumn] != 0))
            gauss(arr, numofrow, numofref, n);
        numofref++;
        if (numofrow+numofref == m)
        {
            numofref=1;
            numofrow++;
            numofcolumn++;
        }
    }
    for(int i=0; i<n; i++)
    {
        if (arr[m-1][i] == 1)
        {
            oneindex=i;
            break;
        }
    }
    // Gauss-Jordan(up)
    while(numofrow > 0)
    {
        if ((arr[numofrow-numofref][oneindex] != 0) && (numofrow-numofref) >= 0)
            gaussinverse(arr, numofrow, numofref, n);
        numofref++;
        if (numofrow-numofref < 0)
        {
            numofref=1;
            numofrow--;
            oneindex--;
        }
    }
    printf("Reduce G:\n");

    //find column of pivot element
    for (int i=0; i<m; i++)
    {
        int flag=1;
        for (int j=0; j<n; j++)
        {
            if (flag && arr[i][j])
            {
                identity[i] = j;
                flag=0;
            }
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    putchar('\n');

    //switch the column(reduce G)
    for (int i=1; i<m; i++)
    {
        int t=identity[i];
        for (int j=0; j<m; j++)
        {
            int tmp = arr[j][i];
            arr[j][i]=arr[j][t];
            arr[j][t] = tmp;
        }
    }

    //construct H(left)
    for (int i=0; i<(n-m); i++)
    {
        for (int j=0; j<m; j++)
        {
            H[i][j] = arr[j][numofHref];
        }
        numofHref++;
    }

    //construct H(right)
    for (int i=0; i<(n-m); i++)
    {
        for(int j=m; j<n; j++)
            {
                if ((j-m) == i)
                    H[i][j]=1;
                else
                    H[i][j]=0;
            }
    }

    //switch the column(H)
    for (int i=(m-1); i>0; i--)
    {
        int t=identity[i];
        for (int j=0; j<(n-m); j++)
        {
            int tmp = H[j][i];
            H[j][i]=H[j][t];
            H[j][t] = tmp;
        }
    }
    printf("H:\n");
    for (int i=0; i<(n-m); i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ", H[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');

    //do Htranspose
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<(n-m); j++)
        {
            Htranspose[i][j]=H[j][i];
            printf("%d ", Htranspose[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');

    //find G*Htranspose=O
    for(int i=0; i<m;i++)
    {
        for(int j=0;j<(n-m); j++)
        {
            ans[i][j]=0;
            for(int m=0; m<n; m++)
            {
                ans[i][j]=ans[i][j]^(arr1[i][m]&Htranspose[m][j]);
            }
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}

void gauss(int **arr, int numofrow, int numofref, int col)
{
    for(int j=0; j<col; j++)
    {
        arr[numofrow+numofref][j]=(arr[numofrow][j])^(arr[numofrow+numofref][j]);
    }
}
void gaussinverse(int **arr, int numofrow, int numofref, int col)
{
    for(int j=0; j<col; j++)
    {
        arr[numofrow-numofref][j]=(arr[numofrow][j])^(arr[numofrow-numofref][j]);
    }
}
