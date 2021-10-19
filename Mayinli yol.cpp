#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>

using namespace std;

char oyunMat[6][5];

void diziyiDoldur(); //dizinin t�m elemanlar�na 'T' at�yor.
void mayinAta(); //rastgele her sat�ra 1 mayin yani 'X' at�yor
char oyunaBasla(); // kullan�cadan de�er al�p ona g�re oyunu kazan�p kaybetti�ini belirliyor.

int main()
{
	setlocale(LC_ALL, "Turkish"); // t�rk�e karakter kullan�m� i�in.
	char kontrol = 'e';  
	
	while(kontrol == 'e' || kontrol == 'E') // oyunu kullan�cadan ald��� de�ere g�re bitirip ba�latan d�ng�.
	{
		diziyiDoldur();
		mayinAta();
		kontrol = oyunaBasla(); // en sonunda fonksiyondan d�nen de�eri de�i�kene at�p ona g�re oyunu bitirip yada devam ettriyoruz.
		
	}

	return 0;
}

void diziyiDoldur()
{
	
	for(int i = 0; i<6; i++)
	{
		for(int j = 0; j<5; j++)
		{
			oyunMat[i][j] = 'T'; // dizinin t�m elemanlar�na 'T' harfini at�yor.
		}
	}
	
}
void mayinAta()
{
	srand(time(0));
	
	for(int i =0 ; i<6; i++)
	{
		int d = rand() % 5;
		oyunMat[i][d] = 'X'; // rand fonksiyonun belirledi�i de�ere g�re her bir sat�ra bir may�n yerle�tiriyor.
	}
}

char oyunaBasla()
{
	int satir= 0,sutun =0,sayac = 0;
	char reflesh;
	while(sayac != 6) // 6 satir oldu�u i�in 6 defa �al��acak d�ng�.
	{
		cout<<"1 ile 5 aras�nda bir say� giriniz: ";
		cin>>sutun;
		
		while(sutun>5 || sutun<1) // e�er girilen de�er 1-5 aras�nda de�ilse de�eri tekrar isteyen d�ng�.
		{
				cout<<"Yanl�� say� girdiniz l�tfen 1 ile 5 aras�nda bir say� giriniz: ";
				cin>>sutun;
		}
		sutun--;
		
		if(oyunMat[satir][sutun] != 'X') // se�ti�imiz elemanda may�n olup olmad���n� kontrol eden yap�.
		{
			oyunMat[satir][sutun] = 'O'; // ge�ti�imiz yerelere 'O' at�yoruz.
			satir += 2;  // dizilerde indis 0 ile ba�lad��� i�in satira 2 ekliyoruz.
			
			cout<<satir <<". sat�ra ge�tiniz."<<endl;
			satir--; // yukarda 2 ekledi�imiz de�eri yazd�rd�ktan sonra tekrar 1 azalt�yoruz
			sayac++; // bir sonraki sat�ra ge�iyoruz
			
			if(sayac == 6) // e�er son sat�ra geldiysek oyunu kazand���n� belirten yap�.
			{
				cout<<"Tebrikler Kazand�n�z!"<<endl;
				for(int i = 0; i<6; i++)
				{
					for(int j =0; j<5; j++)
					{
						cout<<oyunMat[i][j]<<"  "; // matrisi ekrana yazan d�nd�.
					}
					cout<<endl;
				}
				cout<<"Yeniden oynamak ister misiniz? (Evet i�in e/E, Hay�r i�in h/H giriniz): ";
				cin>>reflesh;
				return reflesh; // kullan�c�n�n girdi�i de�eri main fonksiyonuna ileterek oyunun bitirip yada devam etmesini sa�layan de�i�ken.
			}
			
		}
		else // e�er se�ti�imiz de�erde may�n varsa oyunu kaybetti�ini belirten yap�.
		{
			cout<<"May�n Patlad�. �zg�n�m Maalesef Kaybettiniz!"<<endl;

				for(int i = 0; i<6; i++)
				{
					for(int j =0; j<5; j++)
					{
						cout<<oyunMat[i][j]<<"  "; // matrisi ekrana yazan d�ng�.
					}
					cout<<endl;
				}
				cout<<"Yeniden oynamak ister misiniz? (Evet i�in e/E, Hay�r i�in h/H giriniz): ";
				cin>>reflesh;
				return reflesh; // kullan�c�n�n girdi�i de�eri main fonksiyonuna ileterek oyunun bitirip yada devam etmesini sa�layan de�i�ken.
		}
	}
}


