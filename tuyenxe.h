#ifndef _TUYENXE_H_
#define _TUYENXE_H_

struct DiemDoNode {
    char id[10];
    int x;
    int y;
    struct DiemDoNode *next;
};

struct TuyenXeNode{
    char id[10];
    int soDiemDo;
    struct DiemDoNode dsDiemDo[10];
    struct TuyenXeNode *next;
};

typedef struct DiemDoNode* DiemDoDB;
typedef struct TuyenXeNode *TuyenXeDB;

/*Tao 1 danh sach moi*/
DiemDoDB create_list();
/* Đọc dữ liệu từ tệp văn bản */
DiemDoDB read_dddb(char* filename);
TuyenXeDB read_txdb(char* filename);
/* Ghi dữ liệu ra tệp văn bản */
void write_dddb(char* filename,DiemDoDB dddb);
void write_txdb(char* filename,TuyenXeDB txdb);
/* Thêm một diem do vào cuối danh sách, trả về danh sách đã được thêm */
DiemDoDB append_dd(DiemDoDB db,struct DiemDoNode* node);
/* Thêm một diem do vào cuối danh sách, trả về danh sách đã được thêm */
TuyenXeDB append_tx(TuyenXeDB db,struct TuyenXeNode* node);
/*tim diem do theo id,tra ve NULL neu khong tim thay*/
struct DiemDoNode *find_dd_by_id(DiemDoDB db, char *id);
/*Tim diem do gan nhat*/
struct DiemDoNode *find_dd_by_coord(DiemDoDB db,int x,int y);
/*Tim tuyen xe theo id,tra ve NULL neu khong tim thay*/
struct TuyenXeNode *find_tx_by_id(TuyenXeDB db,char *id);
/* In danh sách các cuốn sách */
void print_dd(DiemDoDB db);
void print_tx(TuyenXeDB db);

#endif