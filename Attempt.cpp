#include<iostream>
#include <fstream>
#include<vector>
using namespace std;

int fx(vector<uint8_t>&buffer,int pc){
    int opbytes=1;
    uint8_t code= buffer[pc];
    switch(code){
        case 0x00:
            cout<<"NOP"<<endl;
            break;
        case 0x01:
            cout<<"LXI B,#"<<hex<<buffer[pc+2]<<hex<<buffer[pc+1]<<endl;
            opbytes=3;
            break;
        case 0xc3:
            cout<<"JMP #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=3;
            break;
    }
    int var = buffer[pc];
    // int code = 0xvar;
    cout<<"program counter right now:"<<pc<<endl;
    cout<<"byte read:"<<hex<<var<<endl;
        return opbytes;
}

int main(){
    string s= "space-invaders.rom";
    ifstream file;
    file.open(s,ios::binary|ios::in);
    if(file.is_open()==false){
        return -1;
    }else{
        cout<<"file is opened now! first task done"<<endl;
        // seek the file to it's end
        file.seekg(0,ios::end);
        // identify the file size by telling the seeking position
        int fsize = file.tellg();
        // reset the seek to be at the beginning
        file.seekg(0,ios::beg);
        vector<uint8_t>buffer(fsize,0);
        for(int i=0;i<fsize;i++){
            // read each character of file in integar and save it in buffer
            buffer[i] = (uint8_t)file.get();
        }
        file.close();
        int pc=0;
        while(pc<fsize){
            pc+=fx(buffer,pc);
        }
    }
    return 0;
}