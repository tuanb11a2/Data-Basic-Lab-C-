#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dangky.h"

/*tao 1 danh sach moi*/
MonHocDB create_list_mh() {
  return NULL;
}

DangKyDB create_list_dk(){
    return NULL;
}

/* Đọc dữ liệu từ tệp văn bản diemdo */
MonHocDB read_mhdb(char* filename){
    FILE *fin;
    char buffer[30];
    MonHocDB new,monhoc_list;
    struct MonHocNode tmp;
    monhoc_list = create_list_mh();
    int monhoc_number = 0;

    if ((fin = fopen(filename, "r")) == NULL) {
        printf("Can't read from %s\n",filename);
    }else{
        while(fgets(buffer,sizeof(buffer)-1,fin ) != NULL){
            while(fscanf(fin,"%s %d %d",tmp.id,&tmp.so_tin_chi,&tmp.hoc_ky) == 3){
                new = (MonHocDB)malloc(sizeof(struct MonHocNode));
                new->next = NULL;
                strcpy(new->id,tmp.id);
                new->so_tin_chi = tmp.so_tin_chi;
                new->hoc_ky = tmp.hoc_ky;
                monhoc_list = append_mh(monhoc_list,new);
            }
        }
    }

    fclose(fin);
    return monhoc_list;

};
/* Đọc dữ liệu từ tệp văn bản */
DangKyDB read_dkdb(char* filename){
    FILE *fin;
    char buffer[11];
    struct DangKyNode tmp;
    MonHocDB new_monhoc,monhoc_list;
    monhoc_list = create_list_mh();
    DangKyDB new,dangky_list;
    dangky_list = create_list_dk();
    int dangky_number = 0;
    int i;

    if ((fin = fopen(filename, "r")) == NULL) {
        printf("Can't read from %s\n",filename);
    }else{
        while(fgets(buffer,sizeof(buffer)-1,fin ) != NULL){
            while(fscanf(fin,"%s %d",tmp.id,&tmp.so_mon_hoc) == 2){
                monhoc_list = create_list_mh();
                new = (DangKyDB)malloc(sizeof(struct DangKyNode));
                new->next = NULL;
                new->so_mon_hoc = tmp.so_mon_hoc;
                strcpy(new->id,tmp.id);
                for(i = 0;i< tmp.so_mon_hoc;i++){
                    new_monhoc = (MonHocDB)malloc(sizeof(struct MonHocNode));
                    new_monhoc->next = NULL;
                    fscanf(fin,"%s",tmp.dsmh->id);
                    strcpy(new_monhoc->id,tmp.dsmh->id);
                    monhoc_list = append_mh(monhoc_list,new_monhoc);
                }
                new->dsmh = monhoc_list;
                dangky_list = append_dk(dangky_list,new);
            }
        }
    }

    fclose(fin);
    return dangky_list;

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
DangKyDB append_dk(DangKyDB db,struct DangKyNode* node){
    DangKyDB tmp;
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

MonHocDB append_mh(MonHocDB db,struct MonHocNode* node){
    MonHocDB tmp;
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
struct MonHocNode *find_mh_by_id(MonHocDB db, char *id){
    int state = 0;
    MonHocDB tmp;
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

struct DangKyNode *find_dk_by_id(DangKyDB db,char *id){
    int state = 0;
    DangKyDB tmp;
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
void print_mh(MonHocDB db){
    MonHocDB tmp = db;
    while(tmp != NULL){
        printf("%s\n",tmp->id);
        printf("%d\n",tmp->so_tin_chi);
        printf("%d\n",tmp->hoc_ky);
        tmp = tmp->next;
    }
};

void print_dk(DangKyDB db){
    DangKyDB tmp = db;
    MonHocDB tmp_monhoc;
    int i;
    while(tmp != NULL){
        tmp_monhoc = tmp->dsmh;
        printf("%s\n",tmp->id);
        printf("%d\n",tmp->so_mon_hoc);
        for(i = 0;i< tmp->so_mon_hoc;i++){
            while(tmp_monhoc != NULL){
                printf("%s -",tmp_monhoc->id);
                tmp_monhoc = tmp_monhoc->next;
            }
            
        }
        printf("\n");
        tmp = tmp->next;
    }
};


