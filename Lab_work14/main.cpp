#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	if(!fin || !fout)
	{
		puts("Error. Can't create filestreams");
		return 0;
	}
	fout<<"#1:\n";
	string first, second;
	while(!fin.eof())
	{
		first=second;
		fin>>second;
		if(first.back()==second.front())
			fout<<first<<' '<<second<<'\n';
	}
	fout<<"\n*****\n\n#2:\n";
	fin.seekg(0, ios::beg);
	string input;
	for(int max_num_count, current_num_count=0; !fin.eof(); max_num_count=0, current_num_count=0)
	{
		static int line_count=0;
		getline(fin, input);
		for(auto it : input)
		{
			static char memory=' ';
			if(isdigit(it))
			{
				if(it!=memory)
					current_num_count=0;
				current_num_count++;
			}
			else
				current_num_count=0;
			memory=it;
			if(max_num_count<=current_num_count)
				max_num_count=current_num_count;
		}
		fout<<"Line "<<++line_count<<": "<<max_num_count<<'\n';
	}
	fout<<"\n*****\n\n#3:\n";
	fin.seekg(0, ios::beg);
	//
	//
	fin.close();
	fout.close();
	return 0;
}
