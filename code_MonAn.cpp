#include<bits/stdc++.h>
#include<string>
#include<fstream>
using namespace std;
//khai bao class hang hoa
class MonAn{
    private:
        string _strMaMon;
        string _strTenMon;
        double _dGiaBan;
        int _iSoLuong;
    public:
        string getMaMon(){return _strMaMon;}
        string getTenMon(){return _strTenMon;}
        double getGiaBan(){return _dGiaBan;}
        int getSoLuong(){return _iSoLuong;}

        void setMaMon(string _MaMon){_strMaMon=_MaMon;}
        void setTenMon(string _TenMon){_strTenMon=_TenMon;}
        void setGiaBan(double _GiaBan){_dGiaBan=_GiaBan;}
        void setSoLuong(int _sl){_iSoLuong=_sl;}

        void nhap();
        void docMonAn(ifstream &filein);
        void xuatThongTin();

        friend istream& operator>>(istream& is,MonAn &h){
            cout<<endl<<"Vui long nhap cac thong tin sau cho Mon an: ";
            cout<<endl<<"Nhap ma MON AN: ";
            getline(is,h._strMaMon);
            while(h._strMaMon.size()!=4){
                cout<<"Ma mon an nhap khong chinh xac, vui long nhap lai ! "<<endl;
                cout<<"Nhap ma mon an: ";
                getline(is,h._strMaMon);
            }
            cout<<"Nhap ten Mon An: ";
            getline(is,h._strTenMon);
            cout<<"Nhap gia ban: ";
            is>>h._dGiaBan;
            is.ignore();
            cout<<"Nhap so luong mon an: ";
            is>>h._iSoLuong;
            is.ignore();

            return is;
        }


};

void MonAn::nhap(){
            cout<<endl<<"Vui long nhap cac thong tin sau cho mon an: ";
            cout<<endl<<"Nhap ma mon an: ";
            getline(cin,this->_strMaMon);

            while(_strMaMon.size()!=4){
                cout<<"Ma mon an nhap khong chinh xac, vui long nhap lai ! "<<endl;
                cout<<"Nhap ma mon an: ";
                getline(cin,_strMaMon);
            }
            cout<<"Nhap ten mon an: ";
            getline(cin,_strTenMon);
            cout<<"Nhap gia ban: ";
            cin>>_dGiaBan;
            cin.ignore();
            cout<<"Nhap so luong hang hoa: ";
            cin>>_iSoLuong;
            cin.ignore();
        }
        void MonAn::docMonAn(ifstream &filein){
            getline(filein,_strMaMon,',');
            getline(filein,_strTenMon,',');
            filein>>_dGiaBan;
            filein.ignore();
            filein>>_iSoLuong;
            //xoa cai xuong dong
            string temp;
            getline(filein,temp);

        }
        void MonAn::xuatThongTin(){
        	cout << "\n========================================================\n";
        	cout << endl;
            cout<<_strMaMon<<"\t"<<_strTenMon<<"\t\t"<<_dGiaBan<<"\t\t"<<_iSoLuong<<"\n";
        }



/*----------------------------------LIST HANG HOA------------------------------*/

//khai bao danh sach hang hoa
class ListMonAn:public MonAn{
    MonAn *_pMonAn;//khai bao con tro quan ly mang dong
    int _iTongSoLuong;

    public:
    int getSoLuong();
    void docList_MA(ifstream& is);
    void docListMonAn(ifstream& is);
    void ghiListMonAn(ofstream&fileout);

    void xuatListMonAn();

    //Tim kiem thong tin hang hoa
    void timMonAnTheoTenMon();
    bool kiemMonAnTheoMaMon(string mamon,int so);
    double timGiaBanTheoMaMon(string mamon);
	//Cac ham de quan ly hang hoa o day
    //them 1 hang hoa moi vao list
    void themMonAn();
    //xoa hang hoa theo ma hang
    void xoaMonAnTheoMaMon(string mamon);
    //cap nhat so luong theo ma
    void capNhatSoLuongTheoMa(string mamon,int so);
    void giamSoLuongTheoMa(string mamon,int so);

};

