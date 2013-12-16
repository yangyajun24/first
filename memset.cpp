#include <iostream>
using namespace std;

int max_num_str(char* pstr, char* output)
{
	if ( *pstr == '\0')
	{
		*output = '\0';
		return 0;
	}

	char* p_first = pstr;
	char* p_last = pstr;
	int num = 0;

	while(*p_first != '\0')
	{
		if (*p_first>='0' && *p_first<='9') break;
		++p_first;
	}
	if (*p_first == '\0') 
	{
		*output = '\0';
		return 0;
	}

	p_last = p_first+1;
	while(*p_last != '\0')
	{
		if (*p_last<'0' || *p_last>'9')
		{
			--p_last;// revert
			break;
		}
		++p_last;
	}

	int x = p_last-p_first+1;
	int y = max_num_str(p_last+1, output);
	if (x < y)
		return y;
	
	int i= 0;
	for(;p_first<=p_last;++p_first)
		output[i++]=*p_first;
	output[i] = '\0';
	return x;	
}

int main(int argc, char* argv[])
{
	char* psrc = "aaa123wdfa12345623gff";
	char pdst[100];
	int x = max_num_str(psrc, pdst);
	cout<<x<<endl;
	cout<<pdst<<endl;
	return 0;
}