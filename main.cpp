#include<bits/stdc++.h>
#include<conio.h>
#include "code_DonHang.cpp"
#include <windows.h>
using namespace std;

void thoatChuongTrinh();
void docListMonAnFull();
void docListDonHangFull();
void giaoDien1();
void quaylaiTrangChu();
void giaoDienDangNhap();
void docListNhanVienFull();
void giaoDienNhanVien();
void quanLyMonAn();
void SetConsoleColor(int text_color, int background_color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_color | (background_color << 4));
    }

int main(){
    SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY, BACKGROUND_BLUE);

    filein.open("MonAn.txt",ios_base::in);
    listhh.docListMonAn(filein);
    //listhh.xuatListHangHoa();
    filein.close();

    foi.open("DonHang.txt",ios_base::in);
    ListDonHang listdh;
    listdh.docListDonHang(foi);
    foi.close();

    giaoDien1();
    return 0;
}


void thoatChuongTrinh(){
    system("cls");//xoa man hinh
            cout << endl;
            cout << "\t\t\t+---------------------------------------------------+\n";
            cout << "\t\t\t| CAM ON QUY KHACH, RAT HAN HANH PHUC VU QUY KHACH  |\n";
            cout << "\t\t\t+---------------------------------------------------+\n";
            cout << endl;
    getch();
	exit(0);
}


void docListMonAnFull(){
    filein.open("MonAn.txt",ios_base::in);
    listhh.docListMonAn(filein);
    listhh.xuatListMonAn();
    filein.close();
}

void docListDonHangFull(){
    foi.open("DonHang.txt",ios_base::in);
    listdh.docListDonHang(foi);
    foi.close();
    listdh.xuatListDonHang();
}

void giaoDien1(){
    cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ CHAO MUNG DEN VOI NHA HANG ============|";
	int j;
	system("cls");
	cout<<"\n\t\t   HE THONG QUAN LY NHA HANG\n";
	cout<<"=============================================================";
	cout<<"\n\n\t\t   [1]. Hien thi thong tin mon an\n\n\t\t   [2]. Tim kiem thong tin mon an\n\n\t\t   [3]. Dat hang\n\n\t\t   [4]. Quan ly\n\n\t\t   [5]. Thoat"  ;
	cout<<"\n\n=============================================================\n";
	cout<<"\n\nNHAP LUA CHON CUA BAN: ";

	cin>>j;
    switch(j){
        case 1:
            system("cls");
            cout << "\t\t+--------------------------------------+\n";
            cout << "\t\t|          DANH SACH HIEN CO           |\n";
            cout << "\t\t+--------------------------------------+\n";
            docListMonAnFull();
            quaylaiTrangChu();
            break;

        case 2:
            system("cls");
            cin.ignore();
            listhh.timMonAnTheoTenMon();
            quaylaiTrangChu();
            break;

        case 3:
            system("cls");
            foi.open("DonHang.txt",ios_base::in);
            listdh.docListDonHang(foi);
            foi.close();
            //listdh.xuatListDonHang();
            cin.ignore();
            listdh.themDonHang();
            fot.open("DonHang.txt",ios_base::out);
            listdh.ghiListDonHang(fot);
            fot.close();
            quaylaiTrangChu();
            break;

        case 4:
            system("cls");
            cin.ignore();
            giaoDienDangNhap();
            break;
        case 5:
            thoatChuongTrinh();
    }
}
void quaylaiTrangChu(){
        cout << endl;
        cout << "+--------------------------------------+\n";
        cout << "| NHAN 1 DE QUAY LAI TRANG CHU         |\n";
        cout << "| NHAN 2 DE THOAT CHUONG TRINH         |\n";
        cout << "+--------------------------------------+\n";
        cout << endl;

    int i;
        cout << "NHAP LUA CHON CUA BAN: ";
    cin>>i;
        do{
            if(i==1) giaoDien1();
            if(i==2) thoatChuongTrinh();
            if(i != 1 || i != 2){
            cout<<"Nhap khong chinh xac, vui long nhap lai!"<<endl;
            cout << endl;
            cout << "+--------------------------------------+\n";
            cout << "| NHAN 1 DE QUAY LAI TRANG CHU         |\n";
            cout << "| NHAN 2 DE THOAT CHUONG TRINH         |\n";
            cout << "+--------------------------------------+\n";
            cout << endl;
            cout << "NHAP LUA CHON CUA BAN: ";
            cin>>i;
            }
        }while(i != 1 || i != 2);
}
void giaoDienDangNhap(){

    int iSoLanDangNhap=0;
    docListNhanVienFull();
    string strUser,strPass;
    dangnhap:
    strUser="",strPass="";
    char cKiTu;
    system("cls");
    cout<<"\n=============================================================\n";
    cout<<"\n\t\t   DANG NHAP HE THONG\n";
	cout<<"\n=============================================================\n";

    cout<<"\n\n\n\n\t\tUser: ";
        getline(cin,strUser);
    cout<<"\n\n\n\n\t\tPassword: ";
    for(int z=0;z<3;z++)
	{
		cKiTu=getch();
        strPass+=cKiTu;
		system("cls");
        cout<<"\n=============================================================\n";
        cout<<"\n\t\t   DANG NHAP HE THONG\n";
	    cout<<"\n=============================================================\n";
        cout<<"\n\n\n\n\t\tUser: "<<strUser;

        cout<<"\n\n\n\n\t\tPassword: ";
		for(int i=1;i<=z+1;i++)
		{
			cout<<"*";
		}
	}

    if(listnv.checkDangNhap(strUser,strPass)){
        cout<<endl<<"Dang nhap thanh cong!"<<endl;
        system("pause");
        system("cls");
        giaoDienNhanVien();

    }
    else{
        iSoLanDangNhap++;
        if(iSoLanDangNhap==3){
            cout<<"\n\nTruy cap bi tu choi..\n\n";
            getch();
            getch();

            exit(0);
        }
        else{
            goto dangnhap;
        }

    }
}

