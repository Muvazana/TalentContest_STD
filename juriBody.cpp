#include "juriHeader.h"

bool isEmptyList(list_J L){
    return first(L) == NULL;
}
void createList(list_J &L){
    first(L) = NULL;
}
bool isUsernameExist(list_J L, string username){
    if(isEmptyList(L)){
        return false;
    }else{
        address_J Q = first(L);
        while(Q != NULL){
            if(info(Q).username == username){
                return true;
            }
            Q = next(Q);
        }
        return false;
    }
}
address_J createElmList(list_J &L){
    string tempUsername;
    address_J P = new elm_J;
    do{
        cout << "Username : ";
        cin >> tempUsername;
    }while(isUsernameExist(L, tempUsername));
    info(P).username = tempUsername;

    cout << "Password : ";
    cin >> info(P).password; cin.ignore();
    cout << "Nama : ";
    getline(cin, info(P).namaJuri);
    next(P) = NULL;
    return P;
}
void insertFirst(list_J &L, address_J P){
    if(isEmptyList(L)){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfter(address_J &found, address_J P){
    if(next(found) == NULL){
        next(found) = P;
    }else{
        next(P) = next(found);
        next(found) = P;
    }
}
void insertAsc(list_J &L, address_J P){
    if(isEmptyList(L)){
        insertFirst(L, P);
    }else{
        if(info(P).username <= info(first(L)).username){
            insertFirst(L, P);
        }else if(info(P).username > info(first(L)).username && next(first(L)) == NULL ){
            insertAfter(first(L), P);
        }else{
            address_J found = findElmList(L, info(P).username, "insert");
            insertAfter(found, P);
        }
    }
}
address_J findElmList(list_J &L, string username, string code){
    address_J Q = first(L);
    if(code == "insert"){
        while(next(Q) != NULL){
            if(username < info(next(Q)).username){
                return Q;
            }
            Q = next(Q);
        }
        return Q;
    }else if(code == "update"){
        while (Q != NULL){
            if(info(Q).username == username){
                return Q;
            }
            Q = next(Q);
        }
    }else if(code == "delete"){
        while (Q != NULL){
            if(info(next(Q)).username == username){
                return Q;
            }
            Q = next(Q);
        }
    }
    return NULL;
}
void updateData(list_J L, string username){
    address_J P = findElmList(L, username, "update");
    char change;
    if(P != NULL){
        cout << "Username : " << info(P).username << endl;
        cout << "Nama : " << info(P).namaJuri << endl;
        cout << "---UPDATE---" << endl;
        cout << "Nama Baru : ";
        getline(cin, info(P).namaJuri);
        do{
            cout << "Apakah anda ingin mengganti PASSWORD? y/n ? ";
            cin >> change;
        }while(tolower(change) != tolower('y') && tolower(change) != tolower('n'));
        if(tolower(change) == 'y'){
            cout << "Password Baru : ";
            cin >> info(P).password;
        }
        cout << "Update Data BERHASIL" <<  endl;
    }else{
        cout << "Data Tidak Ditemukan" << endl;
        cout << "Update Data GAGAL" <<  endl;
    }
}
void deleteFirst(list_J &L, address_J &P){
    if(!isEmptyList(L)){
        P = first(L);
        if(next(first(L)) == NULL){
            first(L) = NULL;
        }else{
            first(L) = next(P);
            next(P) = NULL;
        }
    }
}
void deleteAfter(address_J &found, address_J &P){
    P = next(found);
    if(next(P) == NULL){
        next(found) = NULL;
    }else{
        next(found) = next(P);
        next(P) = NULL;
    }
}
void deleteData(list_J &L, string username, address_J &P){
    char sign;
    if(!isEmptyList(L)){
        if(username == info(first(L)).username){
            do{
                cout << "Yakin ingin menghapus Data dengan Username : "<< info(first(L)).username << "? y/n ?"; cin >> sign;
            }while(tolower(sign) != tolower('y') && tolower(sign) != tolower('n'));
            if(tolower(sign) == tolower('y')){
                deleteFirst(L, P);
                cout << "Delete Data BERHASIL" << endl;
            }else{
                cout << "Delete Data Gagal" << endl;
            }
        }else{
            address_J found = findElmList(L, username, "delete");
            if(found != NULL){
                do{
                    cout << "Yakin ingin menghapus Data dengan Username : "<< info(next(found)).username << "? y/n ?"; cin >> sign;
                }while(tolower(sign) != tolower('y') && tolower(sign) != tolower('n'));
                if(tolower(sign) == tolower('y')){
                    deleteAfter(found, P);
                    cout << "Delete Data BERHASIL" << endl;
                }else{
                    cout << "Delete Data Gagal" << endl;
                }
            }else{
                cout << "Username Tidak Ditemukan" << endl;
                cout << "Delete Data GAGAL" << endl;
            }
        }
        cout << "Delete Data BERHASIL" << endl;
    }
}
void viewData(list_J L){
    cout << endl << "Data Juri : " << endl;
    if(!isEmptyList(L)){
        address_J Q = first(L);
        while(Q != NULL){
            cout << "Username : " << info(Q).username;
            cout << "\t\t\t|| Nama : " << info(Q).namaJuri << endl;
            Q = next(Q);
        }
    }else{
        cout << "Tidak ada Juri" << endl;
    }
    cout << endl;
}
