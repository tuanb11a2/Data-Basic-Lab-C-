#ifndef _BOOK_H_
#define _BOOK_H_

struct BookNode {
    char id[10];
    char tittle[50];
    char author[20];
    int published_year;
    struct BookNode *next;
};

typedef struct BookNode* BookDB;

/*Tao 1 danh sach moi*/
BookDB create_list();
/* Đọc dữ liệu từ tệp văn bản */
BookDB read_db(char* filename);
/* Ghi dữ liệu ra tệp văn bản */
BookDB write_db(char* filename,BookDB list);
/* Tạo một cấu trúc sách mới */
struct BookNode* make_node(char *id, char *tittle, char *author, int
published_year);
/* Thêm một sách vào cuối danh sách, trả về danh sách đã được thêm */
BookDB append(BookDB db, struct BookNode *b);
/* Tìm sách theo id, trả về NULL nếu không tìm thấy */
struct BookNode *find_by_id(BookDB db, char *id);
/* Xóa sách có mã id khỏi danh sách, trả về danh sách đã được cập nhật
*/
BookDB remove_book(BookDB db, char *id);
/* Đổi chỗ hai cuốn sách b1, b2 trong danh sách, trả về danh sách thu
được */
BookDB swap(BookDB db, struct BookNode *b1, struct BookNode *b2);
/* In thông tin cuốn sách */
void print_book(struct BookNode *b);
/* In danh sách các cuốn sách */
void print_db(BookDB db);

#endif