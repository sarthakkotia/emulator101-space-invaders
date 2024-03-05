#include<iostream>
using namespace std;
int main(){
    FILE *f = fopen("space-invaders.rom","rb");
    if(f==NULL){
        return -1;
    }
    //fseek() is used to move the file pointer associated with a given file to a specific position.
    fseek(f,0L,SEEK_END);
    //ftell() in C is used to find out the position of the file pointer in the file with respect to starting of the file.
    int fsize = ftell(f);
    unsigned char* buffer = new unsigned char[fsize];
    fread(buffer,fsize,1,f);
    unsigned char*code=&buffer[1];
    if(*code==0x00){
        cout<<"NOP"<<endl;
    }
}