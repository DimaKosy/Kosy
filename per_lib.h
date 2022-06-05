#ifndef XOR

    #ifndef getchar
        #include <stdio.h>
    #endif
    #ifndef rand
        #include <stdlib.h>
    #endif
    #ifndef time
        #include <time.h>
    #endif
    #ifndef round
        #include <math.h>
    #endif

    #define XOR(A,B) !(!A && !B) && !(A && B)

// Grabs integers only ignoring everything else
extern int IntGrab(){
    char Temp;  //For character comparisons
    int Grabbed = 0;

    while(1){    

        scanf("%d",&Grabbed);           //grabs the first int
        Temp = getchar();
        
        if(Temp == '\n'){          //only proceeds if the next available character is a new line
            //printf("Debug IntGrab %d",Grabbed);
            return Grabbed;
        }
        else {           

           while( ((Temp == '\t' ) || (Temp == ' ' )) && (Temp != '\n') ){  //runs if it detects a blank character breaking on a non blank or new line
               Temp = getchar();
           }
           if( ((Temp != '\t' ) || (Temp != ' ')) && (Temp != '\n') ){      //Runs if the grabbed character isnt a flaot
               while(getchar() != '\n');                                    //clears line by reading through it
               printf("Invalid Input\nTry Again\n");
           }
           else if(((Temp != '\t' ) || (Temp != ' ')) && (Temp == '\n')){   //Runs on end of line
               return Grabbed;
           }
            
        }
        //printf("Debug IntGrab %d",Grabbed);
        Grabbed = 0;    //Resets grabbed to 0 due to a bug with + and - resulting in the last value recieved
    }
}

// Grabs integers only returning a false value otherwise
extern int IntFGrab(int FalseReturn){

    char Temp;  //For character comparisons
    int Grabbed = 0;    //Holds the grabbed integer value

    scanf("%d",&Grabbed);       //grabs the first int
    Temp = getchar();
    
    if(Temp == '\n'){          //only proceeds if the next available character is a new line
        return Grabbed;        //returns the grabbed int
    }
    else {           

        while( ((Temp == '\t' ) || (Temp == ' ' )) && (Temp != '\n') ){  //runs if it detects a blank character breaking on a non blank or new line
            Temp = getchar();
        }
        if( ((Temp != '\t' ) || (Temp != ' ')) && (Temp != '\n') ){      //Runs if the grabbed character isn't a float
            while(getchar() != '\n');    //clears line by reading through it
            return FalseReturn;          //returns the FalseReturn value
        }
        else if(((Temp != '\t' ) || (Temp != ' ')) && (Temp == '\n')){   //Runs on end of line
            return Grabbed; //returns the grabbed int
        }
    }
    
    printf("\n\nERROR: Couldn't retrieve value\n");
    return 0;
}

// Grabs floats only ignoring everything else
extern float FloatGrab(){
    char Temp;  //For character comparisons
    float Grabbed = 0;

    while(1){    

        scanf("%f",&Grabbed);           //grabs the first float
        Temp = getchar();
        
        if(Temp == '\n'){          //only proceeds if the next available character is a new line
            return Grabbed; 
        }
        else {

           while( ((Temp == '\t' ) || (Temp == ' ' )) && (Temp != '\n') ){  //runs if it detects a blank character breaking on a non blank or new line
               Temp = getchar();
           }
           if( ((Temp != '\t' ) || (Temp != ' ')) && (Temp != '\n') ){      //Runs if the grabbed character isnt a flaot
               while(getchar() != '\n');                                    //clears line by reading through it
               printf("Invalid Input\nTry Again\n");
           }
           else if(((Temp != '\t' ) || (Temp != ' ')) && (Temp == '\n')){   //Runs on end of line
               return Grabbed;
           }
            
        }
            
        Grabbed = 0;    //Resets grabbed to 0 due to a bug with + and - resulting in the last value recieved
    }
}

//Rounds a value to a certain amount of decimal points
//Round(Number to be rounded, amount of decimal points);
extern float Round(float ToRound,int Decimal){

    float Temp;
    Temp = ToRound * pow(10,Decimal);   //moves decimal point left
    Temp = round(Temp);                 //rounds the remaining decimal point
    Temp = Temp / pow(10,Decimal);      //moves decimal point back
    return Temp;

}

//Weigthed Random
extern int WeightedRandom(int Weights[],int size){

    //printf("Debug %d\n", size);
    //printf("Debug %d\n", Weights[0]);

    int Total = 0;
    for(int i = 0; i < size;i++){
        Total += Weights[i];
    }

    int PickedValue = rand()%Total;
    //printf("Debug %d\n", Total);
    //printf("Debug %d\n", PickedValue);
    for(int i = 0; i < size; i++){
        
        PickedValue -= Weights[i];

        if(PickedValue < 0){
            return i;
        }
    }

    return 0;
}

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