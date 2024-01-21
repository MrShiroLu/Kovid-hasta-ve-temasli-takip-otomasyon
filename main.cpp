#include<iostream>
#include<fstream>
#include<locale.h> 
#include<conio.h>
#include<string.h>
#include"fonksiyonlar.h"//hasta ve temaslý iþlemleri bu kütüphaneden geliyor
/*
Burak Artun
2312729005
Kovid hasta ve temasli takip otomasyonu
*/
using namespace std;

int main(){
	int secim;
	char devam;
	do{
	
	cout << "|------------Menu-------------|"<<endl;
	cout << "|	1.Hasta Ekle          |"<<endl;
	cout << "|	2.Hasta Sil           |"<<endl;
	cout << "|	3.Hasta Listele       |"<<endl;
	cout << "|	4.Temasli Ekle        |"<<endl;
	cout << "|	5.Temasli Sil         |"<<endl;
	cout << "|	6.Temasli listele     |"<<endl;
	cout << "|-----------------------------|"<<endl;
	cin >> secim; cout << endl;
	
	switch(secim){
		case 1:
			hastaEkle();
			break;		
		
		case 2:
			hastaSil();
			break;
		case 3:
			hastaListele();
			break;
		case 4:
			temasliEkle();
			break;
		case 5:
			temasliSil();
			break;
		case 6:
			temasliListele();
			break;
			
		}
		cout << "\nIslemlere devam etmek istiyor musunuz [E/H]: ";
		devam=getch();
		cout << endl;
		system("cls");
	}
	while(devam=='E'|| devam=='e');
	
	return 0;
}
