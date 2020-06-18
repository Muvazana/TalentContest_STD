#include "pesertaHeader.h"

bool isEmptyList(list_P L){
    return first(L) == NULL;
}

void createList(list_P &L){
    first(L) = NULL;
}

address_P createElmList(){
    address_P P = new elm_P;
    cout << "Nama Peserta : ";
    cin.ignore();getline(cin, info(P).namaPeserta);
    info(P).totalNilai = 0;
    next(P) = NULL;
    return P;
}


void insertFirst(list_P &L, address_P P){
    if(isEmptyList(L)){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfter(address_P &found, address_P P){
    if(next(found) == NULL){
        next(found) = P;
    }else{
        next(P) = next(found);
        next(found) = P;
    }
}
void insertLast(list_P &L, address_P P){
    if(isEmptyList(L)){
        insertFirst(L,P);
    }else{
        address_P Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}
address_P findElmList(list_P &L, string namaPeserta, string code){
    address_P Q = first(L);
    if(code == "update"){
        while (Q != NULL){
            if(info(Q).namaPeserta == namaPeserta){
                return Q;
            }
            Q = next(Q);
        }
    }else if(code == "delete"){
        if(next(first(L)) != NULL){
            while (Q != NULL){
                if(info(next(Q)).namaPeserta == namaPeserta){
                    return Q;
                }
                Q = next(Q);
            }
        }
    }
    return NULL;
}
void updateData(list_P L, string namaPeserta){
    address_P P = findElmList(L, namaPeserta, "update");
    if(P != NULL){
        cout << "Nama : " << info(P).namaPeserta << endl;
        cout << "Total Nilai : " << info(P).totalNilai << endl;
        cout << "---UPDATE---" << endl;
        cout << "Nama Baru : ";
        getline(cin, info(P).namaPeserta);
        cout << "Update Data BERHASIL" <<  endl;
    }else{
        cout << "Data Tidak Ditemukan" << endl;
        cout << "Update Data GAGAL" <<  endl;
    }
}

void deleteFirst(list_P &L, address_P &P){
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

void deleteAfter(address_P &found, address_P &P){
    P = next(found);
    if(next(P) == NULL){
        next(found) = NULL;
    }else{
        next(found) = next(P);
        next(P) = NULL;
    }
}

void deleteData(list_P &L, string namaPeserta, address_P &P){
    char sign;
    if(!isEmptyList(L)){
        if(namaPeserta == info(first(L)).namaPeserta){
            do{
                cout << "Yakin ingin menghapus Data dengan Nama : "<< info(first(L)).namaPeserta << "? y/n ?"; cin >> sign;
            }while(tolower(sign) != tolower('y') && tolower(sign) != tolower('n'));
            if(tolower(sign) == tolower('y')){
                deleteFirst(L, P);
                cout << "Delete Data BERHASIL" << endl;
            }else{
                cout << "Delete Data Gagal" << endl;
            }
        }else{
            address_P found = findElmList(L, namaPeserta, "delete");
            if(found != NULL){
                do{
                    cout << "Yakin ingin menghapus Data dengan Nama : "<< info(next(found)).namaPeserta << "? y/n ?"; cin >> sign;
                }while(tolower(sign) != tolower('y') && tolower(sign) != tolower('n'));
                if(tolower(sign) == tolower('y')){
                    deleteAfter(found, P);
                    cout << "Delete Data BERHASIL" << endl;
                }else{
                    cout << "Delete Data Gagal" << endl;
                }
            }else{
                cout << "Nama Tidak Ditemukan" << endl;
                cout << "Delete Data GAGAL" << endl;
            }
        }
    }else{
        cout << "Delete Data GAGAL" << endl;
    }
}
void viewData(list_P L){
    cout << endl << "Data Peserta : " << endl;
    if(!isEmptyList(L)){
        address_P Q = first(L);
        while(Q != NULL){
            cout << "Nama : " << info(Q).namaPeserta;
            cout << "\t\t\t|| Total : " << info(Q).totalNilai << endl;
            Q = next(Q);
        }
    }else{
        cout << "Tidak ada Peserta" << endl;
    }
    cout << endl;
}
