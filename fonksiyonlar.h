#include<iostream>
#include<fstream>
#include<locale.h>
#include<cstdlib>
#include<iomanip> 
#include<stdlib.h>
#include<conio.h>
#include<string.h>

using namespace std;

//temaslý parametreler
struct Temasli{
	char isim[50],soyisim[50],semptom[50],temasli_no[10],cinsiyet;
	int girisGun,girisAy,girisYil,yas;
};

//hasta parametreler
struct Hasta{ 
	char cinsiyet,hasta_no[100],isim[60],soyisim[60],semptom[10] ;
	int girisGun,girisAy,girisYil,yas;
};

// Temasli islemler
int temasliEkle(){
	char secim =' ';
	ofstream yazdir("veriler\\temasli_giris.dat",ios::binary |ios::app);
	if(!yazdir.is_open()){
		cout << "Dosya açma iþlemi baþarýsýz!!!";
		exit(0);
	}

	
	// temaslý yapýsý oluþturma
	Temasli temasli;
	// temaslýnýn bilgilerini alýr
	do{
	
        cout <<  "temaslýnýn ismi: ";
        cin >> temasli.isim;
		cout << endl;
		
        cout << "temaslýnýn soyismi: ";
        cin >> temasli.soyisim;
        cout << endl;
        
        cout << "temaslýnýn numarasýný giriniz: ";
        cin >> temasli.temasli_no;
        cout << endl;
        
		cout << "temaslýnýn yaþý: ";
		cin >> temasli.yas;
		cout << endl;		
		
		cout << "temaslýnýn cinsiyeti: ";
		cin >> temasli.cinsiyet;
		cout << endl;
		
		cout << "temaslýnýn yasadigi en fazla olan semptom: ";
		cin >> temasli.semptom;
		cout << endl;				
		
		cout << "temaslýnýn girdiði gün: ";
		cin >> temasli.girisGun;		
		cout << endl;
		
		cout << "temaslýnýn girdiði ay: ";
		cin >> temasli.girisAy;
		cout << endl;			
		
		cout << "temaslýnýn girdiði yil: ";
		cin >> temasli.girisYil;
		cout << endl;
		
		// dosya içine yazdýrýr
		
		yazdir.write((char*)&temasli, sizeof(temasli));
		
		cout << "Devam etmek ister misiniz?[E/H] ";
		secim = getch();
	}
	while(secim=='e'|| secim=='E');

	yazdir.close();
}
void temasliSil(){
	ifstream dos("veriler\\temasli_giris.dat",ios::binary |ios::app);
	
	Temasli temasli;
	char temno[200];
    char secim= ' ';
    bool var=false;
		
	dos.seekg(0,ios::end);

	int kayitsayisi=dos.tellg()/sizeof(temasli);
	
    cout<<"Kaydini sileceginiz temaslinin numarasini giriniz : ";
    cin>>temno;

    for(int i=0;i<kayitsayisi;i++){
        dos.seekg(i*sizeof(temasli));
		dos.read((char*)&temasli, sizeof(temasli));
			
        if(strcmp(temasli.temasli_no,temno)==0){
        	
            cout<<endl;
            cout<<"temaslinin";
            cout<<"\nAdi: "<<temasli.isim;
            cout<<"\nSoyadi: "<<temasli.soyisim;
            cout<<"\nNO: "<<temasli.temasli_no;
            cout<<"\nYas: "<<temasli.yas;
            cout<<"\nGiris tarihi: " << temasli.girisGun << " "<<temasli.girisAy<<" "<<temasli.girisYil;
            cout<<"\nSemptom(lar): " << temasli.semptom;
            cout<<"\nCinsiyet: ";
            if(temasli.cinsiyet=='e'||temasli.cinsiyet=='E')
                cout<<"Erkek";
            if(temasli.cinsiyet=='k'||temasli.cinsiyet=='K')
                cout<<"Bayan";
                		  
            cout<<"\n\nSilmek Istediginiz Kayit Bu Mu? [E/H] : ";
            secim=getche();
                
            if(secim == 'H' || secim == 'h'){      
			    ofstream yedek_temasli_dosya("Yedek_temasli.dat",ios::app|ios::binary);
                        
                yedek_temasli_dosya.write((char*)&temasli, sizeof(temasli));
                yedek_temasli_dosya.close();
              	}
              
            if(secim=='e'||secim=='E'){
   			   	var=true;
  		 	  	}
        	}	
             else{
                ofstream yedek_temasli_dosya("Yedek_temasli.dat",ios::app|ios::binary);
                     
                yedek_temasli_dosya.write((char*)&temasli, sizeof(temasli));
                yedek_temasli_dosya.close();
            	}
    	}
    	
    dos.close();
    
    if(var){
        remove("veriler\\temasli_giris.dat");
        rename("Yedek_temasli.dat","veriler\\temasli_giris.dat");
        cout<<"\n Kayit Silindi"<<endl;
    }
    else{
        remove("Yedek_temasli.dat");
        cout<<"\n Kayit Bulunamadi"<<endl;                  
    }
}
void temasliListele(){
	
	Temasli temasli;
	
	ifstream dos("veriler\\temasli_giris.dat",ios::binary |ios::app);
		
	dos.seekg(0,ios::end);
	int kayitsayisi=dos.tellg()/sizeof(temasli);

	if(kayitsayisi>0){
     	for(int i=0;i<kayitsayisi;i++){
        	dos.seekg(i*sizeof(temasli));
			dos.read((char*)&temasli, sizeof(temasli));
     
        	cout<<endl;
        	cout<<"---------------------------"<<endl;
        	cout<<i+1<<".temaslinin Verileri";
        	cout<<"\nAdi: "<<temasli.isim;
        	cout<<"\nSoyadi: "<<temasli.soyisim;
        	cout<<"\nNO: "<<temasli.temasli_no;
        	cout<<"\nYas: "<<temasli.yas;
        	cout<<"\nGiris tarihi: " << temasli.girisGun << " "<<temasli.girisAy<<" "<<temasli.girisYil;
        	cout<<"\nSemptom(lar): " << temasli.semptom;
        	cout<<"\nCinsiyet: ";
        	if(temasli.cinsiyet=='e'||temasli.cinsiyet=='E') cout<<"Erkek";
        	if(temasli.cinsiyet=='k'||temasli.cinsiyet=='K') cout<<"Bayan"; 	
			cout << endl;			  
        	}
		}
        else cout << "Veri bulanamadý!!!!" << endl; 
}

