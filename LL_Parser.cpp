//ALBERTO ROCHA PART TWO

#include <iostream>
#include <vector>
#include <string>

using namespace std;


string lookupTable(char row , char col ){
	string table[6][10];
	char terminals[10]= {'a','b','+','-','*','/','(',')','$','='};
	char states[6]= {'S','E', 'Q','T','R','F'};
	int rowIndex = -1 ;
	int r = 0;
	int c = 0;
	int colIndex =-1;


	do {
		if(row == states[r]){

			rowIndex = r;
			r = 6;

		}
		else {

			r++;

		}
	} while (r < 6);

	do {
		if(col == terminals[c]){

			colIndex = c;
			c = 10;
		}
		else {

			c++;
		}
	} while (c < 10);




		table[0][0]= "a=E";
		table[0][9]= "|";
		table[1][0]= "TQ";
		table[1][1]= "TQ";
		table[1][6]= "TQ";
		table[2][2]= "+TQ";
		table[2][3]="-TQ";
		table[2][7]= "|";
		table[2][8]= "|";
		table[3][0]= "FR";
		table[3][1]= "FR";
		table[3][6]= "FR";
		table[4][2]= "|";
		table[4][3]= "|";
		table[4][4]= "*FR";
		table[4][5]= "/FR";
		table[4][7]="|";
		table[4][8]="|";
		table[5][0]="a";
		table[5][1]="b";
		table[5][6]="(E)";


if (rowIndex == -1 || colIndex == -1) {
	return"";
}
else{
return table[rowIndex][colIndex];
}
}

int main(int argc, char *argv[]) {

string userInput;
char pair[2];
int pos = 2;
char readd ;
string result = "Reject";
string  temp;
vector<char> stack;


cout<< "Enter your string";
cin >> userInput;
stack.push_back('$');
stack.push_back('E');

if(userInput[0]!='a' || userInput[1]!='='){
	goto exit; 
}

do {
	if(stack.back() == readd){
		pos++ ;
		stack.pop_back();
        cout << "MATCH" << endl;

        if(readd == '$'){
            result = "ACCEPTED";
            goto exit;
        }

	}

	    for(char & a : stack){

	    cout << a ;
	}

	cout<<  endl;
		pair[0]= stack.back();
		stack.pop_back();
		readd = userInput[pos];
		pair[1]= userInput[pos];
		
		
		if(pair[0] == readd){
				pos++ ;
				stack.pop_back();
		        cout << "MATCH" << endl;
			pair[0]= stack.back();
			}



		temp = lookupTable(pair[0], pair[1]);
		if(temp == ""){
		    goto exit;
		}


		for(int i = temp.size()-1 ; i >= 0 ; i--){
			if (temp[i] != '|' ){

				stack.push_back(temp[i]);
			}

		}


} while (userInput.size() > pos);

exit:
    cout << result;

}