#include "iostream"
#include "cstdlib"
#include "ctime"
using namespace std;

short mas[5][5], maxn;

void inif(short i, short j)
{
	if(mas[i][j] > maxn)
			maxn=mas[i][j];
	cout<<mas[i][j]<<' ';
}

int main() 
{
	srand(time(NULL));
	cout<<"Massive:\n";
	for(short v=0; v<=10; v++)
	{
		maxn=0;
		cout<<"\n>Var "<<v<<":\n";
		for(short i=0; i<5; i++)
			for(short j=0; j<5; j++)
				{
					switch(v){
			    		case 0: 
							mas[i][j]=rand()%10;
							cout<<mas[i][j]<<' ';
							break;
						case 1:
							if(j>=i)
								inif(i,j);
							else
								cout<<"  ";
							break;
						case 2: 
							if(j<=i)
								inif(i,j);
							else
								cout<<"  ";
							break;
						case 3: 
							if(j>=i && (-j+4)>=i)
								inif(i,j);
							else
								cout<<"  ";
							break;
						case 4: 
							if(j<=i && (-j+4)<=i)
								inif(i,j);
							else
								cout<<"  ";
							break;
						case 5: 
							if((j<=i && (-j+4)<=i)||(j>=i && (-j+4)>=i))
								inif(i,j);
							else
								cout<<"  ";
							break;
						case 6: 
							if((j<=i && (-j+4)>=i)||((j>=i && (-j+4)<=i)))
								inif(i,j);
							else
								cout<<"  ";
							break;
						case 7: 
							if(j<=i && (-j+4)>=i)
								inif(i,j);
							else
								cout<<"  ";
							break;
						case 8: 
							if(j>=i && (-j+4)<=i)
								inif(i,j);
							else
								cout<<"  ";
							break;
						case 9: 
							if((-j+4)>=i)
								inif(i,j);
							else
								cout<<"  ";
							break;
						case 10:
							if((-j+4)<=i)
								inif(i,j);
							else
								cout<<"  ";
							break;}
					if(j==4)
						cout<<'\n';
				}
		if(v>0)
			cout<<"Max: "<<maxn<<'\n';
	}
	system("pause");
	return 0;
}
