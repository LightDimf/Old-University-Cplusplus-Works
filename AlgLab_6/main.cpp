#include <iostream>
#include <map>
#define ERROR_PROC_ cin.clear(); cin.ignore(1000, '\n'); puts("Error input"); continue;
#define LOOP_ERRPROC_(var) while(1){cin>>var; if(cin.good()) break;  ERROR_PROC_}
using namespace std;

class Graph
{
	public:
		Graph(int N)
		{
			NoV=N;
		}
		void SET_AdjMat(bool **AM)
		{
			AdjMat=AM;
		}
		void SET_Weight(int **AM)
		{
			Weight=AM;
			Weighted=true;
		}
		bool IsOriented()
		{
			for(size_t i=0; i<NoV; i++)
				for(size_t j=0; j<NoV; j++)
					if(AdjMat[i][j]!=AdjMat[j][i])
						return false;
			return true;
		}
		bool IsWeighted()
		{
			return Weighted;
		}
		int HowManyEdges()
		{
			int EdCount=0;
			for(size_t i=0; i<NoV; i++)
				for(size_t j=i; j<NoV; j++)
					if(AdjMat[i][j]==true)
						EdCount++;
			return EdCount;
		}
		bool HaveAnEdge(int y, int x)
		{
			if(AdjMat[y][x]==true)
				return true;
			if(AdjMat[x][y]==true)
				return true;
			return false;
		}
	private:
		int NoV; //Number of vertices
		bool **AdjMat; //Adjacency matrix
		int **Weight; //Matrix of weight
		bool Weighted=false;
};

template<typename T>
T** SetMatrix(int NoV)
{
	T **Matrix=new T*[NoV];
	putchar(' ');for(size_t i=0; i<NoV; i++) printf(" v%d",i+1);putchar('\n');
	for(size_t i=0; i<NoV; i++)
	{
		Matrix[i]=new T[NoV];
		printf("v%d ",i+1);
		for(size_t j=0; j<NoV; j++)
		{
			LOOP_ERRPROC_(Matrix[i][j])
		}
	}
	return Matrix;
}

int main()
{
	puts("Welcome to the ASD Lab #6\nEnter \"help\" to get information");
	printf("Enter num of vertices: ");
	int NoV; //Number of vertices
	LOOP_ERRPROC_(NoV)
	Graph GR(NoV);
	puts("Enter adjacency matrix:");
	GR.SET_AdjMat(SetMatrix<bool>(NoV));
 	 getchar();
	while(1)
	{
		static string input; //for input
		putchar('>');
		getline(cin, input, '\n');
		if(input=="help")
			puts("/Graph/\nFunctions:\n");///
		else if(input=="set AdjMat")
		{
			puts("Enter adjacency matrix:");
			GR.SET_AdjMat(SetMatrix<bool>(NoV));
		}
		else if(input=="set Weight")
		{
			puts("Enter matrix of weight:");
			GR.SET_Weight(SetMatrix<int>(NoV));
		}
		else if(input=="is oriented?")
			GR.IsOriented()? puts("Yes.") : puts("No.");
		else if(input=="how many edges?")
			printf("%d edges.\n", GR.HowManyEdges());
		else if(input=="have an edge")
		{
			 getchar();
			int y, x;
			cin>>y>>x;
			if(cin.bad())
			{ERROR_PROC_}
			GR.HaveAnEdge(y,x)? puts("Yes.") : puts("No.");
		}
		else if(input=="exit")
			return 0;
		else
		{ERROR_PROC_}
		
	}
}
