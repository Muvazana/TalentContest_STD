#include "assetsHeader.h"

void clear(){
    system("CLS");
}
void waiting(string text, int time){
    cout << endl << "--> " << text;
    for(int i=0;i<time;i++){
        cout << "." << flush;
        Sleep(500);
    }
    cout << endl;
}

void dashboard(string codeDashboard, int &code){
    code = 9;
    if(codeDashboard == "LoginDashboard"){
        do{
            clear();// cleared console
            cout << "||-------\tWelcome to Aplication Talent Contest\t-------||" << endl;
            cout << "||-------\t\tLogin Dashboard\t\t\t-------||" << endl;
            if(code != 1 && code != 2 && code != 3 && code != 9 && cin.fail()){ // cin.fail(); => get the wrong input like type or something from cin
                cout << "Code Salah, Harap Masukkan Code dengan benar!" << endl;
                cin.clear();
                cin.ignore();
            }
            cout << "1. Data Peserta" << endl << "2. Login Admin" << endl << "3. Login Juri" << endl << "9. Exit Aplication" << endl << "Masukan code (1-3 & 9)? ";
            cin >> code;
        }while(code != 1 && code != 2 && code != 3 && code != 9 && cin.fail());
    }else if(codeDashboard == "AdminDashboard"){
        do{
            clear();// cleared console
            cout << "||-------\tWelcome to Aplication Talent Contest\t-------||" << endl;
            cout << "||-------\t\tAdmin Dashboard\t\t\t-------||" << endl;
            if(code != 1 && code != 2 && code != 3 && code != 4 && code != 5 && code != 9 && cin.fail()){
                cout << "Code Salah, Harap Masukkan Code dengan benar!" << endl;
                cin.clear();
                cin.ignore();
            }
            cout << "1. Manage Data Peserta" << endl << "2. Manage Data Juri" << endl << "3. View Nilai Setiap Peserta" << endl << "4. View Penilaian Setiap Juri" << endl << "5. Logout" << endl << "9. Exit Aplication" << endl << "Masukan code (1-5 & 9)? ";
            cin >> code;
        }while(code != 1 && code != 2 && code != 3 && code != 4 && code != 5 && code != 9 && cin.fail());
    }else if(codeDashboard == "ManagePerserta"){
        do{
            clear();// cleared console
            cout << "||-------\tWelcome to Aplication Talent Contest\t-------||" << endl;
            cout << "||-------\t\tManage Data Peserta\t\t-------||" << endl;
            if(code != 1 && code != 2 && code != 3 && code != 4 && code != 5 && code != 6 && code != 9 && cin.fail()){
                cout << "Code Salah, Harap Masukkan Code dengan benar!" << endl;
                cin.clear();
                cin.ignore();
            }
            cout << "1. Insert Peserta" << endl << "2. List Peserta" << endl << "3. Update Peserta" << endl << "4. Delete Peserta" << endl << "5. Logout" << endl << "6. Back to Home" << endl << "9. Exit Aplication" << endl << "Masukan code (1-6 & 9)? ";
            cin >> code;
        }while(code != 1 && code != 2 && code != 3 && code != 4 && code != 5 && code != 6 && code != 9 && cin.fail());
    }else if(codeDashboard == "ManageJuri"){
        do{
            clear();// cleared console
            cout << "||-------\tWelcome to Aplication Talent Contest\t-------||" << endl;
            cout << "||-------\t\tManage Data Juri\t\t-------||" << endl;
            if(code != 1 && code != 2 && code != 3 && code != 4 && code != 5 && code != 6 && code != 9 && cin.fail()){
                cout << "Code Salah, Harap Masukkan Code dengan benar!" << endl;
                cin.clear();
                cin.ignore();
            }
            cout << "1. Insert Juri" << endl << "2. List Juri" << endl << "3. Update Juri" << endl << "4. Delete Juri" << endl << "5. Logout" << endl << "6. Back to Home" << endl << "9. Exit Aplication" << endl << "Masukan code (1-6 & 9)? ";
            cin >> code;
        }while(code != 1 && code != 2 && code != 3 && code != 4 && code != 5 && code != 6 && code != 9 && cin.fail());
    }else if(codeDashboard == "JuriDashboard"){
        do{
            clear();// cleared console
            cout << "||-------\tWelcome to Aplication Talent Contest\t-------||" << endl;
            cout << "||-------\t\tJuri Dashboard\t\t\t-------||" << endl;
            if(code != 1 && code != 2 && code != 3 && code != 4 && code != 5 && code != 9 && cin.fail()){
                cout << "Code Salah, Harap Masukkan Code dengan benar!" << endl;
                cin.clear();
                cin.ignore();
            }
            cout << "1. Insert Nilai Peserta" << endl << "2. List Peserta - Telah Dinilai" << endl << "3. List Peserta - Belum Dinilai" << endl << "4. Hapus Nilai Perserta" << endl << "5. Logout" << endl << "9. Exit Aplication" << endl << "Masukan code (1-5 & 9)? ";
            cin >> code;
        }while(code != 1 && code != 2 && code != 3 && code != 4 && code != 5 && code != 9 && cin.fail());
    }

}

