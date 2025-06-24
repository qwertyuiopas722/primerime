/*so dirty :(*/

#include <iostream>
#include <vector>
#include <cmath>

#include <fstream>

#include <windows.h>

#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void teco(int c){
    SetConsoleTextAttribute(hConsole,c);
}

string dectoxout="";
void dectox(int iv, int len){
    stringstream ss;
    ss << hex << iv;
    string rs=ss.str();
    for (int i=size(rs); i<len; i++){
        rs="0"+rs;
    }
    dectoxout=rs;
}


vector<int> pribol;
void makli(int l){
    int lgo=pow(10,floor(log10(l)));
    teco(15);
    cout<< "makli:" <<endl;
    teco(8);
    for (int i=0; i<l; i++){
        pribol.push_back(1);
        if (i%lgo==0){ cout<<i<<endl; }
    }
    teco(7);
    cout<<size(pribol)<<endl;
    teco(15);
    cout<<"L\n"<<endl;
    teco(8);
}

void mulitechava(int m){
    int x=2;
    while (m*x<size(pribol)){
        pribol[m*x]=0;
        x++;
    }
}

int main(){
    int len=pow(2,14);
    makli(len*len);
    pribol[0]=0;
    pribol[1]=0;
    teco(15);
    cout<<"find in 'sqrted' range:"<<endl;
    teco(7);
    for (int n=2;n<len;n++){
        if (pribol[n]==1){
            mulitechava(n);
            cout<<n<<endl;
        }
    }
    teco(15);
    cout<<"L\n"<<endl;
    cout<<"find all and make txt:"<<endl;
    ofstream txtf;
    int count=0;
    int fn=0;
    txtf.open("primeslist0.txt");
    for (int n=2;n<=size(pribol);n++){
        if (pribol[n]==1){
            dectox(n,7);
            if (count%1024==1023){
                txtf << dectoxout << endl;
            }
            else {
                txtf << dectoxout << " ";
            }
            count++;
            if (count%2097152==0){
                fn++;
                stringstream fns;
                fns << dec << fn;
                string fnst=fns.str();
                txtf.close();
                string f="primeslist" + fnst + ".txt";
                txtf.open(f);
            }
        }
    }
    return 0;
}