int ListMonAn::getSoLuong(){return _iTongSoLuong;}
    void ListMonAn::docListMonAn(ifstream& is){
        int dem=0;
        //B1:tim so luong hang hoa trong file txt- tim so dong de cap phat mang dong
        while(is.eof()==false){//doc den khi con tro ve cuoi file
            string x;
            getline(is,x);//doc nguyen dong
            dem++;
        }
        _iTongSoLuong=dem;
        //B2: CapPhat mang dong hang hoa
        _pMonAn=new MonAn[_iTongSoLuong];
        //B3: Cho con tro chi vi ve dau file
        is.seekg(is.beg,is.beg);
        //B4:doc danh sach hang hoa
        docList_MA(is);

    }
    void ListMonAn::docList_MA(ifstream& is){
        for(int i=0;i<_iTongSoLuong;i++){
            _pMonAn[i].docMonAn(is);//doc thong tin hang hoa thu i
        }
    }

    void ListMonAn::ghiListMonAn(ofstream&fileout){
        for(int i=0;i<_iTongSoLuong;i++){
            fileout<<_pMonAn[i].getMaMon()<<",";
            fileout<<_pMonAn[i].getTenMon()<<",";
            fileout<<_pMonAn[i].getGiaBan()<<",";
            fileout<<_pMonAn[i].getSoLuong();
            if(i!=_iTongSoLuong-1) fileout<<endl;
        }
    }

    void ListMonAn::xuatListMonAn(){
        cout<<"Ma\tTen Mon An\t\tGia Thanh\tSo Luong\n";
        for(int i=0;i<_iTongSoLuong;i++){
            _pMonAn[i].xuatThongTin();
        }
    }

    //Tim kiem thong tin hang hoa
    void ListMonAn::timMonAnTheoTenMon(){

        string _strMonTim;
        cout<<"Nhap ten Mon An can tim kiem: ";
        getline(cin,_strMonTim);
        for(int i=0;i<_iTongSoLuong;i++){
            //stricmp so sanh ko phan biet hoa thuong, chuyen ve char C

            if(stricmp(_pMonAn[i].getTenMon().c_str(),_strMonTim.c_str()) == 0){
                _pMonAn[i].xuatThongTin();
                return;
            }
        }
        cout<<"Khong tim thay mon an"<<endl;
    }
    bool ListMonAn::kiemMonAnTheoMaMon(string mamon,int so){
        for(int i=0;i<_iTongSoLuong;i++){
            //stricmp so sanh ko phan biet hoa thuong, chuyen ve char C
            if(stricmp(_pMonAn[i].getMaMon().c_str(),mamon.c_str()) == 0 && _pMonAn[i].getSoLuong()>so){
                return true;
            }
        }
        return false;
    }
    double ListMonAn::timGiaBanTheoMaMon(string mamon){
        for(int i=0;i<_iTongSoLuong;i++){
            //stricmp so sanh ko phan biet hoa thuong, chuyen ve char C
            if(stricmp(_pMonAn[i].getMaMon().c_str(),mamon.c_str()) == 0){
                return _pMonAn[i].getGiaBan();
            }
        }
        return 0;
    }
//Cac ham de quan ly hang hoa o day
    //them 1 hang hoa moi vao list
    void ListMonAn::themMonAn(){
        int newSize=_iTongSoLuong+1;
        MonAn *temp=new MonAn[newSize];
        for(int i=0;i<_iTongSoLuong;i++){
            temp[i]=_pMonAn[i];
        }
        delete[]_pMonAn;
        _pMonAn=temp;
        _iTongSoLuong=newSize;
        _pMonAn[_iTongSoLuong-1].nhap();
        for(int i=0;i<_iTongSoLuong-1;i++){
            if(_pMonAn[_iTongSoLuong-1].getMaMon()==_pMonAn[i].getMaMon()){
                cout<<"Ma mon an bi trung !!!"<<endl;
                int k;
                cout<<"De them so luong mon an voi ma mon an tren, nhan phim 1"<<endl;
                cout<<"De nhap lai, nhan phim 2";
                cout<<"Nhap k: ";
                cin>>k;
                while(k!=1 && k!=2){
                    cout<<"Nhap chua chinh xac, vui long nhap lai"<<endl;
                    cout<<"Nhap k: ";
                    cin>>k;
                }
                if(k==1){
                    //chay lai size cu
                    newSize=_iTongSoLuong-1;
                    temp=new MonAn[newSize];
                    for(int i=0;i<newSize;i++){
                        temp[i]=_pMonAn[i];
                    }
                    delete[]_pMonAn;
                    _pMonAn=temp;
                    _iTongSoLuong=newSize;
                    //tang sl hang hoa

                }
                if(k==2){
                    _pMonAn[_iTongSoLuong-1].nhap();
                }
            }
        }
    }
    //xoa hang hoa theo ma hang
    void ListMonAn::xoaMonAnTheoMaMon(string mamon){
        int vitri=-1;
        for(int i=0;i<_iTongSoLuong;i++){
            //stricmp so sanh ko phan biet hoa thuong, chuyen ve char C
            if(stricmp(_pMonAn[i].getMaMon().c_str(),mamon.c_str()) == 0){
                vitri=i;break;
            }
        }
        if(vitri==-1) cout<<"Khong tim thay ma mon an nay\n";
        else{
        for(int i=vitri;i<_iTongSoLuong-1;i++){
            _pMonAn[i]=_pMonAn[i+1];
        }
        int newSize=_iTongSoLuong-1;
        MonAn *temp=new MonAn[newSize];
        for(int i=0;i<newSize;i++){
            temp[i]=_pMonAn[i];
        }
        delete[]_pMonAn;
        _pMonAn=temp;
        _iTongSoLuong=newSize;
        }
    }
    //cap nhat so luong theo ma
    void ListMonAn::capNhatSoLuongTheoMa(string mamon,int so){
        for(int i=0;i<_iTongSoLuong;i++){
            //stricmp so sanh ko phan biet hoa thuong, chuyen ve char C
            if(stricmp(_pMonAn[i].getMaMon().c_str(),mamon.c_str()) == 0){
                _pMonAn[i].setSoLuong(_pMonAn[i].getSoLuong()+so);
            }
        }
    }
    void ListMonAn::giamSoLuongTheoMa(string mamon,int so){
        cout<<mamon<<" "<<so<<endl;
        if(kiemMonAnTheoMaMon(mamon,so)){
            for(int i=0;i<_iTongSoLuong;i++){
            //stricmp so sanh ko phan biet hoa thuong, chuyen ve char C
                if(stricmp(_pMonAn[i].getMaMon().c_str(),mamon.c_str()) == 0){
                    _pMonAn[i].setSoLuong(_pMonAn[i].getSoLuong()-so);
                }
            }
        }

            else{
            cout<<"\nSo luong mon an khong du de thuc hien"<<endl;
            }


    }

//KHAI BAO BIEN
ListMonAn listhh;
ifstream filein;
ofstream fileout;