/** Show Peserta Proses*/
address_P newDuplicateElmList(address_P P){
    address_P Q = new elm_P;
    info(Q).namaPeserta = info(P).namaPeserta;
    info(Q).totalNilai = info(P).totalNilai;
    next(Q) = NULL;
    return Q;
}
void newDuplicateList(list_P &newList, list_P L2){
    createList(newList);
    address_P P = first(L2);
    while(P != NULL){
        insertLast(newList, newDuplicateElmList(P));
        P = next(P);
    }
}
address_P findASCElmList(list_P L){
    address_P Q = next(first(L)), temp = first(L);
    while(Q != NULL){
        if(info(Q).totalNilai > info(temp).totalNilai){
            temp = Q;
        }
        Q = next(Q);
    }
    return temp;
}
void showDataPesertaASC(list_P L){
    list_P tempL;
    newDuplicateList(tempL, L);
    address_P tempElmList = NULL, Q;
    if(isEmptyList(tempL)){
        cout << "--> List Peserta KOSONG <--" << endl;
    }else{
        do{
            if(next(first(tempL)) == NULL){
                deleteFirst(tempL, tempElmList);
            }else{
                tempElmList = findASCElmList(tempL);
                Q = first(tempL);
                if(Q == tempElmList){
                    deleteFirst(tempL, tempElmList);
                }else{
                    while(next(Q) != tempElmList){
                        Q = next(Q);
                    }
                    deleteAfter(Q, tempElmList);
                }
            }
            cout << "--> Nama : " << info(tempElmList).namaPeserta << "\t\t|| Total Nilai : " << info(tempElmList).totalNilai << endl;
        }while(first(tempL) != NULL);
    }
    cout << endl << "fecthing data BERHASIL" << endl;
}
void showPesertaAndNilai(list_P L1, list_R L2){
    if(!isEmptyList(L1)){
        int count;
        address_P P = first(L1);
        address_R R;
        while(P != NULL){
            cout << "Nama Peserta : " << info(P).namaPeserta << "\t\t|| Total Nilai : " << info(P).totalNilai << endl;
            if(findElmList(L2, P, NULL, "show") != NULL){
                R = first(L2);
                count = 0;
                while(R != NULL){
                    if(parent(R) == P){
                        cout << "--> Nama Juri : " << info(child(R)).namaJuri << "\t\t|| Nilai : " << infoNilai(R) << endl;
                        count++;
                    }
                    R = next(R);
                }
                if(count == 0){
                    cout << "--> TIDAK ADA Penilaian <--"<< endl;
                }
            }else{
                cout << "--> TIDAK ADA Penilaian <--" << endl;
            }
            P = next(P);
        }
    }else{
        cout << "--> List Peserta KOSONG <--" << endl;
    }
    cout << endl << "fecthing data BERHASIL" << endl;
}
void showJuriAndNilaiPeserta(list_J L1, list_R L2){
    if(!isEmptyList(L1)){
        int count;
        address_J J = first(L1);
        address_R R;
        while(J != NULL){
            cout << "Nama Juri : " << info(J).namaJuri << endl;
            if(findElmList(L2, NULL, J, "show") != NULL){
                R = first(L2);
                count = 0;
                while(R != NULL){
                    if(child(R) == J){
                        cout << "--> Nama Peserta : " << info(parent(R)).namaPeserta << "\t\t|| Nilai : " << infoNilai(R) << endl;
                        count++;
                    }
                    R = next(R);
                }
                if(count == 0){
                    cout << "--> TIDAK ADA Penilaian <--"<< endl;
                }
            }else{
                cout << "--> TIDAK ADA Penilaian <--" << endl;
            }
            J = next(J);
        }
    }else{
        cout << "--> List Juri KOSONG <--" << endl;
    }
    cout << endl << "fecthing data BERHASIL" << endl;
}

