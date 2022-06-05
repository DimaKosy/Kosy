#ifndef KOSY_BINARY
    #define KOSY_BINARY

    #ifndef _INC_STDIO
        #include <stdio.h>
    #endif
    #ifndef _GLIBCXX_MATH_H
        #include <math.h>
    #endif


extern void binary(long long Carry, int BITS,int BitBreak){
    static int Row = 0;
    long long Bit;
    Bit = Carry % 2;

    if(BITS != 0){
        binary(ceil(Carry/2), BITS-1, BitBreak);

        if((Row%BitBreak == 0) && (Row != 0)){
            printf("-");
        }

        Row++;
        printf("%d",Bit);
    }
    else{
        Row = 0;
    }
}

//integer to convert, Number of "bits", Bits spacing, Base number
extern void BaseConvert(long long Carry, unsigned char BITS,unsigned char BitBreak, int Base){
    static int Row = 0;
    long long Bit;
    Bit = Carry % Base;

    if(BITS != 0){
        BaseConvert(ceil(Carry/Base), BITS-1, BitBreak,Base);

        if((BitBreak <= 0)? 0:((Row%BitBreak == 0) && (Row != 0))){
            printf("-");
        }

        Row++;
        printf("%d",Bit);
    }
    else{
        Row = 0;
    }
}

//integer to convert, Number of "bits", Bits spacing, Base number //Recommended max 62 offering 13537086546263551
extern void BaseConvert_Alpha(long long Carry, unsigned char BITS,unsigned char BitBreak, int Base){
    static int Row = 0;
    long long Bit;
    Bit = Carry % Base;

    if(BITS != 0){
        BaseConvert_Alpha(ceil(Carry/Base), BITS-1, BitBreak,Base);

        if((BitBreak <= 0)? 0:((Row%BitBreak == 0) && (Row != 0))){
            printf("-");
        }

        Row++;

        if(Bit >= 0 && Bit <= 9){
            printf("%c",Bit+48);
        }
        else if(Bit>9 && Bit <= 35){
            printf("%c",Bit+87);
        }
        else if(Bit>35 && Bit <= 61){
            printf("%c",Bit+29);
        }
        else{
            printf("[%d]",Bit);
        }
        
    }
    else{
        Row = 0;
    }
}

#endif
