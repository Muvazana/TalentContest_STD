#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <stdlib.h>
#include "relationHeader.h"

void clear();// cleared console
void waiting(string text, int time);// "time" ? 500 milisecond/per DOT
void dashboard(string codeDashboard, int &code);
void nonLoginUser(list_P L);
void loginAdmin(list_R &L1, list_P &L2, list_J &L3, int &code);
void loginJuri(list_R &L1, list_P &L2, address_J &addresJuri, int &code);
address_J prosesLoginJuri(list_J &L, string username, string password);// search juri account from username and password