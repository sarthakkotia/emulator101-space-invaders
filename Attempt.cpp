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
            cout<<"LXI B,#"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=3;
            break;
        case 0x02:
            cout<<"STAX B"<<endl;
            break;
        case 0x03:
            cout<<"INX B"<<endl;
            break;
        case 0x04:
            cout<<"INR B"<<endl;
            break;
        case 0x05:
            cout<<"DCR B"<<endl;
            break;
        case 0x06:
            cout<<"MVI B,#"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0x07:
            cout<<"RLC"<<endl;
            break;
        case 0x09:
            cout<<"DAD B"<<endl;
            break;
        case 0x0a:
            cout<<"LDAX B"<<endl;
            break;
        case 0x0b:
            cout<<"DCX B"<<endl;
            break;
        case 0x0c:
            cout<<"INR C"<<endl;
            break;
        case 0x0d:
            cout<<"DCR C"<<endl;
            break;
        case 0x0e:
            cout<<"MVI D,#"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0x0f:
            cout<<"RRC"<<endl;
            break;
        case 0x17:
            cout<<"RAL"<<endl;
            // A = A << 1; bit 0 = prev CY; CY = prev bit 7
            break;
        case 0x21:
            cout<<"	LXI H,#"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0x32:
            cout<<"STA #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            // (adr) <- A
            opbytes=3;
            break;
        case 0x35:
            cout<<"DCR M";
            break;
            // 	Z, S, P, AC	(HL) <- (HL)-1
        case 0x3e:
            cout<<"MVI A,#"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0x72:
            cout<<"MOV M,D"<<endl;
            // (HL) <- D
            break;
        case 0x80:
            cout<<"ADD B"<<endl;
            // Z, S, P, CY, AC	A <- A + B
            break;
        case 0x8c:
            cout<<"ADC H"<<endl;
            // 	A <- A + H + CY
            break;
        case 0xc0:
            cout<<"RNZ"<<endl;
            // if NZ, RET
            break;
        case 0xc3:
            cout<<"JMP #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=3;
            break;
        case 0xc5:
            cout<<"PUSH B"<<endl;
            // (sp-2)<-C; (sp-1)<-B; sp <- sp - 2
            break;
        case 0xcd:
            cout<<"CALL #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=3;
            break;
        case 0xd5:
            cout<<"PUSH D"<<endl;
            // (sp-2)<-E; (sp-1)<-D; sp <- sp - 2
            break;
        case 0xdb:
            cout<<"IN #"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0xe5:
             cout<<"PUSH H"<<endl;
            //  (sp-2)<-L; (sp-1)<-H; sp <- sp - 2
            break;
        case 0xf5:
            cout<<"PUSH PSW"<<endl;
            // (sp-2)<-flags; (sp-1)<-A; sp <- sp - 2
            break;
        default:
            cout<<"-"<<endl;
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