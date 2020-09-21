#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    int n,m[50],i;
    printf("Day se co so phan tu la:");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        printf("Nhap so nguyen thu %d:",i);
        scanf("%d",&m[i]);
    };
    printf("\n");
    //in ra dãy vừa nhập
    for(i=1;i<=n;i++){
        printf("%d\t",m[i]);
    };

    //tính tổng các phần tử của dãy
    int tong=0;
    for(i=1;i<=n;i++){
        tong = tong + m[i];
    };
    printf("\nTong cua day so la:%d",tong);

    //tính trung bình cộng các phần tử của dãy
    float tbc=0;
    for(i=1;i<=n;i++){
        tbc = (float)tong/i;
    };
    printf("\nTrung binh cong cua day so la:%f",tbc);

    //tìm phần tử lớn(nhỏ) nhất
    int max = m[1];
    for (i = 1; i <= n; i++){
        if(max < m[i]){
            max = m[i];
        };
    };
    printf("\nPhan tu lon nhat:%d",max);

    int min = m[0];
    for (i = 1; i <= n; i++){
        if(min > m[i]){
            min = m[i];
        };
    };
    printf("\nPhan tu nho nhat:%d",min);

    //đếm ra số phần tử dương
    int duong=0;
    for(i=1;i<=n;i++){
        if(m[i]>0){
            duong = duong + 1;
        }
    };
    printf("\nSo phan tu duong la:%d",duong);

    getch();
}
