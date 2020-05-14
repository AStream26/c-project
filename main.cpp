#include <bits/stdc++.h>
using namespace std;
ifstream cab("cabs.json");
ofstream ans("answer.json");

	 double cablat[1000] ;
//double cablat[1000];
int index=0;
double cablng[1000];
#define pi 3.14159265358979323846 
#define earth_radius 6371.0 
  

class cabs{
	double latitude;
	double longitude;
	double cablat[1000];
	double cablng[1000];
	string name[1000];
	int id[100];
	public:
		void setlnglat(double a,double b){
			latitude = a;
			longitude=b;
		}
		
		void setlat(double lat,double lng,string name1,int id1,int i){
			cablat[i] = lat;
			cablng[i] = lng;
			name[i] = name1;
			id[i] = id1;
		}
		
		void show(){
			cout<<latitude<<" "<<longitude<<endl;
			for(int i=0;i<index;++i){
				cout<<id[i]<<" "<<cablat[i]<<":"<<cablng[i]<<" "<<name[i]<<endl;
			}
		}
		
		void write(int id,string name){
			ans<<"{\""<<"id\":"<<id<<",  "<<"\"name\":"<<"\""<<name<<"\"}"<<endl;
			}
		
		
		double calculatedist(double a,double b){
			double angle;
			double delta = b - longitude;
			
			 angle = acos ( sin(latitude) * 
                  sin(a) + cos(latitude) * 
                  cos(a) * cos(delta) ); 
                  return (angle*earth_radius);
			
		}
		
	   void findcab(){
	  
	   		
	   	for(int i=0;i<index;++i){
	   		    if( calculatedist(cablat[i],cablng[i])<=50.0000)
	   		    {
	   		    	write(id[i],name[i]);
				   }
		   }
	   }
}b;

class position{

     	public:

		
		static void parse();
		static void parseline(string);
	
};
void position::parseline(string line){
	char lat[100];
	char id[100];
	char name[100];
	char lng[100];
	
	 for(int i=0;i<line.length();++i){
		   	   int k;int j=0;
		   	   if(i==2){
		   	   	  k = i+12;
		   	   	  while(line[k]!='"'){
		   	   	  //	cout<<line[k];
		   	   	  	   lat[j++] = line[k];
		   	   	  	   ++k;
						}
						lat[j]='\0';
						i=k;
					//	cout<<endl;
					//	break;
				  }
				  
				  
				  
				  if(line[i]=='u'&&line[i+1]=='s'&&line[i+2]=='e'&&line[i+3]=='r'&&line[i+4]=='_'&&line[i+7]=='"'){
				  	int k=i+10;
				  	int j=0;
				  	
				  	while(line[k]!=','){
		   	   	  //	cout<<line[k];
		   	   	  	   id[j++] = line[k];
		   	   	  	   ++k;
						}
						id[j]='\0';
						i=k;
					//	cout<<endl;
				  	
				  	
				  }
				  
				  if(line[i]=='n'&&line[i+1]=='a'&&line[i+2]=='m'&&line[i+3]=='e'){
				  	int k=i+8;
				  	int j=0;
				  		while(line[k]!='"'){
		   	   	  //	cout<<line[k];
		   	   	  	   name[j++] = line[k];
		   	   	  	   ++k;
						}
						name[j]='\0';
						i=k;
					//	cout<<endl;
				  	
				  }
				  
				  if(line[i]=='l'&&line[i+1]=='o'&&line[i+2]=='n'&&line[i+3]=='g'&&line[i+8]=='e'){
				  	int k=i+13;
				  	
				  		while(line[k]!='"'){
		   	   	 // 	cout<<line[k];
		   	   	  	   lng[j++] = line[k];
		   	   	  	   ++k;
						}
						lng[j]='\0';
						i=k;
					//	cout<<endl;
				  }
				  
				  
				  
				  
		   }
		   
		   double lati = atof(lat)*pi/180;
		    
		    ++index;
		   double longi = atof(lng)*pi/180;
		   int id1 = atoi(id);
		   string name1(name);
		     b.setlat(lati,longi,name,id1,index);
		  // cout<<lati<<":"<<longi<<endl;
		  
}

void position::parse(){
		while(!cab.eof()){
		string line;
		   
		   getline(cab,line);
		   parseline(line);
		  
		   
		  
	}
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	double lat,lng;
	cout<<"Enter latitude of customer:";
	cin>>lat;
	cout<<endl;
	cout<<"Enter longitude of customer:";
	cin>>lng;
	lat = lat*pi/180;
	lng = lng*pi/180;
	
   b.setlnglat(lat,lng);
	position::parse();
//	b.show();
	//cout<<"Result"<<endl;
int a;
         b.findcab();
         cout<<"FILE SAVED AS ANSWER.JSON"<<endl;
         cout<<"PRESS 1 TO READ FILE:::::";
         cin>>a;
         if(a==1){
         	ifstream fin("answer.json");
         	string file;
         	while(!fin.eof()){
         	
         		getline(fin,file);
         		cout<<file<<endl;
			 }
		 }
         
	

	return 0;
}
