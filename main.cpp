#include<iostream>
#include<math.h>

double pi=3.141592;

int factorial(int a){
    int P=1;
    for(int i=1; i<=a; i++)
        P=P*i;
    return P;
}

float power(float a, int b){
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

//Base 2 Conversions ===========================

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
            nr=nr+(power(2, aux_test-o-1));
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
//=================================================


//Trigonometry =========================================

void sindeg(float a){
    std::cout<<sin(a*3.141/180);
}

void sinran(float a){
    std::cout<<sin(a);
}

void cosdeg(float a){
    std::cout<<cos(a*3.141/180);
}

void cosran(float a){
    std::cout<<cos(a);
}


void tandeg(float a){
    std::cout<<sin(a*3.141/180)/cos(a*3.141/180);
}

void tanran(float a){
    std::cout<<sin(a)/cos(a);
}

void ctgdeg(float a){
    std::cout<<cos(a*3.141/180)/sin(a*3.141/180);
}

void ctgran(float a){
    std::cout<<cos(a)/sin(a);
}

void logfunc(float a){
    std::cout<<log10(a);
}


//=======================================================


//Basic Operations ======================================

void add(float a, float b){
    std::cout<<a+b;
}

void scad(float a, float b){
    std::cout<<a-b;
}

void mult(float a, float b){
    std::cout<<a*b;
}

void imp(float a, float b){
    std::cout<<a/b;
}

void modfunc(float a){
    std::cout<<a/100;
}

//=========================================================


//Texts ===================================================
void welcome(){
    std::cout<<"Prompt Calculus"<<std::endl<<"Don't use spaces! Always add '='!"<<std::endl<<std::endl;
}

void things(char expresie[44]){
    if(int(expresie[0])==118 || int(expresie[0])==86)
        std::cout<<"Currently under active-development"<<std::endl<<"Beta-Release Prompt Calculus 0.8.3";
    if(int(expresie[0])==104 || int(expresie[0])==72)
        std::cout<<"Write the expression without spaces. Always add the equal sign!"<<std::endl<<"! - factorial"<<std::endl<<"\\ - square root"<<std::endl<<"^ - power"<<std::endl<<"+ , - , x or * , / - basic math operators"<<std::endl<<"'nr'== - decimal to binary conversion"<<std::endl<<"='nr'= - binary to decimal conversion"<<std::endl<<"pi - instead of writing pi, you can simply type 'pi'"<<std::endl<<"% - percent of a number"<<std::endl<<"sid, cod, tgd, ctd - sine, cosine, tangente, cotangent using degrees"<<std::endl<<"sir, cor, tgr, ctr - sine, cosine, tangente, cotangent using radians"<<std::endl<<"log - logarith in base 10 of a given number"<<std::endl<<std::endl<<"Use only 2 numbers or just one for complex operations(sin, cos, log, etc.)!"<<std::endl<<"Write 'X' to exit."<<std::endl;
    if(int(expresie[0])==102 || int(expresie[0])==70){
        std::cout<<"FAQ"<<std::endl<<"Q: What happens if I add spaces? -> A: Adding spaces or not adding '=' will most likely make the program spit out random answers. So yeah, I insist on adding the equal sign."<<std::endl;
        std::cout<<"Q: It's free? -> A: Yes, it's absotulely free and open-source. You can modify the source code if you would need other functions."<<std::endl;
        std::cout<<"Q: Why'd you create this app? There are several other aplications, better than this one. -> A: I know, but it's mine and I'm proud of it. Plus, I hate the Windows built-in calculator (too complicated for me; I like using the CMD or terminal as a developer)"<<std::endl;}
}
//==========================================================

void reading(char expresie[44]){
    int a=0, b=0, semn=0, a_float_aux=0, b_float_aux=0;
    float m=0, n=0;
    bool trecut_semn=0, a_semn=0, b_semn=0, a_float=0, b_float=0, log_func=0, sin_func=0, cos_func=0, tg_func=0, ctg_func=0, mod_func=0;
    for(int i=0; i<42; i++){
        int aux=expresie[i];

        //std::cout<<aux<<" ";

        if(int(expresie[i])==115 && int(expresie[i+1])==105 && (int(expresie[i+2])==100 || int(expresie[i+2])==114))
            sin_func=!sin_func;

        if(int(expresie[i])==99 && int(expresie[i+1])==111 && (int(expresie[i+2])==100 || int(expresie[i+2])==114))
            cos_func=!cos_func;

        if(int(expresie[i])==116 && int(expresie[i+1])==103 && (int(expresie[i+2])==100 || int(expresie[i+2])==114))
            tg_func=!tg_func;

        if(int(expresie[i])==99 && int(expresie[i+1])==116 && (int(expresie[i+2])==100 || int(expresie[i+2])==114))
            ctg_func=!ctg_func;

        if(int(expresie[i])==108 && int(expresie[i+1])==111 && int(expresie[i+2])==103)
            log_func=!log_func;

        if(int(expresie[i])==112 && int(expresie[i+1])==105)
            if(trecut_semn==0){
                m=pi;
                a_float=!a_float;}
            else{
                n=pi;
                b_float=!b_float;}
        if(sin_func==0 && cos_func==0 && tg_func==0 && ctg_func==0 && log_func==0 && int(expresie[i])==112 && int(expresie[i+1])==105 && int(expresie[i+2])==61){
            std::cout<<pi;
            break;
        }


        if(aux==45 && a==0)
            a_semn=1;
        if(aux==45 && b==0 && trecut_semn==1)
            b_semn=1;
        if(trecut_semn==0 && aux==46)
            a_float=1;
        if(trecut_semn==1 && aux==46)
            b_float=1;
        if(a_float==1 && aux==46 && trecut_semn==0){
            for(int q=i+1; q<20; q++){
                if((int(expresie[q])>=42 && int(expresie[q])<=47 && int(expresie[q])!=44 && int(expresie[q])!=46 || int(expresie[q])==94) || int(expresie[q])==61)
                    break;
                else
                    a_float_aux++;
            }
        }
        if(b_float==1 && trecut_semn==1 && aux==46){
            for(int q=i+1; q<21; q++){
                if(int(expresie[q])==61)
                    break;
                else
                    b_float_aux++;
                //std::cout<<"HEllo! Se aduna b float aux"<<std::endl;
            }
        }
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
        if(aux==37){
            mod_func=!mod_func;
        }

        if(aux==61 && int(expresie[i+1])!=61)
            break;
    }
    if(a_semn==1)
        a=a*-1;
    if(b_semn==1)
        b=b*-1;
    //std::cout<<"A inceput a="<<a<<"   b="<<b<<"   a float="<<a_float<<"   a float aux="<<a_float_aux<<"   b float="<<b_float<<"   b float aux="<<b_float_aux<<std::endl;

    //Float Change
    m=a;
    n=b;
    if(a_float==1)
        m=a/int(power(10, a_float_aux))+a%int(power(10, a_float_aux))*power(10, -a_float_aux);
    if(b_float==1)
        n=b/int(power(10, b_float_aux))+b%int(power(10, b_float_aux))*power(10, -b_float_aux);
    //=============

    //std::cout<<std::endl<<a<<" "<<semn<<" "<<b<<std::endl;

    //Basic Operations ============
    if(semn==43) add(m, n);
    if(semn==45) scad(m, n);
    if(semn==120 || semn==42) mult(m, n);
    if(semn==47) imp(m, n);
    //===============================

    //Others
    if(semn==94)  
        std::cout<<power(m, int(n))<<" ";
    //sin
    if(sin_func){
        if(int(expresie[2])==100)
            sindeg(m);
        if(int(expresie[2])==114)
            sinran(m);
    }
    //cos
    if(cos_func){
        if(int(expresie[2])==100)
            cosdeg(m);
        if(int(expresie[2])==114)
            cosran(m);
    }
    //tg
    if(tg_func){
        if(int(expresie[2])==100)
            tandeg(m);
        if(int(expresie[2])==114)
            tanran(m);
    }
    //ctg
    if(ctg_func){
        if(int(expresie[2])==100)
            ctgdeg(m);
        if(int(expresie[2])==114)
            ctgran(m);
    }
    //log
    if(log_func)
        logfunc(m);
    //mod
    if(mod_func)
        modfunc(m);


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