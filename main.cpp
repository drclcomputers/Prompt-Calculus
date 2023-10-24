#include<iostream>
#include<math.h>

void bintodec(int nr_binar[40]){
    int nr=0, aux_test=0;
    for(int w=0; w<40; w++){
        if(nr_binar[w]!=2)
            aux_test+=1;
        else
            break;
    }
    aux_test-=1;
    //std::cout<<std::endl<<"aux: "<<aux_test;
    for(int o=0; o<=aux_test; o++){
        if(nr_binar[o]==1)
            nr=nr+(pow(2, aux_test-o-1));
        if(nr_binar[o]==2)
            break;
    }
    std::cout<<nr;
}

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

void power(int a, int b){
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
    std::cout<<P;
}

void add(int a, int b){
    std::cout<<a+b;
}

void scad(int a, int b){
    std::cout<<a-b;
}

void mult(int a, int b){
    std::cout<<a*b;
}

void imp(int a, int b){
    std::cout<<a*1.0/b;
}

void welcome(){
    std::cout<<"Prompt Calculus"<<std::endl<<"Don't use spaces! Always add '='!"<<std::endl<<std::endl;
}

void things(char expresie[44]){
    if(int(expresie[0])==118 || int(expresie[0])==86)
        std::cout<<"Currently under active-development"<<std::endl<<"Beta-Release Prompt Calculus 0.7.2";
    if(int(expresie[0])==104 || int(expresie[0])==72)
        std::cout<<"Write the expression without spaces. Always add the equal sign!"<<std::endl<<"! - factorial"<<std::endl<<"\\ - square root"<<std::endl<<"^ - power"<<std::endl<<"+ , - , x or * , / - basic math operators"<<std::endl<<"'nr'== - decimal to binary conversion"<<std::endl<<"='nr'= - binary to decimal conversion"<<std::endl<<"Write 'X' to exit."<<std::endl;
    if(int(expresie[0])==102 || int(expresie[0])==70){
        std::cout<<"FAQ"<<std::endl<<"Q: What happens if I don't add spaces? -> A: Not adding '=' on simple operation won't affect the results, but if you would use advanced functions, most likely the program will freeze or spit out random answers. So yeah, I suggest adding the equal sign."<<std::endl;
        std::cout<<"Q: It's free? -> A: Yes, it's absotulely free and open-source. You can modify the source code if you would need other functions."<<std::endl;
        std::cout<<"Q: Why'd you create this app? There are several other aplications, better than this one. -> A: I know, but it's mine and I'm proud of it. Plus, I hate the Windows built-in calculator (too complicated for me; I like using the CMD or terminal)"<<std::endl;}
}

void reading(char expresie[44]){
    int a=0, b=0, semn=0;
    bool trecut_semn=0, a_semn=0, b_semn=0;
    for(int i=0; i<42; i++){
        int aux=expresie[i];
        //std::cout<<aux<<" ";
        if(aux==45 && a==0)
            a_semn=1;
        if(aux==45 && b==0 && trecut_semn==1)
            b_semn=1;
        if(aux>=48 && aux<=57){
            if(trecut_semn==0)
                a=a*10+aux-48;
            else
                b=b*10+aux-48;}
        if(trecut_semn==0 && i!=0)
            if(aux==120 || aux==42 || aux==43 || aux==45 || aux==47 || aux==94){
                trecut_semn=1;
                semn=aux;}
        if(aux==33 && int(expresie[i+1])==61){
            std::cout<<factorial(a);
            break;
        }
        if(aux==92 && int(expresie[i+1])==61){
            if(a_semn==0)
                std::cout<<sqrt(a);
            else
                std::cout<<"Error";
            break;
        }
        if(aux==61 && expresie[i+1]==61){
            dectobin(a);
            break;}
        if(int(expresie[0])==61){
            int nr_binar[40];
            for(int j=1; j<44; j++){
                if(int(expresie[j])!=61){
                    if(int(expresie[j])==48){
                        nr_binar[j-1]=0;}
                    else{
                        nr_binar[j-1]=1;}
                    //std::cout<<nr_binar[j-1];
                }
                else{
                    nr_binar[j]=2;
                    bintodec(nr_binar);
                    break;
                    break;
                }
                //for(int k=0; k<=j; k++)
                    //std::cout<<std::endl<<nr_binar[k];
            }
        }
        if(aux==61 && expresie[i+1]!=61)
            break;
    }
    if(a_semn==1)
        a=a*-1;
    if(b_semn==1)
        b=b*-1;
    //std::cout<<a<<" "<<semn<<" "<<b<<std::endl;
    if(semn==43)
        add(a, b);
    if(semn==45)
        scad(a, b);
    if(semn==120 || semn==42)
        mult(a, b);
    if(semn==47)
        imp(a, b);
    if(semn==94)
        power(a, b);

    std::cout<<std::endl<<std::endl;
}

int main()
{
    welcome();
    char expresie[44];
    while(int(expresie[0])!=88){
        expresie[0]='0';
        std::cout<<"$: "; std::cin>>expresie;
        if(int(expresie[0])==0)
            std::cout<<"$: ";
        things(expresie);
        reading(expresie);
    }
    return 0;
}
