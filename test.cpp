#include<iostream>
#include<math.h>

void dectobin(int a){
    int binary[32];
    int i=0;
    while(a>0){
        binary[i]=a%2;
        a=a/2;
        i++;
    }
    for(int j=i-1; j>=0; j--)
        std::cout<<binary[j];
}

int factorial(int a){
    int P=1;
    for(int i=1; i<=a; i++)
        P=P*i;
    return P;
}

float power(int a, int b){
    float P=1;
    if(b>0)
        for(int i=1; i<=b; i++)
            P=P*a;
    if(b==0)
        P=1;
    if(b<0){
        for(int i=-1; i>=b; i--)
            P=P*a;
        P=1.0/P;}
    return P;
}

void welcome(){
    std::cout<<"Prompt Calculus"<<std::endl<<"Don't use spaces! Always add '='!"<<std::endl;
}

void things(char expresie[44]){
    if(int(expresie[0])==118 || int(expresie[0])==86)
        std::cout<<"Currently under active-development"<<std::endl<<"Beta-Release Prompt Calculus 0.6.8";
    if(int(expresie[0])==104 || int(expresie[0])==72)
        std::cout<<"Write the expression without spaces. Always add the equal sign!"<<std::endl<<"! - factorial"<<std::endl<<"\\ - square root"<<std::endl<<"^ - power"<<std::endl<<"+ , - , x or * , / - basic math operators"<<std::endl<<"Write 'X' to exit."<<std::endl;
}

void reading(char expresie[44]){
    int a=0, b=0, semn;
    bool trecut_semn=0;
    for(int i=0; i<42; i++){
        int aux=expresie[i];
            if(aux>=48 && aux<=57){
                if(trecut_semn==0){
                    a=a*10+aux-48;
                    if(int(expresie[i-1])==45 && trecut_semn==0)
                        a=a*-1;
                }
                else{
                    b=b*10+aux-48;
                    if((int(expresie[i-2])==45 || int(expresie[i-2])==42 || int(expresie[i-2])==47 || int(expresie[i-2])==94) && int(expresie[i-1])==45 && trecut_semn==1)
                        b=b*-1;
                }
            }
            if(trecut_semn==0 && i!=0)
                if(aux==120 || aux==42 || aux==43 || aux==45 || aux==47 || aux==94){
                    trecut_semn=1;
                    semn=aux;
                }
                if(aux==33 && int(expresie[i+1])==61){
                    std::cout<<factorial(a);
                    break;
                }
                if(aux==92 && int(expresie[i+1])==61){
                    std::cout<<sqrt(a);
                    break;
                }
                if(aux==61 && expresie[i+1]==61){
                    dectobin(a);
                    break;}
            if(aux==61 && expresie[i+1]!=61)
                break;
    }
    //std::cout<<a<<" "<<semn<<" "<<b<<std::endl;
        if(semn==43)
            std::cout<<a+b;
        if(semn==45)
            std::cout<<a-b;
        if(semn==120 || semn==42)
            std::cout<<a*b;
        if(semn==47)
            std::cout<<a*1.0/b;
        if(semn==94)
            std::cout<<power(a, b);

    std::cout<<std::endl;
}

int main()
{
    welcome();
    char expresie[44];
    while(int(expresie[0])!=88){
        expresie[0]='\n';
        std::cout<<"$: "; std::cin>>expresie;
        if(int(expresie[0])==0)
            std::cout<<"$: ";
        things(expresie);
        reading(expresie);
    }
    return 0;
}
