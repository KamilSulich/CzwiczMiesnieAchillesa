#include <iostream>
//#include <allegro.h> 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;


void czekaj(int milisekund) 
{ 
clock_t start = clock();
while(clock() < start+milisekund);
}

void przerwa (int czas,int nr,int serie)//czas podawany w sekundach,numer serii,ilo�� serii
{
	cout <<"\n\n Czas na przerw� :)\n";
	for (int i=1;i<czas;i++)
	{
		_sleep(1000);
		cout<<czas-i<<" sek. do konca przerwy i jedziemy z "<<nr+1<<" seria. Jeszcze tylko "<<serie-nr<<" serii"<<endl;
		if(i>czas-7)
		{
			Beep(8000-100*i,100);//cz�stotliwo��,czas
		}
	}
	cout <<"\nKoniec przerwy. Jedziemy dalej\n";
}

void seria(int pow,int dlu,int nr,int serie)//ilosc powtorzen,czas trwania powtorzenia,numer serii,ilo�� serii
{
	for (int i=1;i<pow+1;i++)
	{
		cout <<"\nseria nr "<<nr<<"/"<<serie<< " powt�rzenie nr "<<i<<"/"<<pow<<
			" #### pozosta�o "<<serie-nr<<" ser. i "<<pow-i+1<<" powt. do ko�ca serii";
					for (int j=0;j<serie+1;j++)//odliczanie sekund do ko�ca powt�rzenia
					{
					_sleep(1000);
						cout <<"\n"<<dlu-j;
					}
					_sleep(1000);
	}
}

int main(void)
{
	setlocale(LC_ALL, "");//ustawienie polskich znak�w
	//poni�sza linijka wymaga biblioteki allegro
	// SAMPLE * dzwiek = load_sample( "dzwiek.wav" );
	float serie = 4;//ilo�� serii
	int pauza=60;//czas trwania przerwy w sekundach
	float powt=15;//ilosc powtorzen
	int tpowt=5;//czas trwania powt�rzenia
	int z=3;
	int *tablicaserii = (int*) malloc (sizeof (int) * serie);
	while (z==3)
	{
				cout<< "przysiady czy stanie na palcach? \n"<<
					"a-przysiady \n"<<
					"s-stanie na palcach"<<
					"\nq-koniec "<<
					"\nZalecenia do stania na palcach: 4 serie po 15 powt�rze� przez 5 sekund i potem minuta przerwy\n "
					<< "zalecenia do przysiad�w:  4 serie po 15 powt�rze� i minuta przerwy\n";

				char wybor = getchar ();
					switch (wybor)
					{
					case 's'://stanie na palcach
						for (int i = 1;i< serie+1;i++)
						{
							cout<<"\nzaczynamy serie nr "<<i<<"########################################"<<endl;
						seria(powt,tpowt,i,serie);//ilosc powtorzen,czas trwania powtorzenia,numer serii,ilo�� serii
						przerwa (pauza,i,serie);//czas podawany w sekundach,numer serii,ilo�� serii;
						}
						break;
					case 'a'://przysiady
						{
							puts("zr�b pierwsz� seri� a nast�pnie wcisnij klawisz by zrobi� przerw�");

								for(int i = 0;i<serie-1;i++)
								{
									int n;
									cin>>n;
									przerwa (pauza,i+1,serie);
									time_t start_1 = time (NULL); // czas pocz�tkowy
									cout <<endl<< "zaczynamy serie nr "<<i+2<<".Po jej sko�czeniu wci�nij dowolny klawisz aby kontynuowa�"<<endl;
									cin>>n;
									system("pause");
									time_t stop_1 = time (NULL); // czas ko�cowy
									float tser=difftime (stop_1, start_1);//czas serii
									cout <<endl<< "zrobienie serii nr "<<i+2<<" zaje�o Ci "<<tser<<" sekund. Jeden przysiad zaj�� Ci �rednio "
										<<tser/powt<<" sekund"<<endl;
									tablicaserii[i]=tser;
								}

								for(int i = 0;i<serie-1;i++)//wypisanie czas�w poszczeg�lnych serii
								{
									cout <<endl<< "zrobienie "<<i+1<<" serii zaje�o Ci "<<tablicaserii[i]<<
										" sekund, srednio "<<tablicaserii[i]/powt<<" sekund na przysiad"<<endl;

								}break;

						}
					case 'q':
						{
							z=0;
							break;
						}

					default:
						{
						puts("wcisnij inny klawisz");
						}

						
					}
					break;
		}
system ("pause");
}