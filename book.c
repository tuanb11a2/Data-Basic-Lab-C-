#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tuyenxe.h"

/*tao 1 danh sach moi*/
DiemDoDB create_list_dd() {
  return NULL;
}

TuyenXeDB create_list_tx(){
    return NULL;
}

/* Đọc dữ liệu từ tệp văn bản diemdo */
DiemDoDB read_dddb(char* filename){
    FILE *fin;
    char buffer[11];
    DiemDoDB new,tmp,diemdo_list;
    diemdo_list = create_list_dd();
    int diemdo_number = 0;

    if ((fin = fopen(filename, "r")) == NULL) {
        printf("Can't read from %s\n",filename);
    }else{
        while(fgets(buffer,sizeof(buffer)-1,fin ) != NULL){
            if(diemdo_number == 0){
                diemdo_number = atoi(buffer);
                printf("%d\n",diemdo_number);
            }else{
                new = (DiemDoDB)malloc(sizeof(struct DiemDoNode));
                fscanf(buffer,"%s %d %d",new->id,&(new->x),&(new->y));
                printf("%s\n",new->id);
                printf("%d\n",new->x);
                printf("%d\n",new->y);
                diemdo_list = append_dd(diemdo_list,new);
            }
        }
    }

    fclose(fin);
    return diemdo_list;

};
/* Đọc dữ liệu từ tệp văn bản */
TuyenXeDB read_txdb(char* filename){
    FILE *fin;
    char buffer[11];
    TuyenXeDB new,tmp,tuyenxe_list;
    tuyenxe_list = create_list();
    int tuyenxe_number = 0;
    int i;

    if ((fin = fopen(filename, "r")) == NULL) {
        printf("Can't read from %s\n",filename);
    }else{
        while(fgets(buffer,sizeof(buffer)-1,fin ) != NULL){
            if(tuyenxe_number == 0){
                tuyenxe_number = atoi(buffer);
                printf("%d\n",book_number);
            }else{
                new = (TuyenXeDB)malloc(sizeof(struct TuyenXeNode));
                fscanf(buffer,"%s %d %s %s %s %s %s %s %s %s %s %s",new->id,&(new->soDiemDo),new->dsDiemDo[0]->id,new->dsDiemDo[1]->id,new->dsDiemDo[2]->id,new->dsDiemDo[3]->id,new->dsDiemDo[4]->id,new->dsDiemDo[5]->id,new->dsDiemDo[6]->id,new->dsDiemDo[7]->id,new->dsDiemDo[8]->id,new->dsDiemDo[9]->id);
                printf("%s\n",new->id);
                printf("%d\n",new->soDiemDo);
                for(i = 0;i< new->soDiemDo;i++){
                    printf("%s\n",new->dsDiemDo[i]->id);
                }
                tuyenxe_list = append_tx(tuyenxe_list,new);
            }
        }
    }

    fclose(fin);
    return tuyenxe_list;

};


/* Ghi dữ liệu ra tệp văn bản */
// BookDB write_db(char* filename,BookDB list){
//     FILE *fout;
//     BookDB tmp;
//     tmp = list;
//     if ((fout = fopen(filename, "w+")) == NULL) {
//         printf("Can't write from %s\n",filename);
//     }else{
//         while(tmp != NULL){
//             fprintf(fout,"%s\n",tmp->id);
//             //printf("%s\n",tmp->id);
//             fprintf(fout,"%s\n",tmp->tittle);
//             //printf("%s\n",tmp->tittle);
//             fprintf(fout,"%s\n",tmp->author);
//             //printf("%s\n",tmp->author);
//             fprintf(fout,"%d\n",tmp->published_year);
//             //printf("%d\n",tmp->published_year);
//             tmp= tmp->next;
//         }
//     }
//     fclose(fout);
//     return list;
// };

/* Thêm một sách vào cuối danh sách, trả về danh sách đã được thêm */
DiemDoDB append_dd(DiemDoDB db, char* id,int x,int y){
    DiemDoDB tmp;
    tmp = db;
    DiemDoDB new =(DiemDoDB)malloc(sizeof(struct DiemDoNode));
    strcpy(new->id,id);
    printf("%s\n",new->id);
    new->x = x;
    new->y = y;
    new->next = NULL;
    
    if(db == NULL){
        return new;
    }else{
        while(tmp != NULL){
            if(tmp->next == NULL){
                tmp->next = new;
                break;
            }else{
                tmp = tmp->next;
            }
        }
        return db;
    }
};

/* Tìm sách theo id, trả về NULL nếu không tìm thấy */
// struct BookNode *find_by_id(BookDB db, char *id){
//     int state = 0;
//     BookDB tmp;
//     tmp = db;
//     while(tmp != NULL){
//         if(strcmp(tmp->id,id) == 0){
//             state = 1;
//             break;
//         }else{
//             tmp = tmp->next;
//         }
//     }
//     if(state == 0){
//         return NULL;
//     }else{
//         return tmp;
//     }
// };

/* Xóa sách có mã id khỏi danh sách, trả về danh sách đã được cập nhật
*/
//BookDB remove_book(BookDB db, char *id);
/* Đổi chỗ hai cuốn sách b1, b2 trong danh sách, trả về danh sách thu
được */
//BookDB swap(BookDB db, struct BookNode *b1, struct BookNode *b2);
/* In thông tin cuốn sách */
//void print_book(struct BookNode *b);

/* In danh sách các cuốn sách */
void print_dd(DiemDoDB db){
    BookDB tmp = db;
    while(tmp != NULL){
        printf("%s\n",tmp->id);
        printf("%d\n",tmp->x);
        printf("%d\n",tmp->y);
        tmp = tmp->next;
    }
};



