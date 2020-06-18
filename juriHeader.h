#ifndef JURIHEADER_H_INCLUDED
#define JURIHEADER_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define nil NULL
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

struct infotype_J{
    string username, password;
    string namaJuri;
};
typedef struct elm_J *address_J;
struct elm_J{
    infotype_J info;
    address_J next;
};
struct list_J{
    address_J first;
};

bool isEmptyList(list_J L);
void createList(list_J &L);
bool isUsernameExist(list_J L, string username);
address_J createElmList(list_J &L);
void insertFirst(list_J &L, address_J P);
void insertAfter(address_J &found, address_J P);
void insertAsc(list_J &L, address_J P);
address_J findElmList(list_J &L, string username, string code);
void updateData(list_J L, string username);
void deleteFirst(list_J &L, address_J &P);
void deleteAfter(address_J &found, address_J &P);
void deleteData(list_J &L, string username, address_J &P);
void viewData(list_J L);

#endif // JURIHEADER_H_INCLUDED
