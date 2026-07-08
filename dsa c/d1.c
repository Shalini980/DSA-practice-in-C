#include <stdio.h>
void Rotate(int arr[ ], int x, int y)
{
    y= y % x;
    int temp[y];
    for (int i = 0; i < y; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = 0; i < x - y; i++)
    {
        arr[i] = arr[i + y];
    }
    for (int i = 0; i < y; i++) 
    {
        arr[x - y + i] = temp[i];
    }
  for (int i = 0; i < x; i++) 
   {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() 
{
    int x, s,y;
    scanf("%d", &x);
   while(x--)
   {
    scanf("%d", &s);
    int arr[s];
                  for (int i = 0; i < x; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &y);
    Rotate(arr, x, y);
 }
    return 0;
}





