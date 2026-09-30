#include<iostream>
using namespace std;

class Polynomial{
    private: 
    int degree;
    int* coef;
    public:
    //parameterized constructor
    Polynomial(int deg){
        degree = deg;
        coef = new int[degree+1];
        //initialize all coefficients to 0
        for(int i =0;i<=degree;i++)
        coef[i]=0;
    }
    //Copy Constructor-Prefer deep copy
    Polynomial(const Polynomial& other){
        degree = other.degree;
        //allocate a new array
        coef= new int[degree +1];
        //copy each coefficient
        for(int i=0;i<=degree;i++)
        coef[i]=other.coef[i];
    }
    ~Polynomial(){
        delete[] coef;
    }
    //Overload[] operator
    //Allows access modification for coefficeint
    int& operator[](int power){
        if(power <0 || power>degree){
            cout<<"Error: Power is outside the polynomial degree."<<endl;
            exit(1);
        }
        return coef[power];
    }
    Polynomial operator+ (const Polynomial& other) const{
        //result degree is larger than two degree
        int maxDegree=(degree>other.degree)?degree:other.degree;
        Polynomial result(maxDegree);
        //Add coef that exist in both polynomial

        int smallDegree = (degree < other.degree)? degree:other.degree;

        for(int i=0;i<=smallDegree;i++)
        result.coef[i]=coef[i]+other.coef[i];

        //copy remaining coef from that polynomial 
        //having the larger degree
        if(degree>other.degree){
            for(int i=smallDegree+1;i<=degree;i++)
            result.coef[i]=coef[i];
        }
        else
        {
            for(int i=smallDegree+1;i<=other.degree;i++)
              result.coef[i]=coef[i];
        }
         return result;

    }

    //display 
    void display()const{
        for(int i=degree;i>=0;i--){
            if(coef[i]!=0){
                if(i!=degree && coef[i]>0)
                cout<<" + ";
                if(coef[i]<0)
                cout<<" - ";

                int value = (coef[i]<0)?-coef[i]:coef[i];

                if(i==0)
                cout<<value;
                else if (i==1)
                cout<<value<<"x";
                else
                cout<<value<<"x^"<<i;

                
            }
        }
        cout<<endl;
    }

};

int main(){
    //P1(x) = 5x^3 + 2x^2 - 7x + 4
    Polynomial p1(3);
    p1[0]=4;
    p1[1]=-1;
    p1[2]=3;
    p1[3]=28;

     Polynomial p2(4);
    p2[0]=7;
    p2[1]=-6;
    p2[2]=3;
    p2[3]=28;

    cout<<"P1 =";
    p1.display();
    cout<<"P2 =";
    p2.display();
    Polynomial p3(p1);
    cout<<"\nP# (copy of P1)=";
    p3.display();

    //modify p3 using overload
    cout<<"\nafter modify p3[2] = 100 : "<<endl;
    cout<<"P3= ";
    p3.display();

    cout<<"P1= ";
    p1.display();

    Polynomial p4 = p1 +p2;
    cout<<"P4= ";
    p4.display();

return 0;
    
}