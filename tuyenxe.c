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
    DiemDoDB new,diemdo_list;
    struct DiemDoNode tmp;
    diemdo_list = create_list_dd();
    int diemdo_number = 0;

    if ((fin = fopen(filename, "r")) == NULL) {
        printf("Can't read from %s\n",filename);
    }else{
        while(fgets(buffer,sizeof(buffer)-1,fin ) != NULL){
            while(fscanf(fin,"%s %d %d",tmp.id,&tmp.x,&tmp.y) == 3){
                new = (DiemDoDB)malloc(sizeof(struct DiemDoNode));
                new->next = NULL;
                strcpy(new->id,tmp.id);
                new->x = tmp.x;
                new->y = tmp.y;
                //printf("%s\n",new->id);
                //printf("%d\n",new->x);
                //printf("%d\n",new->y);
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
    struct TuyenXeNode tmp;
    TuyenXeDB new,tuyenxe_list;
    tuyenxe_list = create_list_tx();
    int tuyenxe_number = 0;
    int i;

    if ((fin = fopen(filename, "r")) == NULL) {
        printf("Can't read from %s\n",filename);
    }else{
        while(fgets(buffer,sizeof(buffer)-1,fin ) != NULL){
            while(fscanf(fin,"%s %d",tmp.id,&tmp.soDiemDo) == 2){
                new = (TuyenXeDB)malloc(sizeof(struct TuyenXeNode));
                new->next = NULL;
                strcpy(new->id,tmp.id);
                new->soDiemDo = tmp.soDiemDo;
                printf("%s\n",new->id);
                printf("%d\n",new->soDiemDo);
                for(i = 0;i< new->soDiemDo;i++){
                    fscanf(fin,"%s",tmp.dsDiemDo[i].id);
                    strcpy(new->dsDiemDo[i].id,tmp.dsDiemDo[i].id);
                    //printf("%s - ",tmp.dsDiemDo[i].id);
                }
                printf("\n");
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
TuyenXeDB append_tx(TuyenXeDB db,struct TuyenXeNode* node){
    TuyenXeDB tmp;
    tmp = db;
    if(db == NULL){
        return node;
    }else{
        while(tmp != NULL){
            if(tmp->next == NULL){
                tmp->next = node;
                node->next = NULL;
                break;
            }else{
                tmp = tmp->next;
            }
        }
        return db;
    }
};

DiemDoDB append_dd(DiemDoDB db,struct DiemDoNode* node){
    DiemDoDB tmp;
    tmp = db;
    if(db == NULL){
        return node;
    }else{
        while(tmp != NULL){
            if(tmp->next == NULL){
                tmp->next = node;
                node->next = NULL;
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
struct DiemDoNode *find_dd_by_id(DiemDoDB db, char *id){
    int state = 0;
    DiemDoDB tmp;
    tmp = db;
    while(tmp != NULL){
        if(strcmp(tmp->id,id) == 0){
            state = 1;
            break;
        }else{
            tmp = tmp->next; 
        }
    }
    if(state == 0){
        return NULL;
    }else{
        return tmp;
    }
};

struct TuyenXeNode *find_tx_by_id(TuyenXeDB db,char *id){
    int state = 0;
    TuyenXeDB tmp;
    tmp = db;
    while(tmp != NULL){
        if(strcmp(tmp->id,id) == 0){
            state = 1;
            break;
        }else{
            tmp = tmp->next;
        }
    }
    if(state == 0){
        return NULL;
    }else{
        return tmp;
    }
};



/* In danh sách các cuốn sách */
void print_dd(DiemDoDB db){
    DiemDoDB tmp = db;
    while(tmp != NULL){
        printf("%s\n",tmp->id);
        printf("%d\n",tmp->x);
        printf("%d\n",tmp->y);
        tmp = tmp->next;
    }
};

void print_tx(TuyenXeDB db){
    TuyenXeDB tmp = db;
    int i;
    while(tmp != NULL){
        printf("%s\n",tmp->id);
        printf("%d\n",tmp->soDiemDo);
        for(i = 0;i< tmp->soDiemDo;i++){
            printf("%s -",tmp->dsDiemDo[i].id);
        }
        printf("\n");
        tmp = tmp->next;
    }
};


/*In ra 1 file moi*/
void write_dddb(char* filename,DiemDoDB dddb){
    DiemDoDB tmp = dddb;
    
};
