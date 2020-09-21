#ifndef _DANGKY_H_
#define _DANGKY_H_

struct MonHocNode {
  char id[10];
  int so_tc;
  int hk;
  struct MonHocNode* next;
};

typedef struct MonHocNode *MonHocDB;

struct DangKyNode {
  char id[10];
  MonHocDB dsmh;
  struct DangKyNode *next;
};

typedef struct DangKyNode *DangKyDB;

MonHocDB read_mb(char* filename);

DangKyDB read_dk(char* filename, MonHocDB monhocDB);

void printMonHoc(MonHocDB db);

void printDangKy(DangKyDB db);

MonHocDB append_mh(MonHocDB db, char* id , int so_tc, int hk);

DangKyDB append_dd(DangKyDB db, char* id, MonHocDB dsMonHoc);

struct MonHocNode *find_mh_by_id(MonHocDB db, char* id);

struct DangKyNode *find_dk_by_id(DangKyDB db, char* id);


#endif
