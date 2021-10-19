#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>

using namespace std;

char oyunMat[6][5];

void diziyiDoldur(); //dizinin tüm elemanlarýna 'T' atýyor.
void mayinAta(); //rastgele her satýra 1 mayin yani 'X' atýyor
char oyunaBasla(); // kullanýcadan deðer alýp ona göre oyunu kazanýp kaybettiðini belirliyor.

int main()
{
	setlocale(LC_ALL, "Turkish"); // türkçe karakter kullanýmý için.
	char kontrol = 'e';  
	
	while(kontrol == 'e' || kontrol == 'E') // oyunu kullanýcadan aldýðý deðere göre bitirip baþlatan döngü.
	{
		diziyiDoldur();
		mayinAta();
		kontrol = oyunaBasla(); // en sonunda fonksiyondan dönen deðeri deðiþkene atýp ona göre oyunu bitirip yada devam ettriyoruz.
		
	}

	return 0;
}

void diziyiDoldur()
{
	
	for(int i = 0; i<6; i++)
	{
		for(int j = 0; j<5; j++)
		{
			oyunMat[i][j] = 'T'; // dizinin tüm elemanlarýna 'T' harfini atýyor.
		}
	}
	
}
void mayinAta()
{
	srand(time(0));
	
	for(int i =0 ; i<6; i++)
	{
		int d = rand() % 5;
		oyunMat[i][d] = 'X'; // rand fonksiyonun belirlediði deðere göre her bir satýra bir mayýn yerleþtiriyor.
	}
}

char oyunaBasla()
{
	int satir= 0,sutun =0,sayac = 0;
	char reflesh;
	while(sayac != 6) // 6 satir olduðu için 6 defa çalýþacak döngü.
	{
		cout<<"1 ile 5 arasýnda bir sayý giriniz: ";
		cin>>sutun;
		
		while(sutun>5 || sutun<1) // eðer girilen deðer 1-5 arasýnda deðilse deðeri tekrar isteyen döngü.
		{
				cout<<"Yanlýþ sayý girdiniz lütfen 1 ile 5 arasýnda bir sayý giriniz: ";
				cin>>sutun;
		}
		sutun--;
		
		if(oyunMat[satir][sutun] != 'X') // seçtiðimiz elemanda mayýn olup olmadýðýný kontrol eden yapý.
		{
			oyunMat[satir][sutun] = 'O'; // geçtiðimiz yerelere 'O' atýyoruz.
			satir += 2;  // dizilerde indis 0 ile baþladýðý için satira 2 ekliyoruz.
			
			cout<<satir <<". satýra geçtiniz."<<endl;
			satir--; // yukarda 2 eklediðimiz deðeri yazdýrdýktan sonra tekrar 1 azaltýyoruz
			sayac++; // bir sonraki satýra geçiyoruz
			
			if(sayac == 6) // eðer son satýra geldiysek oyunu kazandýðýný belirten yapý.
			{
				cout<<"Tebrikler Kazandýnýz!"<<endl;
				for(int i = 0; i<6; i++)
				{
					for(int j =0; j<5; j++)
					{
						cout<<oyunMat[i][j]<<"  "; // matrisi ekrana yazan döndü.
					}
					cout<<endl;
				}
				cout<<"Yeniden oynamak ister misiniz? (Evet için e/E, Hayýr için h/H giriniz): ";
				cin>>reflesh;
				return reflesh; // kullanýcýnýn girdiði deðeri main fonksiyonuna ileterek oyunun bitirip yada devam etmesini saðlayan deðiþken.
			}
			
		}
		else // eðer seçtiðimiz deðerde mayýn varsa oyunu kaybettiðini belirten yapý.
		{
			cout<<"Mayýn Patladý. Üzgünüm Maalesef Kaybettiniz!"<<endl;

				for(int i = 0; i<6; i++)
				{
					for(int j =0; j<5; j++)
					{
						cout<<oyunMat[i][j]<<"  "; // matrisi ekrana yazan döngü.
					}
					cout<<endl;
				}
				cout<<"Yeniden oynamak ister misiniz? (Evet için e/E, Hayýr için h/H giriniz): ";
				cin>>reflesh;
				return reflesh; // kullanýcýnýn girdiði deðeri main fonksiyonuna ileterek oyunun bitirip yada devam etmesini saðlayan deðiþken.
		}
	}
}


