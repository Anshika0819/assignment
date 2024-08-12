#include<iostream>
using namespace std;
int main(){
    //step1: input the type of array
    string type;
    cout<<"Enter type of array(int, char, float etc)";
    cin>>type;

    //step2: Define the size of each type
    int typesize;
    if(type=="int")typesize=sizeof(int);
    else if(type=="char")typesize=sizeof(char);
    else if(type=="float")typesize=sizeof(float);
    else{
        cout<<"Not valid"<<endl;
        return -1;
    }

    //step3: input the size of array (rows and columns)
    int rows, columns;
    cout<<"Enter number of rows: ";
    cin>>rows;
    cout<<"Enter number of columns: ";
    cin>>columns;

    //step4: input the memory arrangement(Row or column)
    string arrangement;
    cout<<"Enter the memory arrangement: ";
    cin>>arrangement;

    //step5: input the base address of the array
    int baseAddress;
    cout<<"Enter base address of the array: ";
    cin>>baseAddress;

    //step6: Input the indices (i, j) of the elements
    int i, j;
    cout<<"Enter the address of the element: ";
    cin>>i>>j;

    //step7: calculate the address based on arrangement
    int address;
    if(arrangement=="Row"){
        address=baseAddress+(i* columns + j)*typesize;
} else if(arrangement=="Column"){
    address=baseAddress+(j* rows + i)*typesize;
}else{
    cout<<"Invalid memory arrangement";
    return -1;
}
//output the computed address
cout << "The address of the element at (" << i << ", " << j << ") is: " << address << endl;


    return 0;
}