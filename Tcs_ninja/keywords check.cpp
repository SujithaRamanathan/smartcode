#include<iostream>
#include<string.h>  // we r using strcmp 
using namespace std;

int main() {
	// 16 given words,10 is the max size of each word
	
      char keywords[16][10] ={"break","case","continue","default","defer",
                                              "else","for","func","goto","if","map","range","return","struct","type","var"};

	char input[10];
	cin >> input;
	int flag = 0;
	
	for(int i=0;i<16;i++) {
	if(strcmp(input,keywords[i]) == 0)
	{
		flag = 1;
		break;
	}
            }

	if(flag == 1)
	cout << input << "is a keyword";

	if(flag == 0)
	cout << input << "is not a keyword";

return 0;
}