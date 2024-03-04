#include<iostream>
#include<cstdlib>
using namespace std;

class Image {
    int width, height;
    int* data;
    public:
        Image(int w, int h, int* pix):width(w), height(h){
            data = new int[w*h];
            for(int i=0; i<w*h; i++)
                data[i] = pix[i];
        }
        Image(const Image& img):width(img.width), height(img.height){
            data = new int[width*height];
            for(int i=0; i<width*height; i++)
                data[i] = img.data[i];
        }
        ~Image(){
            delete[] data;
        }
        void display(){
            cout<<"Width: "<<width<<endl;
            cout<<"Height: "<<height<<endl;
            cout<<"Pixels Data: ";
            for(int i=0; i<width*height; i++)
                cout<<data[i]<<" ";
            cout<<endl;
        }
        void updateData(){
            for(int i=0; i<width*height; i++)
                if(data[i]<=0)
                    data[i] = rand()%255+1;
        }
};

int main() {
    srand(time(0));
    int pix[] = {12,0,-1,5,0,-2};
    Image img1(2,3,pix);
    Image img2(img1);
    cout<<"Original Image"<<endl;
    img1.display();
    cout<<"Copied Image"<<endl;
    img2.display();
    img1.updateData();
    cout<<"\nAfter updating the image, details of original and copied image\n";
    cout<<"-----------------------------------------------\n";
    cout<<"Original Image"<<endl;
    img1.display();
    cout<<"Copied Image"<<endl;
    img2.display();
}