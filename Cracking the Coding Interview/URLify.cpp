#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <sstream>
#include <algorithm>
#include <locale>
using namespace std;


const int MAX = 1000;

int replaceSpaces(char str[],int trueLength){

    int space_count = 0, i; 
    for(int i=0;i<trueLength;i++)
        if(str[i] == ' ')space_count++;
    
    if(trueLength < strlen(str)) str[trueLength] = '\0';
    int index = trueLength + space_count * 2 ;

    if(index > MAX)return -1;

    for(int i= trueLength -1 ; i>=0; i--){
        if(str[i] == ' '){
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index  - 3] = '%';
            index -= 3;
        }else {
            str[index - 1] = str[i];
            index--;
        }
    }

    return index;
}

int main(){

    char str[MAX] = "Mr John Smith   ";
    int length = 13;
    int new_length = replaceSpaces(str,length); 

    for(int i= new_length;i<strlen(str);i++)cout<<str[i];

    return 0;
}
