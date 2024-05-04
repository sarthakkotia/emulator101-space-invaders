#include<iostream>
using namespace std;
#include <fstream>
#include<vector>
#include <iomanip>

int disassemble(uint8_t *buffer,int pc){
    int opbytes=1;
    uint8_t code= buffer[pc];
    cout<<uppercase<<setfill('0')<<setw(4)<<hex<<pc<<" ";
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
            cout<<"MVI C,#"<<hex<<(int)buffer[pc+1]<<endl;
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
            cout<<"DCR M"<<endl;
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
            cout<<"NOP"<<endl;
            break;
    }
    int var = buffer[pc];
    // int code = 0xvar;
    // cout<<"program counter right now:"<<pc<<endl;
    // cout<<"byte read:"<<hex<<var<<endl;
        return opbytes;
}
// when arithmetic is done it's done mostly on the accumulator and it affects flags
class Flags{
    public:
        uint8_t z:1;
        //Z (zero) set to 1 when the result is equal to zero
        uint8_t s:1;
        //S (sign) set to 1 when bit 7 (the most significant bit or MSB) of the math instruction is set
        uint8_t p:1;
        //P (parity) is set when the answer has even parity, clear when odd parity
        uint8_t cy:1;
        //CY (carry) set to 1 when the instruction resulted in a carry out or borrow into the high order bit
        uint8_t ac:1;
        //AC (auxillary carry) is used mostly for BCD (binary coded decimal) math. Read the data book for more details, Space Invaders doesn't use it.
        uint8_t pad:3;
};
class State{
    public:
        uint8_t a;
        uint8_t b;
        uint8_t c;
        uint8_t d;
        uint8_t e;
        uint8_t h;
        uint8_t l;
        uint16_t sp;
        uint16_t pc;
        uint8_t *memory;
        Flags flag;
        uint8_t int_enable;
};

void UnimplementedInstruction(State& state){
    cout<<"Error: Unimplemented instruction"<<endl;
    // exit(1);
}