void docListNhanVienFull(){
    ifile.open("Admin.txt",ios_base::in);
    listnv.docListNhanVien(ifile);
    ifile.close();
}
void giaoDienNhanVien(){
    cin.clear();
    int i;
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\tMENU QUAN LY\n1. Xu ly don hang\n2. Quan ly mon an\n3. Exit \n4. Dang xuat";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n NHAP LUA CHON CUA BAN: ";
	cin>>i;

    switch(i){
        case 1:
            cin.ignore();
            //xuat list don hang dang ton tai
            system("cls");
            cout<<"\n\t\t\tDANH SACH DON HANG CHO XU LY\n\n";
            docListDonHangFull();
            getch();
            system("cls");

            //xuat list hang hoa
            cout<<"\n\t\t\tDANH SACH MON AN\n\n";
            docListMonAnFull();
            getch();
            system("cls");

            cout<<"Dang xu ly don hang..."<<endl;
            getch();

            //xu ly don hang, ghi lai file hang hoa
            listdh.xoaXuLyListDonHang();
            fileout.open("MonAn.txt",ios_base::out);
            listhh.ghiListMonAn(fileout);
            fileout.close();

            //ghi lai file don hang
            fot.open("DonHang.txt",ios_base::out);
            listdh.ghiListDonHang(fot);
            fot.close();

            //xuat lai hang hoa sau khi da xu ly don hang
            system("cls");
            cout<<"\n\t\t\tDANH SACH MON AN SAU KHI THUC HIEN\n\n";
            docListMonAnFull();
            //listhh.xuatListHangHoa();
            getch();
            cout<<"Nhan phim bat ky de tro lai trang quan ly \n";
            system("pause");
            giaoDienNhanVien();
            break;

        case 2:
            cin.ignore();
            quanLyMonAn();
            break;

        case 3:
            cout<<"Dang thoat chuong trinh...";
            system("cls");
            cout << endl;
            cout << "+---------------------------------------------------+\n";
            cout << "| CAM ON QUY KHACH, RAT HAN HANH PHUC VU QUY KHACH  |\n";
            cout << "+---------------------------------------------------+\n";
            cout << endl;
            getch();
            exit(0);
        case 4:
            cin.ignore();
            cout<<"Dang xuat thanh cong!!!"<<endl;
            system("pause");
            giaoDienDangNhap();
            break;
    }
}

void quanLyMonAn(){
    string strMaMon;
    int i,iSo;
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\tMENU QUAN LY NHA HANG\n1. Them mon an moi\n2. Xoa mon an theo ma\n3. Cap nhat so luong mon an\n4. Tro ve menu quan ly\n5. Thoat";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n NHAP LUA CHON CUA BAN:\t";
	cin>>i;
    switch(i){
        case 1:
        system("cls");
        cin.clear();
        cin.ignore();
        listhh.themMonAn();
        fileout.open("MonAn.txt",ios_base::out);
        listhh.ghiListMonAn(fileout);
        fileout.close();
            cout << endl;
            cout << "+--------------------+\n";
            cout << "|  DA THEM MON AN <3 |\n";
            cout << "+--------------------+\n";
            cout << endl;
        getch();
        cout<<"Nhan phim bat ky de tro lai trang quan ly \n";
        system("pause");
        quanLyMonAn();
        break;

        case 2:
        system("cls");
        cin.clear();
        cin.ignore();
        cout<<"\nNhap mon an can xoa: ";
        getline(cin,strMaMon);
        listhh.xoaMonAnTheoMaMon(strMaMon);
        fileout.open("MonAn.txt",ios_base::out);
        listhh.ghiListMonAn(fileout);
        fileout.close();
        cout<<"\n\t\t\tDANH SACH MON AN SAU KHI THUC HIEN\n";
        docListMonAnFull();
        getch();
        cout<<"Nhan phim bat ky de tro lai trang quan ly \n";
        system("pause");
        quanLyMonAn();
        break;

        case 3:
        system("cls");
        cin.ignore();
        cout<<"\nNhap ma mon an can cap nhat so luong: ";
        getline(cin,strMaMon);
        cout<<"\nNhap so luong ban muon them vao: ";
        cin>>iSo;
        cin.ignore();
        listhh.capNhatSoLuongTheoMa(strMaMon,iSo);
        fileout.open("MonAn.txt",ios_base::out);
        listhh.ghiListMonAn(fileout);
        fileout.close();
        cout<<"\n\t\t\tDANH SACH MON AN SAU KHI THUC HIEN\n";
        docListMonAnFull();
        getch();
        cout<<"Nhan phim bat ky de tro lai trang quan ly \n";
        system("pause");
        quanLyMonAn();
        break;

        case 4:
        system("cls");
        cin.ignore();
        giaoDienNhanVien();
        break;
        case 5:
        system("cls");
        thoatChuongTrinh();
    }
}
