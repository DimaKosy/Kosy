#ifndef KOSY_LIB

    #define KOSY_LIB

    #ifndef _INC_STDIO
        #include <stdio.h>
    #endif
    #ifndef _GLIBCXX_STDLIB_H
        #include <stdlib.h>
    #endif
    #ifndef _TIME_H_
        #include <time.h>
    #endif
    #ifndef _GLIBCXX_MATH_H
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

#endif