void Emulate(State& state){
     uint16_t pc = state.pc;
     //fetch opcode
     uint8_t opcode = state.memory[pc];
     disassemble(state.memory,pc);
     state.pc+=1;
     switch(opcode){
         case 0x00:
             //NOP
             break;
        case 0x01:
        {
            //LXI B,word b<=byte 3 , c<=byte2
            uint8_t byte2 = state.memory[pc];
            state.c = byte2;
            uint8_t byte3 = state.memory[pc+1];
            state.b = byte3;
            state.pc = pc+2; 
        }
            break;
        case 0x02:
            UnimplementedInstruction(state); 
            break;
        case 0x03:
            UnimplementedInstruction(state); 
            break;
        case 0x04:
            UnimplementedInstruction(state); 
            break;
        case 0x05:
        {
            //DCR B
            // Arithmetic group -> register form
            uint8_t answer = (uint8_t)(state.b);
            answer--;
            //check for zero flag
            if(answer==0){
                state.flag.z=1;
            }else{
                state.flag.z=0;
            }
            //check for sign flag
            if(answer & 0x80){
                state.flag.s=1;
            }else{
                state.flag.s=0;
            }
            state.b = answer;
            // state->flag.Parity()

            // Parity is handled by a subroutine    
            // Parity( answer & 0xff) ? state->flag.p = 1 : state->flag.p = 0;
        }
            break;
        case 0x06:
        //MVI B
        {

        }
            break;
        case 0x07:
            UnimplementedInstruction(state); 
            break;
        case 0x08:
            UnimplementedInstruction(state); 
            break;
        case 0x09:
        //DAD B
        {
            uint32_t hl = (state.h<<8)|state.l;
            uint32_t bc = (state.b<<8)|state.l;
            uint32_t res = hl+bc;
            if((res&0xffff0000)!=0){
                state.flag.cy=1;
            }else{
                state.flag.cy=0;
            }
            state.h = (res&0xff00)<<8;
            state.l = res&0xff;
        }
            break;
        case 0x0a:
            UnimplementedInstruction(state); 
            break;
        case 0x0b:
            UnimplementedInstruction(state); 
            break;
        case 0x0c:
            UnimplementedInstruction(state); 
            break;
        case 0x0d:
        //DCR C
        {
            uint8_t ans = state.c;
            ans--;
            if(ans==0){
                state.flag.z = 1;
            }else{
                state.flag.z=0;
            }
            if(ans&0x80){
                state.flag.s=1;
            }else{
                state.flag.s=0;
            }
            state.c=ans;
        }
            break;
        case 0x0e:
            UnimplementedInstruction(state); 
            break;
        case 0x0f:
        {
            //RRC

        }
            break;
        case 0x10:
            UnimplementedInstruction(state); 
            break;
        case 0x11:
            UnimplementedInstruction(state); 
            break;
        case 0x12:
            UnimplementedInstruction(state); 
            break;
        case 0x13:
        //INX D
        {
            uint8_t d_state = state.d;
            uint8_t e_state = state.e;
            e_state++;
            if(e_state==0){
                d_state++;
            }
            state.d=d_state;
            state.e=e_state;
        }
            break;
        case 0x14:
            UnimplementedInstruction(state); 
            break;
        case 0x15:
            UnimplementedInstruction(state); 
            break;
        case 0x16:
            UnimplementedInstruction(state); 
            break;
        case 0x17:
            UnimplementedInstruction(state); 
            break;
        case 0x18:
            UnimplementedInstruction(state); 
            break;
        case 0x19:
        //DAD D
        {
            uint32_t hl = (state.h<<8)|state.l;
            uint32_t de = (state.b<<8)|state.l;
            uint32_t res = hl+de;
            if((res&0xffff0000)!=0){
                state.flag.cy=1;
            }else{
                state.flag.cy=0;
            }
            state.h = (res&0xff00)<<8;
            state.l = res&0xff;

        } 
            break;
        case 0x1a:
            UnimplementedInstruction(state); 
            break;
        case 0x1b:
            UnimplementedInstruction(state); 
            break;
        case 0x1c:
            UnimplementedInstruction(state); 
            break;
        case 0x1d:
            UnimplementedInstruction(state); 
            break;
        case 0x1e:
            UnimplementedInstruction(state); 
            break;
        case 0x1f:
            UnimplementedInstruction(state); 
            break;
        case 0x20:
            UnimplementedInstruction(state); 
            break;
        case 0x21:
            UnimplementedInstruction(state); 
            break;
        case 0x22:
            UnimplementedInstruction(state); 
            break;
        case 0x23:
        //INX H
        {
            uint8_t h_state = state.h;
            uint8_t l_state = state.l;
            l_state++;
            if(l_state==0){
                h_state++;
            }
            state.h=h_state;
            state.l=l_state;

        }
            break;
        case 0x24:
            UnimplementedInstruction(state); 
            break;
        case 0x25:
            UnimplementedInstruction(state); 
            break;
        case 0x26:
            UnimplementedInstruction(state); 
            break;
        case 0x27:
            UnimplementedInstruction(state); 
            break;
        case 0x28:
            UnimplementedInstruction(state); 
            break;
        case 0x29:
        //DAD H
        {
            uint32_t hl = (state.h<<8)|state.l;
            uint32_t res = hl+hl;
            if((res&0xffff0000)!=0){
                state.flag.cy=1;
            }else{
                state.flag.cy=0;
            }
            state.h = (res&0xff00)<<8;
            state.l = res&0xff;
        }
            break;
        case 0x2a:
            UnimplementedInstruction(state); 
            break;
        case 0x2b:
            UnimplementedInstruction(state); 
            break;
        case 0x2c:
            UnimplementedInstruction(state); 
            break;
        case 0x2d:
            UnimplementedInstruction(state); 
            break;
        case 0x2e:
            UnimplementedInstruction(state); 
            break;
        case 0x2f:
            UnimplementedInstruction(state); 
            break;
        case 0x30:
            UnimplementedInstruction(state); 
            break;
        case 0x31:
            UnimplementedInstruction(state); 
            break;
        case 0x32:
            UnimplementedInstruction(state); 
            break;
        case 0x33:
            UnimplementedInstruction(state); 
            break;
        case 0x34:
            UnimplementedInstruction(state); 
            break;
        case 0x35:
            UnimplementedInstruction(state); 
            break;
        case 0x36:
            UnimplementedInstruction(state); 
            break;
        case 0x37:
            UnimplementedInstruction(state); 
            break;
        case 0x38:
            UnimplementedInstruction(state); 
            break;
        case 0x39:
            UnimplementedInstruction(state); 
            break;
        case 0x3a:
            UnimplementedInstruction(state); 
            break;
        case 0x3b:
            UnimplementedInstruction(state); 
            break;
        case 0x3c:
            UnimplementedInstruction(state); 
            break;
        case 0x3d:
            UnimplementedInstruction(state); 
            break;
        case 0x3e:
            UnimplementedInstruction(state); 
            break;
        case 0x3f:
            UnimplementedInstruction(state); 
            break;
        case 0x40:
            UnimplementedInstruction(state); 
            break;
        case 0x41:
            UnimplementedInstruction(state); 
            break;
        case 0x42:
            UnimplementedInstruction(state); 
            break;
        case 0x43:
            UnimplementedInstruction(state); 
            break;
        case 0x44:
            UnimplementedInstruction(state); 
            break;
        case 0x45:
            UnimplementedInstruction(state); 
            break;
        case 0x46:
            UnimplementedInstruction(state); 
            break;
        case 0x47:
            UnimplementedInstruction(state); 
            break;
        case 0x48:
            UnimplementedInstruction(state); 
            break;
        case 0x49:
            UnimplementedInstruction(state); 
            break;
        case 0x4a:
            UnimplementedInstruction(state); 
            break;
        case 0x4b:
            UnimplementedInstruction(state); 
            break;
        case 0x4c:
            UnimplementedInstruction(state); 
            break;
        case 0x4d:
            UnimplementedInstruction(state); 
            break;
        case 0x4e:
            UnimplementedInstruction(state); 
            break;
        case 0x4f:
            UnimplementedInstruction(state); 
            break;
        case 0x50:
            UnimplementedInstruction(state); 
            break;
        case 0x51:
            UnimplementedInstruction(state); 
            break;
        case 0x52:
            UnimplementedInstruction(state); 
            break;
        case 0x53:
            UnimplementedInstruction(state); 
            break;
        case 0x54:
            UnimplementedInstruction(state); 
            break;
        case 0x55:
            UnimplementedInstruction(state); 
            break;
        case 0x56:
            UnimplementedInstruction(state); 
            break;
        case 0x57:
            UnimplementedInstruction(state); 
            break;
        case 0x58:
            UnimplementedInstruction(state); 
            break;
        case 0x59:
            UnimplementedInstruction(state); 
            break;
        case 0x5a:
            UnimplementedInstruction(state); 
            break;
        case 0x5b:
            UnimplementedInstruction(state); 
            break;
        case 0x5c:
            UnimplementedInstruction(state); 
            break;
        case 0x5d:
            UnimplementedInstruction(state); 
            break;
        case 0x5e:
            UnimplementedInstruction(state); 
            break;
        case 0x5f:
            UnimplementedInstruction(state); 
            break;
        case 0x60:
            UnimplementedInstruction(state); 
            break;
        case 0x61:
            UnimplementedInstruction(state); 
            break;
        case 0x62:
            UnimplementedInstruction(state); 
            break;
        case 0x63:
            UnimplementedInstruction(state); 
            break;
        case 0x64:
            UnimplementedInstruction(state); 
            break;
        case 0x65:
            UnimplementedInstruction(state); 
            break;
        case 0x66:
            UnimplementedInstruction(state); 
            break;
        case 0x67:
            UnimplementedInstruction(state); 
            break;
        case 0x68:
            UnimplementedInstruction(state); 
            break;
        case 0x69:
            UnimplementedInstruction(state); 
            break;
        case 0x6a:
            UnimplementedInstruction(state); 
            break;
        case 0x6b:
            UnimplementedInstruction(state); 
            break;
        case 0x6c:
            UnimplementedInstruction(state); 
            break;
        case 0x6d:
            UnimplementedInstruction(state); 
            break;
        case 0x6e:
            UnimplementedInstruction(state); 
            break;
        case 0x6f:
            UnimplementedInstruction(state); 
            break;
        case 0x70:
            UnimplementedInstruction(state); 
            break;
        case 0x71:
            UnimplementedInstruction(state); 
            break;
        case 0x72:
            UnimplementedInstruction(state); 
            break;
        case 0x73:
            UnimplementedInstruction(state); 
            break;
        case 0x74:
            UnimplementedInstruction(state); 
            break;
        case 0x75:
            UnimplementedInstruction(state); 
            break;
        case 0x76:
            UnimplementedInstruction(state); 
            break;
        case 0x77:
            UnimplementedInstruction(state); 
            break;
        case 0x78:
            UnimplementedInstruction(state); 
            break;
        case 0x79:
            UnimplementedInstruction(state); 
            break;
        case 0x7a:
            UnimplementedInstruction(state); 
            break;
        case 0x7b:
            UnimplementedInstruction(state); 
            break;
        case 0x7c:
            UnimplementedInstruction(state); 
            break;
        case 0x7d:
            UnimplementedInstruction(state); 
            break;
        case 0x7e:
            UnimplementedInstruction(state); 
            break;
        case 0x7f:
            UnimplementedInstruction(state); 
            break;
        case 0x80:
        {
            // ADD B
            // Arithmetic group -> register form
            uint16_t answer = (uint16_t)(state.a) + (uint16_t)(state.b);
            if((answer & 0xff)==0){
                //check for zero flag
                state.flag.z=1;
            }else{
                state.flag.z=0;
            }

            // check for sign flag if bit 7 is set
            if((answer & 0x80)){
                state.flag.s=1;
            }else{
                state.flag.s=0;
            }

            //check for carry flag 
            if(answer>0xff){
                state.flag.cy=1;
            }else{
                state.flag.cy=0;
            }

            // Parity is handled by a subroutine    
            // state->flag.p = Parity( answer & 0xff); 

            state.a = answer&0xff;
        }
            break;
            
        case 0x81:
            UnimplementedInstruction(state); 
            break;
        case 0x82:
            UnimplementedInstruction(state); 
            break;
        case 0x83:
            UnimplementedInstruction(state); 
            break;
        case 0x84:
            UnimplementedInstruction(state); 
            break;
        case 0x85:
            UnimplementedInstruction(state); 
            break;
        case 0x86:
        {
            // ADD M
            // Arithmetic group -> memory form
            uint16_t memoryptr = state.h>>8;
            // s=take h of state and left shift it by 8 bits ie covert all 8 bits to higher bit 
            memoryptr | (state.l);
            // to make this memoryptr to a ptr to memory address which is pointed by HL pair we said that make h higher bits and then or the ptr with l bits so that ptr's last 8 bits would be filled by l bits
            uint16_t answer = (uint16_t)state.a + state.memory[memoryptr];
            answer & 0xff == 0 ? state.flag.z = 1 : state.flag.z = 0;
            answer & 0x80 != 0 ? state.flag.s = 1 : state.flag.s = 0;
            answer > 0xff ? state.flag.cy = 1 : state.flag.cy = 0;
            // Parity( answer & 0xff) ? state->flag.p = 1 : state->flag.p = 0;
            state . a = answer & 0xff; 
        }
            break;
        case 0x87:
            UnimplementedInstruction(state); 
            break;
        case 0x88:
            UnimplementedInstruction(state); 
            break;
        case 0x89:
            UnimplementedInstruction(state); 
            break;
        case 0x8a:
            UnimplementedInstruction(state); 
            break;
        case 0x8b:
            UnimplementedInstruction(state); 
            break;
        case 0x8c:
            UnimplementedInstruction(state); 
            break;
        case 0x8d:
            UnimplementedInstruction(state); 
            break;
        case 0x8e:
            UnimplementedInstruction(state); 
            break;
        case 0x8f:
            UnimplementedInstruction(state); 
            break;
        case 0x90:
            UnimplementedInstruction(state); 
            break;
        case 0x91:
            UnimplementedInstruction(state); 
            break;
        case 0x92:
            UnimplementedInstruction(state); 
            break;
        case 0x93:
            UnimplementedInstruction(state); 
            break;
        case 0x94:
            UnimplementedInstruction(state); 
            break;
        case 0x95:
            UnimplementedInstruction(state); 
            break;
        case 0x96:
            UnimplementedInstruction(state); 
            break;
        case 0x97:
            UnimplementedInstruction(state); 
            break;
        case 0x98:
            UnimplementedInstruction(state); 
            break;
        case 0x99:
            UnimplementedInstruction(state); 
            break;
        case 0x9a:
            UnimplementedInstruction(state); 
            break;
        case 0x9b:
            UnimplementedInstruction(state); 
            break;
        case 0x9c:
            UnimplementedInstruction(state); 
            break;
        case 0x9d:
            UnimplementedInstruction(state); 
            break;
        case 0x9e:
            UnimplementedInstruction(state); 
            break;
        case 0x9f:
            UnimplementedInstruction(state); 
            break;
        case 0xa0:
            UnimplementedInstruction(state); 
            break;
        case 0xa1:
            UnimplementedInstruction(state); 
            break;
        case 0xa2:
            UnimplementedInstruction(state); 
            break;
        case 0xa3:
            UnimplementedInstruction(state); 
            break;
        case 0xa4:
            UnimplementedInstruction(state); 
            break;
        case 0xa5:
            UnimplementedInstruction(state); 
            break;
        case 0xa6:
            UnimplementedInstruction(state); 
            break;
        case 0xa7:
            UnimplementedInstruction(state); 
            break;
        case 0xa8:
            UnimplementedInstruction(state); 
            break;
        case 0xa9:
            UnimplementedInstruction(state); 
            break;
        case 0xaa:
            UnimplementedInstruction(state); 
            break;
        case 0xab:
            UnimplementedInstruction(state); 
            break;
        case 0xac:
            UnimplementedInstruction(state); 
            break;
        case 0xad:
            UnimplementedInstruction(state); 
            break;
        case 0xae:
            UnimplementedInstruction(state); 
            break;
        case 0xaf:
            UnimplementedInstruction(state); 
            break;
        case 0xb0:
            UnimplementedInstruction(state); 
            break;
        case 0xb1:
            UnimplementedInstruction(state); 
            break;
        case 0xb2:
            UnimplementedInstruction(state); 
            break;
        case 0xb3:
            UnimplementedInstruction(state); 
            break;
        case 0xb4:
            UnimplementedInstruction(state); 
            break;
        case 0xb5:
            UnimplementedInstruction(state); 
            break;
        case 0xb6:
            UnimplementedInstruction(state); 
            break;
        case 0xb7:
            UnimplementedInstruction(state); 
            break;
        case 0xb8:
            UnimplementedInstruction(state); 
            break;
        case 0xb9:
            UnimplementedInstruction(state); 
            break;
        case 0xba:
            UnimplementedInstruction(state); 
            break;
        case 0xbb:
            UnimplementedInstruction(state); 
            break;
        case 0xbc:
            UnimplementedInstruction(state); 
            break;
        case 0xbd:
            UnimplementedInstruction(state); 
            break;
        case 0xbe:
            UnimplementedInstruction(state); 
            break;
        case 0xbf:
            UnimplementedInstruction(state); 
            break;
        case 0xc0:
            UnimplementedInstruction(state); 
            break;
        case 0xc1:
            UnimplementedInstruction(state); 
            break;
        case 0xc2:
            //JNZ adr
            {
                if(state.flag.z==0){
                    uint8_t byte2 = state.memory[pc];
                    uint8_t byte3 = state.memory[pc+1];
                    state.pc = (byte3<<8)|byte2; 
                }else{
                    state.pc+=2;
                }
            } 
            break;
        case 0xc3:
        //JMP adr
            {
                uint8_t byte2 = state.memory[pc];
                uint8_t byte3 = state.memory[pc+1];
                state.pc=(byte3<<8)|byte2;
            }
            break;
        case 0xc4:
            UnimplementedInstruction(state); 
            break;
        case 0xc5:
            UnimplementedInstruction(state); 
            break;
        case 0xc6:
        //ADI D8
        {
            uint16_t answer = (uint16_t)state.a + (uint16_t)state.memory[pc];
            state.flag.z = ((answer&0xff==0));
            state.flag.s = ((answer&0x80)==0x80);
            if((answer&0xff00)!=0){
                state.flag.cy = 1;
            }else{
                state.flag.cy=0;
            }
            state.pc++;

        }
            break;
        case 0xc7:
            UnimplementedInstruction(state); 
            break;
        case 0xc8:
            UnimplementedInstruction(state); 
            break;
        case 0xc9:
            //RET
            {
                state.pc=(state.memory[state.sp+1]<<8|state.memory[state.sp]);
                state.sp+=2;    
            }
            break;
        case 0xca:
            UnimplementedInstruction(state); 
            break;
        case 0xcb:
            UnimplementedInstruction(state); 
            break;
        case 0xcc:
            UnimplementedInstruction(state); 
            break;
        case 0xcd:
            //CALL ADR
            {
                uint16_t ret = state.pc+2;
                state.memory[state.sp-1]=(ret>>8)&0xff;
                state.memory[state.sp-2]=(ret)&0xff;
                state.sp-=2;
                uint8_t byte2 = state.memory[pc];
                uint8_t byte3 = state.memory[pc+1];
                state.pc = (byte3<<8)|byte2; 
            }
            break;
        case 0xce:
            UnimplementedInstruction(state); 
            break;
        case 0xcf:
            UnimplementedInstruction(state); 
            break;
        case 0xd0:
            UnimplementedInstruction(state); 
            break;
        case 0xd1:
            UnimplementedInstruction(state); 
            break;
        case 0xd2:
            UnimplementedInstruction(state); 
            break;
        case 0xd3:
            UnimplementedInstruction(state); 
            break;
        case 0xd4:
            UnimplementedInstruction(state); 
            break;
        case 0xd5:
            UnimplementedInstruction(state); 
            break;
        case 0xd6:
            UnimplementedInstruction(state); 
            break;
        case 0xd7:
            UnimplementedInstruction(state); 
            break;
        case 0xd8:
            UnimplementedInstruction(state); 
            break;
        case 0xd9:
            UnimplementedInstruction(state); 
            break;
        case 0xda:
            UnimplementedInstruction(state); 
            break;
        case 0xdb:
            UnimplementedInstruction(state); 
            break;
        case 0xdc:
            UnimplementedInstruction(state); 
            break;
        case 0xdd:
            UnimplementedInstruction(state); 
            break;
        case 0xde:
            UnimplementedInstruction(state); 
            break;
        case 0xdf:
            UnimplementedInstruction(state); 
            break;
        case 0xe0:
            UnimplementedInstruction(state); 
            break;
        case 0xe1:
            UnimplementedInstruction(state); 
            break;
        case 0xe2:
            UnimplementedInstruction(state); 
            break;
        case 0xe3:
            UnimplementedInstruction(state); 
            break;
        case 0xe4:
            UnimplementedInstruction(state); 
            break;
        case 0xe5:
            UnimplementedInstruction(state); 
            break;
        case 0xe6:
            UnimplementedInstruction(state); 
            break;
        case 0xe7:
            UnimplementedInstruction(state); 
            break;
        case 0xe8:
            UnimplementedInstruction(state); 
            break;
        case 0xe9:
            UnimplementedInstruction(state); 
            break;
        case 0xea:
            UnimplementedInstruction(state); 
            break;
        case 0xeb:
            UnimplementedInstruction(state); 
            break;
        case 0xec:
            UnimplementedInstruction(state); 
            break;
        case 0xed:
            UnimplementedInstruction(state); 
            break;
        case 0xee:
            UnimplementedInstruction(state); 
            break;
        case 0xef:
            UnimplementedInstruction(state); 
            break;
        case 0xf0:
            UnimplementedInstruction(state); 
            break;
        case 0xf1:
            UnimplementedInstruction(state); 
            break;
        case 0xf2:
            UnimplementedInstruction(state); 
            break;
        case 0xf3:
            UnimplementedInstruction(state); 
            break;
        case 0xf4:
            UnimplementedInstruction(state); 
            break;
        case 0xf5:
            UnimplementedInstruction(state); 
            break;
        case 0xf6:
            UnimplementedInstruction(state); 
            break;
        case 0xf7:
            UnimplementedInstruction(state); 
            break;
        case 0xf8:
            UnimplementedInstruction(state); 
            break;
        case 0xf9:
            UnimplementedInstruction(state); 
            break;
        case 0xfa:
            UnimplementedInstruction(state); 
            break;
        case 0xfb:
            UnimplementedInstruction(state); 
            break;
        case 0xfc:
            UnimplementedInstruction(state); 
            break;
        case 0xfd:
            UnimplementedInstruction(state); 
            break;
        case 0xfe:
            UnimplementedInstruction(state); 
            break;
        case 0xff:
            UnimplementedInstruction(state); 
            break;    
}
    cout<<"CY->"<<(int)state.flag.cy<<" P->"<<(int)state.flag.p<<" S->"<<(int)state.flag.s<<" Z->"<<(int)state.flag.z<<endl;
    cout<<"A->"<<setw(2)<<setfill('0')<<hex<<(int)state.a;
    cout<<" B->"<<setw(2)<<setfill('0')<<hex<<(int)state.b;
    cout<<" C->"<<setw(2)<<setfill('0')<<hex<<(int)state.c;
    cout<<" D->"<<setw(2)<<setfill('0')<<hex<<(int)state.d;
    cout<<" E->"<<setw(2)<<setfill('0')<<hex<<(int)state.e;
    cout<<" H->"<<setw(2)<<setfill('0')<<hex<<(int)state.h;
    cout<<" L->"<<setw(2)<<setfill('0')<<hex<<(int)state.l;
    cout<<" SP->"<<setw(4)<<setfill('0')<<hex<<(int)state.sp<<endl;
}


int main(){
    string s= "space-invaders.rom";
    // string s= "invaders.h";
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
        uint8_t buffer[fsize]={0};
        // vector<uint8_t>buffer(fsize,0);
        for(int i=0;i<fsize;i++){
            // read each character of file in integar and save it in buffer
            buffer[i] = (uint8_t)file.get();
        }
        file.close();
        State state = State();
        state.memory=buffer;
        for(int i=0;i<4;i++){
            Emulate(state);
        }
    }
    int n;
    cin>>n;

    // Emulate(state);
}