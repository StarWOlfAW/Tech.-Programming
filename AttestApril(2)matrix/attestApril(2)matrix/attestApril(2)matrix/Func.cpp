#include "Header.h"
#include <iostream>
#include <ctime>

using namespace std;

void input_matrix(int** a, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = rand() % 90 + 10;
}
void output_matrix(int** a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
void output_desired(int** a, int n, int m)
{
      int top = 0, bottom = n - 1;
 int left = 0, right = m - 1;
 int max = a[0][0], min = a[0][0];

 while (top <= bottom && left <= right) {
     for (int i = left; i <= right; i++) {
         cout << a[top][i] << " ";
         if (max < a[top][i])
             max = a[top][i];
     }
     top++;

     for (int i = top; i <= bottom; i++) {
         cout << a[i][right] << " ";
         if (max < a[i][right])
             max = a[i][right];
     }
     right--;

     if (top <= bottom) {
         for (int i = right; i >= left; i--) {
             cout << a[bottom][i] << " ";
             if (max < a[bottom][i])
                 max = a[bottom][i];
         }
         bottom--;
     }

     if (left <= right) {
         for (int i = bottom; i >= top; i--) {
             cout << a[i][left] << " ";
             if (max < a[i][left])
                 max = a[i][left];
             if (min > a[i][left])
                 min = a[i][left];
         }
         left++;
     }
     ;
 }
 /*for (int i = m; i < m /2; i--)
     {
         for (int k = i; k > n-i; k--)
             {
             cout << a[k-1][i-1] << " ";
             if (max < a[k-1][i-1])
                 max = a[k-1][i-1];
             if (min > a[k-1][i-1])
                 min = a[k-1][i-1];
                 }
     }*/
     /* for (int i = 0; i < m /2; i++)
      {
           for (int k = i; k < m; k++)
              {
              cout << a[k][i] << " ";
              if (max < a[k][i])
                 max = a[k][i];
                  if (min > a[k][i])
                 min = a[k][i];
              }
          cout << endl;
          }*/
          /*for (int i = n-1; i >= 0; i--)
          {
              for (int k = n - i - 1; k < n; k++)
                  {
                  cout <<a[i][k];
                  if (max < a[i][k])
                 max = a[i][k];
                  if (min > a[i][k])
                 min = a[i][k];
                  }
              cout << endl;
          }*/
          /*for (int i = n-1; i>=0; i--)
          {
              for (int k = 0; k <= i; k++)
                  {
                  cout << a[i][k] << " ";
                  if (max < a[i][k])
                 max = a[i][k];
                  if (min > a[i][k])
                 min = a[i][k];
                  }
              cout << endl;
          }*/
          /* for (int i = n; i >n/2; k < i; k++)
           {
               for(int k = n-i; k <i; k++)
                   {
                   cout << a[i-1][k] << " ";
                   if (max < a[i-1][k])
                 max = a[i-1][k];
                  if (min > a[i-1][k])
                 min = a[i-1][k];
                   }
               cout << endl;
           }*/


           /*for (int j = 0; j < m; j++)
       {
           cout << a[0][j] << " ";
           if (max < a[0][j])
                 max = a[0][j];
                  if (min > a[0][j])
                 min = a[0][j];
       }


       for (int i = 1; i < n - 1; i++)
       {
           cout << a[i][m - 1] << " ";
           if (max < a[i][m-1])
                 max = a[i][m-1];
                  if (min > a[i][m-1])
                 min = a[i][m-1];
       }


       if (n > 1)
       {
           for (int j = m - 1; j >= 0; j--)
           {
               cout << a[n - 1][j] << " ";
               if (max < a[n-1][j])
                 max = a[n-1][j];
                  if (min > a[n-1][j])
                 min = a[n-1][j];
           }
       }


       if (m > 1)
       {
           for (int i = n - 2; i >= 1; i--)
           {
               cout << a[i][0] << " ";
               if (max < a[i][0])
                 max = a[i][0];
                  if (min > a[i][0])
                 min = a[i][0];
           }
       }*/
 cout << endl; cout << " max " << max << " min " << min;

{
    for (int i = n - 2; i >= 1; i--)
    {
        cout << a[i][0] << " ";
    }
}*/
}
