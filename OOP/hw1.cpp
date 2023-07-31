#include <iostream>
using namespace std;
/* complex addition and subtraction */
class Complex {
public:
    Complex(){}
    Complex(float real_val, float image_val):real(real_val), image(image_val){}
    const Complex operator+(const Complex& amount1) const{
        return Complex(real + amount1.getReal(), image + amount1.getImage());
    }
    const Complex operator-(const Complex& amount1) const{
        return Complex(real - amount1.getReal(), image - amount1.getImage());
    }
    float getReal() const{
        return real;
    }
    float getImage() const{
        return image;
    }
private:
    float real, image;
};

ostream& operator <<(ostream& out, const Complex& k){
    float real, image;
    real = k.getReal();
    image = k.getImage();
    if (image >= 0)
        out << real << " + " << image << "i";
    else
        out << real << " - " << -image << "i";
        return out;
}

int main(){
    float real1, real2, image1, image2;
    while(cin >> real1 >> image1 >> real2 >> image2){ //execute if read 4 input
        Complex myComplex1(real1, image1);
        Complex myComplex2(real2, image2);
        cout << myComplex1 + myComplex2 << endl;
        cout << myComplex1 - myComplex2 << endl;
    }
    return 0;
}
