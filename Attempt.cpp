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
        
        case 0x21:
            cout<<"LXI H,#"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0x22:
            cout<<"SHLD #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0x23:
            cout<<"INX H"<<endl;
            break;
        case 0x24:
            cout<<"INR H"<<endl;
            break;
        case 0x25:
            cout<<"DCR H"<<endl;
            break;
        case 0x26:
            cout<<"MVI H,#"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0x27:
            cout<<"DAA"<<endl;
            break;
        case 0x29:
            cout<<"DAD H"<<endl;
            break;
        case 0x2a:
            cout<<"LHLD #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0x2b:
            cout<<"DCX H"<<endl;
            break;
        case 0x2c:
            cout<<"INR L"<<endl;
            break;
        case 0x2d:
            cout<<"DCR L"<<endl;
            break;
        case 0x2e:
            cout<<"MVI L,#"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0x2f:
            cout<<"CMA"<<endl;
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
            cout<<"INX SP"<<endl;
            break;
        case 0x34:
            cout<<"INR M"<<endl;
            break;
        case 0x35:
            cout<<"DCR M";
            break;
        case 0x36:
            cout<<"MVI M,#"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0x37:
            cout<<"STC"<<endl;
            break;
        case 0x39:
            cout<<"DAD SP"<<endl;
            break;
        case 0x3a:
            cout<<"LDA #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0x3b:
            cout<<"DCX SP"<<endl;
            break;
        case 0x3c:
            cout<<"INR A"<<endl;
            break;
        case 0x3d:
            cout<<"DCR A"<<endl;
            break;
        case 0x3e:
            cout<<"MVI A,#"<<hex<<(int)buffer[pc+1]<<endl;
            opbytes=2;
            break;
        case 0x3f:
            cout<<"CMC"<<endl;
            break;
        
        case 0x40:
            cout<<"MOV B,B"<<endl;
            break;
        case 0x41:
            cout<<"MOV B,C"<<endl;
            break;
        case 0x42:
            cout<<"MOV B,D"<<endl;
            break;
        case 0x43:
            cout<<"MOV B,E"<<endl;
            break;
        case 0x44:
            cout<<"MOV B,H"<<endl;
            break;
        case 0x45:
            cout<<"MOV B,L"<<endl;
            break;
        case 0x46:
            cout<<"MOV B,M"<<endl;
            break;
        case 0x47:
            cout<<"MOV B,A"<<endl;
            break;
        case 0x48:
            cout<<"MOV C,B"<<endl;
            break;
        case 0x49:
            cout<<"MOV C,C"<<endl;
            break;
        case 0x4a:
            cout<<"MOV C,D"<<endl;
            break;
        case 0x4b:
            cout<<"MOV C,E"<<endl;
            break;
        case 0x4c:
            cout<<"MOV C,H"<<endl;
            break;
        case 0x4d:
            cout<<"MOV C,L"<<endl;
            break;
        case 0x4e:
            cout<<"MOV C,M"<<endl;
            break;
        case 0x4f:
            cout<<"MOV C,A"<<endl;
            break;
        
        case 0x50:
            cout<<"MOV D,B"<<endl;
            break;
        case 0x51:
            cout<<"MOV D,C"<<endl;
            break;
        case 0x52:
            cout<<"MOV D,D"<<endl;
            break;
        case 0x53:
            cout<<"MOV D,E"<<endl;
            break;
        case 0x54:
            cout<<"MOV D,H"<<endl;
            break;
        case 0x55:
            cout<<"MOV D,L"<<endl;
            break;
        case 0x56:
            cout<<"MOV D,M"<<endl;
            break;
        case 0x57:
            cout<<"MOV D,A"<<endl;
            break;
        case 0x58:
            cout<<"MOV E,B"<<endl;
            break;
        case 0x59:
            cout<<"MOV E,C"<<endl;
            break;
        case 0x5a:
            cout<<"MOV E,D"<<endl;
            break;
        case 0x5b:
            cout<<"MOV E,E"<<endl;
            break;
        case 0x5c:
            cout<<"MOV E,H"<<endl;
            break;
        case 0x5d:
            cout<<"MOV E,L"<<endl;
            break;
        case 0x5e:
            cout<<"MOV E,M"<<endl;
            break;
        case 0x5f:
            cout<<"MOV E,A"<<endl;
            break;
        
        case 0x60:
            cout<<"MOV H,B"<<endl;
            break;
        case 0x61:
            cout<<"MOV H,C"<<endl;
            break;
        case 0x62:
            cout<<"MOV H,D"<<endl;
            break;
        case 0x63:
            cout<<"MOV H,E"<<endl;
            break;
        case 0x64:
            cout<<"MOV H,H"<<endl;
            break;
        case 0x65:
            cout<<"MOV H,L"<<endl;
            break;
        case 0x66:
            cout<<"MOV H,M"<<endl;
            break;
        case 0x67:
            cout<<"MOV H,A"<<endl;
            break;
        case 0x68:
            cout<<"MOV L,B"<<endl;
            break;
        case 0x69:
            cout<<"MOV L,C"<<endl;
            break;
        case 0x6a:
            cout<<"MOV L,D"<<endl;
            break;
        case 0x6b:
            cout<<"MOV L,E"<<endl;
            break;
        case 0x6c:
            cout<<"MOV L,H"<<endl;
            break;
        case 0x6d:
            cout<<"MOV L,L"<<endl;
            break;
        case 0x6e:
            cout<<"MOV L,M"<<endl;
            break;
        case 0x6f:
            cout<<"MOV L,A"<<endl;
            break;
        
        case 0x70:
            cout<<"MOV M,B"<<endl;
            break;
        case 0x71:
            cout<<"MOV M,C"<<endl;
            break;
        case 0x72:
            cout<<"MOV M,D"<<endl;
            break;
        case 0x73:
            cout<<"MOV M,E"<<endl;
            break;
        case 0x74:
            cout<<"MOV M,H"<<endl;
            break;
        case 0x75:
            cout<<"MOV M,L"<<endl;
            break;
        case 0x76:
            cout<<"HLT"<<endl;
            break;
        case 0x77:
            cout<<"MOV M,A"<<endl;
            break;
        case 0x78:
            cout<<"MOV A,B"<<endl;
            break;
        case 0x79:
            cout<<"MOV A,C"<<endl;
            break;
        case 0x7a:
            cout<<"MOV A,D"<<endl;
            break;
        case 0x7b:
            cout<<"MOV A,E"<<endl;
            break;
        case 0x7c:
            cout<<"MOV A,H"<<endl;
            break;
        case 0x7d:
            cout<<"MOV A,L"<<endl;
            break;
        case 0x7e:
            cout<<"MOV A,M"<<endl;
            break;
        case 0x7f:
            cout<<"MOV A,A"<<endl;
            break;
        
        case 0x80:
            cout<<"ADD B"<<endl;
            break;
        case 0x81:
            cout<<"ADD C"<<endl;
            break;
        case 0x82:
            cout<<"ADD D"<<endl;
            break;
        case 0x83:
            cout<<"ADD E"<<endl;
            break;
        case 0x84:
            cout<<"ADD H"<<endl;
            break;
        case 0x85:
            cout<<"ADD L"<<endl;
            break;
        case 0x86:
            cout<<"ADD M"<<endl;
            break;
        case 0x87:
            cout<<"ADD A"<<endl;
            break;
        case 0x88:
            cout<<"ADC B"<<endl;
            break;
        case 0x89:
            cout<<"ADC C"<<endl;
            break;
        case 0x8a:
            cout<<"ADC D"<<endl;
            break;
        case 0x8b:
            cout<<"ADC E"<<endl;
            break;
        case 0x8c:
            cout<<"ADC H"<<endl;
            break;
        case 0x8d:
            cout<<"ADC L"<<endl;
            break;
        case 0x8e:
            cout<<"ADC M"<<endl;
            break;
        case 0x8f:
            cout<<"ADC A"<<endl;
            break;
        
        case 0x90:
            cout<<"SUB B"<<endl;
            break;
        case 0x91:
            cout<<"SUB C"<<endl;
            break;
        case 0x92:
            cout<<"SUB D"<<endl;
            break;
        case 0x93:
            cout<<"SUB E"<<endl;
            break;
        case 0x94:
            cout<<"SUB H"<<endl;
            break;
        case 0x95:
            cout<<"SUB L"<<endl;
            break;
        case 0x96:
            cout<<"SUB M"<<endl;
            break;
        case 0x97:
            cout<<"SUB A"<<endl;
            break;
        case 0x98:
            cout<<"SBB B"<<endl;
            break;
        case 0x99:
            cout<<"SBB C"<<endl;
            break;
        case 0x9a:
            cout<<"SBB D"<<endl;
            break;
        case 0x9b:
            cout<<"SBB E"<<endl;
            break;
        case 0x9c:
            cout<<"SBB H"<<endl;
            break;
        case 0x9d:
            cout<<"SBB L"<<endl;
            break;
        case 0x9e:
            cout<<"SBB M"<<endl;
            break;
        case 0x9f:
            cout<<"SBB A"<<endl;
            break;

        case 0xa0:
            cout<<"ANA B"<<endl;
            break;
        case 0xa1:
            cout<<"ANA C"<<endl;
            break;
        case 0xa2:
            cout<<"ANA D"<<endl;
            break;
        case 0xa3:
            cout<<"ANA E"<<endl;
            break;
        case 0xa4:
            cout<<"ANA H"<<endl;
            break;
        case 0xa5:
            cout<<"ANA L"<<endl;
            break;
        case 0xa6:
            cout<<"ANA M"<<endl;
            break;
        case 0xa7:
            cout<<"ANA A"<<endl;
            break;
        case 0xa8:
            cout<<"XRA B"<<endl;
            break;
        case 0xa9:
            cout<<"XRA C"<<endl;
            break;
        case 0xaa:
            cout<<"XRA D"<<endl;
            break;
        case 0xab:
            cout<<"XRA E"<<endl;
            break;
        case 0xac:
            cout<<"XRA H"<<endl;
            break;
        case 0xad:
            cout<<"XRA L"<<endl;
            break;
        case 0xae:
            cout<<"XRA M"<<endl;
            break;
        case 0xaf:
            cout<<"XRA A"<<endl;
            break;
        
        case 0xb0:
            cout<<"ORA B"<<endl;
            break;
        case 0xb1:
            cout<<"ORA C"<<endl;
            break;
        case 0xb2:
            cout<<"ORA D"<<endl;
            break;
        case 0xb3:
            cout<<"ORA E"<<endl;
            break;
        case 0xb4:
            cout<<"ORA H"<<endl;
            break;
        case 0xb5:
            cout<<"ORA L"<<endl;
            break;
        case 0xb6:
            cout<<"ORA M"<<endl;
            break;
        case 0xb7:
            cout<<"ORA A"<<endl;
            break;
        case 0xb8:
            cout<<"CMP B"<<endl;
            break;
        case 0xb9:
            cout<<"CMP C"<<endl;
            break;
        case 0xba:
            cout<<"CMP D"<<endl;
            break;
        case 0xbb:
            cout<<"CMP E"<<endl;
            break;
        case 0xbc:
            cout<<"CMP H"<<endl;
            break;
        case 0xbd:
            cout<<"CMP L"<<endl;
            break;
        case 0xbe:
            cout<<"CMP M"<<endl;
            break;
        case 0xbf:
            cout<<"CMP A"<<endl;
            break;
        
        case 0xc0:
            cout<<"RNZ"<<endl;
            break;
        case 0xc1:
            cout<<"POP B"<<endl;
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
            cout<<"RST 0"<<endl;
            break;
        case 0xc8:
            cout<<"RZ"<<endl;
            break;
        case 0xc9:
            cout<<"RET"<<endl;
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
            cout<<"RST 1"<<endl;
            break;
        
        case 0xd0:
            cout<<"RNC"<<endl;
            break;
        case 0xd1:
            cout<<"POP D"<<endl;
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
            cout<<"RST 2"<<endl;
            break;
        case 0xd8:
            cout<<"RC"<<endl;
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
            cout<<"RST 3"<<endl;
            break;
        
        case 0xe0:
            cout<<"RPO"<<endl;
            break;
        case 0xe1:
            cout<<"POP H"<<endl;
            break;
        case 0xe2:
            cout<<"JPO #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xe3:
            cout<<"XTHL"<<endl;
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
            cout<<"RST 4"<<endl;
            break;
        case 0xe8:
            cout<<"RPE"<<endl;
            break;
        case 0xe9:
            cout<<"PCHL"<<endl;
            break;
        case 0xea:
            cout<<"JPE #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xeb:
            cout<<"XCHG"<<endl;
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
            cout<<"RST 5"<<endl;
            break;
        
        case 0xf0:
            cout<<"RP"<<endl;
            break;
        case 0xf1:
            cout<<"POP PSW"<<endl;
            break;
        case 0xf2:
            cout<<"JP #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xf3:
            cout<<"DI"<<endl;
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
            cout<<"RST 6"<<endl;
            break;
        case 0xf8:
            cout<<"RM"<<endl;
            break;
        case 0xf9:
            cout<<"SPHL"<<endl;
            break;
        case 0xfa:
            cout<<"JM #"<<hex<<(int)buffer[pc+2]<<hex<<(int)buffer[pc+1]<<endl;
            opbytes =3;
            break;
        case 0xfb:
            cout<<"EI"<<endl;
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
            cout<<"RST 7"<<endl;
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