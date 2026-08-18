# include <iostream>
# include <string>
int main(){
    std :: string choice,classification;
    int total=0;
    do{
    std :: cout<<"Enter number of containers : ";
    int n;
    std :: cin>>n;
    std :: cout<<"Enter the capacity of each container : ";
    int arr[n];
    for(int i=0;i<n;i++){
        std :: cin>>arr[i];
    }
    for(int j=n-1;j>0;--j){
        for(int i=0;i<j;++i){
            if(arr[i]>arr[i+1]){
                arr[i]+=arr[i+1];
                arr[i+1]=arr[i]-arr[i+1];
                arr[i]-=arr[i+1];
            }
        }
    }
    for(int i=0;i<n;++i){
        total+=arr[i];
    }
    if(total<=200){
        classification="light";
    }
    else{
        classification="heavy";
    }
    std :: cout<<"Containers in sorted order:"<<"\n";
    for (int i=0;i<n;++i){
        std :: cout<<i+1<<". "<<arr[i]<<"\n";
    }
    std :: cout<<"Total Shipment weight:"<<total<<"\n";
    std :: cout<<"Classification:"<<classification<<"\n";
    std :: cout<<"Container Weight Bar Chart:"<<"\n";
    for(int i=0;i<n;++i){
        std :: cout<<"container "<<i+1<<"("<<arr[i]<<") :";
        for(int j=1;j<=arr[i]/5;++j){
            std :: cout<<"*";
    }
     std :: cout<< std :: endl;
}
    std :: cout<<"Do you want to process another ship?(Enter either Yes or No)";
    std :: cin>>choice;
}
while(choice=="yes"||choice=="YES"||choice=="Yes");
}