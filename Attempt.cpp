#include<iostream>
#include <fstream>
#include<vector>
using namespace std;

int main(){
    string s= "space-invaders.rom";
    ifstream file;
    file.open(s,fstream::binary|fstream::in);
    if(file.is_open()==false){
        return -1;
    }else{
        cout<<"file is opened now! first task done";
    }


    // file.seekg(0,ios::end);
    // vector<char>buffer(file.tellg());
    // streamsize size = file.tellg();
    // unsigned char* buffer=new unsigned char[size];
    // cout<<file.tellg()<<endl;
    // file.seekg(0,ios::beg);

    // ifstream file;
    // file.open("space-invaders.rom");
    // while(getline(file,myText)){
    //     cout<<myText<<endl;
    // }
    // file.close();
// // Read from the text file
// ifstream MyReadFile("space-invaders.rom");
// // Use a while loop together with the getline() function to read the file line by line
// while (getline (MyReadFile, myText)) {
//   // Output the text from the file
//   cout << myText;
// }

// // Close the file
// MyReadFile.close();
    return 0;
}