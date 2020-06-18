#ifndef PESERTAHEADER_H_INCLUDED
#define PESERTAHEADER_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define nil NULL
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

struct infotype_P{
    string namaPeserta;
    int totalNilai;
};
typedef struct elm_P *address_P;
struct elm_P{
    infotype_P info;
    address_P next;
};
struct list_P{
    address_P first;
};

bool isEmptyList(list_P L);
void createList(list_P &L);
address_P createElmList();
void insertFirst(list_P &L, address_P P);
void insertAfter(address_P &found, address_P P);
void insertLast(list_P &L, address_P P);
address_P findElmList(list_P &L, string namaPeserta, string code);
void updateData(list_P L, string namaPeserta);
void deleteFirst(list_P &L, address_P &P);
void deleteAfter(address_P &found, address_P &P);
void deleteData(list_P &L, string namaPeserta, address_P &P);
void viewData(list_P L);

#endif // PESERTAHEADER_H_INCLUDED
