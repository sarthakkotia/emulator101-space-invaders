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
        case 0x11:
            cout<<"LXI D,#"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=3;
            break;
        case 0x12:
            cout<<"STAX D"<<endl;
            break;
        case 0x13:
            cout<<"INX D"<<endl;
            break;
        case 0x14:
            cout<<"INR D"<<endl;
            break;
        case 0x15:
            cout<<"DCR D"<<endl;
            break;
        case 0x16:
            cout<<"MVI D,#"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0x17:
            cout<<"RAL"<<endl;
            break;
        case 0x19:
            cout<<"DAD D"<<endl;
            break;
        case 0x1a:
            cout<<"LDAX D"<<endl;
            break;
        case 0x1b:
            cout<<"DCX D"<<endl;
            break;
        case 0x1c:
            cout<<"INR E"<<endl;
            break;
        case 0x1d:
            cout<<"DCR E"<<endl;
            break;
        case 0x1e:
            cout<<"MVI E,#"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0x1f:
            cout<<"RAR"<<endl;
            break;
        
        case 0x20:
            break;
        case 0x21:
            cout<<"LXI H,#"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0x22:
            cout<<"SHLD #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0x23:
            break;
        case 0x24:
            break;
        case 0x25:
            break;
        case 0x26:
            cout<<"MVI H,#"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0x27:
            break;
        case 0x29:
            break;
        case 0x2a:
            cout<<"LHLD #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0x2b:
            break;
        case 0x2c:
            break;
        case 0x2d:
            break;
        case 0x2e:
            cout<<"MVI L,#"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0x2f:
            break;
        
        case 0x31:
            cout<<"LXI SP,#"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0x32:
            cout<<"STA #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=3;
            break;
        case 0x33:
            break;
        case 0x34:
            break;
        case 0x35:
            cout<<"DCR M";
            break;
        case 0x36:
            cout<<"MVI M,#"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0x37:
            break;
        case 0x39:
            break;
        case 0x3a:
            cout<<"LDA #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0x3b:
            break;
        case 0x3c:
            break;
        case 0x3d:
            break;
        case 0x3e:
            cout<<"MVI A,#"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0x3f:
            break;
        
        case 0x40:
            break;
        case 0x41:
            break;
        case 0x42:
            break;
        case 0x43:
            break;
        case 0x44:
            break;
        case 0x45:
            break;
        case 0x46:
            break;
        case 0x47:
            break;
        case 0x48:
            break;
        case 0x49:
            break;
        case 0x4a:
            break;
        case 0x4b:
            break;
        case 0x4c:
            break;
        case 0x4d:
            break;
        case 0x4e:
            break;
        case 0x4f:
            break;
        
        case 0x50:
            break;
        case 0x51:
            break;
        case 0x52:
            break;
        case 0x53:
            break;
        case 0x54:
            break;
        case 0x55:
            break;
        case 0x56:
            break;
        case 0x57:
            break;
        case 0x58:
            break;
        case 0x59:
            break;
        case 0x5a:
            break;
        case 0x5b:
            break;
        case 0x5c:
            break;
        case 0x5d:
            break;
        case 0x5e:
            break;
        case 0x5f:
            break;
        
        case 0x60:
            break;
        case 0x61:
            break;
        case 0x62:
            break;
        case 0x63:
            break;
        case 0x64:
            break;
        case 0x65:
            break;
        case 0x66:
            break;
        case 0x67:
            break;
        case 0x68:
            break;
        case 0x69:
            break;
        case 0x6a:
            break;
        case 0x6b:
            break;
        case 0x6c:
            break;
        case 0x6d:
            break;
        case 0x6e:
            break;
        case 0x6f:
            break;
        
        case 0x70:
            break;
        case 0x71:
            break;
        case 0x72:
            cout<<"MOV M,D"<<endl;
            break;
        case 0x73:
            break;
        case 0x74:
            break;
        case 0x75:
            break;
        case 0x76:
            break;
        case 0x77:
            break;
        case 0x78:
            break;
        case 0x79:
            break;
        case 0x7a:
            break;
        case 0x7b:
            break;
        case 0x7c:
            break;
        case 0x7d:
            break;
        case 0x7e:
            break;
        case 0x7f:
            break;
        
        case 0x80:
            cout<<"ADD B"<<endl;
            break;
        case 0x81:
            break;
        case 0x82:
            break;
        case 0x83:
            break;
        case 0x84:
            break;
        case 0x85:
            break;
        case 0x86:
            break;
        case 0x87:
            break;
        case 0x88:
            break;
        case 0x89:
            break;
        case 0x8a:
            break;
        case 0x8b:
            break;
        case 0x8c:
            cout<<"ADC H"<<endl;
            break;
        case 0x8d:
            break;
        case 0x8e:
            break;
        case 0x8f:
            break;
        
        case 0x90:
            break;
        case 0x91:
            break;
        case 0x92:
            break;
        case 0x93:
            break;
        case 0x94:
            break;
        case 0x95:
            break;
        case 0x96:
            break;
        case 0x97:
            break;
        case 0x98:
            break;
        case 0x99:
            break;
        case 0x9a:
            break;
        case 0x9b:
            break;
        case 0x9c:
            break;
        case 0x9d:
            break;
        case 0x9e:
            break;
        case 0x9f:
            break;
        case 0xa0:
            break;
        
        case 0xa1:
            break;
        case 0xa2:
            break;
        case 0xa3:
            break;
        case 0xa4:
            break;
        case 0xa5:
            break;
        case 0xa6:
            break;
        case 0xa7:
            break;
        case 0xa8:
            break;
        case 0xa9:
            break;
        case 0xaa:
            break;
        case 0xab:
            break;
        case 0xac:
            break;
        case 0xad:
            break;
        case 0xae:
            break;
        case 0xaf:
            break;
        
        case 0xb0:
            break;
        case 0xb1:
            break;
        case 0xb2:
            break;
        case 0xb3:
            break;
        case 0xb4:
            break;
        case 0xb5:
            break;
        case 0xb6:
            break;
        case 0xb7:
            break;
        case 0xb8:
            break;
        case 0xb9:
            break;
        case 0xba:
            break;
        case 0xbb:
            break;
        case 0xbc:
            break;
        case 0xbd:
            break;
        case 0xbe:
            break;
        case 0xbf:
            break;
        
        case 0xc0:
            cout<<"RNZ"<<endl;
            break;
        case 0xc1:
            break;
        case 0xc2:
            cout<<"JNZ #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xc3:
            cout<<"JMP #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=3;
            break;
        case 0xc4:
            cout<<"CNZ #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xc5:
            cout<<"PUSH B"<<endl;
            break;
        case 0xc6:
            cout<<"ADI #"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0xc7:
            break;
        case 0xc8:
            break;
        case 0xc9:
            break;
        case 0xca:
            cout<<"JZ #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xcc:
            cout<<"CZ #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xcd:
            cout<<"CALL #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=3;
            break;
        case 0xce:
            cout<<"ACI #"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0xcf:
            break;
        
        case 0xd0:
            break;
        case 0xd1:
            break;
        case 0xd2:
            cout<<"JNC #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xd3:
            cout<<"OUT #"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0xd4:
            cout<<"CNC #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xd5:
            cout<<"PUSH D"<<endl;
            break;
        case 0xd6:
            cout<<"SUI #"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0xd7:
            break;
        case 0xd8:
            break;
        case 0xda:
            cout<<"JC #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xdb:
            cout<<"IN #"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0xdc:
            cout<<"CC #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xde:
            cout<<"SBI #"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0xdf:
            break;
        
        case 0xe0:
            break;
        case 0xe1:
            break;
        case 0xe2:
            cout<<"JPO #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xe3:
            break;
        case 0xe4:
            cout<<"CPO #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xe5:
             cout<<"PUSH H"<<endl;
            break;
        case 0xe6:
            cout<<"ANI #"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0xe7:
            break;
        case 0xe8:
            break;
        case 0xe9:
            break;
        case 0xea:
            cout<<"JPE #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xeb:
            break;
        case 0xec:
            cout<<"CPE #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xee:
            cout<<"XRI #"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0xef:
            break;
        
        case 0xf0:
            break;
        case 0xf1:
            break;
        case 0xf2:
            cout<<"JP #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xf3:
            break;
        case 0xf4:
            cout<<"CP #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xf5:
            cout<<"PUSH PSW"<<endl;
            break;
        case 0xf6:
            cout<<"ORI #"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0xf7:
            break;
        case 0xf8:
            break;
        case 0xf9:
            break;
        case 0xfa:
            cout<<"JM #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xfb:
            break;
        case 0xfc:
            cout<<"CM #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xfe:
            cout<<"CPI #"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0xff:
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