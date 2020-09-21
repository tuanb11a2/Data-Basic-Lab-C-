#ifndef _DANGKY_H_
#define _DANGKY_H_

struct MonHocNode {
    char id[10];
    int so_tin_chi;
    int hoc_ky;
    struct MonHocNode *next;
};

typedef struct MonHocNode* MonHocDB;

struct DangKyNode{
    char id[10];
    int so_mon_hoc;
    MonHocDB dsmh;
    struct DangKyNode *next;
};

typedef struct DangKyNode * DangKyDB;

/*Tao 1 danh sach moi*/
MonHocDB create_list();
/* Đọc dữ liệu từ tệp văn bản */
MonHocDB read_mhdb(char* filename);
DangKyDB read_dkdb(char* filename);
/* Ghi dữ liệu ra tệp văn bản */
void write_mhdb(char* filename,MonHocDB mhdb);
void write_dkdb(char* filename,DangKyDB dkdb);
/* Thêm một mon hoc vào cuối danh sách, trả về danh sách đã được thêm */
MonHocDB append_mh(MonHocDB db,struct MonHocNode* node);
/* Thêm một dang ky vào cuối danh sách, trả về danh sách đã được thêm */
DangKyDB append_dk(DangKyDB db,struct DangKyNode* node);
/*tim mon hoc theo id,tra ve NULL neu khong tim thay*/
struct MonHocNode *find_mh_by_id(MonHocDB db, char *id);
/*Tim tuyen xe theo id,tra ve NULL neu khong tim thay*/
struct DangKyNode *find_dk_by_id(DangKyDB db,char *id);
/* In danh sách các cuốn sách */
void print_mh(MonHocDB db);
void print_dk(DangKyDB db);
MonHocDB create_list_mh();
DangKyDB create_list_dk();
#endif