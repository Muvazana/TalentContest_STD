#include "relationHeader.h"

bool isEmptyList(list_R L){
    return first(L) == NULL;
}
void createList(list_R &L){
    first(L) = NULL;
}
bool isElmExist(list_R L, address_P P, address_J J){
    if(isEmptyList(L)){
        return false;
    }else{
        address_R Q = first(L);
        while(Q != NULL){
            if(parent(Q) == P && child(Q) == J){
                return true;
            }
            Q = next(Q);
        }
        return false;
    }
}
address_R createElmList(address_P P, address_J J){
    address_R Q = new elm_R;
    cout << "Add Nilai : ";
    cin >> infoNilai(Q);
    info(P).totalNilai += infoNilai(Q);
    parent(Q) = P;
    child(Q) = J;
    next(Q) = NULL;
    return Q;
}
void insertFirst(list_R &L, address_R P){
    if(isEmptyList(L)){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}
address_R findElmList(list_R &L, address_P P, address_J J, string code){
    address_R Q = first(L);
    if(code == "show"){
        while (Q != NULL){
            if((parent(Q) == P && P != NULL) || (child(Q) == J && J != NULL)){
                return Q;
            }
            Q = next(Q);
        }
    }else if(code == "update"){
        while (Q != NULL){
            if(parent(Q) == P && child(Q) == J){
                return Q;
            }
            Q = next(Q);
        }
    }else if(code == "delete"){
        while (Q != NULL){
            if((parent(next(Q)) == P && child(next(Q)) == J) || (P == parent(first(L)) && J == NULL) || (P == NULL && J == child(first(L)))){
                return Q;
            }
            Q = next(Q);
        }
    }
    return NULL;
}
void updateData(list_R &L, address_P P, address_J J){
    address_R Q = findElmList(L, P, J, "update");
    if(Q != NULL){
        cout << "Nama : " << info(parent(Q)).namaPeserta << endl;
        cout << "Nilai : " << infoNilai(Q) << endl;
        info(P).totalNilai -= infoNilai(Q);
        cout << "---UPDATE---" << endl;
        cout << "Nilai Baru : ";
        cin >> infoNilai(Q);
        info(P).totalNilai += infoNilai(Q);
    }else{
        cout << "Data Tidak Ditemukan" << endl;
    }
}
void deleteFirst(list_R &L, address_R &P){
    if(!isEmptyList(L)){
        P = first(L);
        if(next(first(L)) == NULL){
            first(L) = NULL;
        } else{
            first(L) = next(P);
            next(P) = NULL;
        }
    }
}
void deleteAfter(address_R &found, address_R &P){
    P = next(found);
    if(next(P) == NULL){
        next(found) = NULL;
    }else{
        next(found) = next(P);
        next(P) = NULL;
    }
}
void deleteData(list_R &L, address_P P, address_J J, address_R &temp){
    if(!isEmptyList(L)){
        if((P == parent(first(L)) && J == child(first(L))) || (P == parent(first(L)) && J == NULL) || (P == NULL && J == child(first(L)))){
            info(P).totalNilai -= infoNilai(first(L));
            deleteFirst(L, temp);
        }else{
            address_R found = findElmList(L, P, J, "delete");
            info(P).totalNilai -= infoNilai(next(found));
            deleteAfter(found, temp);
        }
        cout << "Delete Data BERHASIL" << endl;
    }
}