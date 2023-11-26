#include<bits/stdc++.h>
#include<string>
#include<fstream>
using namespace std;
ifstream ifile;

class NhanVien{
    string _strUserName;
    string _strPassword;

    public:
    string getUserName(){return _strUserName;}
    string getPassword(){return _strPassword;}

    void docNhanVien(ifstream &ifile);
};
void NhanVien::docNhanVien(ifstream &ifile){
        //ifile.ignore();
        getline(ifile,_strUserName,',');
        string temp;
        getline(ifile,_strPassword,',');
        getline(ifile,temp);        
}


class ListNhanVien{
    int _iSoNhanVien;
    NhanVien* _pNhanVien;

    public:
    int getSoNhanVien();

    void docListNhanVien(ifstream& ifile);
    void docList_Ad(ifstream& ifile);
    bool checkDangNhap(string user,string pass);
    void xuatListNhanVien();
};

int ListNhanVien::getSoNhanVien(){return _iSoNhanVien;}

    void ListNhanVien::docListNhanVien(ifstream& ifile){
        int dem=0;
        //B1:tim so luong hang hoa trong file txt- tim so dong de cap phat mang dong
        while(ifile.eof()==false){//doc den khi con tro ve cuoi file
            string x;
            getline(ifile,x);//doc nguyen dong du
            dem++;
        }
        _iSoNhanVien=dem;
        _pNhanVien=new NhanVien[_iSoNhanVien];
        ifile.seekg(ifile.beg,ifile.beg);
        docList_Ad(ifile);
    }
    void ListNhanVien::docList_Ad(ifstream& ifile){
        for(int i=0;i<_iSoNhanVien;i++){
            _pNhanVien[i].docNhanVien(ifile);//doc thong tin thu i
        }
    }
    bool ListNhanVien::checkDangNhap(string user,string pass){
        for(int i=0;i<_iSoNhanVien;i++){
            if(_pNhanVien[i].getUserName()==user && _pNhanVien[i].getPassword()==pass){
                return true;
            }
        }
        return false;
    }
    void ListNhanVien::xuatListNhanVien(){
        for(int i=0;i<_iSoNhanVien;i++){
            cout<<_pNhanVien[i].getUserName()<<" "<<_pNhanVien[i].getPassword()<<endl;
        }
    }

ListNhanVien listnv;