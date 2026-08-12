# include <iostream>
# include <string>
int main(){
    int N,C,total=0,max=-1,min=1e9;
    double W,average;
    std :: string type,status;
    std :: cout<<"Enter max port storage capacity=";
    std :: cin>>C;
     std :: cout<<"Enter number of Cointainers=";
    std :: cin>>N;
    for(int i=1;i<=N;++i){
        std :: cout<<"Enter weight of "<<i<<"th cointainer=";
        std :: cin>>W;
        total+=W;
        if(W>max)
        max=W;
        if(W<min)
        min=W;
    }
    if(total>=200)
    type="Heavy";
    else
    type="Light";
    if(total<=C)
    status="Shipment can be unloaded";
    else
    status="Shipment exceeds port capacity";


    average=total/N;
    std :: cout<<"Total Shipment Weight:"<<total<<"\n";
    std :: cout<<"Average Container Weight:"<<average<<"\n";
    std :: cout<<"Heaviest Container:"<<max<<"\n";
    std :: cout<<"Lightest Container:"<<min<<"\n";
    std :: cout<<"Classification:"<<type<<"\n";
    std :: cout<<"Port Capacity:"<<C<<"\n";
    std :: cout<<"Status:"<<status;
}