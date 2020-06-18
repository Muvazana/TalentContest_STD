#ifndef RELATIONHEADER_H_INCLUDED
#define RELATIONHEADER_H_INCLUDED

#include "juriHeader.h"
#include "pesertaHeader.h"

#define nil NULL
#define first(L) L.first
#define next(P) P->next
#define child(P) P->child
#define parent(P) P->parent
#define infoNilai(P) P->infoNilai

typedef struct elm_R *address_R;
struct elm_R{
    int infoNilai;
    address_P parent;
    address_J child;
    address_R next;
};
struct list_R{
    address_R first;
};

bool isEmptyList(list_R L);
void createList(list_R &L);
bool isElmExist(list_R L, address_P P, address_J J);
address_R createElmList(address_P P, address_J J);
void insertFirst(list_R &L, address_R P);
address_R findElmList(list_R &L, address_P P, address_J J, string code);
void updateData(list_R &L, address_P P, address_J J);
void deleteFirst(list_R &L, address_R &P);
void deleteAfter(address_R &found, address_R &P);
void deleteData(list_R &L, address_P P, address_J J, address_R &temp);


#endif // RELATIONHEADER_H_INCLUDED