// Hasta islemler
int hastaEkle(){
    char secim=' ';
	ofstream yazdir("veriler\\hasta_giris.dat",ios::binary|ios::app);
	if(!yazdir.is_open()){
		cout << "Dosya açma iþlemi baþarýsýz!!!";
		exit(0);
	}
	
	//hasta yapýsý oluþturma
	Hasta hasta;
	
	//hasta bilgilerini alma
	do{
	
		cout << "hastanin ismi: ";
		cin>>hasta.isim;
		cout << endl;
		
		cout  << "hastanin soyismi: ";
		cin >> hasta.soyisim;
		
		cout  << "hastanin numarasini giriniz: ";
		cin >> hasta.hasta_no;
		cout << endl;
		
		cout  << "hastanin yaþý: ";
		cin >> hasta.yas;
		cout << endl;		
		
		cout  << "hastanin cinsiyeti: ";
		cin >> hasta.cinsiyet;
		cout << endl;
		
		
		cout << "hastanin semptomu: ";
		cin>>hasta.semptom;
		cout << endl;				
		
		cout  << "hastanin girdiði gün: ";
		cin >> hasta.girisGun;
		cout << endl;		
		
		cout  << "hastanin girdiði ay: ";
		cin >> hasta.girisAy;
		cout << endl;			
		
		cout  << "hastanin girdiði yil: ";
		cin >> hasta.girisYil;
		cout << endl;
		
		yazdir.write((char*)&hasta, sizeof(hasta));
		cout << "devam mi[E/H]";
		secim=getch();
		cout << endl;
	}	
	while(secim=='E'||secim=='e');
		
	
	yazdir.close();

}
void hastaSil(){
	Hasta hasta;
	ifstream dos("veriler\\hasta_giris.dat",ios::binary |ios::app);
	char hasno[200];
    char secim= ' ';
    bool var=false;
		
	dos.seekg(0,ios::end);

	int kayitsayisi=dos.tellg()/sizeof(hasta);
	
     cout<<"Kaydini sileceginiz hastanin numarasini giriniz : ";
     cin>>hasno;

     for(int i=0;i<kayitsayisi;i++)
     {
            dos.seekg(i*sizeof(hasta));
			dos.read((char*)&hasta, sizeof(hasta));
			
     if(strcmp(hasta.hasta_no,hasno)==0)
       {
                cout<<endl;
                cout<<"Hastanin";
                cout<<"\nAdi: "<<hasta.isim;
                cout<<"\nSoyadi: "<<hasta.soyisim;
                cout<<"\nNO: "<<hasta.hasta_no;
                cout<<"\nYas: "<<hasta.yas;
                cout<<"\nGiris tarihi: " << hasta.girisGun << " "<<hasta.girisAy<<" "<<hasta.girisYil;
                cout<<"\nSemptom(lar): " << hasta.semptom;
                cout<<"\nCinsiyet: ";
                if(hasta.cinsiyet=='e'||hasta.cinsiyet=='E')
                cout<<"Erkek";
                if(hasta.cinsiyet=='k'||hasta.cinsiyet=='K')
                cout<<"Bayan";
                
         	 				  
                cout<<"\n\nSilmek Istediginiz Kayit Bu Mu? [E/H] : ";
                 secim=getche();
            if(secim == 'H' || secim == 'h'){      
			   ofstream yedek_hasta_dosya("Yedek_hasta.dat",ios::app|ios::binary);
                        
                yedek_hasta_dosya.write((char*)&hasta, sizeof(hasta));
                yedek_hasta_dosya.close();
              }
            if(secim=='e'||secim=='E'){
   			   	var=true;
  		 	  }
        }
             else{
			    
                ofstream yedek_hasta_dosya("Yedek_hasta.dat",ios::app|ios::binary);
                     
                yedek_hasta_dosya.write((char*)&hasta, sizeof(hasta));
                yedek_hasta_dosya.close();
             }
     }
    dos.close();
    if(var)
    {
               remove("veriler\\hasta_giris.dat");
               rename("Yedek_hasta.dat","veriler\\hasta_giris.dat");
               cout<<"\n Kayit Silindi"<<endl;
    }
    else
    {
               remove("Yedek_hasta.dat");
               cout<<"\n Kayit Bulunamadi"<<endl;                  
    }
	
	
}
void hastaListele(){
	Hasta hasta;
	ifstream dos("veriler\\hasta_giris.dat",ios::binary |ios::app);
		
	dos.seekg(0,ios::end);

	int kayitsayisi=dos.tellg()/sizeof(hasta);


    for(int i=0;i<kayitsayisi;i++){
        dos.seekg(i*sizeof(hasta));
		dos.read((char*)&hasta, sizeof(hasta));
			
        cout<<endl;
        cout<<"---------------------------"<<endl;
        cout<<i+1<<".Hastanin Verileri";
        cout<<"\nAd: "<<hasta.isim;
        cout<<"\nSoyad: "<<hasta.soyisim;
        cout<<"\nNO: "<<hasta.hasta_no;
        cout<<"\nYas: "<<hasta.yas;
        cout<<"\nGiris tarihi: " << hasta.girisGun << " "<<hasta.girisAy<<" "<<hasta.girisYil;
        cout<<"\nSemptom: " << hasta.semptom;
        cout<<"\nCinsiyet: ";
        if(hasta.cinsiyet=='e'||hasta.cinsiyet=='E')
        cout<<"Erkek";
        if(hasta.cinsiyet=='k'||hasta.cinsiyet=='K')
        cout<<"Bayan";
        cout<<endl;
		}
    
}
