#include "assetsHeader.h"

int main()
{
    list_R L_R;
    list_P L_P;
    list_J L_J;

    address_P tempAddress1;
    address_J tempAddress2;
    address_R tempAddress3;
    const string username = "admin", password = "admin"; // Username dan Password "ADMIN"
    string username_temp = "", password_temp = "";

    int code = 9;
    createList(L_R);
    createList(L_P);
    createList(L_J);
    do{
        dashboard("LoginDashboard", code);// procedure file => assetsHeader.h
        cout << code << endl;
        /** Non User LOGIN */
        if(code == 1){
            clear();// cleared console
            first(L_P) == NULL ? waiting("Process fecthing data", 2) : waiting("Process fecthing data", 5); // Bentuk lain dari IF ELSE => (kondisi ? true : false;)
            clear();// cleared console
            cout << "||-------\tWelcome to Aplication Talent Contest\t-------||" << endl;
            cout << "||-------\t\tList Peserta\t\t\t-------||" << endl;
            nonLoginUser(L_P);// procedure file => assetsHeader.h
        /** Login ADMIN*/
        }else if(code == 2){
            clear();// cleared console
            cout << "--> LOGIN Admin <--" << endl;
            cout << "Username : ";cin >> username_temp;
            cout << "Password : ";cin >> password_temp;
            if(username_temp == username && password_temp == password){
                cout << "Login Admin BERHASIL" << endl;
                Sleep(500);// Aplication will PAUSE during time set
                do{
                    clear();// cleared console
                    loginAdmin(L_R, L_P, L_J, code);// procedure file => assetsHeader.h
                    if(code == 9 || code == 5){// if code = 9? exit from Aplication AND if code = 5? aplication will EXIT from ADMIN Dashboard
                        username_temp = "";
                        password_temp = "";
                    }
                }while(username_temp != "" && password_temp != "");
            }else{
                cout << "Username atau Password Salah" << endl;
                Sleep(500);// Aplication will PAUSE during time set
            }
        /** Login JURI*/
        }else if(code == 3){
            clear();// cleared console
            cout << "--> LOGIN Juri <--" << endl;
            cout << "Username : ";cin >> username_temp;
            cout << "Password : ";cin >> password_temp;
            tempAddress2 = prosesLoginJuri(L_J, username_temp, password_temp);
            if(tempAddress2 != NULL){
                cout << "Login Juri BERHASIL" << endl;
                Sleep(500);// Aplication will PAUSE during time set
                do{
                    clear();// cleared console
                    loginJuri(L_R, L_P, tempAddress2, code);// procedure file => assetsHeader.h
                    if(code == 9 || code == 5){// if code = 9? exit from Aplication AND if code = 5? aplication will EXIT from JURI Dashboard
                        tempAddress2 = NULL;
                    }
                }while(tempAddress2 != NULL);
            }else{
                cout << "Akun Tidak dapat Ditemukan" << endl << "Mohon Cek Kembali Inputan Anda" << endl;
                Sleep(500);// Aplication will PAUSE during time set
            }
        }
    }while(code != 9);
    waiting("Exit Proses Mohon Tunggu", 3);// procedure file => assetsHeader.h ? Set DOT ("string", dotCount);
    cout << endl << "--> Proses Selesai <--" << endl << "--> GoodBye <--" << endl << flush;
    char copyright = 184;
    cout << "||-------Copyright "<< copyright <<" 2020 dicky&noval industri, INC-------||";

    return 0;
}
