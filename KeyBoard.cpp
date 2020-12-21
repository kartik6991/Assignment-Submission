#include<windows.h>
/* windows.h is a Windows-specific header file for the C and C++ programming languages 
which contains declarations for all of the functions in the Windows API, 
all the common macros used by Windows programmers, 
and all the data types used by the various functions and subsystems.*/
#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

//Base class is Keyboard
class Keyboard{
    public:
    string string_1,string_2;

    int i;
    /* The integer variable is used to increment the index of 
    character array of key_press[i]*/

    char key_press[5000];
    /*For reading the inputs and 
    each consecutive single input stored in key_press[]*/

    void DisplayText(int passed_value){
       
        i=passed_value;

    while(true){
            if(GetAsyncKeyState(VK_CONTROL)&&GetAsyncKeyState(0x51)){
            //VK_CONTROL is the virtual code for control key when pressed

            //0x51 is a hexadecimal code for ASCII value of q when pressed    
            
            /* GetAsyncKeyState() is a function which 
            determines whether a key is up or down at the time the function is called, 
            and whether the key was pressed after a previous call to GetAsyncKeyState()*/
                break;
            }
    key_press[i]=getch();
    string_1=string_1+key_press[i];
    //character array of variable key_press[i] is converted into string 
    
    if((key_press[i])=='\r'){
        /* '\r' is a carriage return character and detects whether enter key is pressed 
        and when once enter key is pressed then the condition in if statement is true*/
        string_2=string_1;
        cout<<string_2;
        if(string_2!=""){
            cout<<endl;
        }
        string_1="";//clears the string after the string_1 is displayed
        i++;// increment the value of index in character array key_press[i]
    }
    }
}
};

//Using the concept of Single Inheritance
//Derived class is VirtualKeyboard
class VirtualKeyboard: public Keyboard{
    public:
    void CallingFunction(){
        int passing_value=0;
        /*The integer variable passing_value is used to 
        pass the value to the called function of DisplayText() in class Keyboard 
        from class VirtualKeyboard*/ 

        Keyboard k;//Creating an object of Keyboard
        
        k.DisplayText(passing_value);
        /*calling the called function of DisplayText() with argument integer variable
        in class Keyboard*/
    }
};

int main(){
    VirtualKeyboard v;//Creating object of VirtualKeyboard
    v.CallingFunction();//calling the called function in class VirtualKeyboard 
    return 0;
}

