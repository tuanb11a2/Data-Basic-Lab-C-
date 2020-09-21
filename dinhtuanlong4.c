/* QUAN LY SV
Một tập các phiếu điểm của sinh viên trong mot lop n (n<=100)
- Họ tên
- Lớp
- Mã sv
- Năm sinh
- Quê quán
- ĐTB
1. Nhập dữ liệu cho n sinh viên
2. In du liệu cho n sv đó
3. Tìm sinh viên có DTB cao nhất lớp
4. Điểm trung bình chung của lớp là bao nhiêu
5. Đếm xem có bao nhiêu sinh viên có diem lớn hơn điểm TBC
6. Tính tỉ lệ sinh viên bị lưu ban ( luu ban TBC<3.0)
7. Sx các sinh viên theo thứ tự giảm dần của DTB
*/

#include<stdio.h>
#include<conio.h>

int main()
{
    char ht[100][50];
    char lop[100][10];
    char msv[100][100];
    int ns[100];
    char qq[100][50];
    float dtb[100];

    int i,j,n;
    printf("Cho biet so sv cua lop:");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        printf("\nNhap thong tin cua sinh vien %d:\n",i);
        printf("\tNhap ho va ten:");
        fflush(stdin); gets(ht[i]);
        printf("\tNhap lop:");fflush(stdin);
        scanf("%s",&lop[i]);
        printf("\tNhap ma sinh vien:");fflush(stdin);
        scanf("%s",&msv[i]);
        printf("\tNhap nam sinh:");fflush(stdin);
        scanf("%d",&ns[i]);
        printf("\tNhap que quan:");fflush(stdin);
        gets(qq[i]);
        printf("\tNhap diem trung binh:");fflush(stdin);
        scanf("%f",&dtb[i]);
    }

    for(i=1;i<=n;i++){
        printf("\nThong tin cua sinh vien %d:\n",i);
        printf("\tHo va ten:");puts(ht[i]);
        printf("\tLop:%s\n",lop[i]);
        printf("\tMa sinh vien:%s\n",msv[i]);
        printf("\tnam sinh:%d\n",ns[i]);
        printf("\tQue quan:");puts(qq[i]);
        printf("\tDiem trung binh:%0.2f\n",dtb[i]);
    }
    getch();
}
