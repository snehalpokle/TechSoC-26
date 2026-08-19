# include <iostream>
# include <string>
# include <fstream>
int main(){
     int n; 
    std :: string reportChoice,reportName;
    std :: string choice,classification;
    int total=0,searchElement;

    do{
    std :: cout<<"Enter number of containers : ";
   
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
    std :: cout<<"Do you want to save the report?(Yes/No)";
    std :: cin>>reportChoice;
    if(reportChoice=="Yes" || reportChoice=="yes" || reportChoice=="YES"){
       std :: cout<<"Please enter name of file:";
       std :: cin>>reportName;
       std :: ofstream fout;
       fout.open(reportName+".txt");
       fout<<"Total Shipment Weight:"<<total<<"\n Average Container Weight:";fout<<total/n<<"\n Heaviest Container:"<< arr[n-1];
       fout <<"\n Lightest container:"<<arr[0]<<"\n Classification:"<<classification;
       std :: cout<<"Report saved to "<<reportName<<".txt";
       fout.close();
    }
    std :: cout<<"\n Enter the weight of container to search:";
    std :: cin>>searchElement;
    int start=0, end=n-1,mid;
    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]==searchElement){
            std :: cout<<"Container found!"<<"\n Container "<<mid+1<<" has weight "<<arr[mid];
            if(start==mid && mid==end){
                break;
            }
        }
        else if(arr[mid]<searchElement){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    std :: cout<<"\n Do you want to process another ship?(Enter either Yes or No)";
    std :: cin>>choice;
}
    while(choice=="yes"||choice=="YES"||choice=="Yes");
}