bool isNilaiJuriExist(list_R L1, address_P P, address_J J){
    address_R R = first(L1);
    while(R != NULL){
        if(parent(R) == P && child(R) == J){
            return true;
        }
        R = next(R);
    }
    return false;
}

/** Tampilan Utama */
void nonLoginUser(list_P L){
    showDataPesertaASC(L);
    system("PAUSE");
}
void loginAdmin(list_R &L1, list_P &L2, list_J &L3, int &code){
    char sign;
    string findNama, findUsername;
    address_P tempElmList_P;
    address_J tempElmList_J;
    dashboard("AdminDashboard", code);
    /** Manage Data Peserta */
    if(code == 1){
        do{
            dashboard("ManagePerserta", code);
            if(code == 1){
                do{
                    cout << endl << "--> Add Data Perserta : " << endl;
                    insertLast(L2, createElmList());
                    cout << "Data Sukses Ditambah" << endl;
                    cout << "Ingin menambahkan data peserta lagi? y/n ?"; cin >> sign;
                }while(tolower(sign) == tolower('y'));
            }else if(code == 2){
                viewData(L2);
                system("PAUSE");
            }else if(code == 3){
                cout << endl << "Nama yang akan di UPDATE : ";cin.ignore();getline(cin, findNama);
                cout << findNama << endl;
                tempElmList_P = NULL;tempElmList_P = findElmList(L2, findNama, "update");
                if(tempElmList_P != NULL){
                    updateData(L2, findNama);
                }else{
                    cout << "Nama yang anda cari tidak ditemukan" << endl;
                }
                Sleep(1000);
            }else if(code == 4){
                cout << endl << "Nama yang akan di DELETE : ";cin.ignore();getline(cin, findNama);
                tempElmList_P = NULL;
                tempElmList_P = findElmList(L2, findNama, "update");
                if(tempElmList_P != NULL){
                    deleteData(L2, findNama, tempElmList_P);
                }else{
                    cout << "Nama yang anda cari tidak ditemukan" << endl;
                }
                Sleep(1000);
            }
        }while(code != 5 && code != 6);
    /** Manage Data Juri */
    }else if(code == 2){
        do{
            dashboard("ManageJuri", code);
            if(code == 1){
                do{
                    cout << endl << "--> Add Data Juri : " << endl;
                    insertAsc(L3, createElmList(L3));
                    cout << "Data Sukses Ditambah" << endl;
                    cout << "Ingin menambahkan data peserta lagi? y/n ?"; cin >> sign;
                }while(tolower(sign) == tolower('y'));
            }else if(code == 2){
                viewData(L3);
                system("PAUSE");
            }else if(code == 3){
                cout << endl << "Username yang akan di UPDATE : ";cin.ignore();getline(cin, findUsername);
                tempElmList_J = NULL;tempElmList_J = findElmList(L3, findUsername, "update");
                if(tempElmList_J != NULL){
                    updateData(L3, findUsername);
                }else{
                    cout << "Username yang anda cari tidak ditemukan" << endl;
                }
                Sleep(1000);
            }else if(code == 4){
                cout << endl << "Username yang akan di DELETE : ";cin.ignore();getline(cin, findUsername);
                tempElmList_J = NULL;tempElmList_J = findElmList(L3, findUsername, "update");
                if(tempElmList_J != NULL){
                    deleteData(L3, findUsername, tempElmList_J);
                }else{
                    cout << "Username yang anda cari tidak ditemukan" << endl;
                }
                Sleep(1000);
            }
        }while(code != 5 && code != 6);
    /** Show Data Peserta with final point and each name of juri with point has given */
    }else if(code == 3){
        first(L2) == NULL ? waiting("Process fecthing data", 2) : waiting("Process fecthing data", 5);
        clear();
        cout << "||-------\tWelcome to Aplication Talent Contest\t-------||" << endl;
        cout << "||-------\tData Peserta (Nilai dan Juri)\t\t-------||" << endl;
        showPesertaAndNilai(L2, L1);
        system("PAUSE");
    /** Show Data Juri with point for each peserta*/
    }else if(code == 4){
        first(L3) == NULL ? waiting("Process fecthing data", 2) : waiting("Process fecthing data", 5);
        clear();
        cout << "||-------\tWelcome to Aplication Talent Contest\t-------||" << endl;
        cout << "||-------\tData Juri (Peserta dan Nilai)\t\t-------||" << endl;
        showJuriAndNilaiPeserta(L3, L1);
        system("PAUSE");
    }
}
void loginJuri(list_R &L1, list_P &L2, address_J &addressJuri, int &code){
    string namaPeserta;
    char sign;
    int x;
    address_R R = NULL, tempR = NULL;
    address_P P = NULL;
    dashboard("JuriDashboard", code);
    cout << "||-------\t\tNama Juri : " << info(addressJuri).namaJuri << "\t\t\t-------||" << endl;
    if(code == 1){
        cout << endl << "--> Add Nilai Perserta : " << endl;
        cout << "Cari Peserta : ";cin.ignore();getline(cin, namaPeserta);
        P = findElmList(L2, namaPeserta, "update");
        if(P != NULL){
            R = findElmList(L1, P, addressJuri, "update");
            if(R == NULL){
                cout << "Nama Peserta : " << info(P).namaPeserta << endl;
                insertFirst(L1, createElmList(P, addressJuri));
                cout << endl << "Add Nilai BERHASIL" << endl;
            }else{
                cout << endl << "Anda telah Menilai Peserta ini (Anda dapat MENGUBAH Nilai Peserta ini)" << endl;
                do{
                    cout << "Ingin Mengubah Nilai Peserta " << info(P).namaPeserta << "? y/n ?"; cin >> sign;
                }while(tolower(sign) != tolower('y') && tolower(sign) != tolower('n'));
                if(tolower(sign) == tolower('y')){
                    updateData(L1, P, addressJuri);
                    cout << endl << "Update Nilai BERHASIL" << endl;
                }else{
                    cout << endl << "Update Nilai GAGAL" << endl;
                }
            }
        }else{
            cout << endl << "Data Peserta Tidak ditemukan" << endl;
        }
        Sleep(1000);
    }else if(code == 2){
        cout << endl << "--> List Perserta - Telah Dinilai : " << endl;
        R = first(L1);
        x = 0;
        while(R != NULL){
            if(child(R) == addressJuri){
                cout << "--> Nama : " << info(parent(R)).namaPeserta << "\t|| Total Nilai : " <<  info(parent(R)).totalNilai << "\t|| Nilai dari Anda : " <<  infoNilai(R) << "\t|| Status : Telah di Nilai" << endl;
                x++;
            }
            R = next(R);
        }
        if(x == 0){
            cout << "--> List Kosong <--" << endl;
        }
        system("PAUSE");
    }else if(code == 3){
        cout << endl << "--> List Perserta - Belum Dinilai : " << endl;
        P = first(L2);
        x = 0;
        while(P != NULL){
            if(!isNilaiJuriExist(L1, P, addressJuri)){
                cout << "--> Nama : " << info(P).namaPeserta << "\t|| Total Nilai : " <<  info(P).totalNilai << "\t|| Status : Belum di Nilai" <<endl;
                x++;
            }
            P = next(P);
        }
        if(x == 0){
            cout << "--> List Kosong <--" << endl;
        }
        system("PAUSE");
    }else if(code == 4){
        try{
            cout << endl << "Nama yang akan di DELETE Nilainya : ";cin.ignore();getline(cin, namaPeserta);
            P = findElmList(L2, namaPeserta, "update");
            deleteData(L1, P, addressJuri, tempR);
        }catch(int e){
            cout << "Error code : " << e << " -> Data Gagal UPDATE" << endl;
        }
        Sleep(1000);
    }
}

address_J prosesLoginJuri(list_J &L, string username, string password){
    if(!isEmptyList(L)){
        address_J J = first(L);
        while(J != NULL){
            if(info(J).username == username && info(J).password == password){
                return J;
            }
            J = next(J);
        }
    }
    return NULL;
}
