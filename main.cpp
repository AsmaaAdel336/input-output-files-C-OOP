#include <iostream>
#include<fstream>

using namespace std;
class FloatArray{
protected:
    int Size,n;
    float* arr;
public:
    FloatArray(int s){
    arr= new float[s];
    this->n=0;
    }

   virtual void add(float x){
       if(n<Size){
        arr[Size-1]=x;
        n++;
       }
   }
  friend ostream & operator<<(ostream&out,FloatArray&obj){
  out<<obj.n<<"\t";
  for(int i=0;i<obj.n;i++){
    out<<obj.arr[i]<<"\t";

  }
  out<<endl;
  return out;
  }
    friend istream & operator>>(istream&in,FloatArray&obj){
        float num;
        in>>num;
        obj.add(num);
        return in;
    }


   ~FloatArray(){
   delete [] arr;
   }

};


class SortedArray: public FloatArray{
public:
    SortedArray(int x):FloatArray( x){
    Size=x;
    }

   void add(float x){
    if(n<Size){
        for(int i=n-1;(i>=0 & arr[i]>x);i--){
            arr[i+1]=arr[i];
            arr[i+1]=x;
            n++;
        }


    }

       }



};
class FrontArray: public FloatArray{
public:
    FrontArray(int x):FloatArray(x){
    Size=x;
    }
   void add(float x){
   if(n<Size){
        for(int i=n-1;i>=0;i--){
            arr[i+1]=arr[i];
            arr[i+1]=x;
            n++;
        }
       }   }

};
class PositiveArray:public SortedArray{
public:
    PositiveArray(int x):SortedArray(x){

    }
    void add(float x){
    if(x>0){
        SortedArray::add(x);
    }
    }
};
class NegativeArray:public SortedArray{
public:
    NegativeArray(int x):SortedArray(x){}
    void add(float x){
    if(x<0){
        SortedArray::add(x);
    }
    }


};





int main()
{
    string infile,outfile;
    cout<<"enter the name of the input file"<<endl;
    cin>>infile;
    cout<<"enter the name of the output file"<<endl;
    cin>>outfile;
    ifstream in(infile);
    if(in.fail()){
        cout<<"input file is not open"<<endl;
        exit(1);

    }
    ofstream out(outfile);
    if(out.fail()){
        cout<<"output file is not open"<<endl;
        exit(1);

    }




    return 0;
}
